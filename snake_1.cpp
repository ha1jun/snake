#include <iostream>
#include <algorithm>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include <string>
#define maxn 20

using namespace std;
int fps=60;
char a[maxn][maxn];
int s[4][2]={-1,0,1,0,0,-1,0,1};
int x1=5,y1=5;//�������� 
int x[10000];
int y[10000];
int top=1;
int end=0;
int st=0;//��ʼ���� 
char ch;//�������� 
int dead=0;//�ж��Ƿ�ײǽ 
char key;
int app;
int score=0;
int t=0;
char play=' ';
void print()
{
	string image="";
	for(int i=0;i<maxn;i++)
	{
		for(int j=0;j<maxn;j++)
		{
			image+=a[i][j];
		}	
		image+='\n';
	}
	printf("%s",image.c_str());
}

void move()
{
	if(a[x[top]+s[st][0]][y[top]+s[st][1]]!='*' && a[x[top]+s[st][0]][y[top]+s[st][1]]!='@')
	{
		if(a[x[top]+s[st][0]][y[top]+s[st][1]]=='o')
        {
            a[x[top]+s[st][0]][y[top]+s[st][1]]=a[x[top]][y[top]];
            x[top+1]=x[top];
            y[top+1]=y[top];
            top++;
		    x[top]+=s[st][0];
		    y[top]+=s[st][1];
		    app=1;
		    score++;
        }
        else
        {
           a[x[top]+s[st][0]][y[top]+s[st][1]]=a[x[top]][y[top]];
            x[top+1]=x[top];
            y[top+1]=y[top];
            top++;
		    x[top]+=s[st][0];
		    y[top]+=s[st][1];
            a[x[end]][y[end]]=' ';
            end++;
        }
	}
	else
	{
		dead=1;
		return ;
	}
}

void read()
{
	if(_kbhit())
	{
		key=_getch();
		if(key=='w')
		{
			if(st!=1)
		{
			st=0;
		}	
		}
		else if(key=='s')
		{
			if(st!=0)
			{
				st=1;
			}
		}
		else if(key=='a')
		{
			if(st!=3)
			{
				st=2;
			}
		}
		else if(key=='d')
		{
			if(st!=2)
			{
				st=3;
			}
		}
	}
}

int main()
{
    while(play==' ')
    {
    	for(int i=0;i<10000;i++)
    	{
    		x[i]=0;
    		y[i]=0;
		}
		st=0;
		top=1;
		end=0;
    	score=0;
    	dead=0;
    	x[0]=11;
		y[0]=10;
		y[1]=10;
		x[1]=10;	
		srand(time(0));
		for(int i=0;i<maxn;i++)
		{
			for(int j=0;j<maxn;j++)
			{
				a[i][j]=' ';	
			}	
		}
		for(int i=0;i<maxn;i++)
		{
			a[0][i]='*';
			a[maxn-1][i]='*';
			a[i][0]='*';
			a[i][maxn-1]='*';
		}
		a[5][5]='o';
		a[10][10]='@';
	    a[11][10]='@' ;
    	play='a';
    	print();
   	 	printf("�����⽨��ʼ��Ϸ"); 
    	_getch();
    	system("cls");
		while(1)
		{
			
			app=0;
			read();
			if(t%3==0)
			{
				move();
			}
			t++;
			if(app==1)
			{
				x1=rand()%(maxn-2)+1;
				y1=rand()%(maxn-2)+1;
				a[x1][y1]='o';
			}
			if(dead==1)
			{
				break;
			}
			print();
			Sleep(1.0/fps*1000);
			system("cls");
		}
		if(score<10)
		{
			printf("��%d�֣��˼�",score);
		}
		else
		{
			printf("�����%d��",score);
		}
		printf("\n���������������"); 
		_getch(); 
		system("cls");
		printf("���ո�ʼ����Ϸ"); 
		//system ("pause");
		play=_getch();
		system("cls");
	}
	return 0;
}
