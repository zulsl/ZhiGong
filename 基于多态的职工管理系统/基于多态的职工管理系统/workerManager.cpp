#include"workerManager.h"//˫���ű�ʾ�ӵ�ǰ��Ŀ����ͷ�ļ�
//Դ�ļ������ٰ�������ͷ�ļ�
//��ʵ����Ϊ.h�ļ��Ĳ���

workerManager::workerManager()//����ʵ����Ҫ��������
{
	fstream ifs;//���ļ���
	ifs.open(FILENAME, ios::in);//���ļ�
	if (!ifs.is_open())		//�ж��ļ��Ƿ�򿪳ɹ�������һ����������ֵ
	{
		cout << "�ļ�������" << endl;

		//���ļ������ڵ�����£��ٳ�ʼ���洢������
		m_zgNum = 0;//��ʼ����������
		m_zgArr = NULL;//��ʼ��Ա������ָ��
		m_fileIs = true;//��ʼ���ļ��Ƿ�Ϊ��
		ifs.close();//�ر��ļ�
		return;
	}
	char ch;
	ch = ifs.get();//��ȡһ���ַ���ch
	if (ch == EOF)//�жϸ��ַ��Ƿ�Ϊ�ļ������ַ�EOF(end of file)
	//ifs >> ch;//�ڶ��ְ취�����ļ������ַ�����
	//if(ifs.eof())//�����ļ���ȫΪ�գ�eof()���������ǵ��ļ���ȫΪ��ʱ����true
	{
		cout << "�ļ�Ϊ��" << endl;
		m_zgNum = 0;
		m_zgArr = NULL;
		m_fileIs = true;
		ifs.close();
		return;
	}
	int num = get_zgNum();
	cout << "ְ������Ϊ��"<<num << endl;
	m_zgNum = num;
	//���鶼û����������ʸ�����
	m_zgArr = new worker * [m_zgNum];
	m_fileIs = false;
	init_zg();//��ȡְ��

}
void workerManager::show_menu()
{
	cout << "*******************************************" << endl;
	cout << "***********��ӭʹ��ְ������ϵͳ��**********" << endl;
	cout << "************** 0.�˳�����ϵͳ *************" << endl;
	cout << "************** 1.����ְ����Ϣ *************" << endl;
	cout << "************** 2.��ʾְ����Ϣ *************" << endl;
	cout << "************** 3.ɾ����ְְ�� *************" << endl;
	cout << "************** 4.�޸�ְ����Ϣ *************" << endl;
	cout << "************** 5.����ְ����Ϣ *************" << endl;
	cout << "************** 6.���ձ������ *************" << endl;
	cout << "************** 7.��������ĵ� *************" << endl;
	cout << "*******************************************" << endl;
	cout << endl;

}

void workerManager::exitSystem()//�˳�����
{
	cout << "�˳��ɹ�" << endl;
	system("pause");    //��ʾ��Ϣ��ӳ�����ͣ
	exit(0);//exit�����������˳�����

}




//������
// �û�����������ʱ�����ܻᴴ����ͬ�����ְ��
// ����뽫���в�ͬ�����Ա�������뵽һ�������У����Խ�����Ա����ָ��ά����һ��������
// ������ڳ�����ά������������ȵ�����, ���Խ����鴴��������, ������Worker** ��ָ��ά��

//ʵ�֣�
// �ڶ����������󣬲����ڶ�������һ��������������Щ�����ٴ���һ����������ָ����ά��
// ֻ�����պ��ܷŵ��µ����飬�磺�����������������󣬾ͰѴ���һ���ܷ�������������飬Ȼ���ͷ�֮ǰ������
// ���ְ�����Ȱ����������ȴ洢������Ȼ��������Щ��Ϣ��ʼ����
void workerManager::addZg()//���ְ��
{
	cout << "���������ְ���ĸ�����" << endl;//��ʵ���������
	int addnum = 0;//��ʱ��¼��ӵĸ���
	cin >> addnum;
	if (addnum>0)//�����ӵ���������0
	{
		int newsize = m_zgNum + addnum;//�ȼ�����Ӻ�Ŀռ��С
		worker** newspace = new worker * [m_zgNum + addnum];//�ڶ�������һ���ܷ���ְ�����������飬
													//������һ����ָ������������
		if (m_zgArr != NULL)//���ԭ�������鲻Ϊ��
		{
			for (int i = 0; i < m_zgNum; i++)
			{
				newspace[i] = m_zgArr[i];//���ԭ��������ȫ����������
			}
		}
		//����������
		for (int i = 0; i < addnum; i++)//�������
		{
			int id;//�洢�����ְ���ı��
			string name;//�洢�����ְ��������
			int gangwei;//��λ���
			cout << "�������" << i + 1 << "����ְ���ı��" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;
			cout << "�������ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> gangwei;
			//���崴������
			worker* wo = NULL;//����һ������ָ��
			switch (gangwei)//���ݸ�λ������ִ����ĸ�����
			{
			case 1://��ְͨ��
				wo = new YuanGong(id, name, gangwei);
				break;//����switch
			case 2://����
				wo = new JingLi(id, name, gangwei);
				break;
			case 3://�ϰ�
				wo = new LaoBan(id, name, gangwei);
				break;
			default:
				return;
				break;
			}
			newspace[m_zgNum + i] = wo;//������������ָ�룬���浽������
		}
		delete[] m_zgArr;//�ͷ�ԭ�пռ�//deleteָ����ͷ�����ָ��Ŀռ�
		m_zgArr = newspace;//�������ԭ����ָ���滻��ָ�룬����ʵ�������ָ��ָ��洢���ݵĿռ�
		m_zgNum = newsize;//�����µ�ְ������//
		cout << "�ɹ����" << addnum << "����ְ��" << endl;
		m_fileIs = false;//������ļ�֮�󣬰��ļ�����Ϊ��Ϊ��
		save();//�����ļ�
	}
	else
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}

//����������
// ���ļ����ж�д����һ����ӹ����У�����ֻ�ǽ����е�������ӵ����ڴ��У�
// һ������������޷�����������ļ�����������Ҫһ�����ļ����н����Ĺ���, �����ļ����ж�д����
void workerManager::save()//�����ļ�
{
	fstream ofs;
	ofs.open(FILENAME, ios::out);//��д�ļ������ļ���ÿ�ζ�����д

	for (int i = 0; i < m_zgNum; i++)//�������飬����д���ļ�
	{
		ofs << m_zgArr[i]->m_id << " "
			<< m_zgArr[i]->m_name << " "
			<<m_zgArr[i]->m_bumenId<< endl;
	}

	ofs.close();//�ر��ļ�
}

int workerManager::get_zgNum()//��ȡʱͳ������
{
	fstream ifs;//���ļ���
	ifs.open(FILENAME, ios::in);//���ļ�
	int id;
	string name;
	int gangwei;
	int num = 0;
	while (ifs>>id&&ifs>>name&&ifs>> gangwei)//ifs >> id �����ո�ʱ id �Ͷ�ȡ��ϣ����� ifs >> name
	//��ʶ�ȡ��while(ifs >> buf) �����ո񡢻��л��ļ�β����һ�ζ�ȡ����һ�ζ�ȡ����������
	{
		num++;
	}
	ifs.close();
	return num;
}

void workerManager::init_zg()
{
	fstream ifs;//���ļ���
	ifs.open(FILENAME, ios::in);//���ļ�
	int id;
	string name;
	int gangwei;

	int num = 0;//��¼����
	while (ifs >> id && ifs >> name && ifs >> gangwei)//ÿ����һ�������Ķ�ȡ�ʹ���һ�ζ���
	{
		worker* wo = NULL;
		//���ݲ�ͬ����id������ͬ����
		switch (gangwei)
		{
		case 1://��ְͨ��
			wo = new YuanGong(id, name, gangwei);
			break;
		case 2://����
			wo = new JingLi(id, name, gangwei);
			break;
		case 3://�ϰ�
			wo = new LaoBan(id, name, gangwei);
			break;
		default:
			break;
		}
		//������ϰ���Щ���������������
		this->m_zgArr[num] = wo;
		num++;
	}
	ifs.close();

}

void workerManager::show_zg()//��ʾְ��
{
	if (m_fileIs)
	{
		cout << "��ǰ��ְ����Ϣ" << endl;
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

int workerManager::is_zg(int id)//��ѯְ���Ƿ���ڣ��������򷵻�-1
{
	int index = -1;//������
	for (int i = 0; i < m_zgNum; i++)
	{
		if (id == m_zgArr[i]->m_id)//����������¼����
		{
			index = i;
			break;
		}
	}
	return index;

}


void workerManager::del_zg()//ɾ��
{
	if (m_fileIs)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������Ҫɾ����ְ����ţ�" << endl;
		int id = 0;
		cin >> id;
		int index=is_zg(id);//��ѯְ���Ƿ����
		if (index != -1)//���ְ�����ڣ���ɾ����Ӧλ��
		{
			//����ǰ��
			for (int i=index;i<m_zgNum-1;i++)//����-1�������һ��λ��
			{
				m_zgArr[i] = m_zgArr[i + 1];
			}
			m_zgNum--;//ѭ����ϣ���������-1
			save();//ɾ��֮�󱣴�
			cout << "ɾ���ɹ���" << endl;
			//���ɾ�����һ������ֱ������forѭ��Ȼ��mNum - 1��ֱ���߼�ɾ��û������
		}
		else
		{
			cout << "��ְ����Ų�����" << endl;

		}
	}
	system("pause");
	system("cls");

}

void workerManager::mod_zg()//�޸�ְ��
{
	if (m_fileIs)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫ�޸�ְ���ı��:" << endl;
		int id;
		cin >> id;
		int index = is_zg(id);//��ѯְ���Ƿ����
		if (index != -1)//���ְ������
		{
			cout << "�鵽��ְ����" << endl;
			m_zgArr[index]->showInfo();
			cout << "�Ƿ������1.����\t2.�˳���" << endl;
			int sf;
			cin >> sf;
			if (sf != 1)
			{
				return;
			}
			//���ڲ�ͬ��λ���಻ͬ�����в���ֱ�Ӹ���
			delete m_zgArr[index];//���ͷ�ԭ����
			int newid = 0;
			string newname = "";
			int newgangwei = 0;
			cout << "��������ְ���ı�ţ�" << endl;
			cin >> newid;
			cout << "��������ְ����������" << endl;
			cin >> newname;
			cout << "�������ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> newgangwei;
			//���崴������
			worker* wo = NULL;//����һ������ָ�룬׼��ʵ�ֶ�̬
			switch (newgangwei)//���ݸ�λ������ִ����ĸ�����
			{
			case 1://��ְͨ��
				wo = new YuanGong(newid, newname, newgangwei);
				break;//����switch
			case 2://����
				wo = new JingLi(newid, newname, newgangwei);
				break;
			case 3://�ϰ�
				wo = new LaoBan(newid, newname, newgangwei);
				break;
			default:
				return;
				break;
			}
			m_zgArr[index] = wo;//������������ָ�룬���浽������
		
			cout << "�޸ĳɹ�" << endl;
			save();//�����ļ�
		}
		else
		{
			cout << "δ�ҵ���ְ��" << endl;
		}
	}
	system("pause");
	system("cls");

}

void workerManager::find_zg()
{
	if (m_fileIs)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{

		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1.��ְ����Ų��ң�" << endl;
		cout << "2.���������ң�" << endl;
		int an;
		cin >> an;
		if (an == 1)
		{
			cout << "��ְ���ı�ţ�" << endl;
			int id;
			cin >> id;
			int index = is_zg(id);
			if (index != -1)
			{
				cout << "��ְ����Ϣ���£�" << endl;
				m_zgArr[index]->showInfo();
			}
			else
			{
				cout << "δ�ҵ���ְ��" << endl;
			}
		}
		else if (an == 2)
		{
			cout << "��ְ����������" << endl;
			string name;
			cin >> name;
			bool zhaodao= false;
			for (int i=0;i<m_zgNum;i++)
			{
				if (name == m_zgArr[i]->m_name)
				{
					cout << "���ҳɹ���" << endl;

					cout << "��ְ����Ϣ���£�" << endl;
					m_zgArr[i]->showInfo();
					zhaodao = true;
				}
			}
			if(zhaodao == false)
			{
				cout << "δ�ҵ���ְ��" << endl;
			}

		}
		else
		{
			cout << "��������" << endl;

			return;
		}
	}
	system("pause");
	system("cls");


}

void workerManager::sort_zg()//����
{
	if (m_fileIs)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "ѡ������ʽ��" << endl;
		cout << "1.��ְ������������" << endl;
		cout << "2.��ְ���Ž�������" << endl;
		int xz;
		cin >> xz;
		for (int i = 0; i < m_zgNum; i++)
		{
			int minormax = i;//����һ�����ֵ����Сֵ�±�
			for (int j = i+1; j < m_zgNum; j++)
			{
				if (xz == 1)//����
				{
					if (m_zgArr[minormax]->m_id > m_zgArr[j]->m_id)
					{
						minormax = j;
					}
				}
				else//����
				{
					if (m_zgArr[minormax]->m_id < m_zgArr[j]->m_id)
					{
						minormax = j;
					}
				}
			}
			//�ж�minormax�Ƿ��������Сֵ�����ֵ��������ǣ��򽻻�����
			if (i!= minormax)
			{
				//����m_zgArr��һ��ָ�룬���Կ���ֱ�ӽ���
				worker* temp = m_zgArr[i];//����һ����ʱ��ָ��
				m_zgArr[i] = m_zgArr[minormax];//����ָ��
				m_zgArr[minormax] = temp;
			}

		}
		cout << "����ɹ��������Ľ��Ϊ��" << endl;
		save();//����
		show_zg();//������ʾ����

	}

}

void workerManager::qing_kong()//���
{
	if (m_fileIs)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{

		cout << "�Ƿ�����ļ���" << endl;
		cout << "1.ȷ�����" << endl;
		cout <<"2.�˳�" << endl;
		int xz;
		cin >> xz;
		if (xz == 1)
		{
			ofstream ofs(FILENAME, ios::trunc);//������ļ��ķ�ʽ��
			ofs.close();//�ر��ļ�

			//����ڴ�
			for (int i = 0; i < m_zgNum; i++)//��ն���
			{
				if (m_zgArr[i] != NULL)
				{
					delete m_zgArr[i];
					m_zgArr[i] = NULL;//��ֹҰָ��
				}
			}
			m_zgNum = 0;
			delete[] m_zgArr;//�������ָ��
			m_zgArr = NULL;
			m_fileIs = true;//�ļ�����Ϊ��
			cout << "��ճɹ���" << endl;
			//Ϊʲô��ʹ��������������������ֻ�ڳ��������ŵ���
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
	if (this->m_zgArr != NULL)//�ͷ�ְ������
	{
		delete[] m_zgArr;
		m_zgArr = NULL;//��ֹҰָ��
	}
}

