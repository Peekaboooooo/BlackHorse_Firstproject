#include "Manager.h"
#include<iostream>

//�вι��캯��
Manager::Manager(int id, std::string name, int DID)
{
	this->Worker_ID = id;
	this->Name = name;
	this->DeptID = DID;
}


	//��ʾ������Ϣ
void Manager::Show_personal_Information()
{
	std::cout << "ְ����ţ� " << this->Worker_ID
		<< " \tְ�������� "<<this->Name
		<< " \t��λ��" << this->Department_position()
		<< " \t��λְ������ϰ彻��������,���·������Ա��\n";
}

	//����ְλ
std::string Manager::Department_position()
{
	return std::string("����");
}