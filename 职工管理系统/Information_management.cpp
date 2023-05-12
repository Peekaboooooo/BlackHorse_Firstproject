#include "Information_management.h"
#include"Common_Employee.h"
#include"Manager.h"
#include"Boss.h"
#include<algorithm>

#define Filename "Test.txt"

//构造函数
Information_management::Information_management()		
{
	std::ifstream Infile;
	Infile.open(Filename, std::ios::in);
	if (!Infile.is_open())
	{
		std::cout << "文件不存在\n";
		this->Employee_number = 0; //初始化职员人数
		this->FileIsEmpty = true;	//文件为空
		this->data_Array = nullptr;	//数组初始化
		
		
	}
	else
	{
		std::cout << "打开文件成功\n";
		char ch = '0';
		Infile >> ch;
		if (Infile.eof())
		{
			this->Employee_number = 0; //初始化职员人数
			this->FileIsEmpty = true;	//文件为空
			this->data_Array = nullptr;	//数组初始化
			
			
		}
	}

	int num = this->Registered_employee();
	this->Employee_number = num;

	this->data_Array = new Worker * [this->Employee_number];
	Init_Employee();
	
	

	Infile.close();

	return ;
}

//析构函数
Information_management::~Information_management()		
{
	if (this->data_Array != nullptr)
		delete[] this->data_Array;
}

//菜单
void Information_management::Show_Menu()				
{
	using namespace std;
	cout << "********************************************\n";
	cout << "*********  欢迎使用职工管理系统！ **********\n"  ;
	cout << "*************  0.退出管理程序  *************\n" ;
	cout << "*************  1.增加职工信息  *************\n" ; 
	cout << "*************  2.显示职工信息  *************\n" ;
	cout << "*************  3.删除离职职工  *************\n" ;
	cout << "*************  4.修改职工信息  *************\n" ;
	cout << "*************  5.查找职工信息  *************\n" ;
	cout << "*************  6.按照编号排序  *************\n" ;
	cout << "*************  7.清空所有文档  *************\n" ;
	cout << "********************************************\n";
	cout << endl;
}

//退出系统
void Information_management::ExitSystem()
{
	std::cout << "欢迎下次使用" << std::endl;
}

//添加职员信息
void Information_management::Add_employee()
{
	using namespace std;
	cout << "输入增加员工数量：\n";

	int Add_num = 0;  cin >> Add_num;

	if (Add_num > 0)
	{
		int New_size = this->Employee_number + Add_num;

		Worker** newspace = new Worker * [New_size];	//动态数组扩容

		if (this->data_Array != NULL)	//原来就有职工
		{
			for (int i = 0; i < this->Employee_number; ++i)		//空间转移
				newspace[i] = this->data_Array[i];
		}


		//传入新职员信息
		for (int i = 0; i < Add_num; ++i)
		{
			int id = 0;
			string name;
			int choice = 0;
			cout << "请输入第 " << i + 1 << " 个新职工编号：";
			cin >> id; cout << '\n';

			cout << "请输入第 " << i + 1 << " 个新职工姓名：";
			cin>>name; cout << '\n';

			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> choice;

			Worker* worker = nullptr;

			switch (choice)
			{
			case 1: //普通员工
				worker = new Common_Employee(id, name, 1);
				break;
			case 2: //经理
				worker = new Manager(id, name, 2);
				break;
			case 3:  //老板
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			newspace[this->Employee_number + i] = worker;
		}

		//清空原来的信息
		delete[] this->data_Array;

		//把总信息给更新过来
		this->data_Array = newspace;

		//更新职工总数量
		this->Employee_number = New_size;

		//更新文件空标志
		this->FileIsEmpty = false;
		cout << "成功添加" << Add_num << "名新职工！" << endl;
		//保存信息
		this->save();
	}

	else
		cout << "输入数据不合法" << endl;

	system("pause");
	system("cls");
}

//删除职工
void Information_management::Del_employee()
{
	if (this->FileIsEmpty)
	{
		std::cout << "文件不存在或者记录空！\n";
	}
	else
	{
		std::cout << "请输入需要删除的职工的编号\n";
		int id = 0;
		std::cin >> id;

		int index = this->IsExit_employee(id);	//这里得到的是数组下标
		
		if (index == -1)
		{
			std::cout << "没有该员工信息\n";
		}
		else
		{
			for (int i = index; i < this->Employee_number - 1; ++i)
			{
				this->data_Array[i] = this->data_Array[i + 1];	//数据前移
			}

			this->Employee_number--;	//记得减一个人
			this->save();				//重新保存一下
			std::cout << "删除成功\n";
		}
	}

	system("pause");
	system("cls");
}

//修改职工
void Information_management::Modify_employee_information()
{
	if (this->FileIsEmpty)
	{
		std::cout << "文件不存在或记录为空！\n";
	}
	else
	{
		std::cout << "请输入修改职工编号：\n";
		int id = 0;
		std::cin >> id;

		int index = this->IsExit_employee(id);

		if (index != -1)
		{
			using namespace std;
			//删掉该位置的
			delete this->data_Array[index];
			int NewID = 0;
			std::string Newname;
			int Dchoice = 0;		//部门选择， Departion

			cout << "查到： " << id << "号职工，请输入新职工号： \n";
			cin >> NewID;

			cout << "请输入新姓名： \n";
			cin >> Newname;

			cout << "请输入岗位： \n";
			cout << "1、普通职工\n";
			cout << "2、经理\n";
			cout << "3、老板\n";
			cin >> Dchoice;

			Worker* worker = nullptr;	//定义一个数组指针
			switch (Dchoice)
			{
			case1:
				worker = new Common_Employee(NewID, Newname, Dchoice);
				break;
			case2:
				worker = new Manager(NewID, Newname, Dchoice);
				break;
			case 3:
				worker = new Boss(NewID, Newname, Dchoice);
				break;
			default:
				break;
			}

			//把新数据存回去
			this->data_Array[index] = worker;
			cout << "修改成功\n";

			this->save();

		}
		else
		{
			std::cout << "修改失败，查无此人\n";
		}
	}

	system("pause");
	system("cls");
}

//查找职工
void Information_management::Find_employee()
{
	using namespace std;
	if (this->FileIsEmpty)
	{
		std::cout << "文件不存在或记录为空！\n";
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按姓名查找" << endl;


		int Choice = 0;			cin >> Choice;

		if (Choice == 1)
		{
			int id = 0;
			cout << "输入职工编号:\n";
			cin >> id;

			int ret = IsExit_employee(id);

			if (ret != -1)
			{
				cout << "查找成功,职工信息如下: \n";
				this->data_Array[ret]->Show_personal_Information();
			}
			else
			{
				cout << "查无此人\n";
			}

		}
		else if (Choice == 2)
		{
			string name;
			cout << "输入查找姓名:\n";
			cin >> name;

			bool flag = false;//查找到的标志
			for (int i = 0; i < Employee_number; ++i)
			{
				if (data_Array[i]->Name == name)
				{
					cout << "查找成功,职工编号为:"
						<< data_Array[i]->Worker_ID
						<< "号的信息如下\n";

					flag = true;		//查找成功标志设置为true

					this->data_Array[i]->Show_personal_Information();
				}
			}

			if (flag == false)
			{
				cout << "查找失败，查无此人\n";
			}
		}
		else
		{
			cout << "输入选项有误\n";
		}
	}
	system("pause");
	system("cls");

}

//排序职工
void Information_management::Sort_Employee()
{
	if (this->FileIsEmpty)
	{
		std::cout << "文件不存在或记录为空！\n";
		system("pause");
		system("cls");
	}
	else
	{
		std::cout << "请选择排序方式： \n";
		std::cout << "1、按职工号进行升序\n";
		std::cout << "2、按职工号进行降序\n";

		int select = 0; std::cin >> select;
		
		for (int i = 0; i < Employee_number; ++i)
		{
			int index = i;
			for (int j = i + 1; j < Employee_number; ++j)
			{
				if (select == 1)
				{
					if (data_Array[index]->Worker_ID > data_Array[j]->Worker_ID)//前面大于后面
					{
						index = j;
					}
				}
				else
				{
					if (data_Array[index]->Worker_ID < data_Array[j]->Worker_ID)//后面大于前面
					{
						index = j;
					}
				}
			}

			if (i != index)
			{
				std::swap(data_Array[i], data_Array[index]);

			}
		}
		std::cout << "排序成功,排序后结果为：\n";
		this->save();
		this->Display_Employee_imformation();
	}
}

//清空文件
void Information_management::Clean_File()
{
	std::cout << "确认清空？\n";
	std::cout << "1、确认\n";
	std::cout << "2、返回\n";

	int Choice = 0; std::cin >> Choice;

	if (Choice == 1)
	{
		std::ofstream outFile;
		outFile.open(Filename, std::ios::trunc);	//文件存在就删除重新创建
		outFile.close();

		if (this->data_Array != NULL)	//数组非空
		{
			//把每个数组内的对象指针都给释放掉
			for (int i = 0; i < this->Employee_number; i++)	
			{
				if (this->data_Array[i] != NULL)
				{
					delete this->data_Array[i];
				}
			}
			//初始化
			this->Employee_number = 0;	
			delete[] this->data_Array;
			this->data_Array = NULL;
			this->FileIsEmpty = true;
			
		}
		std::cout << "清空成功！" << std::endl;

	}
	system("pause");
	system("cls");
}

//寻找职工是否存在
int Information_management::IsExit_employee(int id)
{
	int index = -1;		//记录职工位置
	for (int i = 0; i < this->Employee_number; ++i)		//更新位置
	{
		if (this->data_Array[i]->Worker_ID == id)
		{
			index = i;
			break;
		}
	}

	return index;
}



//保存文件
void Information_management::save()
{
	std::ofstream outFile;
	outFile.open(Filename, std::ios::out);

	for (int i = 0; i < this->Employee_number; ++i)
	{
		outFile << this->data_Array[i]->Worker_ID <<" "
			<< this->data_Array[i]->Name <<" "
			<< this->data_Array[i]->DeptID << '\n';
	}

	outFile.close();
}

//统计在档员工人数
int Information_management::Registered_employee()
{
	std::ifstream Infile;
	Infile.open(Filename, std::ios::in);

	//定义三个测试数据
	int ID, DId; /*ID = DId = 0;*/
	std::string name;

	int num = 0;
	while (Infile>>ID && Infile>>name && Infile>>DId)
	{
		num++;
	}
	Infile.close();
	
	return num;
}

//初始化每个员工信息
void Information_management::Init_Employee()
{
	std::ifstream Infile;
	Infile.open(Filename, std::ios::in);

	//定义三个测试数据
	int ID, DId; ID = DId = 0;
	std::string name;

	int index = 0;
	while (Infile >> ID && Infile >> name && Infile >> DId)
	{
		Worker* worker =nullptr;

		if (DId == 1)
		{
			worker = new Common_Employee(ID, name, DId);
		}
		else if (DId == 2)
		{
			worker = new Manager(ID, name, DId);
		}
		else
		{
			worker = new Boss(ID, name, DId);
		}

		this->data_Array[index++] = worker;
	}

	Infile.close();
}

//显示员工信息
void Information_management::Display_Employee_imformation()
{
	if(this->FileIsEmpty)
		std::cout << "文件不存在或记录为空！\n";
	else
	{
		for (int i = 0; i < Employee_number; ++i)
		{
			//多态调用接口
			this->data_Array[i]->Show_personal_Information();
			//就是通过信息管理类逐个访问Worker基类的指针,再通过基类中定义的展示
			//员工信息的纯虚函数，并通过偏移量找到对应的职员派生类。
		}
	}

	system("pause");
 	system("cls");
}