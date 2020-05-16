#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>







class log_screen :  public base_screen
{
    public:

	 void check_details()
	{

			usermgnt u_l;




		//  base_screen::display(0);
		gotoxy(16,6); cout<<"User name             : ";


		gotoxy(16,10); cout<<"Password              : ";


		  gotoxy(40,6); gets(u_l.u_name);



		  while(!(u_l.check_uname()))
		{
            gotoxy(16,7);

		 cout<<"ENTER VALID USER NAME !";

				getch();
            gotoxy(16,7); clreol();
			gotoxy(40,6); clreol();
            gotoxy(40,6);
				gets(u_l.u_name);

		}

		  gotoxy(40,10); gets(u_l.password);

		  while(!u_l.check_password())
			{
				gotoxy(16,11);

				cout<<"Enter correct password !";
				getch();
				gotoxy(16,11); clreol();
				gotoxy(40,10); clreol();
				gotoxy(40,10);
				gets(u_l.password);

			}







	}

	void log_scr_display()
	{  }



};

/*
void main()
{
	 log_screen log;
	 log.check_details();

}    */