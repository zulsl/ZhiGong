//������
#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class JingLi :public worker
{
public:
	//���캯��
	JingLi(int id, string name, int bumenId);
	//��ʾ������Ϣ
	void showInfo();


	//��ȡְ����λ��Ϣ
	string getGangWei();


};