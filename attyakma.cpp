#include <iostream.h>
#include <fstream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <process.h>
#include<math.h>
class User
{
	char name[20];
	int score;
	int highscore;
	char pass[20];


	char username[20];
	char passcheck[20];

	public:
	int level;
	void input();
	void login();
	void save();
	void ReturnInfo();
	void test();
	void display();


}obj;

class stack
{
 stack *link;
 int disc;
 public:
 stack()
 {
  link=NULL;
 }
 void push(stack **a,int b);
 void filltop(stack **a);
 void popandpush(stack **a,stack **b);
 void display(stack *a);
};

stack *top1;
stack *top2;
stack *top3;

void stack::push(stack **a, int b)   //b is the disc number,a is destination
{
 stack *np=new stack;
 if(!np)
 cout<<"Memory Exhausted ";
 np->disc=b;
 np->link=NULL;
 if(*a==NULL)
  {
	*a=np;
  }
 else
  {
	if((np->disc)<((*a)->disc))
	{
	 np->link=*a;
	 *a=np;
	}
	else
	{
	 cout<<endl<<"Violation, big over small ";
	}
  }
}

void stack::popandpush(stack **a,stack **b)//pop from a , push to b
{
 if(*a==NULL)
 cout<<"Stack Underflow.... ";
 else
 {
  stack *temp;
  temp=*a;
  int d;
  d=temp->disc;
  push(b,d);
  *a=(*a)->link;
  delete temp;
 }
}

void stack::display(stack *a)
{
 stack *temp=new stack;
 temp=a;
 while(temp!=NULL)
 {
  cout<<temp->disc<<endl;
  temp=temp->link;
 }
}



char levelcpy[4];
int hanoip[3][10]={{0}};


int level=2;
int MAX=5+(level*2);
int hower=0;
int held=0;
char solve2[]={'w','a','a','a','a','s','a','a','w','a','a','s','a','a','w','a','s','a','w','a','a','a','a','s','a','w','a','s','a','a','w','a','a','s','a','a','w','a','a','a','a','s','a','a','w','a','a','s','a','a','w','a','s','a','a','w','a','a','s','a','a','w','a','s','a','a','a','a','w','a','s','a','w','a','a','a','a','s','a','a','w','a','a','s','a','a','w','a','s','s'};
int moves=(pow(2,(level+3))-1)*1.5;
int movest=0;

void assigntower()
{
	int nos=level+3;
	int i=0;
	int len=1;
	for(int j=(10-nos);j<10;j++)
	{
		len+=2;
		hanoip[i][j]=len;
	}
	j--;
	hanoip[0][j]=len;
	hanoip[1][j]=len;
	hanoip[2][j]=len;

}

int completed=0;

void printhanoi()
{




	cout<<"username:\n";
	cout<<"\nlevel: "<<level;;
	cout<<"\nMoves left: "<<moves;
	cout<<"\nMoves taken: "<<movest;


	if(((hanoip[1][8]==0 || hanoip[2][8]==0) && (hanoip[0][8]==0)) && (held==0))
	{	cout<<"\n                        COMPLETED!!!";
		completed=1;


	}

	int spaceX=10;
	int spaceY=5;

	for( int j=0;j<spaceY;j++)
	cout<<'\n';
	for(int i=0;i<=MAX;i++)
	{


	for( j=0;j<spaceX;j++)
	cout<<' ';

		for( j=0;j<3;j++)
		{
			if(i==0)
			{

				if(j==hower)
				{
					for(int k=0;k<=(MAX-hanoip[j][i])/2; k++)
					{

						cout<<' ';
					}

					cout<<(char)18;
					for( k=0;k<=(MAX-hanoip[j][i])/2; k++)
					{
						cout<<' ';
					}

					cout<<"  ";
				}

				else

				  {	for(int k=0;k<=(MAX-hanoip[j][i])/2; k++)
					{

						cout<<' ';
					}

					cout<<' ';
					for( k=0;k<=(MAX-hanoip[j][i])/2; k++)
					{
						cout<<' ';
					}

					cout<<"  ";
				  }


			}

			else
			{

			for(int k=0;k<=(MAX-hanoip[j][i])/2; k++)
			{

				cout<<' ';
			}
			if(!hanoip[j][i])cout<<" ";




			for( k=0;k<hanoip[j][i]; k++)
			{

				 if(i==9)cout<<'#';
					else if(i<9)
					cout<<'=';
			}



			for( k=0;k<=(MAX-hanoip[j][i])/2; k++)
			{
				cout<<' ';
			}

			cout<<"  ";

			}


		}
		cout<<'\n';
	}
}

void pickup()
{
	if(held==0)
	{

		for(int i=0;i<9;i++)
		{
			if(hanoip[hower][i]>0)
			{
				hanoip[hower][2]=hanoip[hower][i];
				held=hanoip[hower][i];
				hanoip[hower][i]=0;
				break;

			}

		}
	}
}

void move()
{
	if(held>0)
	{
		hanoip[0][2]=0;
		hanoip[1][2]=0;
		hanoip[2][2]=0;
		hanoip[hower][2]=held;
	}




}

void pound()
{

	if(held>0)
	{  moves--;
	movest++;
		for(int i=5;i<10;++i)
		{
			if( hanoip[hower][i]>0 )
			{
					if(hanoip[hower][i]>held)
					{
					hanoip[hower][i-1]=held;
					hanoip[0][2]=0;
					hanoip[1][2]=0;
					hanoip[2][2]=0;
					held=0;

					}
					else
					{
						cout<<"Not Allowed!\n";

					}


				break;
			}





		}

	}
}




char rec[500]={' '};
int M=0;
void movehanoi()
{

	 char inp;
	 hower=0;
	 while(!completed)
	 {
			printhanoi();
			cout<<hower;
			inp=getch();
			rec[M]=inp;
			M++;

			clrscr();

				{switch(inp)
		  {

				case 'w':pickup();
							break;
				case 's':pound();
							break;
				case 'a':if(hower>=0)
							hower--;
							move();


							break;
				case 'd':if(hower<2)hower++;
				move();
				break;

				//case '/':completed=1;

							//break;
				case 13:clrscr();

				break;
				default: cout<<"ENTER CORRECT OPTION\n";getch();
		  }
		  }


		}
		if(completed)
		{
			level++;
			score=moves;

		}

}

void playhanoi()
{
	 hower=0;

	 for(int i=0;i<sizeof(solve2);i++)
	 {
			printhanoi();
			getch();



			clrscr();

				{switch(solve2[i])
		  {

				case 'w':pickup();
							break;
				case 's':pound();
							break;
				case 'a':if(hower>0)hower--;
				move();
							break;
				case 'd':if(hower<2)hower++;
				move();
							break;
				case 13:clrscr();

				break;
				default: cout<<"ENTER CORRECT OPTION\n";getch();
		  }
		  }


		}

}

void akgame()
{
 if (level==1)
	 {
		MAX=9;
	 }
	 getch();
	 assigntower();
	 movehanoi();
	 getch();
	 for(int i=0;i<64;i++)
	 {
		cout<<'\''<<rec[i]<<"\',";
	 }
	moves=(pow(2,(level+3))-1)*1.5;
	movest=0;
	 for(i=0;i<3;i++)
	 for(int j=0;j<10;j++)
	 hanoip[i][j]=0;
	 assigntower();
	 playhanoi();
}




void reg(User obj)
{  obj.input();
	ofstream ofile("LoginInfo.bin", ios::binary|ios::app);
	ofile.write((char*)&obj, sizeof(obj));
	ofile.close();
}

void User::display()
{
 clrscr();
 cout<<"Name :"<<username;
 cout<<endl<<"Score :"<<score<<endl;
 cout<<"Highscore :"<<highscore<<endl;getch();
}
void User::input()
{

	cout<<"Enter name"<<'\n';
	gets(name);
	level = 1;
	cout<<"Enter new password ";
	gets(pass);


	cout<<'\n'<<"Thanks for registering! Please Log in to start your game."<<'\n';


}


void ReadIntro()
{

	ifstream ifile("Instruct.txt");
	if(!ifile)
	 {
	  cout<"File Open Error ";
	  exit(0);
	 }

	char st[115];
	int c=0;
	while(!ifile.eof())
	{
	 ifile.getline(st,115,'\n');
	 ifile.get('\n');
	 puts(st);cout<<endl;
	}
	cout<<"Next -> (Press Enter ) ";
	getch();
	clrscr();

	ifstream ifile2("Controls.txt");
	if(!ifile2)
	 {
	  cout<"File Open Error ";
	  exit(0);
	 }
	while(!ifile2.eof())
	{
	 ifile2.getline(st,115,'\n');
	 ifile2.get('\n');
	 puts(st);cout<<endl;
	}
	getch();
	ifile.close();
	ifile2.close();
}

void User::test()
{
	score = 300;
	highscore = 670;

}

void User::save()   //not working?
{
	obj.test();
	ofstream ofile("user.bin", ios::binary|ios::app);
	ofile.write((char *)&obj, sizeof(obj));obj.display();
	ofile.close();
}

void User::ReturnInfo()
{
	ifstream ifile("user.bin", ios::binary);
	User t;
	while(!ifile.eof())
	{
		ifile.read((char *)&t, sizeof(t));
	}
  ifile.close();
}


void User::login()
{  int f=0;
	ifstream ifile("LoginInfo.bin", ios::binary);
	usercheck:
	cout<<"Username: ";
	gets(username);
	cout<<'\n';
	User obj2;

	while(!ifile.eof())
	{
		ifile.read((char*)&obj2, sizeof(obj2));

		if(strcmp(username,obj2.name)==0)
		{
			cout<<"Password: ";
			gets(passcheck);
			if(strcmp(passcheck, obj2.pass)==0)
			{
				//call game screen function.
				cout<<"Logged In!"<<endl<<"Please Press Anything to Continue ";f=1;
				break;
			}
		}
	}
	if(!f)
	{
	 cout<<"Invalid username, Please enter again : ";
	}
}


void delay()
{
 double i;
 for(i=0;i<99949779;i++);
}
void intr()
{
 cout<<'\t'<<'\t'<<'\t'<<" WELCOME TO THE TOWER OF HANOI ";delay();
 cout<<endl<<endl;
 cout<<"This classic brain game is now available on the C++ platform!";delay();
 cout<<endl<<endl<<"You can learn how to play using our instruction files once you login ";
 delay();cout<<endl<<endl<<"Compare your scores with other friends, and use our self solver for tips and tricks!!";
 delay();
 cout<<endl<<endl<<'\t'<<'\t'<<'\t'<<"Happy Gaming! ";
}
void main()
{
	 intr();
	 getch();
	 clrscr();
	int ch;
	do{ clrscr();
	cout<<"Enter option"<<'\n'<<"1. Register"<<'\n'<<"2. Login"<<'\n'<<"3. Read Instruction Files "<<endl<<"4. Play the game "<<endl;
	cin>>ch;
	switch(ch)
	{

		case 1:
		{
			reg(obj);break;
		}
		case 2:
		{
			obj.login();
			getch();obj.save();break;
		}
		case 3:
		{
			clrscr();
			ReadIntro();break;
		}
		case 4:
		{
		 clrscr();
		 akgame();
		}

	}
	}while(ch!=5);
}
