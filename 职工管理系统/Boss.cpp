#include "Boss.h"
#include<iostream>

//�вι��캯��
Boss::Boss(int id, std::string name, int DID)
{
	this->Worker_ID = id;
	this->Name = name;
	this->DeptID = DID;
}


//��ʾ������Ϣ
void Boss::Show_personal_Information()
{
	std::cout << "ְ����ţ� " << this->Worker_ID
		<< " \tְ�������� "<< this->Name
		<< " \t��λ��" << this->Department_position()
		<< " \t��λְ�𣺹���˾��������\n";
}

//����ְλ
std::string Boss::Department_position()
{
	return std::string("�ܲ�");
}