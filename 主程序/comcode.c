#include"comcode.h"
#include"user.h"
#include<stdio.h>


//用于判断是否继续添加
int JudgeAdd()
{
	char ch9[200], ch1 = 'Y', ch2 = 'N';
	printf("(若不需要添加请输入N需要请输入Y）\n");
	while (1)
	{
		scanf("%s", ch9);
		if (ch9[0] == ch1 || ch9[0] == ch2)
			break;
		else
		{
			printf("请输入正确的字母(Y/N)\n");
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



 