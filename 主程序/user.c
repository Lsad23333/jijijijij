#include"user.h"
#include"comcode.h"
#include"file.h"
#include<stdio.h>
#include<stdlib.h>


//���û���ȡ��ϵ����Ϣ
int read(person *per, int n)

{
	
	
	char SocialInformation[][50] = { "QQ","΢��","��������","����" ,"΢��","Facebook","twitter" };
	int a;
	int i, j;//jΪ�����ѭ���Ŀ�����
	int num;//���ڲ�ѭ���Ŀ�����
	//int b;//����ʱ����
	char ch0[50], ch1 = 'Y', ch2 = 'N';
	for (i = 0; i < n; i++)
	{
		per->inf.phonemem = 0;
		printf("��������ϵ����Ϣ\n");
		printf("��������ϵ��������");
		scanf("%s", &per->inf.name);
		//���´�������¼����ϵ�˵绰�����ѭ��s
		printf("��������ϵ�˵绰���룺\n");
		for (num = 0; num < N; num++)
		{
			//printf("%d", JudgeAdd());
			
			if (JudgeAdd() == 0)
			{
				strcpy(per->inf.phonenumber[num], "NULL");
				break;
				}
					
				
			printf("��������ϵ�˵绰���룺\n");
			scanf("%s", &ch0);
			strcpy(per->inf.phonenumber[num], ch0);
			per->inf.phonemem++;
			//printf("%s", per[i].inf.phonenumber[num]);
		}
		//���´����������빤����λ
		printf("��������ϵ�˹�����λ");
		while(1)
		{
		
			
			if (JudgeAdd() == 0)
			{
				break;
			}
			printf("��������ϵ�˹�����λ\n");
			scanf("%s", &ch0);
			strcpy(per->inf.workplace, ch0);
			per->inf.workmem = 1;
			//printf("%d", per[i].inf.workmem);
			//printf("%s", per[i].inf.workplace);
			break;
		}
		//���´�������Ԥ�貢ѡ���罻��Ϣ
		printf("��ѡ����Ҫ���������Ϣ\n");
		j = 7;
		for (num = 0; num < j; num++)
		{
			
			strcpy(per->SocialInf[num].name, SocialInformation[num]);
		}
		while(1)
			{
			for (num = 0; num < j; num++)
			{
				printf("%d��%s\n",num + 1, per->SocialInf[num].name);
			}
			printf("%d���½�\n", num + 1);
			printf("0���˳�\n");
			printf("�����Ӧ�����Լ���\n");
			scanf("%d", &a);
			/*
			b = num + 1;
			if (num >= '0'&&num <= 'b')
				;
			else
			{
				printf("��������ȷ�����֣�\n");
				continue;
			}
			*/
			if (a == 0)
				break;

			if (a == (j + 1))
			{
				per->SocialInf[a].bool = 1;
				printf("����������\n");
				scanf("%s", &ch0);
				strcpy(per->SocialInf[a-1].name, ch0);
				printf("��������ϸ��Ϣ\n");
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
					printf("��������ϸ��Ϣ\n");
					scanf("%s", &ch0);
					strcpy(per->SocialInf[(a - 1)].information, ch0);
					per->SocialInf[num].bool = 1;
					//printf("%s\n", per[i].SocialInf[(a - 1)].information);
				}
				break;
			}	
			}
		//���´������ڿ������½�����
		printf("��Ϊ����ϵ����ӷ���\n");
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
		//���´������ڿ���
	
	//system("pause");//����return֮ǰ���𶯣�
	return i;
}

//������ϵ��
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

//��ӡ
void printout(person *per, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
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
			printf("�����ص㣺%d\n", per[i].inf.workmem);
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


//�ж��Ƿ�Ϊĳ��������ͬ
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


//ɾ����ϵ��
int delete(person per[], int n, int condition)
{
	int i;
	for (i = condition; i < n - 1; i++)
		per[i] = per[i+1];

	n--;
	return n;
}

//�޸���ϵ����Ϣ
void change(person per[],int condition)
{
	person p;
	printf("���������ϵ�˵���Ϣ\n");
	read(&p, 1);
	per[condition] = p;
}


//������ϵ��
int insertper(person per[], int n, person p)//������ϵ��
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (strcmp(per[i].inf.name, p.inf.name) == 0)
		{
			printf("����û��Ѿ����ڣ���ѡ��������Ŀ��\n");
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