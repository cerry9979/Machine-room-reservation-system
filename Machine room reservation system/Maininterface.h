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
	//�����˵�
	void mainwindow();
	//��½ʵ��
	void LoginIn(string FileName, int Type);
	//����Ա�Ӳ˵�
	void AdminWindows(Basic*& admin);
	//ѧ���Ӳ˵�
	void StudentWindows(Basic*& student);
	//��ʦ�Ӳ˵�
	void TeacherWindows(Basic*& teacher);


};

