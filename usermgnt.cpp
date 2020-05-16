#include<iostream.h>
#include<string.h>
#include<fstream.h>

class usermgnt

{
    public:
	char u_name[30];
	char email[50];
	char password[30];


int check_uname()// function to check whether username already exists
{
	fstream f;
	usermgnt U;
	f.open("users.dat",ios::in|ios::binary);
	while(f.read((char*)&U,sizeof(U)))
	{
		if(strcmpi(U.u_name,u_name)==0)
		{
			f.close();
			return 1;
		}
	}

	f.close();
	return 0;
}// end of check_uname


int check_password() // function to check whether username and password match
{
	fstream f;
	usermgnt U;
	f.open("users.dat",ios::in|ios::binary);
	while(f.read((char*)&U,sizeof(U)))
	{

		if((strcmpi(U.u_name,u_name)==0)&&(strcmpi(U.password,password)==0))
		{
			f.close();
			return 1;
		}
	}

	f.close();
	return 0;

}// end of check_password



void add_details()// function to add details of new user
{
	 usermgnt U;
	 strcpy(U.u_name,u_name);
	 strcpy(U.email,email);
	 strcpy(U.password,password);

	 fstream f;
	 f.open("users.dat",ios::app|ios::binary);
	 f.write((char*)&U,sizeof(U));
	 f.close();

}// end of add_details

};// end of class usermgnt