#pragma once
#ifndef �û�
#define �û�
#include<string.h>
#define N 20
#define NUM 200
//���������Ϣ
typedef struct  baseinformation
{
	char name[100];
	char workplace[200];
	int  workmem;
	char phonenumber[N][15];
	int  phonemem;
}baseinformation;

typedef struct SocialInformation
{
	int bool ;
	char name[50];
	char information[200];
	
}SocialInformation;

typedef struct members
{
	int bool ;
	int mem[100];
}members;






typedef  struct person
   {
	  baseinformation inf;
	  SocialInformation SocialInf[20];
	  //char SocialInformation[20][50];
	  char group[20][50];
	  
	  
   }person;




 
int read(person *per, int n);//��ȡ
int insertper(person per[], int n, person p);//������ϵ��
int search(person per[], int n,person p,int condition, int a[]);//������ϵ��
int  equal(person per1, person per2, int n);//�ж��Ƿ�Ϊĳ��������ͬ
void printout(person *per, int n);//��ӡ
int delete(person per[], int n, int condition);//ɾ����ϵ��
void change(person per[], int condition);//�޸���ϵ����Ϣ
/*
void printout(person *per, int n);//��ӡ
int  equal(person per1, person per2, int n);//�ж��Ƿ�Ϊĳ��������ͬ
int search(person per[], int n, person man, int condition, int a[]);//������ϵ��
int insertper(person per[], int n, person p);//������ϵ��
int change(person per[], int n, person p);//�޸���ϵ����Ϣ
int delete(person per[], int n, person p);//ɾ����ϵ��
*/














#endif//��ɾ