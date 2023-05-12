#include "Boss.h"
#include<iostream>

//有参构造函数
Boss::Boss(int id, std::string name, int DID)
{
	this->Worker_ID = id;
	this->Name = name;
	this->DeptID = DID;
}


//显示个人信息
void Boss::Show_personal_Information()
{
	std::cout << "职工编号： " << this->Worker_ID
		<< " \t职工姓名： "<< this->Name
		<< " \t岗位：" << this->Department_position()
		<< " \t岗位职责：管理公司所有事务\n";
}

//部门职位
std::string Boss::Department_position()
{
	return std::string("总裁");
}