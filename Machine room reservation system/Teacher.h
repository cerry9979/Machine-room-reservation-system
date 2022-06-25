#pragma once
#include "Basic.h"
#include "common.h"
#include "Machine.h"
#include "SubOrder.h"

class Teacher :public Basic
{
public:
    Teacher();
    Teacher(int ID, string name, string password);

    virtual void Interface();   //子菜单界面
    vector<Machine> v_M;        //班级容器
    map<string, string> m;

    //容器初始化
    void initialize_vector();

    int ID = 0;                 //教师编号

    void CheckTheSub();         //审核预约
    void CheckAllTSub();        //查看所有预约
};

