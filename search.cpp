#include<fstream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>




class Games
{
	char p_code[8];
	char name[30];
	float price[3];
	
	char genre[22];
	int mode; // has to be 1 or 2
	//char description[200];
	int maxlen;
	int select;
	



 	public:

	//constructor
	Games()
	{
		strcpy(p_code,"\0");
		strcpy(name,"\0");
		price[0]=price[1]=price[2]=0;
		strcpy(genre,"\0");
		mode=0;
		strcpy(description,"\0");
		maxlen=0;
		select=0;
	}

	//input function

/*
	void wri(Games A)
	{
		fstream f1;
		f1.open("gamlist.dat",ios::app|ios::binary);
		f1.write((char*)&A , sizeof(A));
		f1.close();
	}

	Games(char pcode[] , char nam[] , int pr1,int pr2,int pr3 ,char gen[] , int mod , char des [])
	{
		strcpy(p_code,pcode);
		strcpy(name,nam);
					 price[0]=price[1]=price[2]=0;
		price[0]=pr1;
		price[1]=pr2;
		price[2]=pr3;
		mode=mod;
		strcpy(genre,gen);
		strcpy(description , des);
		maxlen=0;
		select=0;
	}

*/

	void output()
	{
		fstream f1;
		int i=1;
		Games s;
		f1.open("gamlist.dat",ios::in|ios::binary);
		while(f1.read((char*)&s,sizeof(s)))
		{
				cout<<i<<endl;
				cout<<"Name        : "<<s.name<<endl;
			cout<<"PS4         : "<<s.price[0]<<endl;
			cout<<"Xbox One    : "<<s.price[1]<<endl;
			cout<<"PC          : "<<s.price[2]<<endl;
			cout<<"Genre       : "<<s.genre<<endl;
			cout<<"Game mode   : ";
			if(s.mode==1)
			cout<<"Single-Player"<<endl;
			else if(s.mode==2)
			cout<<"Multiplayer"<<endl;
			cout<<"\nDescription : "<<endl;
			cout<<s.description<<endl;
			cout<<"\n\n";
				i++;
		}
		i=1;
		f1.close();
	}





	int get_search_rank(char input[])
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

				if(input[j] != name[i+j])
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
	}


	void sort(char input[])
	{

		fstream f, f1;
		int max=0;   char code[8];

		//copying details from main to search_list//

		f.open("search_list.dat",ios::out|ios::binary);

		f1.open("gamlist.dat",ios::in|ios::out|ios::binary);

		Games g,g1;  int pos = -1*sizeof(g);

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

			f1.open("gamlist.dat",ios::in|ios::out|ios::binary);

			while(f1.read((char*)&g,sizeof(g)))
			{

				if((g.maxlen>max)&&(g.select!=1))
				{	max=g.maxlen;
					strcpy(code,g.p_code);
				}
			}

         f1.close();

			f1.open("gamlist.dat",ios::in|ios::out|ios::binary);

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



		}
		f.close();
	  //	f1.close();

	}


	void search()
	{

		char input[30];

		gets(input);

		cout<<"INPPUT DONE\n";

		sort(input);

		cout<<"SORT DONE\n";

		Games g;  fstream f;

		f.open("search_list.dat",ios::in|ios::binary);

		cout<<"FILE OPENED\n";

		while(f.read((char*)&g,sizeof(g)))
		{

			cout<<"OP";
			g.output();

		}

	}


	void search_screen()
	{




	}


};


void main()
{
	Games g;
	g.search();
}