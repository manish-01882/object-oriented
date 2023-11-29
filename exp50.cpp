//HEADER FILE USED IN PROJECT
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;

// CLASS USED IN PROJECT

class account
{
	int Account_No;
	char Account_Name[50];
	char type;
	int Deposit_Amount;
public:
	void open_account();	//function to get data from user
	void show_account() const;	//function to show data on screen
	void update();	//function to add new data
	void dep(int);	//function to accept amount and add to balance amount
	void withdraw(int);	//function to accept amount and subtract from balance amount
	void report() const;	//function to show data in tabular format
	int Return_Account_Number() const;	//function to return account number
	int Return_Deposit_Amount() const;	//function to return balance amount
	char Return_type() const;	//function to return type of account
};         //class ends here


void account::show_account() const
{
	cout<<"\nAccount No. : "<<Account_No;
	cout<<"\nAccount Holder Name : ";
	cout<<Account_Name;
	cout<<"\nType of Account : "<<type;
	cout<<"\nBalance amount : "<<Deposit_Amount;
}
void account::open_account()
{
	cout<<"\nEnter The account No. :";
	cin>>Account_No;
	cout<<"\nEnter The Name of The account Holder : ";
	cin.ignore();
	cin.getline(Account_Name,44);
	cout<<"\nEnter Type of The account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nEnter The Initial amount(>=440 for Saving and >=1000 for current ) : ";
	cin>>Deposit_Amount;
	cout<<"\n\nAccount Created..";
	cout<<"\nPress Enter to continue: ";
}



	
void account::dep(int x)
{
	Deposit_Amount+=x;
}
	
void account::withdraw(int x)
{
	Deposit_Amount-=x;
}
	
void account::report() const
{
	cout<<Account_No<<setw(10)<<" "<<Account_Name<<setw(10)<<" "<<type<<setw(6)<<Deposit_Amount<<endl;
}

void account::update()
{
	cout<<"\nAccount No. : "<<Account_No;
	cout<<"\nupdate Account Holder Name : ";
	cin.ignore();
	cin.getline(Account_Name,44);
	cout<<"\nupdate Type of Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nupdate Balance amount : ";
	cin>>Deposit_Amount;
}
	
int account::Return_Account_Number() const
{
	return Account_No;
}


char account::Return_type() const
{
	return type;
}
int account::Return_Deposit_Amount() const
{
	return Deposit_Amount;
}

//function declaration

void delete_account(int);	//function to delete record of file
void display_all();		//function to display all account details
void write_account();	//function to write record in binary file
void display_sp(int);	//function to display account details given by user
void Deposit_with_withdraw(int, int); // function to deposit/withwithdraw amount for given account
void intro();	//introductory screen function
void update_account(int);	//function toupdate record of file
//THE MAIN FUNCTION OF PROGRAM

int main()
{
	char ch;
	int num;
	intro();
	do
	{
		system("clear");
		cout<<"\n\n\t\tMAIN MENU:";
		cout<<"\n\n\t\t01. NEW ACCOUNT";
		cout<<"\n\t\t02. DEPOSIT AMOUNT";
		cout<<"\n\t\t03. wITHDRAW AMOUNT";
		cout<<"\n\t\t04. BALANCE ENQUIRY";
		cout<<"\n\t\t05. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\t\t06. CLOSE AN ACCOUNT";
		cout<<"\n\t\t07. MODIFY AN ACCOUNT";
		cout<<"\n\t\t08. EXIT";
		cout<<"\n\t\tSelect Your Option (1-8) ";
		cin>>ch;
		cin.ignore();
		system("clear");
		switch(ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			cout<<"\n\t\tEnter The account No. : "; cin>>num;
			Deposit_with_withdraw(num, 1);
			break;
		case '3':
			cout<<"\n\t\tEnter The account No. : "; cin>>num;
			Deposit_with_withdraw(num, 2);
			break;
		case '4': 
			cout<<"\n\t\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			cout<<"\n\t\tEnter The account No. : "; cin>>num;
			delete_account(num);
			break;
		 case '7':
			cout<<"\n\t\tEnter The account No. : "; cin>>num;
			
	update_account(num);
			break;
		 case '8':
			cout<<"\n\t\tThanks for using bank management system";
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
	}while(ch!='8');
	return 0;
}
//function to write in file

void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.open_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
}

//function to read specific record from file

void display_sp(int n)
{
	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";

    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.Return_Account_Number()==n)
		{
			ac.show_account();
			flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\nAccount number does not exist";
}


//function toupdate record of file

void update_account(int n)
{
	bool found=false;
	account ac;
	fstream File;
	File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.Return_Account_Number()==n)
		{
			ac.show_account();
			cout<<"\nEnter The New Details of account"<<endl;
			ac.
	update();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\t\t Record updated";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n Record Not Found ";
}

//function to delete record of file

void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.Return_Account_Number()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\t\tRecord Deleted ..";
}

//function to display all accounts Deposit_Amount list

void display_all()
{
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\t\t\t\tACCOUNT HOLDER LIST\n";
	cout<<"*********************************************\n";
	cout<<"A/c no.      NAME           Type  Balance\n";
	cout<<"*********************************************\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}

//  	function to Deposit_Amount and withwithdraw amounts


void Deposit_with_withdraw(int n, int option)
{
	int Amount;
	bool found=false;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.Return_Account_Number()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\t\tTO Deposit_AmountE AMOUNT ";
				cout<<"\nEnter The amount to be Deposit_Amounted";
				cin>>Amount;
				ac.dep(Amount);
			}
			if(option==2)
			{
				cout<<"\n\t\tTO WITHwithdraw AMOUNT ";
				cout<<"\nEnter The amount to be withwithdraw: ";
				cin>>Amount;
				int bal=ac.Return_Deposit_Amount()-Amount;
				if((bal<440 && ac.Return_type()=='S') || (bal<1000 && ac.Return_type()=='C'))
					cout<<"Insufficient balance";
				else
					ac.withdraw(Amount);
			}
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\t\t Record updated";
			found=true;
	       }
         }
	File.close();
	if(found==false)
		cout<<"\n Record Not Found ";
}


//INTRODUCTION FUNCTION

void intro()
{
	cout<<"\n\n\t BANK MANAGEMENT SYSTEM";
	cout<<"\n\nMADE BY : MANISH CHOUDHARY ";
	cout<<"\nCOLLEGE : GNE, LUDHIANA ";
	cout<<"\nPress Enter to continue: ";
	cin.get();
}