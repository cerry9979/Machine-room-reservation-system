#include "Teacher.h"

Teacher::Teacher()
{

}
Teacher::Teacher(int ID, string name, string password)
{
	//初始化用户属性
	this->ID = ID;
	this->name = name;
	this->password = password;

	//初始化容器
	this->initialize_vector();

}

void Teacher::Interface()
{
	cout << "欢迎教师：\t" << this->name << "\t登录！" << endl;
	cout << "\t\t__________________________________________________" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                   1：审核预约                  |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                   2：查看所有预约              |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                   0：注销登录                  |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|________________________________________________|" << endl;
	cout << endl << "请输入您所期望的操作：";
}

//审核预约
void Teacher::CheckTheSub()
{
	SubOrder file;
	if (file.resernum == 0)
	{
		cout << "无预约记录" << endl;
		Sleep(5000);
		system("pause");//任意键退出
		system("cls");//清空界面
		return;
	}
	vector<int> v;
	int refer = 0;//编号
	for (int i = 0; i < file.resernum; i++)
	{
		if (file.M_SO[i]["state"] == "1")
		{
			v.push_back(i);
			cout << ++refer << ".";
			cout << "预约日期：周" << file.M_SO[i]["date"];
			cout << "时段：" << (file.M_SO[i]["period"] == "1" ? "上午" : "下午");
			cout << "班级：" << file.M_SO[i]["machine"];
			string state = "状态";
			//0—取消预约	1—审核中
			//2—已预约		-1—预约失败
			if (file.M_SO[i]["state"] == "1")
			{
				state += "审核中";
			}
			cout << state << endl;
		}
	}
	cout << "请输入您想审核的预约记录" << endl;
	cout << "如果您不想审核任何预约请按 0 " << endl;
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
				cout << "请输入审核结果" << endl;
				cout << "1、通过" << endl;
				cout << "2、退回" << endl;
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
				cout << "审核完成！" << endl;
				break;
			}
		}
		cout << "输入无效，请重新输入！" << endl;
	}
	system("pause");//任意键退出
	system("cls");//清空界面
}
//查看所有预约
void Teacher::CheckAllTSub()
{
	SubOrder file;
	if (file.resernum == 0)
	{
		cout << "无预约记录" << endl;
		Sleep(5000);
		system("pause");//任意键退出
		system("cls");//清空界面
		return;
	}
	cout << "所有的预约信息如下：" << endl;
	for (int i = 0; i < file.resernum; i++)
	{
		cout << i + 1 << "、";
		cout << "预约日期：周" << file.M_SO[i]["date"];
		cout << "时段：" << (file.M_SO[i]["period"] == "1" ? "上午" : "下午");
		cout << "学号：" << (file.M_SO[i]["ID"]);
		cout << "姓名：" << (file.M_SO[i]["name"]);
		cout << "班级：" << file.M_SO[i]["machine"];
		string state = "状态";
		//0—取消预约	1—审核中
		//2—已预约		-1—预约失败
		if (file.M_SO[i]["state"] == "1")
		{
			state += "审核中";
		}
		else if (file.M_SO[i]["state"] == "2")
		{
			state += "预约成功";
		}
		else if (file.M_SO[i]["state"] == "-1")
		{
			state += "未通过审核，预约失败";
		}
		else
		{
			state += "已取消预约";
		}
		cout << state << endl;

	}
	Sleep(5000);
	system("pause");//任意键退出
	system("cls");//清空界面

}


//容器初始化
void Teacher::initialize_vector()
{

	//读取班级文件中的信息
	ifstream file_M;
	file_M.open(Machine_File, ios::in);
	if (!file_M.is_open())
	{
		cout << "文件读取失败" << endl;
		Sleep(1000);
		return;
	}
	//清空容器
	v_M.clear();
	//班级初始化
	Machine m;
	while (file_M >> m.Machine_ID && file_M >> m.Machine_volume)
	{
		v_M.push_back(m);
	}
	file_M.close();

}
