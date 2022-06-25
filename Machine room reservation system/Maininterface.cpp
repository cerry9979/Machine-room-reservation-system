#include "Maininterface.h"


Maininterface::Maininterface(void)//类外函数
{
	mainwindow();//调用函数
}
Maininterface::~Maininterface(void){}

void Maininterface::mainwindow()
{
	int symbol;
	while (1)
	{
		cout << "---------------------欢迎来到机房预约系统----------------------"
			<< endl;
		cout << "\t\t__________________________________________________" << endl;
		cout << "\t\t|                                                |" << endl;
		cout << "\t\t|                   1：学生                      |" << endl;
		cout << "\t\t|                   2：老师                      |" << endl;
		cout << "\t\t|                   3：管理员                    |" << endl;
		cout << "\t\t|                   0：退出                      |" << endl;
		cout << "\t\t|________________________________________________|" << endl;
		cout << endl << "请输入您期望的操作" << endl;
		cin >> symbol;
		if (symbol == 0)//退出
		{
			cout << "欢迎您下一次使用！" << endl;
			return;
		}
		else
		{
			switch (symbol)
			{
			case 1://学生
				LoginIn(Student_File, 1);
				break;
			case 2://老师
				LoginIn(Teacher_File, 2);
				break;
			case 3://管理员
				LoginIn(Admin_File, 3);
				break;
			default:
				cout << "输入有误，请重试！" << endl;
				Sleep(1000);
				system("pause");//任意键退出
				system("cls");//清空界面
				break;
			}
		}
	}
}


//登录功能  
//FileName	操作的文件名
//Type		操作者身份类型

void Maininterface::LoginIn(string FileName, int Type)
{
	//父类指针	指向子类对象
	Basic* person = NULL;

	//读文件
	ifstream file;
	file.open(FileName, ios::in);

	//判断文件是否存在
	if (!file.is_open())
	{
		cout << "该文件不存在。" << endl;
		Sleep(1000);
		file.close();
		return;
	}

	//准备接受用户信息
	int ID = 0;
	string name;
	string password;

	//判断身份
	if (Type == 1)//学生
	{
		cout << "请输入你的学号：" << endl;
		cin >> ID;
	}
	else if (Type == 2)//老师
	{
		cout << "请输入你的编号：" << endl;
		cin >> ID;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> password;

	if (Type == 1)//学生
	{
		//学生身份验证
		 
		//文件中读取的信息
		int fileID;
		string fileName;
		string filePassword;
		while (file >> fileID && file >> fileName && file >> filePassword)
		//右移读取
		{
			if (ID == fileID && name == fileName && password == filePassword)
			//比较验证
			{
				cout << "学生身份验证登陆成功！" << endl;
				system("pause");//任意键进入子界面
				system("cls");//清空界面
				//创建学生对象
				person = new Student(ID, name, password);

				//学生子菜单
				StudentWindows(person);

				return;
			}
		}
	}
	else if (Type == 2)//老师
	{
		//老师身份验证
		// 
		//文件中读取的信息
		int fileID;
		string fileName;
		string filePassword;
		while (file >> fileID && file >> fileName && file >> filePassword)
		//右移读取
		{
			if (ID == fileID && name == fileName && password == filePassword)
			//比较验证
			{
				cout << "老师身份验证登陆成功！" << endl;
				system("pause");//任意键进入子界面
				system("cls");//清空界面
				//创建老师对象
				person = new Teacher(ID, name, password);//纯虚函数

				//老师子菜单
				TeacherWindows(person);

				return;
			}
		}
	}
	else if (Type == 3)//管理员
	{
		//管理员身份验证

		//文件中读取的信息
		string fileName;
		string filePassword;
		while (file >> fileName && file >> filePassword)
		//右移读取
		{
			if (name == fileName && password == filePassword)
			//比较验证
			{
				cout << "管理员身份验证登陆成功！" << endl;
				system("pause");//任意键进入子界面
				system("cls");//清空界面

				//创建管理员对象
				person = new Administrator(name, password);
				
				//管理员子菜单
				AdminWindows(person);

				return;
			}
		}

	}

	//其他情况
	cout << "验证登录失败" << endl;
	cout << "输入有误，请重试！" << endl;
	Sleep(2000);
	//system("pause");//任意键退出
	system("cls");//清空界面
	//return;
}


//父类指针接受创建的管理员

//管理员子菜单
void Maininterface::AdminWindows(Basic*& admin)
{
	while (1)
	{
		//进入管理员菜单
		//父类指针调用子类对象 创建共同的接口——多态
		admin->Interface();
		//调用共同的接口Interface

		//把父类的指针转化为子类的指针	调用子类中其他特有的接口 
		Administrator* person_admin = (Administrator*)admin;

		int symbol = 0;
		cin >> symbol;

		if (symbol == 1)//添加账号
		{
			cout << "添加账号：" << endl;
			person_admin->AddAccount();
		}
		else if (symbol == 2)//查看账号
		{
			cout << "查看账号：" << endl;
			person_admin->CheckAccount();
		}
		else if (symbol == 3)//查看机房信息
		{
			cout << "查看班级信息：" << endl;
			person_admin->CheckMachine();
		}
		else if (symbol == 4)//清空预约记录
		{
			cout << "清空预约记录：" << endl;
			person_admin->EmptyRecord();
		}
		else if(symbol == 0)//注销登录
		{
			//利用new的方式创建的堆区
			//用delete的方式销毁掉
			delete admin;
			cout << "注销成功！" << endl;
			cout << "欢迎您的再次使用！" << endl;
			Sleep(2000);
			//system("pause");//任意键退出
			//system("cls");//清空界面
			//return;
		}
		else
		{
			cout << "输入无效，请重试！" << endl;
			Sleep(2000);
			system("cls");//清空界面
			//admin->Interface();
		}
	}
}

//学生子菜单
void Maininterface::StudentWindows(Basic*& student)
{
	while (1)
	{
		//进入管理员菜单
		//父类指针调用子类对象 创建共同的接口——多态
		student->Interface();
		//调用共同的接口Interface

		//把父类的指针转化为子类的指针	调用子类中其他特有的接口 
		Student* person_student = (Student*)student;

		int symbol = 0;
		cin >> symbol;

		if (symbol == 1)//申请预约
		{
			cout << "申请预约：" << endl;
			person_student->ApplySub();
		}
		else if (symbol == 2)//查看预约
		{
			cout << "查看预约：" << endl;
			person_student->CheckSub();
		}
		else if (symbol == 3)//查看所有预约
		{
			cout << "查看所有预约：" << endl;
			person_student->CheckAllSSub();
		}
		else if (symbol == 4)//取消预约
		{
			cout << "取消预约：" << endl;
			person_student->CancelSub();
		}
		else if (symbol == 0)//注销登录
		{
			//利用new的方式创建的堆区
			//用delete的方式销毁掉
			delete student;
			cout << "注销成功！" << endl;
			cout << "欢迎您的再次使用！" << endl;
			Sleep(2000);
			//system("pause");//任意键退出
			//system("cls");//清空界面
			//return;
		}
		else
		{
			cout << "输入无效，请重试！" << endl;
			Sleep(2000);
			system("cls");//清空界面
			//admin->Interface();
		}
	}
}

//教师子菜单
void Maininterface::TeacherWindows(Basic*& teacher)
{
	while (1)
	{
		//进入管理员菜单
		//父类指针调用子类对象 创建共同的接口——多态
		teacher->Interface();
		//调用共同的接口Interface

		//把父类的指针转化为子类的指针	调用子类中其他特有的接口 
		Teacher* person_teacher = (Teacher*)teacher;

		int symbol = 0;
		cin >> symbol;

		if (symbol == 1)//审核预约
		{
			cout << "申请预约：" << endl;
			person_teacher->CheckTheSub();
		}
		else if (symbol == 2)//查看所有预约
		{
			cout << "查看预约：" << endl;
			person_teacher->CheckAllTSub();
		}
		else if (symbol == 0)//注销登录
		{
			//利用new的方式创建的堆区
			//用delete的方式销毁掉
			delete teacher;
			cout << "注销成功！" << endl;
			cout << "欢迎您的再次使用！" << endl;
			Sleep(2000);
			//system("pause");//任意键退出
			//system("cls");//清空界面
			//return;
		}
		else
		{
			cout << "输入无效，请重试！" << endl;
			Sleep(2000);
			system("cls");//清空界面
			//admin->Interface();
		}
	}
}

