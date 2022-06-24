#pragma once
#include "common.h"

//身份抽象类
//保存着老师学生人员的共性基本信息

class Basic
{
public:

	//子类操作菜单 纯虚函数
	virtual void Interface() = 0;

	string name;//用户名
	string password;//密码
};