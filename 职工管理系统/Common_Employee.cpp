#include "Common_Employee.h"

#include<iostream>

//构造函数
Common_Employee::Common_Employee(int id, std::string name, int DID)
{
	this->Worker_ID = id;
	this->Name = name;
	this->DeptID = DID;
}

////析构函数
//Common_Employee::~Common_Employee()
//{
//
//}

//员工个人信息
void Common_Employee::Show_personal_Information()
{
	std::cout << "职工编号： " << this->Worker_ID
		<< " \t职工姓名： "<< this->Name
		<< " \t岗位：" << this->Department_position()
		<< " \t岗位职责：完成经理交给的任务" << std::endl;
}

//部门职位
std::string Common_Employee::Department_position()
{
	return std::string("员工");
}