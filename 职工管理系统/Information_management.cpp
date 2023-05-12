#include "Information_management.h"
#include"Common_Employee.h"
#include"Manager.h"
#include"Boss.h"
#include<algorithm>

#define Filename "Test.txt"

//���캯��
Information_management::Information_management()		
{
	std::ifstream Infile;
	Infile.open(Filename, std::ios::in);
	if (!Infile.is_open())
	{
		std::cout << "�ļ�������\n";
		this->Employee_number = 0; //��ʼ��ְԱ����
		this->FileIsEmpty = true;	//�ļ�Ϊ��
		this->data_Array = nullptr;	//�����ʼ��
		
		
	}
	else
	{
		std::cout << "���ļ��ɹ�\n";
		char ch = '0';
		Infile >> ch;
		if (Infile.eof())
		{
			this->Employee_number = 0; //��ʼ��ְԱ����
			this->FileIsEmpty = true;	//�ļ�Ϊ��
			this->data_Array = nullptr;	//�����ʼ��
			
			
		}
	}

	int num = this->Registered_employee();
	this->Employee_number = num;

	this->data_Array = new Worker * [this->Employee_number];
	Init_Employee();
	
	

	Infile.close();

	return ;
}

//��������
Information_management::~Information_management()		
{
	if (this->data_Array != nullptr)
		delete[] this->data_Array;
}

//�˵�
void Information_management::Show_Menu()				
{
	using namespace std;
	cout << "********************************************\n";
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********\n"  ;
	cout << "*************  0.�˳��������  *************\n" ;
	cout << "*************  1.����ְ����Ϣ  *************\n" ; 
	cout << "*************  2.��ʾְ����Ϣ  *************\n" ;
	cout << "*************  3.ɾ����ְְ��  *************\n" ;
	cout << "*************  4.�޸�ְ����Ϣ  *************\n" ;
	cout << "*************  5.����ְ����Ϣ  *************\n" ;
	cout << "*************  6.���ձ������  *************\n" ;
	cout << "*************  7.��������ĵ�  *************\n" ;
	cout << "********************************************\n";
	cout << endl;
}

//�˳�ϵͳ
void Information_management::ExitSystem()
{
	std::cout << "��ӭ�´�ʹ��" << std::endl;
}

//���ְԱ��Ϣ
void Information_management::Add_employee()
{
	using namespace std;
	cout << "��������Ա��������\n";

	int Add_num = 0;  cin >> Add_num;

	if (Add_num > 0)
	{
		int New_size = this->Employee_number + Add_num;

		Worker** newspace = new Worker * [New_size];	//��̬��������

		if (this->data_Array != NULL)	//ԭ������ְ��
		{
			for (int i = 0; i < this->Employee_number; ++i)		//�ռ�ת��
				newspace[i] = this->data_Array[i];
		}


		//������ְԱ��Ϣ
		for (int i = 0; i < Add_num; ++i)
		{
			int id = 0;
			string name;
			int choice = 0;
			cout << "������� " << i + 1 << " ����ְ����ţ�";
			cin >> id; cout << '\n';

			cout << "������� " << i + 1 << " ����ְ��������";
			cin>>name; cout << '\n';

			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> choice;

			Worker* worker = nullptr;

			switch (choice)
			{
			case 1: //��ͨԱ��
				worker = new Common_Employee(id, name, 1);
				break;
			case 2: //����
				worker = new Manager(id, name, 2);
				break;
			case 3:  //�ϰ�
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			newspace[this->Employee_number + i] = worker;
		}

		//���ԭ������Ϣ
		delete[] this->data_Array;

		//������Ϣ�����¹���
		this->data_Array = newspace;

		//����ְ��������
		this->Employee_number = New_size;

		//�����ļ��ձ�־
		this->FileIsEmpty = false;
		cout << "�ɹ����" << Add_num << "����ְ����" << endl;
		//������Ϣ
		this->save();
	}

	else
		cout << "�������ݲ��Ϸ�" << endl;

	system("pause");
	system("cls");
}

//ɾ��ְ��
void Information_management::Del_employee()
{
	if (this->FileIsEmpty)
	{
		std::cout << "�ļ������ڻ��߼�¼�գ�\n";
	}
	else
	{
		std::cout << "��������Ҫɾ����ְ���ı��\n";
		int id = 0;
		std::cin >> id;

		int index = this->IsExit_employee(id);	//����õ����������±�
		
		if (index == -1)
		{
			std::cout << "û�и�Ա����Ϣ\n";
		}
		else
		{
			for (int i = index; i < this->Employee_number - 1; ++i)
			{
				this->data_Array[i] = this->data_Array[i + 1];	//����ǰ��
			}

			this->Employee_number--;	//�ǵü�һ����
			this->save();				//���±���һ��
			std::cout << "ɾ���ɹ�\n";
		}
	}

	system("pause");
	system("cls");
}

//�޸�ְ��
void Information_management::Modify_employee_information()
{
	if (this->FileIsEmpty)
	{
		std::cout << "�ļ������ڻ��¼Ϊ�գ�\n";
	}
	else
	{
		std::cout << "�������޸�ְ����ţ�\n";
		int id = 0;
		std::cin >> id;

		int index = this->IsExit_employee(id);

		if (index != -1)
		{
			using namespace std;
			//ɾ����λ�õ�
			delete this->data_Array[index];
			int NewID = 0;
			std::string Newname;
			int Dchoice = 0;		//����ѡ�� Departion

			cout << "�鵽�� " << id << "��ְ������������ְ���ţ� \n";
			cin >> NewID;

			cout << "�������������� \n";
			cin >> Newname;

			cout << "�������λ�� \n";
			cout << "1����ְͨ��\n";
			cout << "2������\n";
			cout << "3���ϰ�\n";
			cin >> Dchoice;

			Worker* worker = nullptr;	//����һ������ָ��
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

			//�������ݴ��ȥ
			this->data_Array[index] = worker;
			cout << "�޸ĳɹ�\n";

			this->save();

		}
		else
		{
			std::cout << "�޸�ʧ�ܣ����޴���\n";
		}
	}

	system("pause");
	system("cls");
}

//����ְ��
void Information_management::Find_employee()
{
	using namespace std;
	if (this->FileIsEmpty)
	{
		std::cout << "�ļ������ڻ��¼Ϊ�գ�\n";
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2������������" << endl;


		int Choice = 0;			cin >> Choice;

		if (Choice == 1)
		{
			int id = 0;
			cout << "����ְ�����:\n";
			cin >> id;

			int ret = IsExit_employee(id);

			if (ret != -1)
			{
				cout << "���ҳɹ�,ְ����Ϣ����: \n";
				this->data_Array[ret]->Show_personal_Information();
			}
			else
			{
				cout << "���޴���\n";
			}

		}
		else if (Choice == 2)
		{
			string name;
			cout << "�����������:\n";
			cin >> name;

			bool flag = false;//���ҵ��ı�־
			for (int i = 0; i < Employee_number; ++i)
			{
				if (data_Array[i]->Name == name)
				{
					cout << "���ҳɹ�,ְ�����Ϊ:"
						<< data_Array[i]->Worker_ID
						<< "�ŵ���Ϣ����\n";

					flag = true;		//���ҳɹ���־����Ϊtrue

					this->data_Array[i]->Show_personal_Information();
				}
			}

			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴���\n";
			}
		}
		else
		{
			cout << "����ѡ������\n";
		}
	}
	system("pause");
	system("cls");

}

//����ְ��
void Information_management::Sort_Employee()
{
	if (this->FileIsEmpty)
	{
		std::cout << "�ļ������ڻ��¼Ϊ�գ�\n";
		system("pause");
		system("cls");
	}
	else
	{
		std::cout << "��ѡ������ʽ�� \n";
		std::cout << "1����ְ���Ž�������\n";
		std::cout << "2����ְ���Ž��н���\n";

		int select = 0; std::cin >> select;
		
		for (int i = 0; i < Employee_number; ++i)
		{
			int index = i;
			for (int j = i + 1; j < Employee_number; ++j)
			{
				if (select == 1)
				{
					if (data_Array[index]->Worker_ID > data_Array[j]->Worker_ID)//ǰ����ں���
					{
						index = j;
					}
				}
				else
				{
					if (data_Array[index]->Worker_ID < data_Array[j]->Worker_ID)//�������ǰ��
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
		std::cout << "����ɹ�,�������Ϊ��\n";
		this->save();
		this->Display_Employee_imformation();
	}
}

//����ļ�
void Information_management::Clean_File()
{
	std::cout << "ȷ����գ�\n";
	std::cout << "1��ȷ��\n";
	std::cout << "2������\n";

	int Choice = 0; std::cin >> Choice;

	if (Choice == 1)
	{
		std::ofstream outFile;
		outFile.open(Filename, std::ios::trunc);	//�ļ����ھ�ɾ�����´���
		outFile.close();

		if (this->data_Array != NULL)	//����ǿ�
		{
			//��ÿ�������ڵĶ���ָ�붼���ͷŵ�
			for (int i = 0; i < this->Employee_number; i++)	
			{
				if (this->data_Array[i] != NULL)
				{
					delete this->data_Array[i];
				}
			}
			//��ʼ��
			this->Employee_number = 0;	
			delete[] this->data_Array;
			this->data_Array = NULL;
			this->FileIsEmpty = true;
			
		}
		std::cout << "��ճɹ���" << std::endl;

	}
	system("pause");
	system("cls");
}

//Ѱ��ְ���Ƿ����
int Information_management::IsExit_employee(int id)
{
	int index = -1;		//��¼ְ��λ��
	for (int i = 0; i < this->Employee_number; ++i)		//����λ��
	{
		if (this->data_Array[i]->Worker_ID == id)
		{
			index = i;
			break;
		}
	}

	return index;
}



//�����ļ�
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

//ͳ���ڵ�Ա������
int Information_management::Registered_employee()
{
	std::ifstream Infile;
	Infile.open(Filename, std::ios::in);

	//����������������
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

//��ʼ��ÿ��Ա����Ϣ
void Information_management::Init_Employee()
{
	std::ifstream Infile;
	Infile.open(Filename, std::ios::in);

	//����������������
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

//��ʾԱ����Ϣ
void Information_management::Display_Employee_imformation()
{
	if(this->FileIsEmpty)
		std::cout << "�ļ������ڻ��¼Ϊ�գ�\n";
	else
	{
		for (int i = 0; i < Employee_number; ++i)
		{
			//��̬���ýӿ�
			this->data_Array[i]->Show_personal_Information();
			//����ͨ����Ϣ�������������Worker�����ָ��,��ͨ�������ж����չʾ
			//Ա����Ϣ�Ĵ��麯������ͨ��ƫ�����ҵ���Ӧ��ְԱ�����ࡣ
		}
	}

	system("pause");
 	system("cls");
}