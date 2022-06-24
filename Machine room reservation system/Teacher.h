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

    int ID = 0;                 //教师编号

    void CheckTheSub();         //审核预约
    void CheckAllTSub();        //查看所有预约
};

