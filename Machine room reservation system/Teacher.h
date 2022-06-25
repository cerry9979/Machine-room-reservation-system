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

    virtual void Interface();   //�Ӳ˵�����
    vector<Machine> v_M;        //�༶����
    map<string, string> m;

    //������ʼ��
    void initialize_vector();

    int ID = 0;                 //��ʦ���

    void CheckTheSub();         //���ԤԼ
    void CheckAllTSub();        //�鿴����ԤԼ
};

