#pragma once
#include<iostream>
#include"Workers.h"
#include<fstream>

//��Ϣ������
class Information_management
{
public:
	Information_management();		//���캯��
	~Information_management();		//��������
	int Employee_number;					//��˾ְ����
	Worker** data_Array;	//������
	bool FileIsEmpty;


public:			//����ģ��
	void Show_Menu();		//�˵�

	void Add_employee();		//����ְ��

	void Del_employee();		//ɾ��ְ��
	int IsExit_employee(int id);		//Ѱ��ְ���Ƿ����

	void Modify_employee_information();	//�޸�ְ����Ϣ

	void Find_employee();				//����ְ��

	void Sort_Employee();				//����ְ��

	void Clean_File();					//����ļ�

	void ExitSystem();		//�˳�ϵͳ

	void save();		//�����ļ�
	int Registered_employee();	//ͳ�ƵǼ�Ա������
	void Init_Employee();		//��ʼ������Ա����Ϣ
	void Display_Employee_imformation(); //��ʾԱ����Ϣ

	

};

