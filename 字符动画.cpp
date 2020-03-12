#include<Windows.h>
#include<MMSystem.h>
#pragma comment(lib,"WINMM.LIB")
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define WIDTH  400//宽
#define HIGHT 300//高
#define PAGE_LIMIT 400000//帧数
#define N HIGHT*WIDTH//宽*高

char name[]="d\\ASCII-0000.txt";
char str[N];

int main()
{
	
//	PlaySound("",NULL,SND_FILENAME | SND_ASYNC); 
	int i,n=1,p,q;
	char a[4]="000";

	for(i=1;i<=PAGE_LIMIT;i++)
	{
		for(p=10,q=0;q<4;q++)
		{
			if(i<10&&q==1)break;
			else if(i<100&&q==2)break;
			else if(i<1000&&q==3)break;
			else 
			{
				a[q]=i%p/(p/10)+48;
				p*=10;
			}
		}
		for(p=0;p<q;p++)
			name[11-p]=a[p];
			FILE *fp;
		if((fp=fopen(name,"r"))==NULL)
		{
			printf("%d",i);
			system("pause");
			continue;
		}
		
		while(fgets(str,N,fp)!=NULL) 
			printf("%s",str);
		Sleep(rand()%10+1);
		
		fclose(fp);
		system("cls");//清屏
	
		
		
	}
	system("pause");
	return 0;

}