#pragma once
#include "Basic.h"
#include "Student.h"
#include "Teacher.h"
#include "Machine.h"
#include "common.h"
#include <vector>


class Administrator:public Basic
{
public:
    Administrator();
    Administrator(string name, string password);
    ~Administrator(){}

    virtual void Interface();   //子菜单界面

    //容器初始化
    void initialize_vector();

    //班级信息获取
    void initialize_machine();

    vector<Student> v_S;        //学生容器
    vector<Teacher> v_T;        //老师容器
    vector<Machine> v_M;        //班级容器

    //检测重复
    bool CheckRepeat(int ID, int Type);

    void AddAccount();      //添加账号
    void CheckAccount();    //查看账号
    void CheckMachine();    //查看班级信息
    void EmptyRecord();     //清空预约记录

};

