#include"workerManager.h"//双引号表示从当前项目查找头文件
//源文件不用再包含基础头文件
//其实是作为.h文件的补充

workerManager::workerManager()//类外实现需要加作用域
{
	fstream ifs;//读文件流
	ifs.open(FILENAME, ios::in);//打开文件
	if (!ifs.is_open())		//判断文件是否打开成功，返回一个布尔类型值
	{
		cout << "文件不存在" << endl;

		//在文件不存在的情况下，再初始化存储的数组
		m_zgNum = 0;//初始化人数个数
		m_zgArr = NULL;//初始化员工数组指针
		m_fileIs = true;//初始化文件是否为空
		ifs.close();//关闭文件
		return;
	}
	char ch;
	ch = ifs.get();//获取一个字符给ch
	if (ch == EOF)//判断该字符是否为文件结束字符EOF(end of file)
	//ifs >> ch;//第二种办法，将文件结束字符移走
	//if(ifs.eof())//这是文件完全为空，eof()函数作用是当文件完全为空时返回true
	{
		cout << "文件为空" << endl;
		m_zgNum = 0;
		m_zgArr = NULL;
		m_fileIs = true;
		ifs.close();
		return;
	}
	int num = get_zgNum();
	cout << "职工人数为："<<num << endl;
	m_zgNum = num;
	//数组都没创建，你访问个锤子
	m_zgArr = new worker * [m_zgNum];
	m_fileIs = false;
	init_zg();//读取职工

}
void workerManager::show_menu()
{
	cout << "*******************************************" << endl;
	cout << "***********欢迎使用职工管理系统！**********" << endl;
	cout << "************** 0.退出管理系统 *************" << endl;
	cout << "************** 1.增加职工信息 *************" << endl;
	cout << "************** 2.显示职工信息 *************" << endl;
	cout << "************** 3.删除离职职工 *************" << endl;
	cout << "************** 4.修改职工信息 *************" << endl;
	cout << "************** 5.查找职工信息 *************" << endl;
	cout << "************** 6.按照编号排序 *************" << endl;
	cout << "************** 7.清空所有文档 *************" << endl;
	cout << "*******************************************" << endl;
	cout << endl;

}

void workerManager::exitSystem()//退出程序
{
	cout << "退出成功" << endl;
	system("pause");    //提示信息后加程序暂停
	exit(0);//exit函数作用是退出程序

}




//分析：
// 用户在批量创建时，可能会创建不同种类的职工
// 如果想将所有不同种类的员工都放入到一个数组中，可以将所有员工的指针维护到一个数组里
// 如果想在程序中维护这个不定长度的数组, 可以将数组创建到堆区, 并利用Worker** 的指针维护

//实现：
// 在堆区创建对象，并且在堆区创建一个数组来接收这些对象，再创建一个这个数组的指针来维护
// 只创建刚好能放的下的数组，如：如果创建超过五个对象，就把创建一个能放六个对象的数组，然后释放之前的数组
// 添加职工：先把输入姓名等存储起来，然后在用这些信息初始子类
void workerManager::addZg()//添加职工
{
	cout << "请输入添加职工的个数：" << endl;//可实现批量添加
	int addnum = 0;//临时记录添加的个数
	cin >> addnum;
	if (addnum>0)//如果添加的数量大于0
	{
		int newsize = m_zgNum + addnum;//先计算添加后的空间大小
		worker** newspace = new worker * [m_zgNum + addnum];//在堆区开辟一个能放下职工个数的数组，
													//并且用一个新指针接收这个数组
		if (m_zgArr != NULL)//如果原本的数组不为空
		{
			for (int i = 0; i < m_zgNum; i++)
			{
				newspace[i] = m_zgArr[i];//则把原本的数组全部拷贝进来
			}
		}
		//输入新数据
		for (int i = 0; i < addnum; i++)//批量添加
		{
			int id;//存储新添加职工的编号
			string name;//存储新添加职工的姓名
			int gangwei;//岗位编号
			cout << "请输入第" << i + 1 << "个新职工的编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工的姓名" << endl;
			cin >> name;
			cout << "请输入该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> gangwei;
			//具体创建对象
			worker* wo = NULL;//创建一个父类指针
			switch (gangwei)//根据岗位编号区分创建哪个子类
			{
			case 1://普通职工
				wo = new YuanGong(id, name, gangwei);
				break;//结束switch
			case 2://经理
				wo = new JingLi(id, name, gangwei);
				break;
			case 3://老板
				wo = new LaoBan(id, name, gangwei);
				break;
			default:
				return;
				break;
			}
			newspace[m_zgNum + i] = wo;//将创建的数组指针，保存到数组中
		}
		delete[] m_zgArr;//释放原有空间//delete指针会释放它所指向的空间
		m_zgArr = newspace;//再让这个原本的指针替换新指针，最终实现最初的指针指向存储数据的空间
		m_zgNum = newsize;//更新新的职工个数//
		cout << "成功添加" << addnum << "名新职工" << endl;
		m_fileIs = false;//当添加文件之后，把文件设置为不为空
		save();//保存文件
	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}

//功能描述：
// 对文件进行读写在上一个添加功能中，我们只是将所有的数据添加到了内存中，
// 一旦程序结束就无法保存了因此文件管理类中需要一个与文件进行交互的功能, 对于文件进行读写操作
void workerManager::save()//保存文件
{
	fstream ofs;
	ofs.open(FILENAME, ios::out);//以写文件而打开文件，每次都会重写

	for (int i = 0; i < m_zgNum; i++)//遍历数组，依次写入文件
	{
		ofs << m_zgArr[i]->m_id << " "
			<< m_zgArr[i]->m_name << " "
			<<m_zgArr[i]->m_bumenId<< endl;
	}

	ofs.close();//关闭文件
}

int workerManager::get_zgNum()//读取时统计人数
{
	fstream ifs;//读文件流
	ifs.open(FILENAME, ios::in);//打开文件
	int id;
	string name;
	int gangwei;
	int num = 0;
	while (ifs>>id&&ifs>>name&&ifs>> gangwei)//ifs >> id 遇到空格时 id 就读取完毕，跳到 ifs >> name
	//逐词读取：while(ifs >> buf) 遇到空格、换行或文件尾结束一次读取，即一次读取连续的内容
	{
		num++;
	}
	ifs.close();
	return num;
}

void workerManager::init_zg()
{
	fstream ifs;//读文件流
	ifs.open(FILENAME, ios::in);//打开文件
	int id;
	string name;
	int gangwei;

	int num = 0;//记录人数
	while (ifs >> id && ifs >> name && ifs >> gangwei)//每进行一次完整的读取就创建一次对象
	{
		worker* wo = NULL;
		//根据不同部门id创建不同对象
		switch (gangwei)
		{
		case 1://普通职工
			wo = new YuanGong(id, name, gangwei);
			break;
		case 2://经理
			wo = new JingLi(id, name, gangwei);
			break;
		case 3://老板
			wo = new LaoBan(id, name, gangwei);
			break;
		default:
			break;
		}
		//创建完毕把这些对象放在数组里面
		this->m_zgArr[num] = wo;
		num++;
	}
	ifs.close();

}

void workerManager::show_zg()//显示职工
{
	if (m_fileIs)
	{
		cout << "当前无职工信息" << endl;
	}
	else
	{
		for (int i = 0; i < m_zgNum; i++)
		{
			m_zgArr[i]->showInfo();
		}

	}
	system("pause");
	system("cls");
}

int workerManager::is_zg(int id)//查询职工是否存在，不存在则返回-1
{
	int index = -1;//计数器
	for (int i = 0; i < m_zgNum; i++)
	{
		if (id == m_zgArr[i]->m_id)//如果存在则记录其编号
		{
			index = i;
			break;
		}
	}
	return index;

}


void workerManager::del_zg()//删除
{
	if (m_fileIs)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		cout << "请输入你要删除的职工编号：" << endl;
		int id = 0;
		cin >> id;
		int index=is_zg(id);//查询职工是否存在
		if (index != -1)//如果职工存在，则删掉对应位置
		{
			//数据前移
			for (int i=index;i<m_zgNum-1;i++)//数组-1才是最后一个位置
			{
				m_zgArr[i] = m_zgArr[i + 1];
			}
			m_zgNum--;//循环完毕，数组人数-1
			save();//删除之后保存
			cout << "删除成功！" << endl;
			//如果删除最后一个数会直接跳过for循环然后mNum - 1，直接逻辑删除没有问题
		}
		else
		{
			cout << "该职工编号不存在" << endl;

		}
	}
	system("pause");
	system("cls");

}

void workerManager::mod_zg()//修改职工
{
	if (m_fileIs)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		cout << "请输入要修改职工的编号:" << endl;
		int id;
		cin >> id;
		int index = is_zg(id);//查询职工是否存在
		if (index != -1)//如果职工存在
		{
			cout << "查到该职工：" << endl;
			m_zgArr[index]->showInfo();
			cout << "是否继续（1.继续\t2.退出）" << endl;
			int sf;
			cin >> sf;
			if (sf != 1)
			{
				return;
			}
			//由于不同岗位的类不同，所有不能直接覆盖
			delete m_zgArr[index];//先释放原数据
			int newid = 0;
			string newname = "";
			int newgangwei = 0;
			cout << "请输入新职工的编号：" << endl;
			cin >> newid;
			cout << "请输入新职工的姓名：" << endl;
			cin >> newname;
			cout << "请输入该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> newgangwei;
			//具体创建对象
			worker* wo = NULL;//创建一个父类指针，准备实现多态
			switch (newgangwei)//根据岗位编号区分创建哪个子类
			{
			case 1://普通职工
				wo = new YuanGong(newid, newname, newgangwei);
				break;//结束switch
			case 2://经理
				wo = new JingLi(newid, newname, newgangwei);
				break;
			case 3://老板
				wo = new LaoBan(newid, newname, newgangwei);
				break;
			default:
				return;
				break;
			}
			m_zgArr[index] = wo;//将创建的数组指针，保存到数组中
		
			cout << "修改成功" << endl;
			save();//保存文件
		}
		else
		{
			cout << "未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");

}

void workerManager::find_zg()
{
	if (m_fileIs)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{

		cout << "请输入查找的方式：" << endl;
		cout << "1.按职工编号查找：" << endl;
		cout << "2.按姓名查找：" << endl;
		int an;
		cin >> an;
		if (an == 1)
		{
			cout << "请职工的编号：" << endl;
			int id;
			cin >> id;
			int index = is_zg(id);
			if (index != -1)
			{
				cout << "该职工信息如下：" << endl;
				m_zgArr[index]->showInfo();
			}
			else
			{
				cout << "未找到该职工" << endl;
			}
		}
		else if (an == 2)
		{
			cout << "请职工的姓名：" << endl;
			string name;
			cin >> name;
			bool zhaodao= false;
			for (int i=0;i<m_zgNum;i++)
			{
				if (name == m_zgArr[i]->m_name)
				{
					cout << "查找成功：" << endl;

					cout << "该职工信息如下：" << endl;
					m_zgArr[i]->showInfo();
					zhaodao = true;
				}
			}
			if(zhaodao == false)
			{
				cout << "未找到该职工" << endl;
			}

		}
		else
		{
			cout << "输入有误" << endl;

			return;
		}
	}
	system("pause");
	system("cls");


}

void workerManager::sort_zg()//排序
{
	if (m_fileIs)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		cout << "选择排序方式：" << endl;
		cout << "1.按职工号升序排序" << endl;
		cout << "2.按职工号降序排序" << endl;
		int xz;
		cin >> xz;
		for (int i = 0; i < m_zgNum; i++)
		{
			int minormax = i;//声明一个最大值或最小值下标
			for (int j = i+1; j < m_zgNum; j++)
			{
				if (xz == 1)//升序
				{
					if (m_zgArr[minormax]->m_id > m_zgArr[j]->m_id)
					{
						minormax = j;
					}
				}
				else//降序
				{
					if (m_zgArr[minormax]->m_id < m_zgArr[j]->m_id)
					{
						minormax = j;
					}
				}
			}
			//判断minormax是否真的是最小值或最大值，如果不是，则交换数据
			if (i!= minormax)
			{
				//由于m_zgArr是一个指针，所以可以直接交换
				worker* temp = m_zgArr[i];//创建一个临时的指针
				m_zgArr[i] = m_zgArr[minormax];//交换指针
				m_zgArr[minormax] = temp;
			}

		}
		cout << "排序成功！排序后的结果为：" << endl;
		save();//保存
		show_zg();//调用显示函数

	}

}

void workerManager::qing_kong()//清空
{
	if (m_fileIs)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{

		cout << "是否清空文件：" << endl;
		cout << "1.确定清空" << endl;
		cout <<"2.退出" << endl;
		int xz;
		cin >> xz;
		if (xz == 1)
		{
			ofstream ofs(FILENAME, ios::trunc);//以清空文件的方式打开
			ofs.close();//关闭文件

			//清空内存
			for (int i = 0; i < m_zgNum; i++)//清空对象
			{
				if (m_zgArr[i] != NULL)
				{
					delete m_zgArr[i];
					m_zgArr[i] = NULL;//防止野指针
				}
			}
			m_zgNum = 0;
			delete[] m_zgArr;//清空数组指针
			m_zgArr = NULL;
			m_fileIs = true;//文件设置为空
			cout << "清空成功！" << endl;
			//为什么不使用析构函数：析构函数只在程序结束后才调用
		}
		else
		{
			return;
		}
	}
	system("pause");
	system("cls");
}


workerManager::~workerManager()
{
	if (this->m_zgArr != NULL)//释放职工数组
	{
		delete[] m_zgArr;
		m_zgArr = NULL;//防止野指针
	}
}

