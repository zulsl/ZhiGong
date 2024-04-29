//老板类
#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class LaoBan :public worker
{
public:

	//构造函数
	LaoBan(int id, string name, int bumenId);
	//显示个人信息
	void showInfo();


	//获取职工岗位信息
	string getGangWei();


};