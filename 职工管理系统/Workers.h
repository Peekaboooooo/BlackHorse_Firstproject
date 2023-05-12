#pragma once
#include<string>

//职工抽象基类
class Worker
{
	//成员
public:
	////构造函数
	Worker();
	//析构函数
	~Worker();
	int Worker_ID, DeptID;		//职工编号, 部门ID
	std::string Name;			//职工姓名

	

	//成员函数
public:
	virtual void Show_personal_Information() = 0;		//显示个人信息
	virtual std::string Department_position() = 0;		//部门职位
		

};

