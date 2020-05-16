#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>





class reg_screen :  public base_screen
{
	 public:



	 void add_details()
{
	char pass[30], re_pass[30];
			usermgnt u_r;
		  //	base_screen::display(0);

		gotoxy(16,6);  cout<<"User name             : ";

		gotoxy(16,8);  cout<<"Email id              : ";

		gotoxy(16,10); cout<<"Password              : ";

		gotoxy(16,12); cout<<"Re-enter password     : ";


	gotoxy(40,6); gets(u_r.u_name);
	while(u_r.check_uname())
	{


		gotoxy(16,7);  cout<<"User name already taken!";

		getch();
		gotoxy(16,7);  clreol();
		gotoxy(40,6);  clreol();
		gotoxy(40,6); gets(u_r.u_name);
	}

	 gotoxy(40,8); gets(u_r.email);
	 gotoxy(40,10); gets(pass);

	while(strlen(pass)<=5)
	{

		gotoxy(16,11);  cout<<"Password has to be more than 5 characters!";

		getch();
		gotoxy(40,11);  clreol();
		gotoxy(40,10);  clreol();
		gotoxy(40,10); gets(pass);
	}


	gotoxy(40,12); gets(re_pass);

	while(strcmpi(pass,re_pass)!=0)
	{

		gotoxy(16,13);  cout<<"Re-enter password correctly!";

		getch();
		gotoxy(16,13);  clreol();
		gotoxy(40,12);  clreol();
		gotoxy(40,12); gets(re_pass);
	}

	strcpy(u_r.password,pass);


	fstream f;
	f.open("users.dat",ios::app|ios::binary);
	f.write((char*)&u_r,sizeof(u_r));

	f.close();



}

 };


 /*
void main()
{
	 reg_screen reg;
	 reg.add_details();

}   */