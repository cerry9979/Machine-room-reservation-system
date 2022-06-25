#include "Maininterface.h"


Maininterface::Maininterface(void)//���⺯��
{
	mainwindow();//���ú���
}
Maininterface::~Maininterface(void){}

void Maininterface::mainwindow()
{
	int symbol;
	while (1)
	{
		cout << "---------------------��ӭ��������ԤԼϵͳ----------------------"
			<< endl;
		cout << "\t\t__________________________________________________" << endl;
		cout << "\t\t|                                                |" << endl;
		cout << "\t\t|                   1��ѧ��                      |" << endl;
		cout << "\t\t|                   2����ʦ                      |" << endl;
		cout << "\t\t|                   3������Ա                    |" << endl;
		cout << "\t\t|                   0���˳�                      |" << endl;
		cout << "\t\t|________________________________________________|" << endl;
		cout << endl << "�������������Ĳ���" << endl;
		cin >> symbol;
		if (symbol == 0)//�˳�
		{
			cout << "��ӭ����һ��ʹ�ã�" << endl;
			return;
		}
		else
		{
			switch (symbol)
			{
			case 1://ѧ��
				LoginIn(Student_File, 1);
				break;
			case 2://��ʦ
				LoginIn(Teacher_File, 2);
				break;
			case 3://����Ա
				LoginIn(Admin_File, 3);
				break;
			default:
				cout << "�������������ԣ�" << endl;
				Sleep(1000);
				system("pause");//������˳�
				system("cls");//��ս���
				break;
			}
		}
	}
}


//��¼����  
//FileName	�������ļ���
//Type		�������������

void Maininterface::LoginIn(string FileName, int Type)
{
	//����ָ��	ָ���������
	Basic* person = NULL;

	//���ļ�
	ifstream file;
	file.open(FileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!file.is_open())
	{
		cout << "���ļ������ڡ�" << endl;
		Sleep(1000);
		file.close();
		return;
	}

	//׼�������û���Ϣ
	int ID = 0;
	string name;
	string password;

	//�ж����
	if (Type == 1)//ѧ��
	{
		cout << "���������ѧ�ţ�" << endl;
		cin >> ID;
	}
	else if (Type == 2)//��ʦ
	{
		cout << "��������ı�ţ�" << endl;
		cin >> ID;
	}

	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> password;

	if (Type == 1)//ѧ��
	{
		//ѧ�������֤
		 
		//�ļ��ж�ȡ����Ϣ
		int fileID;
		string fileName;
		string filePassword;
		while (file >> fileID && file >> fileName && file >> filePassword)
		//���ƶ�ȡ
		{
			if (ID == fileID && name == fileName && password == filePassword)
			//�Ƚ���֤
			{
				cout << "ѧ�������֤��½�ɹ���" << endl;
				system("pause");//����������ӽ���
				system("cls");//��ս���
				//����ѧ������
				person = new Student(ID, name, password);

				//ѧ���Ӳ˵�
				StudentWindows(person);

				return;
			}
		}
	}
	else if (Type == 2)//��ʦ
	{
		//��ʦ�����֤
		// 
		//�ļ��ж�ȡ����Ϣ
		int fileID;
		string fileName;
		string filePassword;
		while (file >> fileID && file >> fileName && file >> filePassword)
		//���ƶ�ȡ
		{
			if (ID == fileID && name == fileName && password == filePassword)
			//�Ƚ���֤
			{
				cout << "��ʦ�����֤��½�ɹ���" << endl;
				system("pause");//����������ӽ���
				system("cls");//��ս���
				//������ʦ����
				person = new Teacher(ID, name, password);//���麯��

				//��ʦ�Ӳ˵�
				TeacherWindows(person);

				return;
			}
		}
	}
	else if (Type == 3)//����Ա
	{
		//����Ա�����֤

		//�ļ��ж�ȡ����Ϣ
		string fileName;
		string filePassword;
		while (file >> fileName && file >> filePassword)
		//���ƶ�ȡ
		{
			if (name == fileName && password == filePassword)
			//�Ƚ���֤
			{
				cout << "����Ա�����֤��½�ɹ���" << endl;
				system("pause");//����������ӽ���
				system("cls");//��ս���

				//��������Ա����
				person = new Administrator(name, password);
				
				//����Ա�Ӳ˵�
				AdminWindows(person);

				return;
			}
		}

	}

	//�������
	cout << "��֤��¼ʧ��" << endl;
	cout << "�������������ԣ�" << endl;
	Sleep(2000);
	//system("pause");//������˳�
	system("cls");//��ս���
	//return;
}


//����ָ����ܴ����Ĺ���Ա

//����Ա�Ӳ˵�
void Maininterface::AdminWindows(Basic*& admin)
{
	while (1)
	{
		//�������Ա�˵�
		//����ָ������������ ������ͬ�Ľӿڡ�����̬
		admin->Interface();
		//���ù�ͬ�Ľӿ�Interface

		//�Ѹ����ָ��ת��Ϊ�����ָ��	�����������������еĽӿ� 
		Administrator* person_admin = (Administrator*)admin;

		int symbol = 0;
		cin >> symbol;

		if (symbol == 1)//����˺�
		{
			cout << "����˺ţ�" << endl;
			person_admin->AddAccount();
		}
		else if (symbol == 2)//�鿴�˺�
		{
			cout << "�鿴�˺ţ�" << endl;
			person_admin->CheckAccount();
		}
		else if (symbol == 3)//�鿴������Ϣ
		{
			cout << "�鿴�༶��Ϣ��" << endl;
			person_admin->CheckMachine();
		}
		else if (symbol == 4)//���ԤԼ��¼
		{
			cout << "���ԤԼ��¼��" << endl;
			person_admin->EmptyRecord();
		}
		else if(symbol == 0)//ע����¼
		{
			//����new�ķ�ʽ�����Ķ���
			//��delete�ķ�ʽ���ٵ�
			delete admin;
			cout << "ע���ɹ���" << endl;
			cout << "��ӭ�����ٴ�ʹ�ã�" << endl;
			Sleep(2000);
			//system("pause");//������˳�
			//system("cls");//��ս���
			//return;
		}
		else
		{
			cout << "������Ч�������ԣ�" << endl;
			Sleep(2000);
			system("cls");//��ս���
			//admin->Interface();
		}
	}
}

//ѧ���Ӳ˵�
void Maininterface::StudentWindows(Basic*& student)
{
	while (1)
	{
		//�������Ա�˵�
		//����ָ������������ ������ͬ�Ľӿڡ�����̬
		student->Interface();
		//���ù�ͬ�Ľӿ�Interface

		//�Ѹ����ָ��ת��Ϊ�����ָ��	�����������������еĽӿ� 
		Student* person_student = (Student*)student;

		int symbol = 0;
		cin >> symbol;

		if (symbol == 1)//����ԤԼ
		{
			cout << "����ԤԼ��" << endl;
			person_student->ApplySub();
		}
		else if (symbol == 2)//�鿴ԤԼ
		{
			cout << "�鿴ԤԼ��" << endl;
			person_student->CheckSub();
		}
		else if (symbol == 3)//�鿴����ԤԼ
		{
			cout << "�鿴����ԤԼ��" << endl;
			person_student->CheckAllSSub();
		}
		else if (symbol == 4)//ȡ��ԤԼ
		{
			cout << "ȡ��ԤԼ��" << endl;
			person_student->CancelSub();
		}
		else if (symbol == 0)//ע����¼
		{
			//����new�ķ�ʽ�����Ķ���
			//��delete�ķ�ʽ���ٵ�
			delete student;
			cout << "ע���ɹ���" << endl;
			cout << "��ӭ�����ٴ�ʹ�ã�" << endl;
			Sleep(2000);
			//system("pause");//������˳�
			//system("cls");//��ս���
			//return;
		}
		else
		{
			cout << "������Ч�������ԣ�" << endl;
			Sleep(2000);
			system("cls");//��ս���
			//admin->Interface();
		}
	}
}

//��ʦ�Ӳ˵�
void Maininterface::TeacherWindows(Basic*& teacher)
{
	while (1)
	{
		//�������Ա�˵�
		//����ָ������������ ������ͬ�Ľӿڡ�����̬
		teacher->Interface();
		//���ù�ͬ�Ľӿ�Interface

		//�Ѹ����ָ��ת��Ϊ�����ָ��	�����������������еĽӿ� 
		Teacher* person_teacher = (Teacher*)teacher;

		int symbol = 0;
		cin >> symbol;

		if (symbol == 1)//���ԤԼ
		{
			cout << "����ԤԼ��" << endl;
			person_teacher->CheckTheSub();
		}
		else if (symbol == 2)//�鿴����ԤԼ
		{
			cout << "�鿴ԤԼ��" << endl;
			person_teacher->CheckAllTSub();
		}
		else if (symbol == 0)//ע����¼
		{
			//����new�ķ�ʽ�����Ķ���
			//��delete�ķ�ʽ���ٵ�
			delete teacher;
			cout << "ע���ɹ���" << endl;
			cout << "��ӭ�����ٴ�ʹ�ã�" << endl;
			Sleep(2000);
			//system("pause");//������˳�
			//system("cls");//��ս���
			//return;
		}
		else
		{
			cout << "������Ч�������ԣ�" << endl;
			Sleep(2000);
			system("cls");//��ս���
			//admin->Interface();
		}
	}
}

