#pragma once
#include "Workers.h"
class Manager :public Worker
{
	//����
public:
	//�вι��캯��
	Manager(int id, std::string name, int DID);

	//����
public:
	//��ʾ������Ϣ
	virtual void Show_personal_Information();	

	//����ְλ
	virtual std::string Department_position();		
};

