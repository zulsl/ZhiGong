//创建职工抽象类
// 职工的分类为：普通员工、经理、老板
// 将三种职工抽象到一个类(worker)中, 利用多态管理不同职工种类
// 职工的属性为：职工编号、职工姓名、职工所在部门编号
// 职工的行为为:岗位职责信息描述, 获取岗位名称
//
#pragma once
#include<iostream>
using namespace std;

class worker//职工类
{
public:
	//显示个人信息
	virtual void showInfo() = 0;//纯虚函数
	//获取岗位名称
	virtual string getGangWei() = 0;//纯虚函数，父类不需要实现
	
	int m_id;//职工编号
	string m_name;//职工姓名
	int m_bumenId;//职工部门编号

};
