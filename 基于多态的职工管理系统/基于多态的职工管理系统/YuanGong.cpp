#include"YuanGong.h"


	//���캯��
YuanGong::YuanGong(int id,string name,int bumenId)
{
	m_id = id;
	m_name = name;
	m_bumenId = bumenId;

}
	//��ʾ������Ϣ
void YuanGong::showInfo()
{
	cout << "ְ����ţ�" << m_id
		<< "\tְ��������" << m_name
		<< "\t��λ��" << getGangWei()
		<< "\t��λְ����ɾ�����������" << endl;
}

	//��ȡְ����λ��Ϣ
string YuanGong::getGangWei() //Ϊ�������֣�ר��дһ������
{
	return string("Ա��");
}
