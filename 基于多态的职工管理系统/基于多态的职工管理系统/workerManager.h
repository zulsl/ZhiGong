//�����ฺ����������£�
// ���û��Ĺ�ͨ�˵�����
// ��ְ����ɾ�Ĳ�Ĳ���
// ���ļ��Ķ�д����
//
#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>
#include<fstream>//�����ļ���
using namespace std;
#include"worker.h"
#include"YuanGong.h"
#include"LaoBan.h"
#include"JingLi.h"
#pragma warning(disable:6385) 
#pragma warning(disable:6386)
#define FILENAME "zgfile.txt"//���ļ�·������������Ϊ�����������ε���

class workerManager
{
public:
	//���캯��
	workerManager();

	//չʾ�˵�
	void show_menu();

	//�˳�����
	void exitSystem();

	//���ְ������
	void addZg();

	//�����ļ�����
	void save();

	//��ʾְ������
	void show_zg();

	//��ȡʱ��¼����
	int get_zgNum();

	//��ȡְ��
	void init_zg();

	//��ѯְ���Ƿ����
	int is_zg(int id);//�ú������ظô��ڵ�ְ��id

	//ɾ��ְ������
	void del_zg();

	//�޸�ְ������
	void mod_zg();

	//����ְ������
	void find_zg();
	
	//������
	void sort_zg();

	//��պ���
	void qing_kong();

	//��������
	~workerManager();

	//��¼��������
	int m_zgNum;
	//Ա������ָ��
	worker** m_zgArr;//�ⲻ��һ�����飬����һ������ָ��
	//�ж��ļ��Ƿ�Ϊ��
	bool m_fileIs;
};
