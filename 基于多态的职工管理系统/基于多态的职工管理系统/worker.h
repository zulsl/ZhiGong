//����ְ��������
// ְ���ķ���Ϊ����ͨԱ���������ϰ�
// ������ְ������һ����(worker)��, ���ö�̬����ְͬ������
// ְ��������Ϊ��ְ����š�ְ��������ְ�����ڲ��ű��
// ְ������ΪΪ:��λְ����Ϣ����, ��ȡ��λ����
//
#pragma once
#include<iostream>
using namespace std;

class worker//ְ����
{
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;//���麯��
	//��ȡ��λ����
	virtual string getGangWei() = 0;//���麯�������಻��Ҫʵ��
	
	int m_id;//ְ�����
	string m_name;//ְ������
	int m_bumenId;//ְ�����ű��

};
