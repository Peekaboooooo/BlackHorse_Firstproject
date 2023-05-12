#pragma once
#include"Workers.h"
//普通员工类
class Common_Employee :public Worker
{
	//基本
public:
	//构造函数
	Common_Employee(int id, std::string name, int DeptID);
	
	////析构函数
	//~Common_Employee();
	
	//功能模型
public:
	//员工个人信息
	virtual void Show_personal_Information();

	//部门职位
	virtual std::string Department_position();


};

