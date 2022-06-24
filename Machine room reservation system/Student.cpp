#include "Student.h"


Student::Student()
{

}
Student::Student(int ID, string name, string password)
{
	//��ʼ���û�����
	this->ID = ID;
	this->name = name;
	this->password = password;
}

void Student::Interface()
{
	cout << "��ӭѧԱ��\t" << this->name << "\t��¼��" << endl;
	cout << "\t\t__________________________________________________" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                   1������ԤԼ                  |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                   2���鿴ԤԼ                  |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                   3���鿴����ԤԼ              |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                   4��ȡ��ԤԼ                  |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                   0��ע����¼                  |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|________________________________________________|" << endl;
	cout << endl << "���������������Ĳ�����";
}

//����ԤԼ
void Student::ApplySub()
{
	cout << "��������ʱ��Ϊ��һ�����壡��" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ��" << endl;
	cout << "2���ܶ���" << endl;
	cout << "3��������" << endl;
	cout << "4�����ģ�" << endl;
	cout << "5�����壺" << endl;
	int date = 0, period = 0, machine = 0;
	while (1)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "������Ч�����������룡" << endl;
	}
	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;

	while (1)
	{
		cin >> period;
		if (period >= 1 && period <= 2)
		{
			break;
		}
		cout << "������Ч�����������룡" << endl;
	}

	cout << "����������ԤԼ�Ļ�����" << endl;
	cout << "1������1" << v_M[0].Machine_ID << "\t����������" << v_M[0].Machine_volume << endl;
	cout << "2������2" << v_M[1].Machine_ID << "\t����������" << v_M[1].Machine_volume << endl;

	while (1)
	{
		cin >> machine;
		if (machine >= 1 && machine <= 2)
		{
			break;
		}
		cout << "������Ч�����������룡" << endl;
	}

	cout << "ԤԼ�ɹ���ԤԼ��Ϣ������..." << endl;
	cout << "��ȴ���ʦ��ˣ�" << endl;

	Sleep(5000);
	system("pause");//������˳�
	system("cls");//��ս���

	//����ԤԼ
	ofstream file(SubOrder_File, ios::app);
	file << "ʱ��:" << date << " ";
	file << "ʱ���:" << period << " ";
	file << "ѧ��ѧ��:" << ID << " ";
	file << "ѧ������:" << this->name << " ";//����������
	file << "ѡ�����:" << machine << " ";
	file << "���״̬:" << 1 << endl << " ";//ԤԼ״̬����
	file.close();

}
//�鿴ԤԼ
void Student::CheckSub()
{
	SubOrder file;
	if (file.resernum == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		Sleep(5000);
		system("pause");//������˳�
		system("cls");//��ս���
		return;
	}
	cout << "����ԤԼ��Ϣ���£�" << endl;
	for (int i = 0; i < file.resernum; i++)
	{
		if (atoi(file.M_SO[i]["ID"].c_str()) == this->ID)
		{
			cout << "ԤԼ���ڣ���" << file.M_SO[i]["date"];
			cout << "ʱ�Σ�" << (file.M_SO[i]["period"] == "1"?"����":"����");
			cout << "������" << file.M_SO[i]["machine"];
			string state = "״̬";
			//0��ȡ��ԤԼ	1�������
			//2����ԤԼ		-1��ԤԼʧ��
			if (file.M_SO[i]["state"] == "1")
			{
				state += "�����";
			}
			else if (file.M_SO[i]["state"] == "2")
			{
				state += "ԤԼ�ɹ�";
			}
			else if (file.M_SO[i]["state"] == "-1")
			{
				state += "δͨ����ˣ�ԤԼʧ��";
			}
			else
			{
				state += "��ȡ��ԤԼ";
			}
			cout << state << endl;
		}
	}
	Sleep(5000);
	system("pause");//������˳�
	system("cls");//��ս���
}
//�鿴����ԤԼ
void Student::CheckAllSSub()
{
	SubOrder file;
	if (file.resernum == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		Sleep(5000);
		system("pause");//������˳�
		system("cls");//��ս���
		return;
	}
	cout << "���е�ԤԼ��Ϣ���£�" << endl;
	for (int i = 0; i < file.resernum; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼ���ڣ���" << file.M_SO[i]["date"];
		cout << "ʱ�Σ�" << (file.M_SO[i]["period"] == "1" ? "����" : "����");
		cout << "ѧ�ţ�" << (file.M_SO[i]["ID"]);
		cout << "������" << (file.M_SO[i]["name"]);
		cout << "������" << file.M_SO[i]["machine"];
		string state = "״̬";
		//0��ȡ��ԤԼ	1�������
		//2����ԤԼ		-1��ԤԼʧ��
		if (file.M_SO[i]["state"] == "1")
		{
			state += "�����";
		}
		else if (file.M_SO[i]["state"] == "2")
		{
			state += "ԤԼ�ɹ�";
		}
		else if (file.M_SO[i]["state"] == "-1")
		{
			state += "δͨ����ˣ�ԤԼʧ��";
		}
		else
		{
			state += "��ȡ��ԤԼ";
		}
		cout << state << endl;
			
	}
	Sleep(5000);
	system("pause");//������˳�
	system("cls");//��ս���
}
//ȡ��ԤԼ
void Student::CancelSub()
{
	SubOrder file;
	if (file.resernum == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		Sleep(5000);
		system("pause");//������˳�
		system("cls");//��ս���
		return;
	}
	cout << "ע��ֻ��ԤԼ�ɹ�������е�ԤԼ��¼����ȡ��" << endl;
	cout << "����������Ҫȡ����ԤԼ��¼" << endl;
	vector<int> v;
	int refer = 0;//���
	for (int i = 0; i < file.resernum; i++)
	{
		//�±�Ч�ʹ���
		if (atoi(file.M_SO[i]["ID"].c_str()) == this->ID)
		{
			if (file.M_SO[i]["state"] == "1" || file.M_SO[i]["state"] == "2")
			{
				v.push_back(i);
				cout << refer++ << ".";
				cout << "ԤԼ���ڣ���" << file.M_SO[i]["date"];
				cout << "ʱ�Σ�" << (file.M_SO[i]["period"] == "1" ? "����" : "����");
				cout << "������" << file.M_SO[i]["machine"];
				string state = "״̬";
				//0��ȡ��ԤԼ	1�������
				//2����ԤԼ		-1��ԤԼʧ��
				if (file.M_SO[i]["state"] == "1")
				{
					state += "�����";
				}
				else if (file.M_SO[i]["state"] == "2")
				{
					state += "ԤԼ�ɹ�";
				}
				cout << state << endl;
			}
		}
	}
	cout << "����������ȡ����ԤԼ��¼" << endl;
	cout << "���������ȡ���κ�ԤԼ�밴 0 " << endl;
	int symbol = 0;
	while (1)
	{
		cin >> symbol;
		if (symbol >= 0 && symbol <= v.size())
		{
			if (symbol == 0)
			{
				break;
			}
			else
			{
				//cout<<"��¼����λ��"<<v[symbol - 1]<<endl;
				file.M_SO[symbol - 1]["state"] = "0";
				file.updateSubOrder();
				cout << "ȡ��ԤԼ�ɹ�" << endl;
				break;
			}
		}
		cout << "������Ч�����������룡" << endl;
	}
	Sleep(5000); 
	system("pause");//������˳�
	system("cls");//��ս���
}

//������Ϣ��ȡ
void Student::initialize_machine()
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
