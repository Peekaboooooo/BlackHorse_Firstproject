#pragma once
#include<iostream>
#include"Workers.h"
#include<fstream>

//信息管理类
class Information_management
{
public:
	Information_management();		//构造函数
	~Information_management();		//析构函数
	int Employee_number;					//公司职工数
	Worker** data_Array;	//类数组
	bool FileIsEmpty;


public:			//功能模块
	void Show_Menu();		//菜单

	void Add_employee();		//增加职工

	void Del_employee();		//删除职工
	int IsExit_employee(int id);		//寻找职工是否存在

	void Modify_employee_information();	//修改职工信息

	void Find_employee();				//查找职工

	void Sort_Employee();				//排序职工

	void Clean_File();					//清空文件

	void ExitSystem();		//退出系统

	void save();		//保存文件
	int Registered_employee();	//统计登记员工人数
	void Init_Employee();		//初始化单个员工信息
	void Display_Employee_imformation(); //显示员工信息

	

};

