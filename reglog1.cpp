#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include "usermgnt.cpp"
#include "button.cpp"


void display()// function to display title and instructions
{

	gotoxy(1,1); cout<<"________________________________________________________________________________";

	gotoxy(1,3); cout<<"                              1UP - THE GAME STORE";
	gotoxy(1,4); cout<<"________________________________________________________________________________\n";

	gotoxy(15,24);cout<<"Use W,A,S,D keys to navigate. Use SPACEBAR to select.";

}// end of display



void delay(long time)// function to provide delay in loading screen
{
 clock_t start=clock();
 while(clock()-start<time);
}// end of delay


char pwd[30];//global array

void input_pwd()//function to convert letters typed in as password by the user to '*'
{
  for(int i=0;;i++)
  {
	 pwd[i]=getch();
	 if(pwd[i]!='\r')
		cout<<"*";
	 if(pwd[i]=='\r')
		break;
	 if(pwd[i]==8 )
	 {
		 cout<<"\b\b";
		 i-=2;
	 }
  }
  pwd[i]='\0';

} // end of input_pwd



class reg_screen
{
	 public:



	 int add_details()// function to accept details of new user
{
	char pass[30], re_pass[30];
	usermgnt u_r;
	display();

	button b[2];

	strcpy(b[0].button_name,"SIGN UP"); b[0].b_x=30; b[0].b_y=22;

	strcpy(b[1].button_name,"BACK"); b[1].b_x=50; b[1].b_y=22;

	int ptr=0;

	gotoxy(30,22); cout<<"SIGN UP";
	gotoxy(50,22); cout<<"BACK";


	gotoxy(16,6);  cout<<"User name             : ";

	gotoxy(16,8);  cout<<"Email id              : ";

	gotoxy(16,10); cout<<"Password              : ";

	gotoxy(16,12); cout<<"Re-enter password     : ";


	gotoxy(40,6); gets(u_r.u_name);

	gotoxy(40,8); gets(u_r.email);

	gotoxy(40,10); gets(pass);

	gotoxy(40,12); gets(re_pass);



	options:

	pointer_movement(b,2,ptr);

	if(ptr==0)
	{

		if(u_r.check_uname())
		{
			gotoxy(1,22); clreol();

			gotoxy(30,22); cout<<"SIGN UP";
			gotoxy(50,22); cout<<"BACK";

			gotoxy(16,7);

			cout<<"User name already in use !";

			getch();
			gotoxy(16,7); clreol();
			gotoxy(40,6); clreol();

			gotoxy(40,6);	gets(u_r.u_name);

			goto options;


		}

		else if(strlen(pass)<=5)
		{
			gotoxy(1,22); clreol();

			gotoxy(30,22); cout<<"SIGN UP";
			gotoxy(50,22); cout<<"BACK";



			gotoxy(16,11);  cout<<"Password has to be more than 5 characters!";

			getch();

			gotoxy(16,11);  clreol();

			gotoxy(40,10);  clreol();

			gotoxy(40,10); gets(pass);

			gotoxy(40,12);  clreol();

			gotoxy(40,12); gets(re_pass);

			goto options;

		}

		else if(strcmpi(pass,re_pass)!=0)
		{
			gotoxy(1,22); clreol();

			gotoxy(30,22); cout<<"SIGN UP";
			gotoxy(50,22); cout<<"BACK";



			gotoxy(16,13);  cout<<"Re-enter password correctly!";

			getch();

			gotoxy(16,13);  clreol();

			gotoxy(40,12);  clreol();

			gotoxy(40,12); gets(re_pass);

			goto options;

		}


		strcpy(u_r.password,pass);


		fstream f;

		f.open("users.dat",ios::app|ios::binary);

		f.write((char*)&u_r,sizeof(u_r));

		f.close();

		clrscr();

		return 0;


	}

	else if(ptr==1)
	{
		clrscr();
		return 1  ;
	}


}// end of add_details

}; // end of class reg_screen




class log_screen
{
	 public:

	 int check_details()// function to check username and password
	{

			usermgnt u_l;


			display();

			button b[2];

			strcpy(b[0].button_name,"LOGIN"); b[0].b_x=30; b[0].b_y=20;

			strcpy(b[1].button_name,"BACK"); b[1].b_x=50; b[1].b_y=20;

			int ptr=0;

			gotoxy(30,20); cout<<"LOGIN";
			gotoxy(50,20); cout<<"BACK";


			gotoxy(16,6); cout<<"User name             : ";


			gotoxy(16,10); cout<<"Password              : ";


			gotoxy(40,6); gets(u_l.u_name);

			gotoxy(40,10); input_pwd(); strcpy(u_l.password,pwd);

			options:

			pointer_movement(b,2,ptr);

			if(ptr==0)
			{

				if(!(u_l.check_password()))
				{
					gotoxy(1,20);  clreol();
					gotoxy(30,20); cout<<"LOGIN";
					gotoxy(50,20); cout<<"BACK";

					gotoxy(16,13);

					cout<<"ENTER CORRECT DETAILS !";

					getch();
					gotoxy(16,13); clreol();
					gotoxy(40,6); clreol();
					gotoxy(40,10); clreol();

					gotoxy(40,6);	gets(u_l.u_name);
					gotoxy(40,10); input_pwd(); strcpy(u_l.password,pwd);
					goto options;


				}

				clrscr();

				return 0;


			}

			else if(ptr==1)
			{
				clrscr();
				return 1;
			}


	}// end of check_details



}; // end of class log_screen








class Games
{
	char p_code[8];
	char name[35];
	float price[3];
	char genre[22];
	int mode; // has to be 1 or 2
	int maxlen;
	int select;




	public:

	//constructor
	Games()
	{
		strcpy(p_code,"\0");
		strcpy(name,"\0");
		price[0]= price[1]=price[2]=0;
		strcpy(genre,"\0");
		mode=0;
		maxlen=0;
		select=0;
	}


	void gname_output(Games g) // function to display name and platform game is available in
	{
	 cout<<g.name<<" (";
	 if(g.price[0])
	  cout<<"PS4, ";
	 if(g.price[1])
	  cout<<"Xbox One, ";
	 if(g.price[2])
	  cout<<"PC, ";
	cout<<"\b\b";
	  cout<<")";
		cout<<endl;

	}// end of gname_output


	int purchase() // function to display order confirmation
	{
		clrscr();
		display();
		gotoxy(32,5);cout<<"Processing...";
		gotoxy(12,7);cout<<"[";
		gotoxy(64,7);cout<<"]";
		for(int i=13,j=0;i<65;i++)
		{
			delay(100);
			gotoxy(i,7);cout<<"|";
		}

		gotoxy(64,7);cout<<"]";

		gotoxy(27,5);clreol();
		gotoxy(32,5);cout<<"Order Confirmed";

		button b[2];
		strcpy(b[0].button_name,"CONTINUE SHOPPING"); b[0].b_x=20; b[0].b_y=22;
		strcpy(b[1].button_name,"EXIT"); b[1].b_x=55; b[1].b_y=22;

		int ptr=0;

		pointer_movement(b,2,ptr);

		if(ptr==1)
		{
			clrscr();

			gotoxy(29,10);cout<<"THANK YOU FOR SHOPPING";
			gotoxy(34,12);cout<<"AT 1UP GAMES";
			gotoxy(30,14);cout<<"PLEASE VISIT US AGAIN";
			getch();
			exit(0);
		}
		return ptr;

	}// end of purchase



	int checkout(Games g,float pr, int a) // function to accept details and display MY CART
	{

		char pform[10]="\0";
		char str2[15]="\0";
		int day=0;
		int no=0;
		long int pincode=0;
		char city[20]="\0";
		float qty=0;


		clrscr();

		display();

		//accepting details

		gotoxy(10,7);
		cout<<"Enter pincode  : "<<endl;
		A:
		display();
		gotoxy(27,7);
		cin>>pincode;

		if(pincode%7==0)//pincode condition
		{
			gotoxy(37,7);
			cout<<"Cannot be delivered to this location";
			getch();
			gotoxy(27,7);clreol();
			goto A;
		}

		gotoxy(10,10);
		cout<<"Enter city     : "<<endl;
		gotoxy(27,10);
		gets(city);
		gotoxy(10,13);
		cout<<"Enter quantity : "<<endl;
		gotoxy(27,13);
		cin>>qty;


		clrscr();

		display();

		float total =0;
      // display of MY CART
		gotoxy(2,5);cout<<"MY CART";
		gotoxy(1,6);cout<<"_______________________________________________________________________________";
		gotoxy(2,7);cout<<"Item";
		gotoxy(32,7);cout<<"Qty";
		gotoxy(37,7);cout<<"Price";
		gotoxy(44,7);cout<<"Delivery Details";
		gotoxy(64,7);cout<<"SubTotal";
		gotoxy(1,9);cout<<"_______________________________________________________________________________";
		gotoxy(2,11);cout<<g.name;
		gotoxy(2,12);

		int ch=0;
		for(int i=0;i<3;i++)
		{
			if(g.price[i]!=0)
				if(ch==a)
				{
					if(i==0)
						strcpy(pform,"PS4");
					else if(i==1)
						strcpy(pform,"Xbox One");
					else if(i==2)
						strcpy(pform,"PC");
				}
				else
					ch++;
		}


	 cout<<pform<<" // "<<g.p_code;
	 gotoxy(2,13);cout<<"Seller : ";
    // condition for seller
	 if(strcmpi(pform,"PS4")==0)
		  strcpy(str2,"WSRetail");
	 else if(strcmpi(pform,"Xbox One")==0)
		  strcpy(str2,"Games4U");
	 else if(strcmpi(pform,"PC")==0)
		  strcpy(str2,"RetailNet");

	 cout<<str2;

	 randomize();

	 no=2+random(4);

	 gotoxy(2,14);cout<<"Eligible for ";
	 gotoxy(2,15);cout<<no<<" offers!!";
	 gotoxy(33,11);cout<<qty;
	 gotoxy(37,11);cout<<pr;
	 gotoxy(44,11);cout<<"Pincode : "<<pincode;
	 gotoxy(44,12);cout<<"City : "<<city;
	 gotoxy(44,13);cout<<"Will be delivered";

	 // delivery duration
	 day=2+random(5);

	 float tot;
	 tot=pr*qty;

	 gotoxy(44,14);cout<<"in "<<day<<" days";
	 gotoxy(64,11);cout<<tot;
	 gotoxy(64,12);cout<<"*Rs.50 delivery";
	 gotoxy(64,13);cout<<"charges present";
	 gotoxy(1,16);cout<<"_______________________________________________________________________________";
	 gotoxy(60,18);cout<<"Total : ";
	 total=tot+50;
	 cout<<total;
	 gotoxy(1,20);cout<<"_______________________________________________________________________________";

	 button b[2];

	 strcpy(b[0].button_name,"PURCHASE"); b[0].b_x=55; b[0].b_y=22;
	 strcpy(b[1].button_name,"BACK"); b[1].b_x=20; b[1].b_y=22;

	 int ptr=0;
	 int s;

	 pointer_movement(b,2,ptr);

	 if(ptr==0)
	 {
		s=purchase();
		if(s==0)
		{
			clrscr();
			display();
			return 8;
		}
	 }

	 else if(ptr==1)
	 {
		 clrscr();
		 display();
		 return 8;
	 }


}// end of checkout




	float ginfo_output(Games g) // function to display all details of game
	{
		clrscr();

		display();
		gotoxy(5,6);  cout<<g.name<<" ("<<g.p_code<<")";

		gotoxy(8,8);  cout<<"Genre:  "<<g.genre;

		gotoxy(42,8);cout<<"Mode: ";
		gotoxy(48,8);

		if(mode==1)
			cout<<"Single Player";
		else if(mode==2)
			cout<<"Multi-player";

		int s=10;

		if(g.price[0])
		{	gotoxy(8,s);  cout<<"PS4";  gotoxy(20,s); cout<<g.price[0]; s+=2;  }

		if(g.price[1])
		{	gotoxy(8,s);  cout<<"XBOX ONE";  gotoxy(20,s); cout<<g.price[1]; s+=2; }

		if(g.price[2])
		{	gotoxy(8,s);  cout<<"PC";  gotoxy(20,s); cout<<g.price[2]; s+=2; }


		button b[4];

		for(int i=0,j=0;i<3;i++)
		{
			if(g.price[i])
			{
				strcpy(b[j].button_name,"BUY");
				b[j].b_x=36;  b[j].b_y= 10 + (2*j);
				j++;
			}

		}

		strcpy(b[j].button_name,"BACK");   b[j].b_x=60;  b[j].b_y= 20;

		int ptr=0;

		pointer_movement(b,j+1,ptr);

		clrscr();
		display();
		int q;

		//selection of game

		if(ptr>=0&&ptr<j)
		{
			for(int v=0,u=0;v<3;v++)
			{
				if(g.price[v]!=0)
				{

					if(u==ptr)
					{
						q=checkout(g,g.price[v],ptr);
						return q;
					}
					u++;
				}
			}
		 }

		else return 8;


	}// end of ginfo_output




	int get_search_rank(char input[])//function to give maxlen value
	{
		int i = 0;
		int j = 0;
		int maxlen = 0;
		int name_len = strlen(name);
		int input_len = strlen(input);

		int match = 1;
		while(i <= (name_len - input_len) )
		{
			j=0;
			match = 1;
			while(j < input_len)
			{

				if(tolower(input[j]) != tolower(name[i+j]))
				{
					match = 0;
					break;
				}
				j++;
			}

			if ( j > maxlen)
			{
				maxlen = j;
			}
			if ( match)
			{

				maxlen = input_len;
				break;
			}
			i++;
		}
		return maxlen;

	}// end of get_search_rank



	void sort(char input[])// function to assign maxlen value and sort the top 5 search results based on maxlen
	{

		fstream f, f1;
		int max=0;
		char code[8];

		//copying details from main to search_list//

		f.open("slst.dat",ios::out|ios::binary);

		f1.open("glist.dat",ios::in|ios::out|ios::binary);

		Games g;
		 int pos = -1*sizeof(g);

		while(f1.read((char*)&g,sizeof(g)))
		{
			g.maxlen=g.get_search_rank(input);
			g.select=0;
			f1.seekp(pos,ios::cur);
			f1.write((char*)&g,sizeof(g));
		}

		f1.close();


		for( int i=0;i<5;i++)
		{
			max=0;

			f1.open("glist.dat",ios::in|ios::out|ios::binary);

			while(f1.read((char*)&g,sizeof(g)))
			{

				if((g.maxlen>=max)&&(g.select!=1))
				{
					max=g.maxlen;
					strcpy(code,g.p_code);
				}
			}

			f1.close();

			f1.open("glist.dat",ios::in|ios::out|ios::binary);

			while(f1.read((char*)&g,sizeof(g)))
			{

				if(strcmpi(g.p_code,code)==0)
				{
					f.write((char*)&g,sizeof(g));
					g.select=1;
					f1.seekp(pos,ios::cur);
					f1.write((char*)&g,sizeof(g));
				}
			}

			f1.close();

		}//end of for loop

		f.close();


	}//end of sort



	int game_options()//function to print the game names and buttons in search page and trending page
	{
		display();

		fstream f;

		f.open("slst.dat",ios::in|ios::binary);

		Games g;  int l=9, i=0;

		button b[7];

		while(f.read((char*)&g,sizeof(g)))
		{
			gotoxy(5,l);
			gname_output(g);

			strcpy(b[i].button_name,"MORE"); b[i].b_x=60; b[i].b_y=l;

			l+=2;  i++;

		}

		f.close();

		strcpy(b[5].button_name,"BACK"); b[5].b_x=70; b[5].b_y=22;

		strcpy(b[6].button_name,"LOGOUT"); b[6].b_x=70; b[6].b_y=3;

		int ptr=0;

		pointer_movement(b,7,ptr);

		return ptr;

	}// end of game_options




	int search_screen()// function to display search page and search results
	{
		clrscr();

		display();

		gotoxy(30,5); cout<<"SEARCH: ";

		char input[35];

		gets(input);

		sort(input);

		gotoxy(30,7); cout<<"SEARCH RESULTS";

		int k=game_options();

		clrscr();

		display();

		float s;

		fstream f;
		f.open("slst.dat",ios::in|ios::binary);

		Games g;

		if(k>=0&&k<=4)
		{
			int r=0;
			while(f.read((char*)&g,sizeof(g)))
			{
				if(k==r)
				{
					s=g.ginfo_output(g);
					if(s==8)
					{
						f.close();
						return 5;
					}

				}

				r++;
			}

		}

		else
		{
			f.close();
			return k;
		}

	}// end of search_screen



	int trend_screen()// function to display trending page
	{
		fstream fl, fm; Games g;
		int j;
		fl.open("slst.dat",ios::out|ios::binary);
		randomize();
		int r;

		for(int i=0;i<5;i++)
		{
			fm.open("glist.dat",ios::in|ios::binary);
			r=random(20);
			j=0;
			while(fm.read((char*)&g,sizeof(g)))
			{
				if(j==r)
				{
					fl.write((char*)&g,sizeof(g));
					fm.close();
					break;
				}

				j++;

			}
			fm.close();

		}// end of for loop

		fl.close();

		clrscr();

		display();

		gotoxy(33,6); cout<<"TRENDING GAMES";

		int k=game_options();


		clrscr();
		int s;


		fstream f;
		f.open("slst.dat",ios::in|ios::binary);

		if(k>=0&&k<=4)
		{
			int r=0;
			while(f.read((char*)&g,sizeof(g)))
			{
				if(k==r)
				{
					s=g.ginfo_output(g);
					if(s==8)
					{
						f.close();
						return 5;
					}
				}
				r++;
			}// end of while loop

		}

		else
		{
			f.close();
			return k;
		}

	}// end of trend_screen



	int home_screen()// function to display home page
	{
		display();

		button b[3];

		Games g;

		options:

		strcpy(b[0].button_name,"SEARCH FOR GAMES"); b[0].b_x=30; b[0].b_y=11;

		strcpy(b[1].button_name,"TRENDING GAMES"); b[1].b_x=30; b[1].b_y=12;

		strcpy(b[2].button_name,"LOGOUT"); b[2].b_x=70; b[2].b_y=3;

		int ptr=0;
		int h;

		pointer_movement(b,3,ptr);

		if(ptr==0)
		{
			h=g.search_screen();

			if(h==5)
				goto options;

			else if(h==6)
			{
				clrscr();
				return 2;
			}
		}

		else if(ptr==1)
		{
			h=g.trend_screen();

			if(h==5)
				goto options;

			else if(h==6)
			{
				clrscr();
				return 2;
			}
		}

		else if(ptr==2)
		{
			clrscr();
			return ptr;
		}

	}// end of home_screen


};// end of class Games


void wallpaper()// function to display starting screen wallpaper
{

	cout<<"                                                                          "<<endl;
	cout<<"                                                   IIIIIIIIIIIIII          "<<endl;
	cout<<"                                                IIIIIIIIIIIIIIIIIIII       "<<endl;
	cout<<"                                              IIIIIIIIIIIIIIIIIIIIIIII     "<<endl;
	cout<<"                                              IIIIIIIIIIIIIIIIIIIIIIII     "<<endl;
	cout<<"    IIIIII  IIII    IIII  IIIIIIIIIII        IIIIIIIIIIIIIIIIIIIIIIIIII    "<<endl;
	cout<<"    IIIIII  IIII    IIII  IIIIIIIIIII        IIIIIIIIIIIIIIIIIIIIIIIIII    "<<endl;
	cout<<"      IIII  IIII    IIII  IIII   IIII        IIIIIIIIIIIIIIIIIIIIIIIIII    "<<endl;
	cout<<"      IIII  IIII    IIII  IIII   IIII        IIIIIIII  II  II  IIIIIIII    "<<endl;
	cout<<"      IIII  IIII    IIII  IIIIIIIIIII          IIII    II  II    IIII      "<<endl;
	cout<<"      IIII  IIII    IIII  IIIIIIIIIII            II              II        "<<endl;
	cout<<"      IIII  IIIIIIIIIIII  IIII                   IIII          IIII        "<<endl;
	cout<<"      IIII  IIIIIIIIIIII  IIII                     IIIIIIIIIIIIII          "<<endl;
	cout<<"                                                                            "<<endl;
	cout<<"  IIIIIIIIIIII  IIIIIIIIIIII  IIIIIIIIIIIIIIIIII  IIIIIIIIIIII  IIIIIIIIIIII"<<endl;
	cout<<"  IIIIIIIIIIII  IIIIIIIIIIII  IIIIIIIIIIIIIIIIII  IIIIIIIIIIII  IIIIIIIIIIII"<<endl;
	cout<<"  IIII          IIII    IIII  IIII   IIII   IIII  IIII          IIII        "<<endl;
	cout<<"  IIII    IIII  IIIIIIIIIIII  IIII   IIII   IIII  IIIIIIII      IIIIIIIIIIII"<<endl;
	cout<<"  IIII    IIII  IIIIIIIIIIII  IIII   IIII   IIII  IIIIIIII      IIIIIIIIIIII"<<endl;
	cout<<"  IIII    IIII  IIII    IIII  IIII   IIII   IIII  IIII                  IIII"<<endl;
	cout<<"  IIIIIIIIIIII  IIII    IIII  IIII   IIII   IIII  IIIIIIIIIIII  IIIIIIIIIIII"<<endl;
	cout<<"  IIIIIIIIIIII  IIII    IIII  IIII   IIII   IIII  IIIIIIIIIIII  IIIIIIIIIIII"<<endl;
	cout<<"                                                                            "<<endl;
	cout<<"                             THE ONLINE GAME STORE                          "<<endl;


	getch();

	clrscr();

}// end of wallpaper


void start_screen()// function to display main menu
{
	button b[3];

	int h;

	startscreen:

	display();

	strcpy(b[0].button_name,"LOGIN"); b[0].b_x=35; b[0].b_y=12;

	strcpy(b[1].button_name,"SIGN UP"); b[1].b_x=35; b[1].b_y=14;

	strcpy(b[2].button_name,"EXIT"); b[2].b_x=35; b[2].b_y=16;

	int ptr=0, c;     Games g;

	pointer_movement(b,3,ptr);

	if(ptr==0)
	{
		clrscr();
		log_screen log;
		h=log.check_details();

	}

	else if(ptr==1)
	{
		clrscr();
		reg_screen reg;
		h=reg.add_details();

	}

	else if(ptr==2)
	{
		clrscr();

		gotoxy(29,10);cout<<"THANK YOU FOR SHOPPING";
		gotoxy(34,12);cout<<"AT 1UP GAMES";
		gotoxy(30,14);cout<<"PLEASE VISIT US AGAIN";

		getch();
		exit(0);
	}

	if(h==0)
	{
		c=g.home_screen();
	}

	if(h==1||c==2)
		goto startscreen;

}// end of start_screen



 void main()
 {
  Games A;
  wallpaper();
  start_screen();
 }










