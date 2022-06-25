#include "Student.h"


Student::Student()
{

}
Student::Student(int ID, string name, string password)
{
	//初始化用户属性
	this->ID = ID;
	this->name = name;
	this->password = password;

	//初始化容器
	this->initialize_vector();

}

void Student::Interface()
{
	cout << "欢迎学员：\t" << this->name << "\t登录！" << endl;
	cout << "\t\t__________________________________________________" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                   1：申请预约                  |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                   2：查看预约                  |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                   3：查看所有预约              |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                   4：取消预约                  |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                   0：注销登录                  |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|________________________________________________|" << endl;
	cout << endl << "请输入您所期望的操作：";
}

//申请预约
void Student::ApplySub()
{
	cout << "课程开放时间为周一至周五！：" << endl;
	cout << "请输入您想预约的时间：" << endl;
	cout << "1、周一：" << endl;
	cout << "2、周二：" << endl;
	cout << "3、周三：" << endl;
	cout << "4、周四：" << endl;
	cout << "5、周五：" << endl;
	int date = 0, period = 0, machine = 0;
	while (1)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "输入无效，请重新输入！" << endl;
	}
	cout << "请输入您想预约的时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;

	while (1)
	{
		cin >> period;
		if (period >= 1 && period <= 2)
		{
			break;
		}
		cout << "输入无效，请重新输入！" << endl;
	}

	cout << "请输入您想预约的课程班：" << endl;
	//cout << "1、班级1" << v_M[0].Machine_ID << "\t机房容量：" << v_M[0].Machine_volume << endl;
	//cout << "2、班级2" << v_M[1].Machine_ID << "\t机房容量：" << v_M[1].Machine_volume << endl;
	cout << "1号班级容量：" << v_M[0].Machine_volume << endl;
	cout << "2号班级容量：" << v_M[1].Machine_volume << endl;

	while (1)
	{
		cin >> machine;
		if (machine >= 1 && machine <= 2)
		{
			break;
		}
		cout << "输入无效，请重新输入！" << endl;
	}

	cout << "预约成功！预约信息处理中..." << endl;
	cout << "请等待教师审核！" << endl;

	//存入预约
	ofstream file(SubOrder_File, ios::app);
	file << "时间:" << date << " ";
	file << "时间段:" << period << " ";
	file << "学生学号:" << this->ID << " ";
	file << "学生姓名:" << this->name << " ";//区分姓名；
	file << "选择班级:" << machine << " ";
	file << "审核状态:" << 1 << endl << " " << endl;//预约状态！！
	file.close();

	Sleep(5000);
	system("pause");//任意键退出
	system("cls");//清空界面
}
//查看预约
void Student::CheckSub()
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
	cout << "您的预约信息如下：" << endl;
	for (int i = 0; i < file.resernum; i++)
	{
		if (atoi(file.M_SO[i]["ID"].c_str()) == this->ID)
		{
			cout << "预约日期：周" << file.M_SO[i]["date"];
			cout << "时段：" << (file.M_SO[i]["period"] == "1"?"上午":"下午");
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
	}
	Sleep(5000);
	system("pause");//任意键退出
	system("cls");//清空界面
}
//查看所有预约
void Student::CheckAllSSub()
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
//取消预约
void Student::CancelSub()
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
	cout << "注：只有预约成功或审核中的预约记录可以取消" << endl << endl;
	vector<int> v;
	int refer = 0;//编号
	for (int i = 0; i < file.resernum; i++)
	{
		//下标效率过低
		if (atoi(file.M_SO[i]["ID"].c_str()) == this->ID)
		{
			if (file.M_SO[i]["state"] == "1" || file.M_SO[i]["state"] == "2")
			{
				v.push_back(i);
				cout << refer++ << ".";
				cout << "预约日期：周" << file.M_SO[i]["date"];
				cout << "时段：" << (file.M_SO[i]["period"] == "1" ? "上午" : "下午");
				cout << "班级：" << file.M_SO[i]["machine"];
				string state = "状态：";
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
				cout << state << endl;
			}
		}
	}
	cout << "请输入您想取消的预约记录" << endl;
	cout << "如果您不想取消任何预约请按 0 " << endl;
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
				//cout<<"记录所在位置"<<v[symbol - 1]<<endl;
				file.M_SO[symbol - 1]["state"] = "0";
				file.updateSubOrder();
				cout << "取消预约成功" << endl;
				break;
			}
		}
		cout << "输入无效，请重新输入！" << endl;
	}
	system("pause");//任意键退出
	system("cls");//清空界面
}

//班级信息获取
//void Student::initialize_machine()
//{
//	//读取班级文件中的信息
//	ifstream file_M;
//	file_M.open(Machine_File, ios::in);
//	//if (!file_M.is_open())
//	//{
//	//	cout << "文件读取失败" << endl;
//	//	Sleep(1000);
//	//	return;
//	//}
//	////清空容器
//	//v_M.clear();
//	////班级初始化
//	Machine m;
//	while (file_M >> m.Machine_ID && file_M >> m.Machine_volume)
//	{
//		v_M.push_back(m);
//	}
//	//cout << "\t当前班级数量为：" << v_M.size() << endl << endl;
//	file_M.close();
//}

//容器初始化
void Student::initialize_vector()
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
