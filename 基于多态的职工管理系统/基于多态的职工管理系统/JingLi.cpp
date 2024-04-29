#include"JingLi.h"


//构造函数
JingLi::JingLi(int id, string name, int bumenId)
{
	m_id = id;
	m_name = name;
	m_bumenId = bumenId;

}
//显示个人信息
void JingLi::showInfo()
{
	cout << "职工编号：" << m_id
		<< "\t职工姓名：" << m_name
		<< "\t岗位：" << getGangWei()
		<< "\t岗位职责：完成老板交给的任务，并下发给员工" << endl;
}

//获取职工岗位信息
string JingLi::getGangWei()
{
	return string("经理");
}
