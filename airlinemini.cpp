#include <iostream>
#include <cstdio>
#include <string.h>
#include <string_view>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include<time.h>
#include<conio.h>
#include <cstdlib>
#include<windows.h>

using namespace std;

class Flight
{
    public:
    string flightno,flight_code,source,destination,fdate,arrival,departure,price,favail,pid,pname,pnum,paddr,fclass,fseat;

    void addFlight();
    void modFlight();
    void delFlight();
    void adisplayFlight();
    void udisplayFlight();
    void searchFlight();
    void alogin();
    void admin();
    int ulogin();
    void user();
    void bookTicket();
    void cancelTicket();
    void showTicket();
    bool searchFno(string);
    bool searchPid(string);
    bool flightAvailability(string);
};
Flight f;

int main()
{
    start:
    system("cls");
    int choice;
    time_t currentTime;
    time(&currentTime);
    cout<<"\n\t\t"<<ctime(&currentTime)<<"\n";
    cout<<"\n\t******************************************\n";
    cout<<"\t\tWELCOME TO PACIFIC AIRWAYS";
    cout<<"\n\t******************************************\n\n";
    cout<<"\t\t1.Admin\n";
    cout<<"\t\t2.User\n";
    cout<<"\t\t3.Exit\n";
    cout<<"\n\t******************************************\n";
    cout<<"\n\tEnter the choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            f.alogin();
            break;
        case 2:
            f.ulogin();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout<<"\n\tWrong Choice!!!";
            getch();
            goto start;
    }
    return(0);
}

void Flight::alogin()
{
    system("cls");
    char password[20]="admin",pass[20];
    int ch,i=0;
    fflush(stdin);
    cout<<"\n\t\tEnter admin password: ";
    while((ch=getch())!= 13)
    {
        cout<<"*";
        pass[i]=ch;
        i++;
    }
    pass[i]='\0';
    if(strcmp(pass,password)==0)
    {
        f.admin();
    }
    else
    {
        cout<<"\n\n\t\t\t ERROR: Wrong Password\n";
        getch();
        main();
    }
}


void Flight::admin()
{
    system("cls");
        start:
        system("cls");
        int achoice;
        char x;
        cout<<"\n\n\t\t      WELCOME  ADMIN";
        cout<<"\n\t##########################################\n";
        cout<<"\t\tAIRLINE RESERVATION SYSTEM";
        cout<<"\n\t##########################################\n\n";
        cout<<"\t1.Add Flight\n";
        cout<<"\t2.Delete Flight\n";
        cout<<"\t3.Change Flight Details\n";
        cout<<"\t4.Display Flight Details\n";
        cout<<"\t5.Search Flight\n";
        cout<<"\t6.Log out\n";
        cout<<"\t7.Exit\n";
        cout<<"\n\t##########################################\n";
        cout<<"\n\tEnter the choice: ";
        cin>>achoice;
        switch(achoice)
        {
        case 1:
            do
            {
                f.addFlight();
                cout<<"\n\t\tDo you want to add another flight details?(Y/N) :";
                cin>>x;
            }while(x=='y' || x=='Y');
            break;
        case 2:
            f.delFlight();
            break;
        case 3:
            f.modFlight();
            break;
        case 4:
            f.adisplayFlight();
            break;
        case 5:
            f.searchFlight();
            break;
        case 6:
            main();
            break;
        case 7:
            exit(0);
            break;
        default:
            cout<<"\n\tWrong Choice!!!\n\n";
            goto start;
        }
        getch();
        goto start;
}


int Flight::ulogin()
{
    string pass_reg = "";
    string name_reg = "";
    string pass = "";
    string name = "";
    fstream file;
    char ch;
    system("cls");
    cout<<"\n\t\t>>>>>>>>>>>>>>>>>>>>||  WELCOME TO AIRLINE RESERVATION SYSTEM  ||<<<<<<<<<<<<<<<<<<<<\n\n";
    cout<<"\n\t\t\t\t1. Register";
    cout<<"\n\t\t\t\t2. Login";
    int selection;
    cout<<"\n\n\t\tEnter your choice: ";
    cin>>selection;
    if (selection == 1)
    {
        system("cls");
        cout<<"\n\t\t>>>>>>>>>>>>>>>>>>>>||  REGISTRATION ||<<<<<<<<<<<<<<<<<<<<\n\n";
        cout<<"\n\n\t\t\tEnter Your Name      : ";
        cin>>name_reg;
        cout<<"\n\t\t\tEnter Your Password  : ";
        ch= _getch();
        while(ch!=13)
        {
            pass_reg.push_back(ch);
            cout<<'*';
            ch= _getch();
        }
        file.open("ULogin.txt", ios::app);
        file<<" "<<name_reg<<" "<<pass_reg<<"\n";
        file.close();
        cout<<"\n\t\t\tRegistration Succesful!!!!!";
        getch();
        f.ulogin();
    }
    else if(selection == 2)
    {
        system("cls");
        file.open("ULogin.txt",ios::in);
        cout<<"\n\t\t>>>>>>>>>>>>>>>>>>>>||  LOGIN ||<<<<<<<<<<<<<<<<<<<<\n\n";
        cout<<"\n\n\t\t\tEnter Your Name      : ";
        cin>>name;
        cout<<"\n\t\t\tEnter Your Password  : ";
        ch= _getch();
        while(ch != 13)
        {
            pass.push_back(ch);
            cout<<'*';
            ch= _getch();
        }
        file>>name_reg>>pass_reg;
        while(!file.eof())
        {
            if(pass==pass_reg && name==name_reg)
            {
                cout<<"\n\n\n\t\t\t\t| Verfiying USER |\n\t\t\t\t";
                for(int a=1;a<8;a++)
                {
                    Sleep(500);
                    cout<<"...";
                }
                cout<<"\n\n\t\t\tAccess Granted..!\n\n";
                system("PAUSE");
                f.user();
            }
            else
            {
                cout<<"\n\n\n\t\t\t\t| Verfiying USER |\n\t\t\t\t";
                for(int a=1;a<8;a++)
                {
                    Sleep(500);
                    cout<<"...";
                }
                cout<<"\n\n\t\t\tAccess Aborted...!\n\n";
                system("PAUSE");
                system("cls");
                f.ulogin();
            }
            file >> name_reg >> pass_reg;
        }
        file.close();
    }
    else
    {
        cout << "\n\tInvalid Input.. Please Try Again..";
        getch();
        f.ulogin();
    }
    return 0;
}


void Flight::user()
{
    system("cls");
        start:
        system("cls");
        int uchoice;
        cout<<"\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
        cout<<"\t\tPACIFIC AIRWAYS WELCOMES YOU";
        cout<<"\n\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n";
        cout<<"\t1.Display Flights\n";
        cout<<"\t2.Book a Ticket\n";
        cout<<"\t3.Cancel the Ticket\n";
        cout<<"\t4.Show the Ticket\n";
        cout<<"\t5.Log out\n";
        cout<<"\t6.Exit\n";
        cout<<"\n\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
        cout<<"\n\tEnter the choice: ";
        cin>>uchoice;
        switch(uchoice)
        {
        case 1:
            f.udisplayFlight();
            break;
        case 2:
            f.bookTicket();
            break;
        case 3:
            f.cancelTicket();
            break;
        case 4:
            f.showTicket();
            break;
        case 5:
            main();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout<<"\n\tWrong Choice!!!\n\n";
            goto start;
        }
        getch();
        goto start;
}


void Flight::addFlight()
{
    start:
    system("cls");
    fstream file;
    int s1,d1;
    string c,src,dest;
    cout<<"\n\t*****************************ADD FLIGHT DETAILS*****************************\n";
    cout<<"\n\tEnter Flight No.            : ";
    cin>>flightno;
    cout<<"\tEnter Flight Code           : ";
    cin>>flight_code;
    cout<<"\tChoose Source                : ";
    cout<<"\n\t\t1.Bangalore \n\t\t2.Bhubaneswar \n\t\t3.Chennai \n\t\t4.Delhi";
    cout<<"\n\t\t5.Kochi \n\t\t6.Mumbai \n\t\t7.Siliguri \n\t\t8.Visakhapatnam";
    cout<<"\n\t\t\tEnter your choice: ";
    cin>>s1;
    switch(s1)
    {
    case 1:
        source="Bangalore";
        break;
    case 2:
        source="Bhubaneswar";
        break;
    case 3:
        source="Chennai";
        break;
    case 4:
        source="Delhi";
        break;
    case 5:
        source="Kochi";
        break;
    case 6:
        source="Mumbai";
        break;
    case 7:
        source="Siliguri";
        break;
    case 8:
        source="Visakhapatnam";
        break;
    default:
            cout<<"\n\n\t\tWrong choice!";
            getch();
            goto start;
    }
    cout<<"\tChoose Destination           : ";
    cout<<"\n\t\t1.Bangalore \n\t\t2.Bhubaneswar \n\t\t3.Chennai \n\t\t4.Delhi";
    cout<<"\n\t\t5.Kochi \n\t\t6.Mumbai \n\t\t7.Siliguri \n\t\t8.Visakhapatnam";
    cout<<"\n\t\t\tEnter your choice: ";
    cin>>d1;
    switch(d1)
    {
    case 1:
        destination="Bangalore";
        break;
    case 2:
        destination="Bhubaneswar";
        break;
    case 3:
        destination="Chennai";
        break;
    case 4:
        destination="Delhi";
        break;
    case 5:
        destination="Kochi";
        break;
    case 6:
        destination="Mumbai";
        break;
    case 7:
        destination="Siliguri";
        break;
    case 8:
        destination="Visakhapatnam";
        break;
    default:
        cout<<"\n\n\t\tWrong choice!";
        getch();
        goto start;
    }
    cout<<"\tEnter Date(dd/mm/yyyy)      : ";
    cin>>fdate;
    cout<<"\tEnter Arrival Time(hh:mm)   : ";
    cin>>arrival;
    cout<<"\tEnter Departure Time(hh:mm) : ";
    cin>>departure;
    cout<<"\tEnter Price                 : ";
    cin>>price;
    cout<<"\tEnter Availability(YES/NO)  : ";
    cin>>favail;
    cout<<"\n\n\tConfirm?(y/n): ";
    cin>>c;
    if(c=="n")
    {
        getch;
        f.admin();
    }
    file.open("FlightRecord.txt",ios::app|ios::out);
    file<<" "<<flightno<<" "<<flight_code<<" "<<source<<" "<<destination<<" "<<fdate<<" "<<arrival<<" "<<departure<<" "<<price<<" "<<favail<<"\n";
    file.close();
}


void Flight::adisplayFlight()
{
    system("cls");
    fstream file;
    int total=1;
    cout<<"\n\t\t*******************************FLIGHT DETAILS*******************************\n\n";
    file.open("FlightRecord.txt",ios::in);
    if(!file)
    {
        cout<<"\n\t\t\tERROR: File doesn't exist";
        file.close();
        getch();
        f.admin();
    }
    else
    {
        file>>flightno>>flight_code>>source>>destination>>fdate>>arrival>>departure>>price>>favail;
        while(!file.eof())
        {
            cout<<endl<<"\t"<<total;
            total++;
            cout<<endl<<"\t\tFlight No.         : "<<flightno;
            cout<<endl<<"\t\tFlight Code        : "<<flight_code;
			cout<<endl<<"\t\tSource             : "<<source;
			cout<<endl<<"\t\tDestination        : "<<destination;
			cout<<endl<<"\t\tDate               : "<<fdate;
			cout<<endl<<"\t\tArrival Time       : "<<arrival;
			cout<<endl<<"\t\tDeparture Time     : "<<departure;
			cout<<endl<<"\t\tPrice              : "<<price;
			cout<<endl<<"\t\tAvailability       : "<<favail;
			cout<<endl;
			file>>flightno>>flight_code>>source>>destination>>fdate>>arrival>>departure>>price>>favail;
        }
        if(total==0)
        {
            cout<<"\n\tNo data";
            getch();
            f.admin();
        }
    }
    file.close();
    getch();
    admin();
}

void Flight::udisplayFlight()
{
    start:
    system("cls");
    fstream file;
    int found=0;
    file.open("FlightRecord.txt",ios::in);
    if(!file)
    {
        cout<<"\n\t\t\tERROR: File doesn't exist";
        file.close();
        getch();
        f.admin();
    }
    else
    {
        string src,dest;
        int s1,d1;
        cout<<"\n\t*********************************SEARCH FLIGHT*********************************\n\n";
        cout<<"\n\t\tSource      : ";
        cout<<"\n\t\t1.Bangalore \n\t\t2.Bhubaneswar \n\t\t3.Chennai \n\t\t4.Delhi";
        cout<<"\n\t\t5.Kochi \n\t\t6.Mumbai \n\t\t7.Siliguri \n\t\t8.Visakhapatnam";
        cout<<"\n\n\t\tEnter your choice: ";
        cin>>s1;
        cout<<"\n\n\t\tDestination : ";
        cout<<"\n\t\t1.Bangalore \n\t\t2.Bhubaneswar \n\t\t3.Chennai \n\t\t4.Delhi";
        cout<<"\n\t\t5.Kochi \n\t\t6.Mumbai \n\t\t7.Siliguri \n\t\t8.Visakhapatnam";
        cout<<"\n\n\t\tEnter your choice: ";
        cin>>d1;
        switch(s1)
        {
        case 1:
            src="Bangalore";
            break;
        case 2:
            src="Bhubaneswar";
            break;
        case 3:
            src="Chennai";
            break;
        case 4:
            src="Delhi";
            break;
        case 5:
            src="Kochi";
            break;
        case 6:
            src="Mumbai";
            break;
        case 7:
            src="Siliguri";
            break;
        case 8:
            src="Visakhapatnam";
            break;
        default:
            cout<<"\n\n\t\tWrong choice!";
            getch();
            goto start;
        }
        switch(d1)
        {
        case 1:
            dest="Bangalore";
            break;
        case 2:
            dest="Bhubaneswar";
            break;
        case 3:
            dest="Chennai";
            break;
        case 4:
            dest="Delhi";
            break;
        case 5:
            dest="Kochi";
            break;
        case 6:
            dest="Mumbai";
            break;
        case 7:
            dest="Siliguri";
            break;
        case 8:
            dest="Visakhapatnam";
            break;
        default:
            cout<<"\n\n\t\tWrong choice!";
            getch();
            goto start;
        }
        getch();
        system("cls");
        file>>flightno>>flight_code>>source>>destination>>fdate>>arrival>>departure>>price>>favail;
        while(!file.eof())
        {
            if((src==source) && (dest==destination))
            {
                //system("cls");
                cout<<"\n\n";
                cout<<endl<<"\t\tFlight No.         : "<<flightno;
                cout<<endl<<"\t\tFlight Code        : "<<flight_code;
                cout<<endl<<"\t\tSource             : "<<source;
                cout<<endl<<"\t\tDestination        : "<<destination;
                cout<<endl<<"\t\tDate               : "<<fdate;
                cout<<endl<<"\t\tArrival Time       : "<<arrival;
                cout<<endl<<"\t\tDeparture Time     : "<<departure;
                cout<<endl<<"\t\tPrice              : "<<price;
                cout<<endl<<"\t\tAvailability       : "<<favail;
                cout<<endl;
                found++;
            }
            file>>flightno>>flight_code>>source>>destination>>fdate>>arrival>>departure>>price>>favail;
        }
        if(found==0)
        {
            cout<<"\n\t\tFlight not available...!";
        }
        file.close();
    }
}

void Flight::modFlight()
{
    system("cls");
    fstream file,file1;
    string fno;
    int found=0;
    cout<<"\n\t********************************MODIFY FLIGHT DETAILS********************************\n\n";
    file.open("FlightRecord.txt",ios::in);
    if(!file)
    {
        cout<<"\n\t\t\tERROR: File doesn't exist";
        file.close();
        getch();
        f.admin();
    }
    else
    {
        cout<<"\n\tEnter Flight No. of the FLIGHT you want to MODIFY: ";
        cin>>fno;
        file1.open("frecord.txt",ios::app|ios::out);
        file>>flightno>>flight_code>>source>>destination>>fdate>>arrival>>departure>>price>>favail;
        while(!file.eof())
        {
            if(fno!=flightno)
            {
                file1<<" "<<flightno<<" "<<flight_code<<" "<<source<<" "<<destination<<" "<<fdate<<" "<<arrival<<" "<<departure<<" "<<price<<" "<<favail<<"\n";
            }
            else
            {
                cout<<"\n\n\t1.Flight No.\n\t2.Flight_code\n\t3.Source\n\t4.Destination";
                cout<<"\n\t5.Date\n\t6.Arrival Time\n\t7.Departure Time\n\t8.Price\n\t9.Availability\n\t10.Back\n";
                int ch;
                cout<<"\n\tEnter the choice you want to MODIFY: ";
                cin>>ch;
                switch(ch)
                {
                case 1:
                    cout<<"\n\tEnter Flight No.   : ";
                    cin>>flightno;
                    break;
                case 2:
                    cout<<"\n\tEnter Flight Code  : ";
                    cin>>flight_code;
                    break;
                case 3:
                    cout<<"\n\tEnter Source   : ";
                    cin>>source;
                    break;
                case 4:
                    cout<<"\n\tEnter Destination   : ";
                    cin>>destination;
                    break;
                case 5:
                    cout<<"\n\tEnter Date(dd/mm/yyyy)   : ";
                    cin>>fdate;
                    break;
                case 6:
                    cout<<"\n\tEnter Arrival Time(hh:mm)   : ";
                    cin>>arrival;
                    break;
                case 7:
                    cout<<"\n\tEnter Departure Time(hh:mm)    : ";
                    cin>>departure;
                    break;
                case 8:
                    cout<<"\n\tEnter Price   : ";
                    cin>>price;
                    break;
                case 9:
                    cout<<"\n\tEnter Availability(YES/NO)    : ";
                    cin>>favail;
                    break;
                default:
                    f.admin();
                }
                file1<<" "<<flightno<<" "<<flight_code<<" "<<source<<" "<<destination<<" "<<fdate<<" "<<arrival<<" "<<departure<<" "<<price<<" "<<favail<<"\n";
                found++;
            }
            file>>flightno>>flight_code>>source>>destination>>fdate>>arrival>>departure>>price>>favail;
            if(found==0)
            {
                cout<<"\n\t\tFlight No. NOT FOUND...!";
            }
        }
        file1.close();
        file.close();
        remove("FlightRecord.txt");
        rename("frecord.txt","FlightRecord.txt");
    }

}

void Flight::searchFlight()
{
    system("cls");
    fstream file;
    int found=0;
    file.open("FlightRecord.txt",ios::in);
    if(!file)
    {
        cout<<"\n\t\t\tERROR: File doesn't exist";
        file.close();
        getch();
        f.admin();
    }
    else
    {
        string fno;
        cout<<"\n\t*********************************SEARCH FLIGHT*********************************\n\n";
        cout<<"\n\tEnter Flight No. of FLIGHT you want to SEARCH: ";
        cin>>fno;
        file>>flightno>>flight_code>>source>>destination>>fdate>>arrival>>departure>>price>>favail;
        while(!file.eof())
        {
            if(fno==flightno)
            {
                cout<<endl<<"\t\tFlight No.         : "<<flightno;
                cout<<endl<<"\t\tFlight Code        : "<<flight_code;
                cout<<endl<<"\t\tSource             : "<<source;
                cout<<endl<<"\t\tDestination        : "<<destination;
                cout<<endl<<"\t\tDate               : "<<fdate;
                cout<<endl<<"\t\tArrival Time       : "<<arrival;
                cout<<endl<<"\t\tDeparture Time     : "<<departure;
                cout<<endl<<"\t\tPrice              : "<<price;
                cout<<endl<<"\t\tAvailability       : "<<favail;
                cout<<endl;
                found++;
            }
            file>>flightno>>flight_code>>source>>destination>>fdate>>arrival>>departure>>price>>favail;
        }
        if(found==0)
        {
            cout<<"\n\t\tFlight No. NOT FOUND...!";
        }
        file.close();
    }
}


void Flight::delFlight()
{
    system("cls");
    fstream file,file1;
    int found=0;
    string fno;
    cout<<"\n\t*************************************DELETE FLIGHT*************************************\n\n";
    file.open("FlightRecord.txt",ios::in);
    if(!file1)
    {
        cout<<"\n\t\t\tERROR: File doesn't exist";
        file.close();
        getch();
        f.admin();
    }
    else
    {
        cout<<"\n\t\tEnter Flight No. of FLIGHT you want to DELETE: ";
        cin>>fno;
        file1.open("frecord.txt",ios::app|ios::out);
        file>>flightno>>flight_code>>source>>destination>>fdate>>arrival>>departure>>price>>favail;
        while(!file.eof())
        {
            if(fno!=flightno)
            {
                file1<<" "<<flightno<<" "<<flight_code<<" "<<source<<" "<<destination<<" "<<fdate<<" "<<arrival<<" "<<departure<<" "<<price<<" "<<favail<<"\n";
            }
            else
            {
                found++;
                cout<<"\n\t\tFlight Deleted Successfully!!!";
            }
            file>>flightno>>flight_code>>source>>destination>>fdate>>arrival>>departure>>price>>favail;
        }
        if(found==0)
        {
            cout<<"\n\t\tFlight No. NOT FOUND...!";
        }
        file1.close();
        file.close();
        remove("FlightRecord.txt");
        rename("frecord.txt","FlightRecord.txt");
    }
}


void Flight::bookTicket()
{
    system("cls");
    fstream file1;
    string pid2;
    bool found1=0,found2=0,found3=0;
    srand((unsigned) time(NULL));
    int rseat;
    cout<<"\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^BOOK TICKET^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n";
    cout<<"\n\tEnter Flight No.        : ";
    cin>>flightno;
    found1=f.searchFno(flightno);
    if(!found1)
    {
        cout<<"\n\t\tPlease enter valid Flight No. !";
        getch();
        f.user();
    }
    found2=f.flightAvailability(flightno);
    if(found2)
    {
        cout<<"\n\t\tFlight is not available !";
        getch();
        f.user();
    }

    cout<<"\tEnter Flight Class\n\t(F/B/E)                 : ";
    cin>>fclass;
    cout<<"\tEnter Passenger Id      : ";
    cin>>pid;
    cout<<"\tEnter Name              : ";
    cin>>pname;
    cout<<"\tEnter Phone Number      : ";
    cin>>pnum;
    cout<<"\tEnter Address           : ";
    cin>>paddr;
    if(fclass=="E" || fclass=="e")
    {
        rseat=1+(rand() % 190);
        fseat= to_string(rseat)+"E";
    }
    else if(fclass=="B" || fclass=="b")
    {
        rseat=1+(rand() % 50);
        fseat= to_string(rseat)+"B";
    }
    else if(fclass=="F" || fclass=="f")
    {
        rseat=1+(rand() % 20);
        fseat= to_string(rseat)+"F";
    }
    else
    {
        rseat=1+(rand() % 190);
        fseat= rseat;
    }
    file1.open("PassengerRecord.txt",ios::app|ios::out);
    file1<<" "<<pid<<" "<<pname<<" "<<pnum<<" "<<paddr<<" "<<flightno<<" "<<fclass<<" "<<fseat<<"\n";
    file1.close();
}

void Flight::cancelTicket()
{
    system("cls");
    fstream file,file1;
    int found=0;
    string pd;
    cout<<"\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^CANCEL TICKET^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n";
    file.open("PassengerRecord.txt",ios::in);
    if(!file)
    {
        cout<<"\n\t\t\tERROR: File doesn't exist";
        file.close();
        getch();
        f.user();
    }
    else
    {
        cout<<"\n\tEnter the Passenger Id  : ";
        cin>>pd;
        file1.open("precord.txt",ios::app|ios::out);
        file>>pid>>pname>>pnum>>paddr>>flightno>>fclass>>fseat;
        while(!file.eof())
        {
            if(pd!=pid)
            {
                file1<<" "<<pid<<" "<<pname<<" "<<pnum<<" "<<paddr<<" "<<flightno<<" "<<fclass<<" "<<fseat<<"\n";
            }
            else
            {
                found++;
                cout<<"\n\t\tTicket cancelled successfully!!!";
            }
            file>>pid>>pname>>pnum>>paddr>>flightno>>fclass>>fseat;
        }
        if(found==0)
        {
            cout<<"\n\t\tPassenger Id NOT FOUND...!";
        }
        file1.close();
        file.close();
        remove("PassengerRecord.txt");
        rename("precord.txt","PassengerRecord.txt");
    }
}

void Flight::showTicket()
{
    system("cls");
    fstream file,file1;
    int found=0,found1=0;
    string pid2,flightno2,pd,fno;
    string pname1,fno1,fseat1,fdate1,departure1,source1,destination1;
    file.open("FlightRecord.txt",ios::in);
    file1.open("PassengerRecord.txt",ios::in);
    if(!file1)
    {
        cout<<"\n\t\t\tERROR: File doesn't exist";
        file.close();
        getch();
        f.user();
    }
    else
    {
        cout<<"\n\n\t\tEnter the Passenger Id: ";
        cin>>pd;
        file1>>pid>>pname>>pnum>>paddr>>flightno2>>fclass>>fseat;
        file>>flightno>>flight_code>>source>>destination>>fdate>>arrival>>departure>>price>>favail;
        while(!file1.eof())
        {
            if(pd==pid)
            {
                pname1=pname;
                fno1=flightno2;
                fseat1=fseat;
                found1++;
            }
            file1>>pid>>pname>>pnum>>paddr>>flightno2>>fclass>>fseat;
        }
        if(found1==0)
        {
            cout<<"\n\t\tPassenger Id NOT FOUND...!";
            file1.close();
            file.close();
            getch();
            f.user();
        }
        while(!file.eof())
        {
            if(fno1==flightno)
            {
                fdate1=fdate;
                departure1=departure;
                source1=source;
                destination1=destination;
                cout<<"\n\n\n----------------------------------------------------------------------------------------------------------\n";
                cout<<"\n\n\t\tPassenger Name : "<<pname1;
                cout<<"\n\n\t\tFlight No. : "<<fno1;
                cout<<"\t\t\t\tSeat No. : "<<fseat1;
                cout<<"\n\n\t\tDate : "<<fdate1;
                cout<<"\t\t\t\tTime : "<<departure1;
                cout<<"\n\n\t\tFrom : "<<source1;
                cout<<"\t\t\t\t\tTo : "<<destination1;
                cout<<"\n\n\n----------------------------------------------------------------------------------------------------------\n";
                found++;
            }
            file>>flightno>>flight_code>>source>>destination>>fdate>>arrival>>departure>>price>>favail;
        }
        if(found==0)
        {
            cout<<"\n\t\tFlight is not available.\n";
        }
        file1.close();
        file.close();
    }
}

bool Flight::searchFno(string fn)
{
    fstream file;
    int found=0;
    file.open("FlightRecord.txt",ios::in);
    file>>flightno>>flight_code>>source>>destination>>fdate>>arrival>>departure>>price>>favail;
    while(!file.eof())
    {
        if(fn == flightno)
        {
            found++;
            file.close();
            return true;
        }
        file>>flightno>>flight_code>>source>>destination>>fdate>>arrival>>departure>>price>>favail;
    }
    if(found==0)
    {
        file.close();
        return false;
    }
    file.close();
}


bool Flight::flightAvailability(string fn)
{
    fstream file;
    int found=0;
    file.open("FlightRecord.txt",ios::in);
    file>>flightno>>flight_code>>source>>destination>>fdate>>arrival>>departure>>price>>favail;
    while(!file.eof())
    {
        if(fn == flightno)
        {
            if((favail=="NO") || (favail=="No") || (favail=="no"))
            {
                found++;
                file.close();
                return true;
            }
            else
            {
                file.close();
                return false;
            }
        }
        file>>flightno>>flight_code>>source>>destination>>fdate>>arrival>>departure>>price>>favail;
    }
    if(found==0)
    {
        file.close();
        return false;
    }
    file.close();
}
