#include"comcode.h"
#include"user.h"
#include"file.h"
#include<stdio.h>
#include<stdlib.h>


void menu()
{
	printf("***********1、联系人信息一览***********\n");
	printf("***********2、联系人信息操作***********\n");
	printf("***********3、联系人信息导出***********\n");
	printf("***************0、退出*****************\n");
}

void menu2()
{
	printf("***********1、联系人信息查询***********\n");
	printf("***********2、联系人信息删除***********\n");
	printf("***********3、联系人信息修改***********\n");
	printf("***********4、联系人信息添加***********\n");
	printf("**************0、返回上级**************\n");
}

void menu2_1()
{
	printf("***********1、按姓名查询***********\n");
	printf("***********2、按号码查询***********\n");
	printf("************0、返回上级************\n");
}

void commenu()
{
	printf("请查找需要操作的联系人\n");
}
void M2_1(person per[], int n)
{
	
	int i,  findnum, f[NUM];
	int  chioce;
	person p;
	do
	{
		menu2_1();
		scanf("%d", &chioce);
	
			switch (chioce)
			{
			case 1:
				printf("请输入联系人姓名\n");
				scanf("%s", &p.inf.name);
				break;
			case 2:
				printf("请输入联系人电话号码\n");
				scanf("%s", p.inf.phonenumber[0]);
				break;
			case 0:
				break;
			}
			if (chioce >= 1 && chioce <= 2)
			{
				findnum = search(per, n, p, chioce, f);
				if (findnum)
				{
					for (i = 0; i < findnum; i++)
						printout(&per[f[i]], 1);
				}
				else
					printf("无法找到\n");
			}
		
		
	} while (chioce);
}
	
void M2_2(person per[], int n)
{
	int   findnum, f[NUM];
	int chioce;
	person p;
	do
	{
		commenu();
		menu2_1();
		scanf("%d", &chioce);

		switch (chioce)
		{
		case 1:
			printf("请输入联系人姓名\n");
			scanf("%s", &p.inf.name);
			break;
		case 2:
			printf("请输入联系人电话号码\n");
			scanf("%s", p.inf.phonenumber[0]);
			break;
		case 0:
			break;
		}
		if (chioce >= 1 && chioce <=2)
		{
			findnum = search(per, n, p, chioce, f);
			if (findnum)
			{
				delete(per, n, f[0]);
				printf("删除成功\n");
			}
			else
				printf("无法找到\n");
		}


	} while (chioce);
}

void M2_3(person per[],int n)
{
	int   findnum, f[NUM];
	int chioce;
	person p;
	do
	{
		commenu();
		menu2_1();
		scanf("%d", &chioce);

		switch (chioce)
		{
		case 1:
			printf("请输入联系人姓名\n");
			scanf("%s", &p.inf.name);
			break;
		case 2:
			printf("请输入联系人电话号码\n");
			scanf("%s", p.inf.phonenumber[0]);
			break;
		case 0:
			break;
		}
		if (chioce >= 1 && chioce <= 2)
		{
			findnum = search(per, n, p, chioce, f);
			if (findnum)
			{
				change(per, f[0]);
			}
			else
				printf("无法找到\n");
		}


	} while (chioce);
}


int M2(person per[],int n)
{
	int chioce;
	person p;
	do
	{
		menu2();
		printf("输入数字以继续\n");
		scanf("%d", &chioce);
		switch (chioce)
		{
		case 1:M2_1(per, n);
			break;
		case 2:M2_2(per, n);
			break;
		case 3:M2_3(per, n);
			break;
		case 4:read(&p, 1);
			n = insertper(per, n, p);
			break;

		}


	} while (chioce );
	return n;
}

void M1(person per[])
{
	int i, j;
	for (i = 1; i < readFile(per); i++)
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

void M3(person per[], int n)
{
	int   findnum, f[NUM];
	int chioce;
	person p;
	do
	{
		commenu();
		menu2_1();
		scanf("%d", &chioce);

		switch (chioce)
		{
		case 1:
			printf("请输入联系人姓名\n");
			scanf("%s", &p.inf.name);
			break;
			case 2:
			printf("请输入联系人电话号码\n");
			scanf("%s", p.inf.phonenumber[0]);
			break;
		case 0:
			break;
		}
		if (chioce >= 1 && chioce <=2)
		{
			findnum = search(per, n, p, chioce, f);
			if (findnum)
			{
				output(per, f[0]);
				printf(".txt文件输出成功\n");
				printf("请按规定操作退出后查看\n");
				printf("文件储存在D盘根目录中\n");

			}
			else
				printf("无法找到\n");
		}


	} while (chioce);
}


int runmain(person per[],int n,int chioce)
{
	switch (chioce)
	{
	case 1:M1(per);
		break;
	case 2:n = M2(per, n);
		break;
	case 3: M3(per, n);
		break;
	}
	return n;
}
person per[NUM];

int main()
{
	int  n;
	int chioce;
	n = readFile(per);
	if (!n)
	{
		n = createFlie(per);
		printf("文件创建成功！\n");
	}
	do
	{
		menu();
		printf("输入数字以继续\n");
		if (scanf("%d", &chioce) == 1)
		{
			if (chioce >= 0 && chioce <= 3)
				n = runmain(per, n, chioce);
			else
			{
				printf("输入错误！请输入正确的数字！\n");
				continue;
			}
		}
		if (chioce >= 0 && chioce <= 3)
			n = runmain(per, n, chioce);
		else
			printf("输入错误！请输入正确的数字！\n");
				continue;
	} while (chioce);
	saveFile(per, n);
	return 0;
}

//if(scanf("%d", &chioce)==1)