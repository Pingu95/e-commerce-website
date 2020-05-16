 #include<iostream.h>
 #include<conio.h>

class base_screen
{



    public:


	void display()
	{

		clrscr();

		gotoxy(1,1); cout<<"________________________________________________________________________________";

		gotoxy(1,3); cout<<"                              1UP - THE GAME STORE";
		gotoxy(1,4); cout<<"________________________________________________________________________________\n";

      gotoxy(15,24);cout<<"Use W,A,S,D keys to navigate. Use SPACEBAR to select.";
  	}
};