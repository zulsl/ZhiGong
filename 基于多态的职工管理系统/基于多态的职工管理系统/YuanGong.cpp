#include"YuanGong.h"


	//构造函数
YuanGong::YuanGong(int id,string name,int bumenId)
{
	m_id = id;
	m_name = name;
	m_bumenId = bumenId;

}
	//显示个人信息
void YuanGong::showInfo()
{
	cout << "职工编号：" << m_id
		<< "\t职工姓名：" << m_name
		<< "\t岗位：" << getGangWei()
		<< "\t岗位职责：完成经理交给的任务" << endl;
}

	//获取职工岗位信息
string YuanGong::getGangWei() //为了两个字，专门写一个函数
{
	return string("员工");
}
