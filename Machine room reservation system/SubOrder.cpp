#include "SubOrder.h"


void SubOrder::updateSubOrder()
{
	if (this->resernum == 0)
	{
		return;
	}

	//����ȫ������
	ofstream file(SubOrder_File, ios::trunc);
	for (int i = 0; i < resernum; i++)
	{
		file << "ʱ��:" << this->M_SO [i]["date"] << " ";
		file << "ʱ���:" << this->M_SO[i]["period"] << " ";
		file << "ѧ��ѧ��:" << this->M_SO[i]["ID"] << " ";
		file << "ѧ������:" << this->M_SO[i]["name"] << " ";
		file << "ѡ��༶:" << this->M_SO[i]["machine"] << " ";
		file << "���״̬:" << this->M_SO[i]["state"] << " ";
		file.close();
	}
	file.close();

}
