#pragma once
#include "common.h"
#include "Student.h"
#include "Teacher.h"
#include "Administrator.h"
#include "SubOrder.h"
#include "Basic.h"

class Maininterface
{
public:
	Maininterface(void);
	~Maininterface(void);
	//外界面菜单
	void mainwindow();
	//登陆实现
	void LoginIn(string FileName, int Type);
	//管理员子菜单
	void AdminWindows(Basic*& admin);
	//学生子菜单
	void StudentWindows(Basic*& student);
	//教师子菜单
	void TeacherWindows(Basic*& teacher);


};

