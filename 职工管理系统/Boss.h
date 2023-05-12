#pragma once
#include "Workers.h"
class Boss : public Worker
{
	//基本
public:
	//有参构造函数
	Boss(int id, std::string name, int DID);

	//功能
public:
	//显示个人信息
	virtual void Show_personal_Information();

	//部门职位
	virtual std::string Department_position();
};

