#pragma once
#ifndef 用户
#define 用户
#include<string.h>
#define N 20
#define NUM 200
//定义基本信息
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




 
int read(person *per, int n);//读取
int insertper(person per[], int n, person p);//插入联系人
int search(person per[], int n,person p,int condition, int a[]);//查找联系人
int  equal(person per1, person per2, int n);//判断是否为某种属性相同
void printout(person *per, int n);//打印
int delete(person per[], int n, int condition);//删除联系人
void change(person per[], int condition);//修改联系人信息
/*
void printout(person *per, int n);//打印
int  equal(person per1, person per2, int n);//判断是否为某种属性相同
int search(person per[], int n, person man, int condition, int a[]);//查找联系人
int insertper(person per[], int n, person p);//插入联系人
int change(person per[], int n, person p);//修改联系人信息
int delete(person per[], int n, person p);//删除联系人
*/














#endif//勿删