//经理类
#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class JingLi :public worker
{
public:
	//构造函数
	JingLi(int id, string name, int bumenId);
	//显示个人信息
	void showInfo();


	//获取职工岗位信息
	string getGangWei();


};