#include<iostream>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<string.h>
using namespace std;



//*************************************************Declaration Student**********************************************
class student{
	
	int id;
	char name[10];
	char course[10];
	char str_semester[10];
	public:
		void get_stdData();
		void put_stdData();
		int get_stdIDnum();
};

void std_insert();
void std_display();
void std_menu();
void std_enquiry();
void std_del();
void login();

void student::get_stdData()
{
	cout<<endl;
	cout<<"Id:";
	cin>>id;
	cout<<"Name:";
	cin>>name;
	cout<<"Course:";
	cin>>course;
	cout<<"Semester:";
	cin>>str_semester;
}

void student::put_stdData()
{
	cout<<"  "<< id<<"\t "<<name<<"\t\t"<<str_semester<<"\t    "<<course<<endl;
}


void std_menu()
{
	student std;
	int choice;
	while(1)
	{
	 cout<<"\n1.Add Student \n2.View Student \n3.Search and View \n4.Delete \n5.Back to Menu \n6.Exit"<<endl;
	 cout<<"Enter your choice:";
	 cin>>choice;
	 switch(choice)
	 {
		case 1: std_insert();
				break;
		case 2: std_display();
				break;
		case 3: std_enquiry();
				break;
		case 4: std_del();
				break;
		case 5: login();
		        break;
		case 6: exit(0);        
		default: cout<<"Wrong Choice!!"<<endl;
     }
    }
}

void std_insert()
{
	student std;
	system("cls");
	ofstream outFile;
	outFile.open("alu.txt",ios::binary|ios::app);
	char op;
	do
	{
		cout<<" -----Enter Students Details-----"<<endl;
		std.get_stdData();
		outFile.write(reinterpret_cast<char *>(&std),sizeof(student));
		cout<<"\nFile Created Sucessfully"<<endl;
		cout<<"\nDo you want to add more [Y/N] ";
		op=getch();
		cout<<endl;
	}
	while(op=='Y'||op=='y');
	outFile.close();
}

void std_display()
{
	student std;
	ifstream inFile;
	inFile.open("alu.txt",ios::binary|ios::app);
	system("cls");
	inFile.read(reinterpret_cast<char *>(&std),sizeof(student));
	cout<<" _____________________________________________\n"; 
	
	cout<< "| ID \t Name \t     Semester \t   Course     |  \n"; 
	cout<<"|_____________________________________________|\n"<<endl;
	while(!inFile.eof())
	{
		std.put_stdData();
		inFile.read(reinterpret_cast<char *>(&std),sizeof(student));
	}
	cout<<"\n\n\nPress any key to continue.......";
	inFile.close();
	getch();
	system("cls");
}
void std_enquiry()
{

	student std;
	ifstream inFile;
	inFile.open("alu.txt",ios::binary|ios::app);
	int x,found=0;
	cout<<"Enter the ID number: ";
	cin>>x;
	system("cls");
	inFile.read(reinterpret_cast<char *>(&std),sizeof(student));
	while(!inFile.eof())
	{
		if(std.get_stdIDnum()==x)
		{
			cout<<" _____________________________________________\n";
	
        	cout<< "| ID \t Name \t     Semester \t   Course     |  \n"; 
        	cout<<"|_____________________________________________|\n"<<endl;
			std.put_stdData();
			found=1;
			break;
		}
		inFile.read(reinterpret_cast<char *>(&std),sizeof(student));
	}
	inFile.close();
	if(found==0)
	{
		cout<<"\nNo Record.....";
	}
	cout<<"\n\n\n\nPress any key to continue.......";
	getch();
	system("cls");
}

int student::get_stdIDnum()
{
	return id;
}

void std_del()
{
	student std;
	int data; 
	cout<<"Enter the ID number to be deletd:";
	cin>>data;
	cout<<"\n\nPress any key to continue....";
	cin.ignore();
	cin.get();
	ifstream inFile("alu.txt",ios::binary);
	ofstream outFile("Today.txt",ios::binary);
	
	while(inFile.read((char *)&std,sizeof(std)))
	{
		if(data!=std.get_stdIDnum())
		outFile.write((char *)&std,sizeof(std));	
	}
	inFile.close();
	outFile.close();
	remove("alu.txt");
	rename("Today.txt","alu.txt");

}


//******************************************Student complete**************************************************//





class teacher{
	
	 int hr;
	 char name[15];
	 char qualification[20];
	 char designation[20];
	 char str_exp[5];
	 long long contact;
	 char str_address[15];
	 
	 public:
	 	void gettea();
	 	void puttea();
	 	int getIDnum();
};
void tea_menu();
void insert();
void display();
void search();
void s_delete();



void teacher::gettea()
{
	cout<<"HR-NO: ";
	cin>>hr;
	cout<<"Name: ";
	cin>>name;
	cout<<"Qualification: ";
	cin>>qualification;
	cout<<"Designation: ";
	cin>>designation;
	cout<<"Experience: ";
	cin>>str_exp;
	cout<<"Contact: ";
	cin>>contact;
	cout<<"Address: ";
	cin>>str_address;
}

void teacher::puttea()
{
	cout<<setw(2)<<hr<<setw(15)<<name<<setw(15)<<qualification<<setw(25)<<designation<<setw(13)<<str_exp<<setw(21)<<str_address<<setw(22)<<contact<<endl<<endl;
}

void tea_menu()
{
    teacher tea;
	int choice;
	while(1)
	{
	 cout<<"\n1.Add Teacher \n2.View Teacher \n3.Search and View \n4.Delete \n5.Back to Menu \n6.Exit"<<endl;
	 cout<<"Enter your choice:";
	 cin>>choice;
	 switch(choice)
     {
	    case 1: insert();
				break;
		case 2: display();
				break;
		case 3: search();
				break;
		case 4: s_delete();
				break;
		case 5: login();
		        break;
		case 6: exit(0);
		default: cout<<"Wrong Choice!!"<<endl;
	 }
    }
}
void insert()
{

	teacher tea;
	system("cls");
	ofstream outFile;
	outFile.open("teach.txt",ios::binary|ios::app);
	char op;
	do
	{
		cout<<"****************Enter Teacher Details*********************\n\n";
		tea.gettea();
		outFile.write(reinterpret_cast<char *>(&tea),sizeof(teacher));
		cout<<"\nFile Created Successfully"<<endl;
		cout<<"Do you want to add more[Y/N]: ";
		op=getch();
		cout<<endl;
	}
	while(op=='y'||op=='Y');
	outFile.close();
}

void display()
{
	teacher tea;
	ifstream inFile;
	inFile.open("teach.txt",ios::binary|ios::app);
	system("cls");
	inFile.read(reinterpret_cast<char *>(&tea),sizeof(teacher));
	cout<<" ___________________________________________________________________________________________________________________\n";
	cout<<"| HR-NO      Name        Qualification       Deisgnation        Experience          Address            Contact      |\n";
	cout<<"|___________________________________________________________________________________________________________________|\n"<<endl;
	while(!inFile.eof())
	{
		tea.puttea();
		inFile.read(reinterpret_cast<char *>(&tea),sizeof(teacher));
	}
	cout<<"\n\n\n\n\n\n\n\nPress any Key to continue.....";
	inFile.close();
	getch();
	system("cls");
}

int teacher::getIDnum()
{
	return hr;
}

void search()
{
	teacher tea;
	ifstream inFile;
	inFile.open("teach.txt",ios::binary);
	int id,count=0;
	cout<<"Enter the HR-NO: ";
	cin>>id;
	system("cls");
	inFile.read(reinterpret_cast<char *>(&tea),sizeof(teacher));
	while(!inFile.eof())
	{
		if(tea.getIDnum()==id)
		{
			cout<<" ___________________________________________________________________________________________________________________\n";
	        cout<<"| HR-NO      Name        Qualification       Deisgnation        Experience          Address            Contact      |\n";
        	cout<<"|___________________________________________________________________________________________________________________|\n"<<endl;
			tea.puttea();
			count=1;
			break;
		}
		inFile.read(reinterpret_cast<char *>(&tea),sizeof(teacher));
	}
	if(count==0)
	cout<<"\n\nNo Record!!"<<endl;
	cout<<"\n\n\n\n\n\nPress any key to continue...";
	getch();
	system("cls");
}

void s_delete()
{
	teacher tea;
	int x;
	cout<<"Enter the Hr-No you want to delete:";
	cin>>x;
	cout<<"Press any key to continue....";
	cin.ignore();
	cin.get();
	ifstream inFile("teach.txt",ios::binary|ios::app);
	ofstream outFile("Temp.txt",ios::binary);
	while(inFile.read((char *)&tea,sizeof(tea)))
	{
		if(x!=tea.getIDnum())
		outFile.write((char *)&tea,sizeof(tea));
	}
	inFile.close();
	outFile.close();
	remove("teach.txt");
	rename("Temp.txt","teach.txt");
}

//********************************************Teacher Complete***************************************************************

void login()
{
	int choice;
	system("cls");
	 while(1)
	 {
		cout<<"\n1.Student Login \n2.Teachar Login \n3.Exit "<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		system("cls");
		switch(choice)
		{
			case 1: std_menu();
			break;
			case 2: tea_menu();
			break;
			case 3: exit(0);
			default: cout<<"Wrong choice!!!"<<endl;
		}
     }
	system("cls");
}
main()
{
	student std;
	teacher tea;
		
	int password;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\tCreated By";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\tMM IBRAHIM";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t   TIKU";
	cout<<"\t\t\t\t\t\t\t    --------------------\n";
	cout<<"\t\t\t\t\t    |GLOCAL UNIVERSITY |\n";
	cout<<"\t\t\t\t\t    |STUDENT MANAGEMENT|\n";
	cout<<"\t\t\t\t\t    --------------------\n";
	
	system("color F0");
	
	string username,Ram;
	cout<<"\n\t\t\t\t\tUsername: ";
	cin>>username;
	cout<<"\t\t\t\t\tPassword: ";
	cin>>password;
	system("cls");
	if(username=="Ram" && password==123)
	{
	  login();
    }
    else
    {
    	cout<<"Wrong Username or Password!!!!..."<<endl;
	}
}


