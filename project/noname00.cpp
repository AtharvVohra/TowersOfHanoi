#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <iomanip.h>
#include <process.h>

int t = 1;

struct enemy
{
  int health;
  char name[20];
}krrish,meghnamind,shreyk,JimShauryarty;

struct user
{
 char name[20];
 float coins;
 int health;
 int level;
}gamer;



void display()
{
 cout<<"Your inventory:-"<<endl;
 cout<<"Weapons:-"<<endl;
 cout<<endl<<" ID          WEAPON           COST"<<endl;
 cout<<endl<<" D           DAGGER            150"<<endl;
 cout<<endl<<" F           FLAMETHROWER      350"<<endl;
 cout<<endl<<endl<<"Coins in the bag = "<<gamer.coins;
 cout<<endl;
}



void inventory()
{ clrscr();
 int ch;
 char id;
  do
 {
  cout<<"Your inventory:-"<<endl;
  cout<<"Weapons:-"<<endl;
  cout<<endl<<" ID           WEAPON           COST"<<endl;
  cout<<endl<<"  D           DAGGER            150"<<endl;
  cout<<endl<<"  F           FLAMETHROWER      350"<<endl;
  cout<<endl<<endl<<"Coins in the bag = "<<gamer.coins;
  cout<<endl<<"OPTIONS ;-"<<endl;
  cout<<"1. Buy"<<endl<<"2. Leave inventory ";
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
  cout<<"Sword bought, Congrats!! ";
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
}


void battle(int choice)
{    int turn,attack_choice;
	 switch(choice)
	 {
		case 1:
		{
		  cout<<"The battle with Krrish.B begins!!!"<<'\n';
		  krrish.health = 50;
		  gamer.health = 100;
			turn = 0;
			attack_choice;
		  while(gamer.health>0 && krrish.health>0)
		  {
			 if(turn == 0)
			 {	clrscr();
				cout<<"Rival stats :-"<<'\n'<<"Health "<<krrish.health<<'\n'<<'\n';

				cout<<'\n'<<setw(30)<<" "<<"Your stats :-"<<'\n'<<setw(30)<<" "<<"Health "<<gamer.health<<'\n'<<'\n';
				cout<<setw(30)<<" "<<"It is your turn to attack!"<<'\n';
				choose:
				cout<<setw(30)<<" "<<"Choose your attacking weapon"<<'\n';
				cout<<setw(30)<<" "<<"1. Wooden Sword  2. Dagger   3. Flamethrower ";
				cin>>attack_choice;
				switch(attack_choice)
				{
				  case 1:
				  {  clrscr();
					  cout<<"Attack successful!"<<endl;
					  krrish.health-=random(15-1+1)+1;
					  cout<<"Krrish has "<<krrish.health<<" health remaining!"<<'\n';
					  turn=1;
					  break;

				  }
				  case 2:
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
						goto choose;
					 }
					 break;
				  }
				  case 3:
				  {
					if(t==4 || t==3)
					 {
					  clrscr();
					  cout<<"Attack successful!"<<endl;
					  krrish.health-=random(30-20+1)+20;
					  cout<<"Krrish has "<<krrish.health<<" health remaining!"<<'\n';
					  turn=1;

					 }
					 else
					 {
					  cout<<"You have not yet bought this weapon,please re-enter weapon choice ";
						goto choose;
					 }
					 break;
				  }
				}
				turn = 1;

			 }
			 else
			 {

				cout<<"Rival stats :-"<<'\n'<<"Health "<<krrish.health<<'\n'<<'\n';
				cout<<'\n'<<setw(30)<<" "<<"Your stats :-"<<'\n'<<setw(30)<<" "<<"Health "<<gamer.health<<'\n'<<'\n'<<endl;
				cout<<"It is Krrish.B's turn to attack!"<<'\n';

				gamer.health-=random(20-1+1)+1;
				turn = 0;
			 }
		  }


		  }
		  if(gamer.health<=0)
		  { clrscr();

			 cout<<setw(15)<<"Well played, but GAME OVER!!!!";
			 exit(0);
		  }
		  else
		  { clrscr();
			 cout<<setw(15)<<"Well done, Krrish.B has been beaten!! "<<endl<<endl;
			 cout<<"Well done, you have earned 50 coins!!";
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
			attack_choice;
		  cout<<"Jim is smarter than you are, he goes first!"<<'\n';
		  while(gamer.health>0 && JimShauryarty.health>0)
		  { if(turn == 0)
			 {
				cout<<"Rival stats :-"<<'\n'<<"Health "<<JimShauryarty.health<<'\n'<<'\n';
				cout<<'\n'<<setw(30)<<" "<<"Your stats :-"<<'\n'<<setw(30)<<" "<<"Health "<<gamer.health<<'\n'<<'\n';
				gamer.health-=random(40-15+1)+15;
				turn=1;
			 }
			 else
			 { cout<<"It's Jim's turn to attack!"<<endl<<'\n';
				cout<<"Rival stats :-"<<'\n'<<"Health "<<JimShauryarty.health<<'\n';
				cout<<'\n'<<setw(30)<<" "<<"Your stats :-"<<'\n'<<setw(30)<<" "<<"Health "<<gamer.health<<'\n'<<'\n';
				cout<<setw(30)<<" "<<"It is your turn to attack!"<<'\n'<<'\n';
				choose2:
				cout<<setw(30)<<" "<<"Choose your attacking weapon"<<'\n';
				cout<<setw(30)<<" "<<"1. Wooden Sword  2. Dagger   3. Flamethrower ";
				cin>>attack_choice;
				switch(attack_choice)
				{
				  case 1:
				  {  clrscr();
					  cout<<"Attack successful"<<endl;
					  JimShauryarty.health-=random(15-1+1)+1;
					  cout<<"Jim has "<<JimShauryarty.health<<" health remaining!"<<'\n';
					  turn=1;
					  break;

				  }
				  case 2:
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
						goto choose2;
					 }
					 break;
				  }
				  case 3:
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
						goto choose2;
					 }
					 if(gamer.health<=0)
					 {
						clrscr();
						cout<<setw(15)<<"Well played, but GAME OVER!!!!";
						exit(0);

					 }
					 else
					 if(JimShauryarty.health<=0)
					 {
					  clrscr();
					  cout<<setw(15)<<"Well done, Jim Shauryarty has been beaten!!"<<endl<<endl;
					  cout<<"Well done, you have earned 200 coins";
					  cout<<"Press anything to continue ";
					  getch();
					  gamer.coins+=200;
					  inventory();
					 }

					 break;
				  }
				}
				turn = 0;
			 }

		}
		break;









		case 3:
		{ clrscr();
		  cout<<"The battle with MeghnaMind begins!!!"<<'\n';
		  meghnamind.health = 150;
		  gamer.health = 100;
			turn = 0;
			attack_choice;
		  while(gamer.health>0 && meghnamind.health>0)
		  {
			 if(turn == 0)
			 {clrscr();
			 cout<<"Rival stats :-"<<'\n'<<"Health "<<meghnamind.health<<'\n'<<'\n';
				cout<<'\n'<<setw(30)<<" "<<"Your stats :-"<<'\n'<<setw(30)<<" "<<"Health "<<gamer.health<<'\n'<<'\n';
				cout<<setw(30)<<" "<<"It is your turn to attack!"<<'\n';
				choose3:
				cout<<setw(30)<<" "<<"Choose your attacking weapon"<<'\n';
				cout<<setw(30)<<" "<<"1. Wooden Sword  2. Dagger   3. Flamethrower ";
				cin>>attack_choice;
				switch(attack_choice)
				{
				  case 1:
				  {
					  cout<<"Attack successful"<<endl;
					  meghnamind.health-=random(15-1+1)+1;
					  cout<<"MeghnaMind has "<<meghnamind.health<<" health remaining!"<<'\n';
					  turn=1;
					  break;

				  }
				  case 2:
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
						goto choose3;
					 }
					 break;
				  }
				  case 3:
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
						goto choose3;
					 }
					 break;
				  }


				}
				turn = 1;

			 }
			 else
			 { clrscr();
				cout<<"Rival stats :-"<<'\n'<<"Health "<<meghnamind.health<<'\n'<<endl<<'\n';
				cout<<'\n'<<setw(30)<<" "<<"Your stats :-"<<'\n'<<setw(30)<<" "<<"Health "<<gamer.health<<'\n'<<'\n'<<endl;
				cout<<"It is MeghnaMind's turn to attack!"<<'\n'<<endl;

				gamer.health-=random(10-1+1)+1;
				turn = 0;
			 }
			 if(gamer.health<=0)
		  {  clrscr();
			 cout<<setw(15)<<"Well played, but GAME OVER!!!!";
			 exit(0);
		  }
		  else
		  if(meghnamind.health<=0)
		  { clrscr();
			 cout<<"Well done, MeghnaMind has been beaten!! "<<endl<<endl;
			 cout<<"Well done, you have earned 100 coins!!";
			 cout<<endl<<"Press anything to continue ";
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
			 { clrscr();
			  cout<<"Rival stats :-"<<'\n'<<"Health "<<shreyk.health<<'\n'<<'\n';
				cout<<'\n'<<setw(30)<<" "<<"Your stats :-"<<'\n'<<setw(30)<<" "<<"Health "<<gamer.health<<'\n'<<'\n';
				cout<<setw(30)<<" "<<"It is your turn to attack!"<<'\n';
				choose4:
				cout<<setw(30)<<" "<<"Choose your attacking weapon"<<'\n';
				cout<<setw(30)<<" "<<"1. Wooden Sword  2. Dagger   3. Flamethrower ";
				cin>>attack_choice;
				switch(attack_choice)
				{
				  case 1:
				  {  clrscr();
					  cout<<"Attack successful"<<endl;
					  shreyk.health-=random(15-1+1)+1;
					  cout<<"Shreyk has "<<shreyk.health<<" health remaining!"<<'\n';
					  turn=1;
					  break;

				  }
				  case 2:
				  {
					 if(t==2 || t==3)
					 {
					  clrscr();
					  cout<<"Attack successful"<<endl;
					  shreyk.health-=random(25-10+1)+10;
					  cout<<"Shreyk has "<<shreyk.health<<" health remaining!"<<'\n';
					  turn=1;

					 }
					 else
					 {
						cout<<"You have not yet bought this weapon,please re-enter weapon choice ";
						goto choose4;
					 }
					 break;
				  }
				  case 3:
				  {
					if(t==4 || t==3)
					 {
					  clrscr();
					  cout<<"Attack successful"<<endl;
					  shreyk.health-=random(30-20+1)+20;
					  cout<<"Shreyk has "<<shreyk.health<<" health remaining!"<<'\n'<<endl;
					  turn=1;

					 }
					 else
					 {
					  cout<<"You have not yet bought this weapon,please re-enter weapon choice ";
						goto choose4;
					 }
					 break;
				  }


				}
				turn = 1;

			 }
			 else
			 { clrscr();
				cout<<"Rival stats :-"<<'\n'<<"Health "<<shreyk.health<<'\n'<<'\n';
				cout<<'\n'<<setw(30)<<" "<<"Your stats :-"<<'\n'<<"Health "<<gamer.health<<'\n'<<'\n';
				cout<<"It is Shrey's turn to attack!"<<'\n';

				gamer.health-=random(30-10+1)+10;
				turn = 0;
			 }
			 if(gamer.health<=0)
		  {  clrscr();
			 cout<<setw(15)<<"Well played, but GAME OVER!!!!";
			 exit(0);
		  }
		  else
		  if(shreyk.health<=0)
		  {
			 cout<<"Well done, Shreyk has been beaten!! "<<endl<<endl;
			 cout<<"Well done, you have earned 150 coins!!";
			 cout<<endl<<"Press anything to continue ";
			 getch();
			 gamer.coins+=150;
			 inventory();

		  }
		  }
		  break;
		}

	 }
}
}




void main()
{

 int rival_choice;
 cout<<"                                  THRIVE TO SURVIVE                 "<<endl<<endl;
 cout<<" In this game, one must defeat creatures and earn coins to progress ";
 cout<<endl;
 cout<<" By using the inventory, upgrade to a new weapon and defeat them monsters"<<endl;
 cout<<endl<<"                                   Good Luck!                  "<<endl;
 cout<<endl<<"Press anything to continue ";
 getch();
 clrscr();
 cout<<"Enter user name ";
 gets(gamer.name);
 gamer.coins=50;
 cout<<"Game starts with you having "<<gamer.coins<<" coins "<<endl;
 cout<<"Here is your inventory "<<endl;
 display();
 cout<<"Press anything to continue ";
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

  //cout<<"Here are your fellow rivals :-"<<'\n'<<"1. Krrish.B   2. Jim Shauryarty   3. MeghnaMind   4. Shreyk";
  //cout<<endl<<"Enter the number of the rival you want to face --> ";
  //cin>>rival_choice;
  //cout<<'\n';
  //clrscr();
  //battle(rival_choice);
 }while(gamer.health>0);
}