#include"user.h"
#include"comcode.h"
#include"file.h"
#include<stdio.h>
#include<stdlib.h>


//从用户读取联系人信息
int read(person *per, int n)

{
	
	
	char SocialInformation[][50] = { "QQ","微信","电子邮箱","博客" ,"微博","Facebook","twitter" };
	int a;
	int i, j;//j为分组的循环的控制量
	int num;//做内部循环的控制量
	//int b;//做临时变量
	char ch0[50], ch1 = 'Y', ch2 = 'N';
	for (i = 0; i < n; i++)
	{
		per->inf.phonemem = 0;
		printf("请输入联系人信息\n");
		printf("请输入联系人姓名：");
		scanf("%s", &per->inf.name);
		//以下代码用于录入联系人电话号码的循环s
		printf("请输入联系人电话号码：\n");
		for (num = 0; num < N; num++)
		{
			//printf("%d", JudgeAdd());
			
			if (JudgeAdd() == 0)
			{
				strcpy(per->inf.phonenumber[num], "NULL");
				break;
				}
					
				
			printf("请输入联系人电话号码：\n");
			scanf("%s", &ch0);
			strcpy(per->inf.phonenumber[num], ch0);
			per->inf.phonemem++;
			//printf("%s", per[i].inf.phonenumber[num]);
		}
		//以下代码用于输入工作单位
		printf("请输入联系人工作单位");
		while(1)
		{
		
			
			if (JudgeAdd() == 0)
			{
				break;
			}
			printf("请输入联系人工作单位\n");
			scanf("%s", &ch0);
			strcpy(per->inf.workplace, ch0);
			per->inf.workmem = 1;
			//printf("%d", per[i].inf.workmem);
			//printf("%s", per[i].inf.workplace);
			break;
		}
		//以下代码用于预设并选择社交信息
		printf("请选择想要填的其他信息\n");
		j = 7;
		for (num = 0; num < j; num++)
		{
			
			strcpy(per->SocialInf[num].name, SocialInformation[num]);
		}
		while(1)
			{
			for (num = 0; num < j; num++)
			{
				printf("%d、%s\n",num + 1, per->SocialInf[num].name);
			}
			printf("%d、新建\n", num + 1);
			printf("0、退出\n");
			printf("输入对应数字以继续\n");
			scanf("%d", &a);
			/*
			b = num + 1;
			if (num >= '0'&&num <= 'b')
				;
			else
			{
				printf("请输入正确的数字！\n");
				continue;
			}
			*/
			if (a == 0)
				break;

			if (a == (j + 1))
			{
				per->SocialInf[a].bool = 1;
				printf("请输入名称\n");
				scanf("%s", &ch0);
				strcpy(per->SocialInf[a-1].name, ch0);
				printf("请输入详细信息\n");
				scanf("%s", &ch0);
				strcpy(per->SocialInf[a-1].information, ch0);
				per->SocialInf[a-1].bool = 1;
				j++;
				continue;
			}

			
			for(num=1;num<(j+1);num++)
			{
				if (a == num)
				{
					printf("请输入详细信息\n");
					scanf("%s", &ch0);
					strcpy(per->SocialInf[(a - 1)].information, ch0);
					per->SocialInf[num].bool = 1;
					//printf("%s\n", per[i].SocialInf[(a - 1)].information);
				}
				break;
			}	
			}
		//以下代码用于控制与新建分组
		printf("请为该联系人添加分组\n");
		reset(per, 1);
		while (1)
		{
			if (JudgeAdd() == 0)
				break;
			if (JudgeAdd() == 1)
			{

			}
		}
	}
		//以下代码用于控制
	
	//system("pause");//放于return之前（勿动）
	return i;
}

//查找联系人
int search(person per[], int n,person p,int condition, int a[])
{
	int i, j = 0, find = 0;
	for (i = 0; i < n; i++)
	{
		if (equal(per[i], p, condition))
		{
			a[j++] = i;
			find++;
		}
	}
	return find;
}

//打印
void printout(person *per, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		printf("姓名：%s\n", per[i].inf.name);
		while (1)
		{
			if (per[i].inf.phonemem == 0)
			{
				printf("联系方式：无\n");
				break;
			}
			for (j = 0; j < per[i].inf.phonemem; j++)
			{
				printf("联系方式：%s\n", per[i].inf.phonenumber);
			}
			break;
		}
		if (per[i].inf.workmem == 1)
		{
            printf("工作地点：%s\n", per[i].inf.workplace);
			printf("工作地点：%d\n", per[i].inf.workmem);
		}
		
		while (1)
		{
			for (j = 0; j < 20; j++)
			{
				if (per[i].SocialInf[j].bool != 1)
					break;
				printf("%d、%s:%s\n", j + 1, per[i].SocialInf[j].name, per[i].SocialInf[j].information);
			}
			break;
		}
	}
}


//判断是否为某种属性相同
int  equal(person per1, person per2, int n)
{
	int i;
	if (n == 1)
	{
		if (strcmp(per1.inf.name, per2.inf.name) == 0)
			return 1;
		else
			return 0;
	}
	if (n == 2)
	{
		for (i = 0; i < per1.inf.phonemem; i++)
		{
			if (strcmp(per1.inf.phonenumber[i], per2.inf.phonenumber[0]) == 0)
				return 1;
		}
			return 0;
	}
	return 1;
}


//删除联系人
int delete(person per[], int n, int condition)
{
	int i;
	for (i = condition; i < n - 1; i++)
		per[i] = per[i+1];

	n--;
	return n;
}

//修改联系人信息
void change(person per[],int condition)
{
	person p;
	printf("请重设该联系人的信息\n");
	read(&p, 1);
	per[condition] = p;
}


//插入联系人
int insertper(person per[], int n, person p)//插入联系人
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (strcmp(per[i].inf.name, p.inf.name) == 0)
		{
			printf("这个用户已经存在！请选择其他项目！\n");
				return n;
		}
	}
	strcpy(per[n].inf.name, p.inf.name);
	per[n].inf.phonemem=p.inf.phonemem;
	
	strcpy(per[n].inf.workplace, p.inf.workplace);
	for (i = 0; i < 20; i++)
	{
	   strcpy(per[n].inf.phonenumber[i], p.inf.phonenumber[i]);
       per[n].SocialInf[i].bool=p.SocialInf[i].bool;
	   strcpy(per[n].SocialInf[i].name, p.SocialInf[i].name);
	   strcpy(per[n].SocialInf[i].information, p.SocialInf[i].information);
	   strcpy(per[n].group[i], p.group[i]);
	}
	
	n++;
	return n;
}