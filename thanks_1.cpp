#include<iostream.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<time.h>

void delay(long time)
{
 clock_t start=clock();
 while(clock()-start<time);
}

void thankyou()
{
 clrscr();
 gotoxy(32,3);cout<<"Processing...";
 gotoxy(12,5);cout<<"[";
 for(int i=13,j=0;i<65;i++)
 {
  delay(100);
  gotoxy(i,5);cout<<"|";
 }
 gotoxy(64,5);cout<<"]";
 gotoxy(27,3);clreol();
 gotoxy(32,3);cout<<"Order Confirmed";
 gotoxy(27,7);cout<<"Press any key to continue";
 getch();
 clrscr();
 gotoxy(29,3);cout<<"THANK YOU FOR SHOPPING";
 gotoxy(34,5);cout<<"AT 1UP GAMES";
 gotoxy(30,7);cout<<"PLEASE VISIT US AGAIN";
 getch();
}


