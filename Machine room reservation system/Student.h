#pragma once
#include "Basic.h"
#include "common.h"
#include "Machine.h"
#include "SubOrder.h"

//学生类
class Student :public Basic
{
public:
    Student();
    Student(int ID, string name, string password);

    int ID = 0;                 //学生学号
    vector<Machine> v_M;        //机房容器

    virtual void Interface();   //子菜单界面

    //机房信息获取
    void initialize_machine();


    void ApplySub();        //申请预约
    void CheckSub();        //查看预约
    void CheckAllSSub();    //查看所有预约
    void CancelSub();       //取消预约
};

