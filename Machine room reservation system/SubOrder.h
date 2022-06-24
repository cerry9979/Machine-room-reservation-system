#pragma once
#include "common.h"
#include "Basic.h"

class SubOrder//��ȡ��Ϣ�������������
{
public:
	SubOrder()
	{
		ifstream file;
		file.open(SubOrder_File, ios::in);

		//		ʱ�� ʱ���	 ѧ��  ����	 ������� ���״̬
		string date, period, S_ID, S_name, M_num, state;
		
		//ԤԼ��¼����
		this->resernum = 0;

		while (file >> date && file >> period &&
			file >> S_ID && file >> S_name &&
			file >> M_num && file >> state)
		{
			string key, value;
			int pos = 0;
			map<string, string> m;

			//ʱ��
			pos = date.find(":");
			if (pos != -1)
			{
				key = date.substr(0, pos);
				value = date.substr(pos + 1, date.size() - pos);
				m.insert(make_pair(key, value));
			}

			//ʱ���
			pos = period.find(":");
			if (pos != -1)
			{
				key = period.substr(0, pos);
				value = period.substr(pos + 1, period.size() - pos);
				m.insert(make_pair(key, value));
			}

			//ѧ��
			pos = S_ID.find(":");
			if (pos != -1)
			{
				key = S_ID.substr(0, pos);
				value = S_ID.substr(pos + 1, S_ID.size() - pos);
				m.insert(make_pair(key, value));
			}

			//����
			pos = S_name.find(":");
			if (pos != -1)
			{
				key = S_name.substr(0, pos);
				value = S_name.substr(pos + 1, S_name.size() - pos);
				m.insert(make_pair(key, value));
			}

			//�������
			pos = M_num.find(":");
			if (pos != -1)
			{
				key = M_num.substr(0, pos);
				value = M_num.substr(pos + 1, M_num.size() - pos);
				m.insert(make_pair(key, value));
			}

			//���״̬
			pos = state.find(":");
			if (pos != -1)
			{
				key = state.substr(0, pos);
				value = state.substr(pos + 1, state.size() - pos);
				m.insert(make_pair(key, value));
			}

			//ȫ���ɶ���ӵ����������		//��¼����  С������
			this->M_SO.insert(make_pair(this->resernum, m));
			this->resernum++;
		}
		file.close();


	}
	~SubOrder() {};

	//����ԤԼ��¼	//�������״̬
	void updateSubOrder();

	//��¼������
	//����Ƕ����������
	//һ����¼��Ϊһ��С����
	//һ��ΪԤԼ��¼������
	map<int, map<string, string>> M_SO;

	//ԤԼ��¼����
	int resernum;
};

