#include"LaoBan.h"


//���캯��
LaoBan::LaoBan(int id, string name, int bumenId)
{
	m_id = id;
	m_name = name;
	m_bumenId = bumenId;

}
//��ʾ������Ϣ
void LaoBan::showInfo()
{
	cout << "ְ����ţ�" << m_id
		<< "\tְ��������" << m_name
		<< "\t��λ��" << getGangWei()
		<< "\t��λְ�𣺹���˾��������" << endl;
}

//��ȡְ����λ��Ϣ
string LaoBan::getGangWei()
{
	return string("�ϰ�");
}
