#include<math.h>
#include<stdio.h>
#include "Position.h"

/*
����: scara_inverse_kinematics
����: scara�������˶�ѧ���
����: ��۳�L1(100mm)��С�۳�L2(100mm)��������ĩ������cartesianPos(mm��rad)
      ��ϵhandcoor����־λflagJ1��flagJ2
���: �����˹ؽ�λ��jointPos(rad)
*/
void scara_inverse_kinematics(double x, double y, int handcoor, double jointPos[2])
{
	// ������㾫��
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
			// �׳��쳣
			printf("Error: ���򲻿ɵ���\n");
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
	// ���ؽڵ�λ�������� [-�У���]
	if (jointPos[0] <= -PI)
	{
		jointPos[0] = jointPos[0] + 2.0 * PI;
	}
	else if (jointPos[0] > PI)
	{
		jointPos[0] = jointPos[0] - 2.0 * PI;
	}
}
