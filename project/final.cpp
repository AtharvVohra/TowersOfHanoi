/*Prologue:- The program is for a text based role playing game developed by Akhil, Mahir and Atharv.
The name of the game is Thrive to Survive.The user navigates on a map, faces foes and on defeating them,
earns coins to buy weapon upgrades from the inventory.
The developers would like to thank Chandita ma'am for her full support and suggestions. We hope the project is impactful, and moreover,FUN!!
													THANK YOU!!!
*/

using namespace std;

#include<stdio.h>
#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<iomanip.h>
#include<ctype.h>
#include<time.h>
#define wait(x) for(double k=0;k<100000;k+=x);

 char map[20][73]={{' '}};

 int t = 1;  //Weapon status
				 //t=1 - wooden sword
				 //t=2- dagger and sword
				 //t=3- all weapons owned
				 //t=4- sword and flamethrower


 struct enemy
{
  int health;       //enemy attributes
  char name[20];
}krrish,meghnamind,shreyk,JimShauryarty;



struct user
{
 char name[20];    //user attributes
 float coins;
 int health;
 int level;
}gamer;



void display()       //only to display,not to buy
{
 cout<<"Your inventory:-"<<endl;
 cout<<"Weapons:-"<<endl;
 cout<<endl<<'\t'<<'\t'<<" ID          WEAPON           COST"<<endl;
 cout<<endl<<'\t'<<'\t'<<" D           DAGGER            150"<<endl;
 cout<<endl<<'\t'<<'\t'<<" F           FLAMETHROWER      350"<<endl;
 cout<<endl<<endl<<'\t'<<'\t'<<"Coins in the bag = "<<gamer.coins;
 cout<<endl;
}

void H(int x, int y=0)   //health display function
{


	if(y)
	{
	 cout<<setw(30)<<' ';

	}

	for(int i=1;i<(x/5);i++)
	{
		cout<<'=';
	}cout<<'\n';

}



void inventory()       //inventory to buy upgrades
{
	clrscr();
	int ch;
	char id;
	do
	{
		cout<<"Your inventory:-"<<endl;
		cout<<"Weapons:-"<<endl;
		cout<<endl<<'\t'<<'\t'<<" ID           WEAPON           COST"<<endl;
		cout<<endl<<'\t'<<'\t'<<"  D           DAGGER            150"<<endl;
		cout<<endl<<'\t'<<'\t'<<"  F           FLAMETHROWER      350"<<endl;
		cout<<endl<<endl<<'\t'<<'\t'<<"Coins in the bag = "<<gamer.coins;
		cout<<endl<<'\t'<<'\t'<<"OPTIONS ;-"<<endl;
		cout<<'\t'<<'\t'<<"1. Buy"<<endl<<'\t'<<'\t'<<"2. Leave inventory ";
		reenter :
		cout<<endl<<"Enter a choice ";
		cin>>ch;
		switch(ch)
  {
 case 1:
 {

  cout<<"Enter ID of item to be bought ";
  cin>>id;
  if(id=='D' || id=='d')
  {
	if (gamer.coins>=150)
	{clrscr();
  cout<<"Dagger bought, Congrats!! "<<endl;
  gamer.coins-=150;
  if (::t == 4)
	::t = 3;
  else
	 ::t = 2;
	}
	else
	{
  cout<<"Not enough coins to buy ";
  goto reenter;
	}
  }
  else if(id=='F' || id=='f')
  {
	if (gamer.coins>=350)
	{
  cout<<"Flamethrower bought, Congrats!! ";
  gamer.coins-=350;
  if(::t == 2)
	 ::t = 3;
  else
	 ::t = 4;
	}
	else
	{
  cout<<"Not enough coins to buy ";
  goto reenter;
	}
  }
  break;

 }
  }
 }while(ch!=2);
 clrscr();
}


void battle(int choice)          //battle function to fight foes
{    int turn,f=0;
	  char attack_choice;
	 switch(choice)
	 {
		case 1:
		{
		  cout<<"The battle with Krrish.B begins!!!"<<'\n';
		  krrish.health = 50;
		  gamer.health = 100;
			turn = 0;

		  while(gamer.health>0 && krrish.health>0)
		  {
			 if(turn == 0)
			 {
				wait(0.0001)       //time delay
				clrscr();
				cout<<"Rival stats :-"<<'\n'<<"Health "<<krrish.health<<'\n'<<'\n';
				H(krrish.health);
				cout<<'\n'<<setw(30)<<"Your stats :-"<<'\n'<<setw(30)<<"Health "<<gamer.health<<'\n'<<'\n';
				H(gamer.health,1);
				cout<<setw(30)<<" "<<"It is your turn to attack!"<<'\n';
				do
				{ f=0;
				cout<<setw(30)<<" "<<"Choose your attacking weapon"<<'\n';
				cout<<setw(30)<<" "<<"1. Wooden Sword  2. Dagger   3. Flamethrower ";
				cin>>attack_choice;
				switch(attack_choice)
				{
				  case '1':
				  {
					  cout<<"Attack successful!"<<endl;
					  krrish.health-=random(15-1+1)+1;
					  cout<<"Krrish has "<<krrish.health<<" health remaining!"<<'\n';
					  turn=1;
					  break;

				  }
				  case '2':
				  {
					 if(t==2 || t==3)
					 {

					  cout<<"Attack successful!"<<endl;
					  krrish.health-=random(25-10+1)+10;
					  cout<<"Krrish has "<<krrish.health<<" health remaining!"<<'\n';
					  turn=1;

					 }
					 else
					 {
						cout<<"You have not yet bought this weapon,please re-enter weapon choice ";
						f=1;		  //takes user back to choose options
					 }
					 break;
				  }
				  case '3':
				  {
					if(t==4 || t==3)
					 {

					  cout<<"Attack successful!"<<endl;
					  krrish.health-=random(30-20+1)+20;
					  cout<<"Krrish has "<<krrish.health<<" health remaining!"<<'\n';
					  turn=1;

					 }
					 else
					 {
					  cout<<"You have not yet bought this weapon,please re-enter weapon choice ";
					  f=1;
					 }
					 break;
				  }
				  default:f=1;
				}
				}while(f==1);
				turn = 1;

			 }
			 else
			 {

				cout<<"Rival stats :-"<<'\n'<<"Health "<<krrish.health<<'\n'<<'\n';
				H(krrish.health);
				cout<<'\n'<<setw(30)<<" "<<"Your stats :-"<<'\n'<<setw(30)<<" "<<"Health "<<gamer.health<<'\n'<<endl;
				H(gamer.health,1);
				cout<<"It is Krrish.B's turn to attack!"<<'\n';

				gamer.health-=random(20-1+1)+1;   //krrish.b's damage
				turn = 0;
			 }
		  }


		  }
		  if(gamer.health<=0)
		  {

			 cout<<endl<<endl<<endl<<'\t'<<'\t'<<'\t'<<"Well played, but GAME OVER!!!!";
			 exit(0);
		  }
		  else
		  { clrscr();
			 cout<<'\t'<<'\t'<<'\t'<<"Well done, Krrish.B has been beaten!! "<<endl<<endl;
			 cout<<'\t'<<'\t'<<'\t'<<"Well done, you have earned 50 coins!!"<<endl<<endl;
			 cout<<"Press anything to continue ";
			 getch();
			 gamer.coins+=50;
			 inventory();
		  }

		  break;

		case 2:
		{
		  cout<<"The battle with Jim Shauryarty begins!!!"<<'\n';
		  JimShauryarty.health = 100;
		  gamer.health = 100;
			turn = 0;
		  cout<<"Jim is smarter than you are, he goes first!"<<'\n';
				while(gamer.health>0 && JimShauryarty.health>0)
					{ if(turn == 0)
						{
							cout<<"Rival stats :-"<<'\n'<<"Health "<<JimShauryarty.health<<'\n';
							H(JimShauryarty.health);
							cout<<'\n'<<setw(30)<<" "<<"Your stats :-"<<'\n'<<setw(30)<<" "<<"Health "<<gamer.health<<'\n'<<'\n';
							H(gamer.health,1);
							gamer.health-=random(35-15+1)+15;
							turn=1;
						}
					 else
					  {
						wait(0.0001)
						cout<<"It's Jim's turn to attack!"<<endl<<'\n';
						cout<<"Rival stats :-"<<'\n'<<"Health "<<JimShauryarty.health<<'\n';
						H(JimShauryarty.health);
						cout<<'\n'<<setw(30)<<" "<<"Your stats :-"<<'\n'<<setw(30)<<" "<<"Health "<<gamer.health<<'\n';
						H(gamer.health,1);
						cout<<setw(30)<<" "<<"It is your turn to attack!"<<'\n'<<'\n';
						do
						  {
							f=0;
							cout<<setw(30)<<" "<<"Choose your attacking weapon"<<'\n';
							cout<<setw(30)<<" "<<"1. Wooden Sword  2. Dagger   3. Flamethrower ";
							cin>>attack_choice;
							switch(attack_choice)
							{
								 case '1':
								{  clrscr();
									cout<<"Attack successful"<<endl;
									JimShauryarty.health-=random(15-1+1)+1;
									cout<<"Jim has "<<JimShauryarty.health<<" health remaining!"<<'\n';
									turn=1;
									 break;

								}
								  case '2':
								{
									 if(t==2 || t==3)
										{
											clrscr();
											cout<<"Attack successful"<<endl;
											JimShauryarty.health-=random(25-10+1)+10;
											cout<<"Jim has "<<JimShauryarty.health<<" health remaining!"<<'\n';
											turn=1;

										}
									else
										{
											cout<<"You have not yet bought this weapon,please re-enter weapon choice ";
											f=1;
										}
									break;
								}
								 case '3':
								{
									if(t==4 || t==3)
									 {
											clrscr();
											cout<<"Attack successful!"<<endl;
											JimShauryarty.health-=random(30-20+1)+20;
											cout<<"Jim has "<<JimShauryarty.health<<" health remaining!"<<'\n';

											 turn=1;

									 }
									else
									 {
											 cout<<"You have not yet bought this weapon,please re-enter weapon choice ";
											 f=1;
									 }
								 break;
								}
								default:f=1;
						}
						}while(f==1);
						turn=0;
					}

					 if(gamer.health<=0)
					 {
						clrscr();
						cout<<setw(15)<<'\t'<<'\t'<<'\t'<<"Well played, but GAME OVER!!!!";
						exit(0);

					 }
					 else
					 if(JimShauryarty.health<=0)
					 {
					  clrscr();
					  cout<<'\t'<<'\t'<<'\t'<<"Well done, Jim Shauryarty has been beaten!!"<<endl<<endl;
					  cout<<'\t'<<'\t'<<'\t'<<"Well done, you have earned 200 coins"<<endl;
					  cout<<"Press anything to continue ";
					  getch();
					  gamer.coins+=200;
					  inventory();
					 }





			 }

		}
		break;


		case 3:
		{

		  cout<<"The battle with MeghnaMind begins!!!"<<'\n';
		  meghnamind.health = 150;
		  gamer.health = 100;
			turn = 0;
			attack_choice;
		  while(gamer.health>0 && meghnamind.health>0)
		  {
			 if(turn == 0)
			 {
					wait(0.0001)
					clrscr();
			 cout<<"Rival stats :-"<<'\n'<<endl<<"Health "<<meghnamind.health<<'\n'<<'\n';
			 H(meghnamind.health);
				cout<<endl<<setw(30)<<" "<<"Your stats :-"<<'\n'<<setw(30)<<" "<<"Health "<<gamer.health<<'\n'<<'\n';
				H(gamer.health,1);
				cout<<endl<<setw(30)<<" "<<"It is your turn to attack!"<<'\n';
				do
				{f=0;
				cout<<setw(30)<<" "<<"Choose your attacking weapon"<<'\n';
				cout<<setw(30)<<" "<<"1. Wooden Sword  2. Dagger   3. Flamethrower ";
				cin>>attack_choice;
				switch(attack_choice)
				{
				  case '1':
				  {
					  cout<<"Attack successful"<<endl;
					  meghnamind.health-=random(15-1+1)+1;
					  cout<<"MeghnaMind has "<<meghnamind.health<<" health remaining!"<<'\n';
					  turn=1;
					  break;

				  }
				  case '2':
				  {
					 if(t==2 || t==3)
					 {

					  cout<<"Attack successful"<<endl;
					  meghnamind.health-=random(25-10+1)+10;
					  cout<<"MeghnaMind has "<<meghnamind.health<<" health remaining!"<<'\n';
					  turn=1;

					 }
					 else
					 {
						cout<<"You have not yet bought this weapon,please re-enter weapon choice ";
						f=1;
					 }
					 break;
				  }
				  case '3':
				  {
					if(t==4 || t==3)
					 {

					  cout<<"Attack successful"<<endl;
					  meghnamind.health-=random(30-20+1)+20;
					  cout<<"MeghnaMind has "<<meghnamind.health<<" health remaining!"<<'\n';
					  turn=1;

					 }
					 else
					 {
					  cout<<"You have not yet bought this weapon,please re-enter weapon choice ";
						f=1;
					 }
					 break;
				  }
				  default:f=1;

				}
				}while(f==1);
				turn = 1;

			 }
			 else
			 {
				cout<<"Rival stats :-"<<'\n'<<endl<<"Health "<<meghnamind.health<<'\n'<<endl<<'\n';
				H(meghnamind.health);
				cout<<endl<<setw(30)<<" "<<"Your stats :-"<<'\n'<<setw(30)<<" "<<"Health "<<gamer.health<<'\n'<<'\n';
				H(gamer.health,1);
				cout<<"It is MeghnaMind's turn to attack!"<<'\n'<<endl;

				gamer.health-=random(7-1+1)+1;
				turn = 0;
			 }
			 if(gamer.health<=0)
		  {  clrscr();
			 cout<<'\t'<<'\t'<<'\t'<<"Well played, but GAME OVER!!!!";
			 exit(0);
		  }
		  else
		  if(meghnamind.health<=0)
		  { clrscr();
			 cout<<'\t'<<'\t'<<'\t'<<"Well done, MeghnaMind has been beaten!! "<<endl<<endl;
			 cout<<'\t'<<'\t'<<'\t'<<"Well done, you have earned 100 coins!!";
			 cout<<endl<<endl<<"Press anything to continue ";
			 getch();
			 gamer.coins+=100;
			 inventory();
		  }


		  }
		  break;
		}









		case 4:
		{

		  cout<<"The battle with Shreyk begins!!!"<<'\n';
		  shreyk.health = 100;
		  gamer.health = 100;
			turn = 0;
			attack_choice;
		  while(gamer.health>0 && shreyk.health>0)
		  {
			 if(turn == 0)
			 {

				wait(0.0001)
				clrscr();
			  cout<<"Rival stats :-"<<'\n'<<endl<<"Health "<<shreyk.health<<'\n'<<'\n';
			  H(shreyk.health);
				cout<<'\n'<<" "<<"Your stats :-"<<'\n'<<setw(30)<<" "<<"Health "<<gamer.health<<'\n';
				H(gamer.health,1);
				cout<<endl<<setw(30)<<" "<<"It is your turn to attack!"<<'\n';
				do
				{f=0;
				cout<<setw(30)<<" "<<"Choose your attacking weapon"<<'\n';
				cout<<setw(30)<<" "<<"1. Wooden Sword  2. Dagger   3. Flamethrower ";
				cin>>attack_choice;
				switch(attack_choice)
				{
				  case '1':
				  {
					  cout<<"Attack successful"<<endl;
					  shreyk.health-=random(20-1+1)+1;
					  cout<<"Shreyk has "<<shreyk.health<<" health remaining!"<<'\n';
					  turn=1;
					  break;

				  }
				  case '2':
				  {
					 if(t==2 || t==3)
					 {
					  clrscr();
					  cout<<"Attack successful"<<endl;
					  shreyk.health-=random(30-10+1)+10;
					  cout<<"Shreyk has "<<shreyk.health<<" health remaining!"<<'\n';
					  turn=1;

					 }
					 else
					 {
						cout<<"You have not yet bought this weapon,please re-enter weapon choice ";
						f=1;
					 }
					 break;
				  }
				  case '3':
				  {
					if(t==4 || t==3)
					 {
					  clrscr();
					  cout<<"Attack successful"<<endl;
					  shreyk.health-=random(35-15+1)+20;
					  cout<<"Shreyk has "<<shreyk.health<<" health remaining!"<<'\n'<<endl;
					  turn=1;

					 }
					 else
					 {
					  cout<<"You have not yet bought this weapon,please re-enter weapon choice ";
						f=1;
					 }
					 break;
				  }
				 default:f=1;

				}
				}while(f==1);
				turn = 1;

			 }
			 else
			 {
				cout<<"Rival stats :-"<<'\n'<<"Health "<<shreyk.health<<'\n'<<'\n';
				H(shreyk.health);
				cout<<setw(30)<<" "<<"Your stats :-"<<'\n'<<setw(30)<<'\t'<<" Health "<<gamer.health<<'\n'<<'\n';
				H(gamer.health,1);
				cout<<endl<<"It is Shreyk's turn to attack!"<<'\n';

				gamer.health-=random(30-10+1)+10;
				turn = 0;
			 }
			 if(gamer.health<=0)
		  {  clrscr();
			 cout<<'\t'<<'\t'<<'\t'<<"Well played, but GAME OVER!!!!";
			 cout<<"Press anything to continue ";
			 getch();
			 exit(0);
		  }
		  else
		  if(shreyk.health<=0)
		  {
			 cout<<'\t'<<'\t'<<'\t'<<"Well done, Shreyk has been beaten!! "<<endl<<endl;
			 cout<<'\t'<<'\t'<<'\t'<<"Well done, you have earned 150 coins!!";
			 cout<<endl<<endl<<"Press anything to continue ";
			 getch();
			 gamer.coins+=150;
			 inventory();

		  }
		  }
		  break;
		}

	 }
}




void print(int m, int n)
{

	map[m][n]=toupper(gamer.name[0]);
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<73;j++)
		cout<<map[i][j];          //design of map area
		map[3][4] = '_';map[3][5] = '_';map[3][6] = '_';map[3][7] = '_';map[3][8] = '_';map[3][9] = '_';map[3][10] = '_';map[3][11] = '_';
		map[4][4] = '|';map[4][5] = ' ';map[4][6] = 'M';map[4][7] = 'a';map[4][8] = 'r';map[4][9] = 't';map[4][10] = ' ';map[4][11] = '|';
		map[5][4] = '|';map[5][5] = ' ';map[5][6] = ' ';map[5][7] = '_';map[5][8] = '_';map[5][9] = ' ';map[5][10] = ' ';map[5][11] = '|';
		map[6][4] = '|';map[6][5] = ' ';map[6][6] = '|';map[6][7] = ' ';map[6][8] = ' ';map[6][9] = '|';map[6][10] = ' ';map[6][11] = '|';
		map[8][14] = '/';map[7][15] = '_';map[7][16] = '_';map[7][17] = '_';map[8][18] = '\\';    //houses
		map[8][15] = '_';map[8][16] = '_';map[8][17] = '_';
		map[9][14] = '|';map[9][15] = ' ';map[9][16] = 'O';map[9][17] = ' ';map[9][18] = '|'; //center left house



		map[3][26] = '/';map[2][27] = '_';map[2][28] = '_';;map[2][29] = '_';map[3][30] = '\\';
		map[3][27] = '_';map[3][28] = '_';map[3][29] = '_';
		map[4][26] = '|';map[4][27] = ' ';map[4][28] = 'O';map[9][19] = ' ';map[2][29] = ' ';map[4][30] = '|';  //top center left house

		map[15][31] = '*';map[15][32] = '*';
		map[16][31] = '^';map[16][32] = '^';
		map[17][30] = '^';map[17][31] = '^';map[17][32] = '^';map[17][33] = '^';    //bottom tree
		map[18][30] = '^';map[18][31] = '|';map[18][32] = '|';map[18][33] = '^';
map[7][41] = '*';map[7][42] = '*';
		map[8][41] = '^';map[8][42] = '^';
		map[9][40] = '^';map[9][41] = '^';map[9][42] = '^';map[9][43] = '^';    //center tree
		map[10][40] = '^';map[10][41] = '|';map[10][42] = '|';map[10][43] = '^';





		map[15][40] = '/';map[14][41] = '_';map[14][42] = '_';map[14][43] = '_';map[15][44] = '\\';
		map[15][41] = '_';map[15][42] = '_';map[15][43] = '_';
		map[16][40] = '|';map[16][41] = ' ';map[16][42] = 'O';map[16][43] = ' ';map[16][44] = '|';  //bottom center house



		map[10][51] = '*';map[10][52] = '*';
		map[11][51] = '^';map[11][52] = '^';
		map[12][50] = '^';map[12][51] = '^';map[12][52] = '^';map[12][53] = '^';    //right upper to house tree
		map[13][50] = '^';map[13][51] = '|';map[13][52] = '|';map[13][53] = '^';
map[3][62] = '_';map[3][63] = '_';                                                                //right most bush
		map[4][61] = '(';map[4][64] = ')';
		map[5][60] = '(';map[5][61] = ' ';map[5][62] = '|';map[5][63] = '|';map[5][64] = ' ';map[5][65] = ')';


		map[12][14] = '_';map[12][15] = '_';                                                                //bottom bush
		map[13][13] = '(';map[13][16] = ')';
		map[14][12] = '(';map[14][13] = ' ';map[14][14] = '|';map[14][15] = '|';map[14][16] = ' ';map[14][17] = ')';





		map[18][60] = '/';map[17][61] = '_';map[17][62] = '_';map[17][63] = '_';map[18][64] = '\\';
		map[18][61] = '_';map[18][62] = '_';map[18][63] = '_';
		map[19][60] = '|';map[19][61] = ' ';map[19][62] = 'O';map[19][63] = ' ';map[19][64] = '|';  //bottom right house

map[16][3] = '*';map[16][4] = '*';
		map[17][3] = '^';map[17][4] = '^';
		map[18][2] = '^';map[18][3] = '^';map[18][4] = '^';map[18][5] = '^';    //bottom left tree
		map[19][2] = '^';map[19][3] = '|';map[19][4] = '|';map[19][5] = '^';

		cout<<'\n';
		//if(j/4==1||i/6==1){
		//battle();
		//}
	}
	map[m][n]=' ';


}
void main()

{



 int rival_choice;
 cout<<endl<<endl<<endl<<endl<<endl<<endl<<"                                  A GAME OF PUNS                 "<<endl<<endl;
 wait(0.0003);
 cout<<" In this game, one must defeat creatures and earn coins to progress ";
 cout<<endl;
 cout<<" By using the inventory, upgrade to a new weapon and defeat them monsters"<<endl;
 cout<<endl<<"                                   Good Luck!                  "<<endl;
 cout<<endl<<endl<<"Press anything to continue ";
 getch();
 clrscr();
 cout<<"Enter user name ";
 gets(gamer.name);
 gamer.coins=50;
 cout<<'\t'<<'\t'<<'\t'<<"Game starts with  "<<gamer.coins<<" coins in your bag "<<endl;
 cout<<'\t'<<'\t'<<'\t'<<"Here is your inventory "<<endl;
 display();
 cout<<endl<<"Press anything to continue ";
 getch();
 clrscr();
 for(long j=0.0001;j<10000000;j++);
 cout<<endl<<endl<<endl<<endl<<endl<<endl<<"You will now be taken to the map, use standard w,a,s,d control to navigate!!";
 cout<<endl<<endl<<"Press anything to continue ";
 getch();
 clrscr();
 do
 {

		int x=0,y=0;
	while(1)
	{

		if(y==20)y=0;
		if(x==73)x=0;
		if(x==-1)x=72;
		if(y==-1)y=19;
		print(y,x);
		if(y==6&&(x==7||x==8))
		inventory();
		char ch=getch();
		clrscr();



		if((random(10-1+1)+1)==7)
		{
		clrscr();
		randomize();

	   battle(rand()%4);
		}

		switch(ch)
		{
			case 'w':y--;break;
			case 'a':x--;break;
			case 's':y++;break;
			case 'd':x++;break;
		}


	}

 }while(gamer.health>0);


}
