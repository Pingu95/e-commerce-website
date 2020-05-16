#include<iostream.h>
#include<string.h>
#include "reg_log.cpp"
#include<stdlib.h>









void start_screen()
{
	button b[3]; int h;
	//base_screen::display(0);

	homescreen:

	gotoxy(1,1); cout<<"________________________________________________________________________________";

	gotoxy(1,3); cout<<"                             1UP - THE GAME STORE";
	gotoxy(1,4); cout<<"________________________________________________________________________________\n";

	strcpy(b[0].button_name,"LOGIN"); b[0].b_x=35; b[0].b_y=12;

	strcpy(b[1].button_name,"SIGN UP"); b[1].b_x=35; b[1].b_y=14;

	strcpy(b[2].button_name,"EXIT"); b[2].b_x=35; b[2].b_y=16;

	int ptr=0;

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
		exit(0);
	}

	if(h)
   	goto homescreen;

}



void main()
{
			start_screen();
} 
