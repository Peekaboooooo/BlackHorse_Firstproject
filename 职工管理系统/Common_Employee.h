#pragma once
#include"Workers.h"
//��ͨԱ����
class Common_Employee :public Worker
{
	//����
public:
	//���캯��
	Common_Employee(int id, std::string name, int DeptID);
	
	////��������
	//~Common_Employee();
	
	//����ģ��
public:
	//Ա��������Ϣ
	virtual void Show_personal_Information();

	//����ְλ
	virtual std::string Department_position();


};

