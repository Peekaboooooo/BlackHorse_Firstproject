#include <iostream>
#include"Information_management.h"
#include"Workers.h"		//员工抽象基类
#include"Common_Employee.h"	//普通员工
#include"Manager.h"		//经理
#include"Boss.h"	//老板

void test()
{
	Worker* worker = NULL;
	worker = new Common_Employee(1, "张三", 1);
	worker->Show_personal_Information();
	delete worker;

	worker = new Manager(2, "李四", 2);
	worker->Show_personal_Information();
	delete worker;

	worker = new Boss(3, "王五", 3);
	worker->Show_personal_Information();
	delete worker;
}

int main()
{
    Information_management wm;
    short num = 0;
    wm.Show_Menu();
    std::cout << "输入您的选择：" << std::endl;
    std::cin >> num;

    switch (num)
    {
	case 0: //退出系统
		wm.ExitSystem();
		break;
	case 1: //添加职工
		wm.Add_employee();
		break;
	case 2: //显示职工
		wm.Display_Employee_imformation();
		break;
	case 3: //删除职工
		wm.Del_employee();
		break;
	case 4: //修改职工
		wm.Modify_employee_information();
		break;
	case 5: //查找职工
		wm.Find_employee();
		break;
	case 6: //排序职工
		wm.Sort_Employee();
		break;
	case 7: //清空文件
		wm.Clean_File();
		break;
	default:
		system("cls");  //清屏
		break;
    }
	/*test();*/
    return 0;
}

