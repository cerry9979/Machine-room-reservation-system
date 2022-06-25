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

    virtual void Interface();   //�Ӳ˵�����

    //������ʼ��
    void initialize_vector();

    //�༶��Ϣ��ȡ
    void initialize_machine();

    vector<Student> v_S;        //ѧ������
    vector<Teacher> v_T;        //��ʦ����
    vector<Machine> v_M;        //�༶����

    //����ظ�
    bool CheckRepeat(int ID, int Type);

    void AddAccount();      //����˺�
    void CheckAccount();    //�鿴�˺�
    void CheckMachine();    //�鿴�༶��Ϣ
    void EmptyRecord();     //���ԤԼ��¼

};

