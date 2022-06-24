#pragma once
#include "Basic.h"
#include "common.h"
#include "Machine.h"
#include "SubOrder.h"

//ѧ����
class Student :public Basic
{
public:
    Student();
    Student(int ID, string name, string password);

    int ID = 0;                 //ѧ��ѧ��
    vector<Machine> v_M;        //��������

    virtual void Interface();   //�Ӳ˵�����

    //������Ϣ��ȡ
    void initialize_machine();


    void ApplySub();        //����ԤԼ
    void CheckSub();        //�鿴ԤԼ
    void CheckAllSSub();    //�鿴����ԤԼ
    void CancelSub();       //ȡ��ԤԼ
};

