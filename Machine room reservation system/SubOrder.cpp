#include "SubOrder.h"


void SubOrder::updateSubOrder()
{
	if (this->resernum == 0)
	{
		return;
	}

	//更新全部数据
	ofstream file(SubOrder_File, ios::trunc);
	for (int i = 0; i < resernum; i++)
	{
		file << "时间:" << this->M_SO [i]["date"] << " ";
		file << "时间段:" << this->M_SO[i]["period"] << " ";
		file << "学生学号:" << this->M_SO[i]["ID"] << " ";
		file << "学生姓名:" << this->M_SO[i]["name"] << " ";
		file << "选择机房:" << this->M_SO[i]["machine"] << " ";
		file << "审核状态:" << this->M_SO[i]["state"] << " ";
		file.close();
	}
	file.close();

}
