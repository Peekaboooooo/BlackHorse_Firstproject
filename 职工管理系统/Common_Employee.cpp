#include "Common_Employee.h"

#include<iostream>

//���캯��
Common_Employee::Common_Employee(int id, std::string name, int DID)
{
	this->Worker_ID = id;
	this->Name = name;
	this->DeptID = DID;
}

////��������
//Common_Employee::~Common_Employee()
//{
//
//}

//Ա��������Ϣ
void Common_Employee::Show_personal_Information()
{
	std::cout << "ְ����ţ� " << this->Worker_ID
		<< " \tְ�������� "<< this->Name
		<< " \t��λ��" << this->Department_position()
		<< " \t��λְ����ɾ�����������" << std::endl;
}

//����ְλ
std::string Common_Employee::Department_position()
{
	return std::string("Ա��");
}