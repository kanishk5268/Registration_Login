#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();

int main(){
	int choice;
	cout<<"Welcome"<<endl;
	cout<<"| 1.) LOGIN"<<endl;
	cout<<"| 2.) REGISTER"<<endl;
	cout<<"| 3.) FORGOT PASSWORD"<<endl;
	cout<<"| 4.) EXIT"<<endl;
	cout<<"Enter your choice : "<<endl;
	cin>>choice;
	
	switch(choice)
		{
			case 1:
			login();
			break;
		case 2:
			registration();
			break;
		case 3:
			forgot();
			break;
		case 4:
			cout<<"THANK YOU!";
			break;
		default:
			system("cls");
			cout<<"Please enter a valid option!"<<endl;
			main();
		}
		
}


void login(){
	int count;
	string username,password,id,pass;
	system("cls");
	cout<<"Please enter the username and password : "<<endl;
	cout<<"USERNAME: "<<endl;
	cin>>username;
	cout<<"PASSWORD: "<<endl;
	cin>>password;
	
	/*Now we will check if the username or password exist or not and for that
	 we will use file handling method and will use ifstream as it used to read 
	 the data.*/
	 
	 ifstream input("records.txt");
	 while(input>>id>>pass){
	 	if(id == username && pass == password ){
	 		count = 1;
	 		system("cls");
		 }
	 }
	 input.close();
	 
	 if(count == 1){
	 	cout<<username<<"Your Login is Successful!"<<endl;
	 	main();
	 }
	 else{
	 	cout<<"Login Error!\n Please check your credentials\n";
	 	main();
	 }
}



void registration(){
	
	string rusername, rpassword, rid,rpass;
	system("cls");
	cout<<"Enter desired username: "<<endl;
	cin>>rusername;
	cout<<"Enter desired password: "<<endl;
	cin>>rpassword;
	
	/*Here we want to write the username and password inside a file so we will
	use the ofstream class to write inside a file.*/
	
	ofstream f1("records.txt", ios::app); // ios means the input output stream and app will open the file and append the output.
	f1<<rusername<<" "<<rpassword<<endl;
	system("cls");
	cout<<"Your Registration is Successful !!"<<endl;
	main();
}


void forgot(){
	int option;
	system("cls");
	cout<<"Forgot Your Password?"<<endl;
	cout<<"Press 1 to search your id by username"<<endl;
	cout<<"Press 2 to go to the main menu"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>option;
    switch(option){
    	case 1:
    		{
    			int count = 0;
    			string susername,sid,spass;
    			cout<<"Enter the username that you remeber"<<endl;
    			cin>>susername;
    			
    			ifstream f2("records.txt");
    			while(f2>>sid>>spass){
    				if(sid == susername){
    					count =1;
					}
				}
				f2.close();
				if(count == 1){
					cout<<"Account Found"<<endl;
					cout<<"Password : "<<spass;
					main();
				}else{
					cout<<"Account Not Found"<<endl;
					main();
				}
				break;
			}
		case 2:
			{
				main();
			}
		default:
			cout<<"Wrong Choice, Please try again"<<endl;
			forgot();
	}
}
