#include"file.h"
#include"user.h"
int createFlie(person per[])
{
	FILE *fp;
	
	if ((fp = fopen("d:\\person.dat", "wb")) == NULL)
	{
		printf("文件无法打开!\n");
		exit(0);
	}
	printf("输入联系人信息:\n");
	
	fwrite(per, sizeof(person), 1, fp);
	fclose(fp);
	return 1;
}


int readFile(person per[])
{
	FILE *fp;
	int i = 0;
	if ((fp = fopen("d:\\person.dat", "rb")) == NULL)
	{
		printf("文件不存在，请先创建！\n");
		return 0;
	}
	fread(&per[i], sizeof(person), 1, fp);
	while (!feof(fp))
	{
		i++;
		fread(&per[i], sizeof(person), 1, fp);
	}
	fclose(fp);
	return i;
}

void saveFile(person per[], int n)
{
	FILE *fp;
	if ((fp = fopen("d:\\person.dat", "wb")) == NULL)
	{
		printf("文件无法打开!\n");
		exit(0);
	}fwrite(per, sizeof(person), n, fp);
	fclose(fp);
}

void output(person per[], int n)
{
	FILE*fp;
	int j;
	/*
	char str[200] = "E:\\";
	strcpy(per[n].inf.phonenumber[0], str);
	strcpy(".txt",str);
	*/
	fp = fopen("D:\\per[n].inf.phonenumber[0].txt", "w+");
	if (fp == 0)
	{
		printf("文件错误！\n");
		exit(1);
	}
		fprintf(fp,"姓名：%s\n", per[n].inf.name);
		while (1)
		{
			if (per[n].inf.phonemem == 0)
			{
				fprintf(fp,"联系方式：无\n");
				break;
			}
			for (j = 0; j < per[n].inf.phonemem; j++)
			{
				fprintf(fp,"联系方式：%s\n", per[n].inf.phonenumber);
			}
			break;
		}
		if (per[n].inf.workmem == 1)
		{
			fprintf(fp,"工作地点：%s\n", per[n].inf.workplace);
		}

		while (1)
		{
			for (j = 0; j < 20; j++)
			{
				if (per[n].SocialInf[j].bool != 1)
					break;
				fprintf(fp,"%d、%s:%s\n", j + 1, per[n].SocialInf[j].name, per[n].SocialInf[j].information);
			}
			break;
		}
}
