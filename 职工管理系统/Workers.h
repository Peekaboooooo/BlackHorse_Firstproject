#pragma once
#include<string>

//ְ���������
class Worker
{
	//��Ա
public:
	////���캯��
	Worker();
	//��������
	~Worker();
	int Worker_ID, DeptID;		//ְ�����, ����ID
	std::string Name;			//ְ������

	

	//��Ա����
public:
	virtual void Show_personal_Information() = 0;		//��ʾ������Ϣ
	virtual std::string Department_position() = 0;		//����ְλ
		

};

