#include"JingLi.h"


//���캯��
JingLi::JingLi(int id, string name, int bumenId)
{
	m_id = id;
	m_name = name;
	m_bumenId = bumenId;

}
//��ʾ������Ϣ
void JingLi::showInfo()
{
	cout << "ְ����ţ�" << m_id
		<< "\tְ��������" << m_name
		<< "\t��λ��" << getGangWei()
		<< "\t��λְ������ϰ彻�������񣬲��·���Ա��" << endl;
}

//��ȡְ����λ��Ϣ
string JingLi::getGangWei()
{
	return string("����");
}
