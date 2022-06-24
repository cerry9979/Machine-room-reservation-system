#include "Administrator.h"


Administrator::Administrator()
{

}
Administrator::Administrator(string name, string password)
{
	this->name = name;
	this->password = password;

	//初始化容器
	this->initialize_vector();

	//获取机房信息
	void initialize_machine();
}

void Administrator::Interface()
{
	cout << "欢迎管理员：\t" << this->name << "\t登录！" << endl;
	cout << "\t\t__________________________________________________" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                   1：添加账号                  |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                   2：查看账号                  |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                   3：查看机房                  |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                   4：清空预约                  |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|                   0：注销登录                  |" << endl;
	cout << "\t\t|                                                |" << endl;
	cout << "\t\t|________________________________________________|" << endl;
	cout << endl << "请输入您所期望的操作：";

}

//添加账号
void Administrator::AddAccount()
{
	cout << endl << "请输入期望添加的账号类型：" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl << endl;

	string file_name;
	string number;
	ofstream file;

	int symbol = 0;
	cin >> symbol;

	//检测学号是否重复
	string errorID;

	if (symbol == 1)//学生
	{
		file_name = Student_File;
		number = "请输入该学生的学号：";
		errorID = "学号重复，请重新输入！";
	}
	else if (symbol == 2)//老师
	{
		file_name = Teacher_File;
		number = "请输入该老师的教职编号：";
		errorID = "职工号重复，请重新输入！";
	}
	else
	{
		cout << "输入有误，请重新输入！" << endl;
		Sleep(1000);
		system("cls");//清空界面
		AddAccount();//
	}

	//打开文件				写入	追加
	//利用追加的方式写文件
	file.open(file_name, ios::out | ios::app);
	int ID;
	string name;
	string password;
	cout << number << endl;

	while (1)//检查是否重复
	{
		cin >> ID;

		bool repeat = CheckRepeat(ID, symbol);

		if (repeat)//有重复
		{
			cout << errorID << endl;
		}
		else
		{
			break;
		}
	}

	cout << "请输入您的姓名" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> password;

	//文件里输入信息
	file << ID << " " << name << " " << password << endl;
	cout << "添加成功！" << endl;
	Sleep(1000);

	system("cls");//清空界面

	file.close();

	//调用初始化 避免重复输入
	//重新读取数据
	this->initialize_vector();
}

//查看账号
//void Administrator::CheckAccount()

//打印学生信息
//void PrintStudent(Student& s)
//{
//	cout << "学号" << s.ID << "姓名" << s.name << "密码" << s.password << endl;
//}

//打印老师信息
//void PrintTeacher(Teacher& t)
//{
//	cout << "职工号" << t.ID << "姓名" << t.name << "密码" << t.password << endl;
//}
//查看账号
void Administrator::CheckAccount()
{
	cout << "请选择想要查看的内容：" << endl;
	cout << "1、查看所有学生；" << endl;
	cout << "2、查看所有老师；" << endl;

	int symbol = 0;
	cin >> symbol;

	if (symbol == 1)
	{
		cout << "所有的学生信息如下：" << endl;
		//遍历容器
		//for_each(v_S.begin(), v_S.end(), PrintStudent);
		//迭代器  容器内遍历
		for (vector<Student>::iterator it = v_S.begin(); it != v_S.end(); it++)
		{
			cout << "学号" << it->ID << "\t姓名" << it->name << "\t密码" << it->password << endl;
		}

	}
	else if (symbol == 2)
	{
		cout << "所有的老师信息如下：" << endl;
		//遍历容器
		//for_each(v_T.begin(), v_T.end(), PrintTeacher);
		//迭代器  容器内遍历
		for (vector<Teacher>::iterator it = v_T.begin(); it != v_T.end(); it++)
		{
			cout << "职工号" << it->ID << "\t姓名" << it->name << "\t密码" << it->password << endl;
		}
	}
	Sleep(5000);
	system("pause");//任意键退出
	system("cls");//清空界面

}

//查看机房信息
void Administrator::CheckMachine()
{
	cout << "所有的机房信息如下：" << endl;
	//迭代器  容器内遍历
	for (vector<Machine>::iterator it = v_M.begin(); it != v_M.end(); it++)
	{
		cout << "机房编号：" << it->Machine_ID << "\t机房容量：" << it->Machine_volume << endl;
	}
	Sleep(5000);
	system("pause");//任意键退出
	system("cls");//清空界面
}

//清空预约记录
void Administrator::EmptyRecord()
{
	ofstream file(SubOrder_File, ios::trunc);
	file.close();
	cout << "清空成功！" << endl;
	Sleep(3000);
	system("pause");//任意键退出
	system("cls");//清空界面
}

//容器初始化
void Administrator::initialize_vector()
{

	//读取学生文件中的信息
	ifstream file_S;
	file_S.open(Student_File, ios::in);
	if (!file_S.is_open())
	{
		cout << "文件读取失败" << endl;
		Sleep(1000);
		return;
	}

	//读取老师文件中的信息
	ifstream file_T;
	file_T.open(Teacher_File, ios::in);
	if (!file_T.is_open())
	{
		cout << "文件读取失败" << endl;
		Sleep(1000);
		return;
	}

	//清空容器
	v_S.clear();
	v_T.clear();

	//学生初始化
	Student s;
	while (file_S >> s.ID && file_S >> s.name && file_S >> s.password)
	{
		v_S.push_back(s);
	}
	cout << endl << "\t当前学生数量为：" << v_S.size() << endl;
	file_S.close();

	//老师初始化
	Teacher t;
	while (file_T >> t.ID && file_T >> t.name && file_T >> t.password)
	{
		v_T.push_back(t);
	}
	cout << "\t当前老师数量为：" << v_T.size() << endl;
	file_T.close();
}

//机房信息获取
void Administrator::initialize_machine()
{
	//读取机房文件中的信息
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
	//机房初始化
	Machine m;
	while (file_M >> m.Machine_ID && file_M >> m.Machine_volume)
	{
		v_M.push_back(m);
	}
	cout << "\t当前机房数量为：" << v_M.size() << endl << endl;
	file_M.close();
}

//检测重复
bool Administrator::CheckRepeat(int ID, int Type)
{
	if (Type == 1)
	{
		//迭代器  容器内遍历
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
		//迭代器  容器内遍历
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
