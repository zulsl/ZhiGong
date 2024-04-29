//管理类负责的内容如下：
// 与用户的沟通菜单界面
// 对职工增删改查的操作
// 与文件的读写交互
//
#pragma once//防止头文件重复包含
#include<iostream>
#include<fstream>//包含文件流
using namespace std;
#include"worker.h"
#include"YuanGong.h"
#include"LaoBan.h"
#include"JingLi.h"
#pragma warning(disable:6385) 
#pragma warning(disable:6386)
#define FILENAME "zgfile.txt"//将文件路径及名称设置为常量，方便多次调用

class workerManager
{
public:
	//构造函数
	workerManager();

	//展示菜单
	void show_menu();

	//退出程序
	void exitSystem();

	//添加职工函数
	void addZg();

	//保存文件函数
	void save();

	//显示职工函数
	void show_zg();

	//读取时记录人数
	int get_zgNum();

	//读取职工
	void init_zg();

	//查询职工是否存在
	int is_zg(int id);//该函数返回该存在的职工id

	//删除职工函数
	void del_zg();

	//修改职工函数
	void mod_zg();

	//查找职工函数
	void find_zg();
	
	//排序函数
	void sort_zg();

	//清空函数
	void qing_kong();

	//析构函数
	~workerManager();

	//记录人数个数
	int m_zgNum;
	//员工数组指针
	worker** m_zgArr;//这不是一个数组，而是一个数组指针
	//判断文件是否为空
	bool m_fileIs;
};
