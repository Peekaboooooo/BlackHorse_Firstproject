#pragma once
#include "Workers.h"
class Boss : public Worker
{
	//����
public:
	//�вι��캯��
	Boss(int id, std::string name, int DID);

	//����
public:
	//��ʾ������Ϣ
	virtual void Show_personal_Information();

	//����ְλ
	virtual std::string Department_position();
};

