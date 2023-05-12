#include "Manager.h"
#include<iostream>

//有参构造函数
Manager::Manager(int id, std::string name, int DID)
{
	this->Worker_ID = id;
	this->Name = name;
	this->DeptID = DID;
}


	//显示个人信息
void Manager::Show_personal_Information()
{
	std::cout << "职工编号： " << this->Worker_ID
		<< " \t职工姓名： "<<this->Name
		<< " \t岗位：" << this->Department_position()
		<< " \t岗位职责：完成老板交给的任务,并下发任务给员工\n";
}

	//部门职位
std::string Manager::Department_position()
{
	return std::string("经理");
}