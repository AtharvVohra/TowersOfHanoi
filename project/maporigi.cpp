#include<stdio.h>
#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
 char map[20][73]={{' '}};
 void battle(int n)
 {
	clrscr();
	cout<<n;
	getch();
 }
void print(int m, int n)
{

	map[m][n]='Q';
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<73;j++)
		cout<<map[i][j];
		cout<<'\n';
		//if(j/4==1||i/6==1){
		//battle();
		//}
	}
	map[m][n]=' ';


}
void main()

{



	int x=0,y=0;
	while(1)
	{

		if(y==20)y=0;
		if(x==73)x=0;
		if(x==-1)x=72;
		if(y==-1)y=19;
		print(y,x);

		char ch=getch();
		clrscr();

		//map[x][y]=' ';

		if((random(10-1+1)+1)==7)
		{
		clrscr();
		battle(random(4-1+1)+1);
		}

		switch(ch)
		{
			case 'w':y--;break;
			case 'a':x--;break;
			case 's':y++;break;
			case 'd':x++;break;
		}


	}

}