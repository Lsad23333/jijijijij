#include"comcode.h"
#include"user.h"
#include"file.h"
#include<stdio.h>
#include<stdlib.h>


void menu()
{
	printf("***********1����ϵ����Ϣһ��***********\n");
	printf("***********2����ϵ����Ϣ����***********\n");
	printf("***********3����ϵ����Ϣ����***********\n");
	printf("***************0���˳�*****************\n");
}

void menu2()
{
	printf("***********1����ϵ����Ϣ��ѯ***********\n");
	printf("***********2����ϵ����Ϣɾ��***********\n");
	printf("***********3����ϵ����Ϣ�޸�***********\n");
	printf("***********4����ϵ����Ϣ���***********\n");
	printf("**************0�������ϼ�**************\n");
}

void menu2_1()
{
	printf("***********1����������ѯ***********\n");
	printf("***********2���������ѯ***********\n");
	printf("************0�������ϼ�************\n");
}

void commenu()
{
	printf("�������Ҫ��������ϵ��\n");
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
				printf("��������ϵ������\n");
				scanf("%s", &p.inf.name);
				break;
			case 2:
				printf("��������ϵ�˵绰����\n");
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
					printf("�޷��ҵ�\n");
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
			printf("��������ϵ������\n");
			scanf("%s", &p.inf.name);
			break;
		case 2:
			printf("��������ϵ�˵绰����\n");
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
				printf("ɾ���ɹ�\n");
			}
			else
				printf("�޷��ҵ�\n");
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
			printf("��������ϵ������\n");
			scanf("%s", &p.inf.name);
			break;
		case 2:
			printf("��������ϵ�˵绰����\n");
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
				printf("�޷��ҵ�\n");
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
		printf("���������Լ���\n");
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
		printf("������%s\n", per[i].inf.name);
		while (1)
		{
			if (per[i].inf.phonemem == 0)
			{
				printf("��ϵ��ʽ����\n");
				break;
			}
			for (j = 0; j < per[i].inf.phonemem; j++)
			{
				printf("��ϵ��ʽ��%s\n", per[i].inf.phonenumber);
			}
			break;
		}
		if (per[i].inf.workmem == 1)
		{
			printf("�����ص㣺%s\n", per[i].inf.workplace);
		}

		while (1)
		{
			for (j = 0; j < 20; j++)
			{
				if (per[i].SocialInf[j].bool != 1)
					break;
				printf("%d��%s:%s\n", j + 1, per[i].SocialInf[j].name, per[i].SocialInf[j].information);
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
			printf("��������ϵ������\n");
			scanf("%s", &p.inf.name);
			break;
			case 2:
			printf("��������ϵ�˵绰����\n");
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
				printf(".txt�ļ�����ɹ�\n");
				printf("�밴�涨�����˳���鿴\n");
				printf("�ļ�������D�̸�Ŀ¼��\n");

			}
			else
				printf("�޷��ҵ�\n");
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
		printf("�ļ������ɹ���\n");
	}
	do
	{
		menu();
		printf("���������Լ���\n");
		if (scanf("%d", &chioce) == 1)
		{
			if (chioce >= 0 && chioce <= 3)
				n = runmain(per, n, chioce);
			else
			{
				printf("���������������ȷ�����֣�\n");
				continue;
			}
		}
		if (chioce >= 0 && chioce <= 3)
			n = runmain(per, n, chioce);
		else
			printf("���������������ȷ�����֣�\n");
				continue;
	} while (chioce);
	saveFile(per, n);
	return 0;
}

//if(scanf("%d", &chioce)==1)