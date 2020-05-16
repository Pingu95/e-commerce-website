#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<iostream.h>



struct button
{
	char button_name[20];
	int b_x, b_y;
	char key;
	
};


void clr_space(int x, int y, int l)//To clear out the space around the button
{

	for(int i=l;i>=0;i--)
	{
		gotoxy(x+i,y); cout<<'\b';
	}

}//end of clr_space




int button_print(button b[],int n, int ptr)//to print button at specific locations
{
	int ub=n-1;  int s;

	for(s=0;s<=ub;s++)
	{
		clr_space((b[s].b_x-3), b[s].b_y, (strlen(b[s].button_name)+6)) ;

	}


	for(s=0;s<=ub;s++)
	{
		gotoxy(b[s].b_x,b[s].b_y);   cout<<b[s].button_name;

	}
	gotoxy((b[ptr].b_x)-2,b[ptr].b_y);  cout<<"<";
	gotoxy((b[ptr].b_x)+strlen(b[ptr].button_name)+2,b[ptr].b_y);  cout<<">";

	b[ptr].key=getch();
	return b[ptr].key;

}//end of button_print


void pointer_movement(button b[], int n,int &ptr)//to navigate across screen and select buttons
{
	char k;
	while(n>1)
	{
		k=button_print(b,n,ptr);
		if(isalpha(k))
			switch (tolower(k))
			{
				case 'w': case 'a':
					if(ptr==0)
						ptr=n-1;
					else
						ptr--;
					break;

				case 's': case 'd':
					if(ptr==n-1)
						ptr=0;
					else
						ptr++;
					break;
			}//end of switch case

		else if(k==' ')
			break;

	}// end of while loop

}// end of pointer movement



