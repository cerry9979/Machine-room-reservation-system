#pragma once
#include "common.h"
#include "Basic.h"

class SubOrder//获取信息并存放在容器中
{
public:
	SubOrder()
	{
		ifstream file;
		file.open(SubOrder_File, ios::in);

		//		时间 时间段	 学号  姓名	 机房编号 审核状态
		string date, period, S_ID, S_name, M_num, state;
		
		//预约记录条数
		this->resernum = 0;

		while (file >> date && file >> period &&
			file >> S_ID && file >> S_name &&
			file >> M_num && file >> state)
		{
			string key, value;
			int pos = 0;
			map<string, string> m;

			//时间
			pos = date.find(":");
			if (pos != -1)
			{
				key = date.substr(0, pos);
				value = date.substr(pos + 1, date.size() - pos);
				m.insert(make_pair(key, value));
			}

			//时间段
			pos = period.find(":");
			if (pos != -1)
			{
				key = period.substr(0, pos);
				value = period.substr(pos + 1, period.size() - pos);
				m.insert(make_pair(key, value));
			}

			//学号
			pos = S_ID.find(":");
			if (pos != -1)
			{
				key = S_ID.substr(0, pos);
				value = S_ID.substr(pos + 1, S_ID.size() - pos);
				m.insert(make_pair(key, value));
			}

			//姓名
			pos = S_name.find(":");
			if (pos != -1)
			{
				key = S_name.substr(0, pos);
				value = S_name.substr(pos + 1, S_name.size() - pos);
				m.insert(make_pair(key, value));
			}

			//机房编号
			pos = M_num.find(":");
			if (pos != -1)
			{
				key = M_num.substr(0, pos);
				value = M_num.substr(pos + 1, M_num.size() - pos);
				m.insert(make_pair(key, value));
			}

			//审核状态
			pos = state.find(":");
			if (pos != -1)
			{
				key = state.substr(0, pos);
				value = state.substr(pos + 1, state.size() - pos);
				m.insert(make_pair(key, value));
			}

			//全部成对添加到大的容器里		//记录个数  小的容器
			this->M_SO.insert(make_pair(this->resernum, m));
			this->resernum++;
		}
		file.close();


	}
	~SubOrder() {};

	//更新预约记录	//更新审核状态
	void updateSubOrder();

	//记录的容器
	//容器嵌套容器——
	//一条记录记为一个小容器
	//一记为预约记录的条数
	map<int, map<string, string>> M_SO;

	//预约记录条数
	int resernum;
};

