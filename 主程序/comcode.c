#include"comcode.h"
#include"user.h"
#include<stdio.h>


//�����ж��Ƿ�������
int JudgeAdd()
{
	char ch9[200], ch1 = 'Y', ch2 = 'N';
	printf("(������Ҫ���������N��Ҫ������Y��\n");
	while (1)
	{
		scanf("%s", ch9);
		if (ch9[0] == ch1 || ch9[0] == ch2)
			break;
		else
		{
			printf("��������ȷ����ĸ(Y/N)\n");
			//ch0[0] = 0;
			continue;
		}
	}
	if (ch9[0] == ch1)
		return 1;
	else
		return 0;
}

void reset(person *per,int i)
{
	int n;
	if (i == 1)
	{
		for (n = 0; n < 20; n ++ )
		{
			strcpy(per->group[n], "NULL");
		}
	}
}



 