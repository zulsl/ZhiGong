//Ա����
#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class YuanGong:public worker
{
public:

	//���캯��
	YuanGong(int id, string name, int bumenId);
	//��ʾ������Ϣ
	void showInfo();


	//��ȡְ����λ��Ϣ
	string getGangWei();


};