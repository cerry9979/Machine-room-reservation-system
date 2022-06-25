#include "Teacher.h"

Teacher::Teacher()
{

}
Teacher::Teacher(int ID, string name, string password)
{
	//��ʼ���û�����
	this->ID = ID;
	this->name = name;
	this->password = password;

	//��ʼ������
	this->initialize_vector();

}

void Teacher::Interface()
{
	cout << "��ӭ��ʦ��\t" << this->name << "\t��¼��" << endl;
	cout << "\t\t__________________________________________________" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                   1�����ԤԼ                  |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                   2���鿴����ԤԼ              |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                   0��ע����¼                  |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|________________________________________________|" << endl;
	cout << endl << "���������������Ĳ�����";
}

//���ԤԼ
void Teacher::CheckTheSub()
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
	vector<int> v;
	int refer = 0;//���
	for (int i = 0; i < file.resernum; i++)
	{
		if (file.M_SO[i]["state"] == "1")
		{
			v.push_back(i);
			cout << ++refer << ".";
			cout << "ԤԼ���ڣ���" << file.M_SO[i]["date"];
			cout << "ʱ�Σ�" << (file.M_SO[i]["period"] == "1" ? "����" : "����");
			cout << "�༶��" << file.M_SO[i]["machine"];
			string state = "״̬";
			//0��ȡ��ԤԼ	1�������
			//2����ԤԼ		-1��ԤԼʧ��
			if (file.M_SO[i]["state"] == "1")
			{
				state += "�����";
			}
			cout << state << endl;
		}
	}
	cout << "������������˵�ԤԼ��¼" << endl;
	cout << "�������������κ�ԤԼ�밴 0 " << endl;
	int symbol = 0, ret;
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
				cout << "��������˽��" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2���˻�" << endl;
				cin >> ret;

				if (ret == 1)
				{
					file.M_SO[symbol - 1]["state"] = "2";
				}
				else
				{
					file.M_SO[symbol - 1]["state"] = "-1";
				}
				file.updateSubOrder();
				cout << "�����ɣ�" << endl;
				break;
			}
		}
		cout << "������Ч�����������룡" << endl;
	}
	system("pause");//������˳�
	system("cls");//��ս���
}
//�鿴����ԤԼ
void Teacher::CheckAllTSub()
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
		cout << "�༶��" << file.M_SO[i]["machine"];
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


//������ʼ��
void Teacher::initialize_vector()
{

	//��ȡ�༶�ļ��е���Ϣ
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
	//�༶��ʼ��
	Machine m;
	while (file_M >> m.Machine_ID && file_M >> m.Machine_volume)
	{
		v_M.push_back(m);
	}
	file_M.close();

}
