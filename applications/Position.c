#include<math.h>
#include<stdio.h>
#include "Position.h"

/*
函数: scara_inverse_kinematics
描述: scara机器人运动学逆解
输入: 大臂长L1(100mm)，小臂长L2(100mm)，机器人末端坐标cartesianPos(mm或rad)
      手系handcoor，标志位flagJ1与flagJ2
输出: 机器人关节位置jointPos(rad)
*/
void scara_inverse_kinematics(double x, double y, int handcoor, double jointPos[2])
{
	// 定义计算精度
	double calculateError = 1.0e-8;

	double c2 = (x * x + y * y - L1 * L1 - L2 * L2) / (2.0 * L1 * L2);
	double temp = 1.0 - c2 * c2;

	if (temp < 0.0)
	{
		if (temp > -calculateError)
		{
			temp = 0.0;
		}
		else
		{
			// 抛出异常
			printf("Error: 区域不可到达\n");
			return;
		}
	}

	double s2 = 0.0;
	if (handcoor == 0) // left handcoor
	{
		s2 = -sqrt(temp);
	}   
	else                // right handcoor
	{
		s2 = sqrt(temp);
	}

	jointPos[1] = atan2(s2, c2);
	double s1 = sin(atan2(y, x) - atan2(L2 * s2, L1 + L2 * c2));
	jointPos[0] = atan2(s1, cos(atan2(y, x) - atan2(L2 * s2, L1 + L2 * c2)));
	// 将关节的位置限制在 [-π，π]
	if (jointPos[0] <= -PI)
	{
		jointPos[0] = jointPos[0] + 2.0 * PI;
	}
	else if (jointPos[0] > PI)
	{
		jointPos[0] = jointPos[0] - 2.0 * PI;
	}
}
