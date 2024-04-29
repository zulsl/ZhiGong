#include"LaoBan.h"


//构造函数
LaoBan::LaoBan(int id, string name, int bumenId)
{
	m_id = id;
	m_name = name;
	m_bumenId = bumenId;

}
//显示个人信息
void LaoBan::showInfo()
{
	cout << "职工编号：" << m_id
		<< "\t职工姓名：" << m_name
		<< "\t岗位：" << getGangWei()
		<< "\t岗位职责：管理公司所有事务" << endl;
}

//获取职工岗位信息
string LaoBan::getGangWei()
{
	return string("老板");
}
