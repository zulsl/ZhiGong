//�ϰ���
#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class LaoBan :public worker
{
public:

	//���캯��
	LaoBan(int id, string name, int bumenId);
	//��ʾ������Ϣ
	void showInfo();


	//��ȡְ����λ��Ϣ
	string getGangWei();


};