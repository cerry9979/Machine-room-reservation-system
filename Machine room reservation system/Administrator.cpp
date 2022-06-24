#include "Administrator.h"


Administrator::Administrator()
{

}
Administrator::Administrator(string name, string password)
{
	this->name = name;
	this->password = password;

	//��ʼ������
	this->initialize_vector();

	//��ȡ������Ϣ
	void initialize_machine();
}

void Administrator::Interface()
{
	cout << "��ӭ����Ա��\t" << this->name << "\t��¼��" << endl;
	cout << "\t\t__________________________________________________" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                   1������˺�                  |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                   2���鿴�˺�                  |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                   3���鿴����                  |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                   4�����ԤԼ                  |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                   0��ע����¼                  |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|________________________________________________|" << endl;
	cout << endl << "���������������Ĳ�����";

}

//����˺�
void Administrator::AddAccount()
{
	cout << endl << "������������ӵ��˺����ͣ�" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl << endl;

	string file_name;
	string number;
	ofstream file;

	int symbol = 0;
	cin >> symbol;

	//���ѧ���Ƿ��ظ�
	string errorID;

	if (symbol == 1)//ѧ��
	{
		file_name = Student_File;
		number = "�������ѧ����ѧ�ţ�";
		errorID = "ѧ���ظ������������룡";
	}
	else if (symbol == 2)//��ʦ
	{
		file_name = Teacher_File;
		number = "���������ʦ�Ľ�ְ��ţ�";
		errorID = "ְ�����ظ������������룡";
	}
	else
	{
		cout << "�����������������룡" << endl;
		Sleep(1000);
		system("cls");//��ս���
		AddAccount();//
	}

	//���ļ�				д��	׷��
	//����׷�ӵķ�ʽд�ļ�
	file.open(file_name, ios::out | ios::app);
	int ID;
	string name;
	string password;
	cout << number << endl;

	while (1)//����Ƿ��ظ�
	{
		cin >> ID;

		bool repeat = CheckRepeat(ID, symbol);

		if (repeat)//���ظ�
		{
			cout << errorID << endl;
		}
		else
		{
			break;
		}
	}

	cout << "��������������" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> password;

	//�ļ���������Ϣ
	file << ID << " " << name << " " << password << endl;
	cout << "��ӳɹ���" << endl;
	Sleep(1000);

	system("cls");//��ս���

	file.close();

	//���ó�ʼ�� �����ظ�����
	//���¶�ȡ����
	this->initialize_vector();
}

//�鿴�˺�
//void Administrator::CheckAccount()

//��ӡѧ����Ϣ
//void PrintStudent(Student& s)
//{
//	cout << "ѧ��" << s.ID << "����" << s.name << "����" << s.password << endl;
//}

//��ӡ��ʦ��Ϣ
//void PrintTeacher(Teacher& t)
//{
//	cout << "ְ����" << t.ID << "����" << t.name << "����" << t.password << endl;
//}
//�鿴�˺�
void Administrator::CheckAccount()
{
	cout << "��ѡ����Ҫ�鿴�����ݣ�" << endl;
	cout << "1���鿴����ѧ����" << endl;
	cout << "2���鿴������ʦ��" << endl;

	int symbol = 0;
	cin >> symbol;

	if (symbol == 1)
	{
		cout << "���е�ѧ����Ϣ���£�" << endl;
		//��������
		//for_each(v_S.begin(), v_S.end(), PrintStudent);
		//������  �����ڱ���
		for (vector<Student>::iterator it = v_S.begin(); it != v_S.end(); it++)
		{
			cout << "ѧ��" << it->ID << "\t����" << it->name << "\t����" << it->password << endl;
		}

	}
	else if (symbol == 2)
	{
		cout << "���е���ʦ��Ϣ���£�" << endl;
		//��������
		//for_each(v_T.begin(), v_T.end(), PrintTeacher);
		//������  �����ڱ���
		for (vector<Teacher>::iterator it = v_T.begin(); it != v_T.end(); it++)
		{
			cout << "ְ����" << it->ID << "\t����" << it->name << "\t����" << it->password << endl;
		}
	}
	Sleep(5000);
	system("pause");//������˳�
	system("cls");//��ս���

}

//�鿴������Ϣ
void Administrator::CheckMachine()
{
	cout << "���еĻ�����Ϣ���£�" << endl;
	//������  �����ڱ���
	for (vector<Machine>::iterator it = v_M.begin(); it != v_M.end(); it++)
	{
		cout << "������ţ�" << it->Machine_ID << "\t����������" << it->Machine_volume << endl;
	}
	Sleep(5000);
	system("pause");//������˳�
	system("cls");//��ս���
}

//���ԤԼ��¼
void Administrator::EmptyRecord()
{
	ofstream file(SubOrder_File, ios::trunc);
	file.close();
	cout << "��ճɹ���" << endl;
	Sleep(3000);
	system("pause");//������˳�
	system("cls");//��ս���
}

//������ʼ��
void Administrator::initialize_vector()
{

	//��ȡѧ���ļ��е���Ϣ
	ifstream file_S;
	file_S.open(Student_File, ios::in);
	if (!file_S.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		Sleep(1000);
		return;
	}

	//��ȡ��ʦ�ļ��е���Ϣ
	ifstream file_T;
	file_T.open(Teacher_File, ios::in);
	if (!file_T.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		Sleep(1000);
		return;
	}

	//�������
	v_S.clear();
	v_T.clear();

	//ѧ����ʼ��
	Student s;
	while (file_S >> s.ID && file_S >> s.name && file_S >> s.password)
	{
		v_S.push_back(s);
	}
	cout << endl << "\t��ǰѧ������Ϊ��" << v_S.size() << endl;
	file_S.close();

	//��ʦ��ʼ��
	Teacher t;
	while (file_T >> t.ID && file_T >> t.name && file_T >> t.password)
	{
		v_T.push_back(t);
	}
	cout << "\t��ǰ��ʦ����Ϊ��" << v_T.size() << endl;
	file_T.close();
}

//������Ϣ��ȡ
void Administrator::initialize_machine()
{
	//��ȡ�����ļ��е���Ϣ
	ifstream file_M;
	file_M.open(Machine_File, ios::in);
	if (!file_M.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		Sleep(1000);
		return;
	}
	//�������
	v_M.clear();
	//������ʼ��
	Machine m;
	while (file_M >> m.Machine_ID && file_M >> m.Machine_volume)
	{
		v_M.push_back(m);
	}
	cout << "\t��ǰ��������Ϊ��" << v_M.size() << endl << endl;
	file_M.close();
}

//����ظ�
bool Administrator::CheckRepeat(int ID, int Type)
{
	if (Type == 1)
	{
		//������  �����ڱ���
		for (vector<Student>::iterator it = v_S.begin(); it != v_S.end(); it++)
		{
			if (ID == it->ID)
			{
				return true;
			}
		}
	}
	else if (Type == 2)
	{
		//������  �����ڱ���
		for (vector<Teacher>::iterator it = v_T.begin(); it != v_T.end(); it++)
		{
			if (ID == it->ID)
			{
				return true;
			}
		}
	}
	return false;
}
