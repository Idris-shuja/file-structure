#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<ctime>
#include<conio.h>
using namespace std;

class homecare_a
{
	string buffer,aname,adetails,aid,aprice;
	string aidlist[100];
    int count,addlist[100];
 	public:

 		void createindex();
 		string extractaid(string);
 		void sortindex();
 		void insert();
 		void display_equipment();
 		void print();
 		void search(string);
 		int searchindex(string);
 		void remove(string);

 		/* index list */
 		void index_create();
 		string aid_extract(string);
 		void index_sort();
} a;

class hospitalcare_b
{
    public:
        string bid,bprice,bdetails,bname;
        string bidlist[100];
        int count,addlist[100];
        void createindex();
        void insert();
        void display_b_record();
        void print();
        void remove(string);
        int searchindex(string);
        void search(string);
        void sortindex();
        string extractbid(string);

        /* index list */
 		void index_create();
 		string bid_extract(string);
 		void index_sort();
}b;

void homecare_a::index_create() {
    fstream file;
	int pos;

	string buffer,aid;
     	count=-1;
     	file.open("homecare_equipment.txt",ios::in);
     	while(!file.eof())
	{
           pos=file.tellg();
           buffer.erase();
           getline(file,buffer);
           if(buffer[0]!='*')
           {
                      if(buffer.empty())
                      break;
                      aid=aid_extract(buffer);
                      aidlist[++count]=aid;
                      addlist[count]=pos;
           }
     }
     file.close();
     index_sort();
     buffer.erase();
 }
 string homecare_a::aid_extract(string buffer)
 {
     string aid;
     int i=0;
     aid.erase();
     while(buffer[i]!='|')
     aid+=buffer[i++];
     return aid;
 }
 void homecare_a::index_sort()
 {
     int i,j,tempadd;
     string tempid;
     for(i=0;i<=count;i++)
     {
           for(j=i+1;j<=count;j++)
           {
               if(aidlist[i]>aidlist[j])

                {
                      tempid=aidlist[i];
			          aidlist[i]=aidlist[j];
                      aidlist[j]=tempid;
                      tempadd=addlist[i];

                      addlist[i]=addlist[j];
                      addlist[j]=tempadd;
                }
           }
     }

     cout<<"\n-------INDEXLIST--------\n";
     cout<<"\n ID\tINDEX";
     for(i=0;i<=count;i++)
     cout<<"\n"<<aidlist[i]<<"\t"<<addlist[i]<<endl;

 }

 void hospitalcare_b::index_create() {
    fstream file;
	int pos;
	string buffer,bid;
    count=-1;
    file.open("hospitalcare_equipment.txt",ios::in);
    while(!file.eof())
	{
       pos=file.tellg();
       buffer.erase();
       getline(file,buffer);
       if(buffer[0]!='*')
       {
          if(buffer.empty())
             break;
          bid=bid_extract(buffer);
          bidlist[++count]=bid;
          addlist[count]=pos;
       }
    }
    file.close();
    index_sort();
    buffer.erase();
 }
 string hospitalcare_b::bid_extract(string buffer)
 {
     string bid;
     int i=0;
     bid.erase();
     while(buffer[i]!='|')
     bid+=buffer[i++];
     return bid;
 }
 void hospitalcare_b::index_sort()
 {
     int i,j,tempadd;
     string tempid;
     for(i=0;i<=count;i++)
     {
           for(j=i+1;j<=count;j++)
           {
               if(bidlist[i]>bidlist[j])

                {
                      tempid=bidlist[i];
			          bidlist[i]=bidlist[j];
                      bidlist[j]=tempid;
                      tempadd=addlist[i];

                      addlist[i]=addlist[j];
                      addlist[j]=tempadd;
                }
           }
     }

     cout<<"\n-------INDEXLIST--------\n";
     cout<<"\n ID\tINDEX";

     for(i=0;i<=count;i++)
     cout<<"\n"<<bidlist[i]<<"\t"<<addlist[i]<<endl<<endl;

 }

void homecare_a::createindex() {
    fstream file;
	int pos;
	string buffer,aid;
     	count=-1;
     	file.open("homecare_equipment.txt",ios::in);
     	while(!file.eof())
	{
           pos=file.tellg();
           buffer.erase();
           getline(file,buffer);
           if(buffer[0]!='*')
           {
                      if(buffer.empty())
                      break;
                      aid=extractaid(buffer);
                      aidlist[++count]=aid;
                      addlist[count]=pos;
           }
     }
     file.close();
     sortindex();
     buffer.erase();
 }

 void homecare_a::insert()
 {
     string buffer,aname,adetails,aid,aprice;
     int pos;
     fstream fp;

	 cout << "\nEnter Home Care Equipment ID\n";
     cin >> aid;
     cout << "\nEnter Home Care Equipment Name\n";
     cin >> aname;
     cout << "\nEnter Home Care Equipment Price\n";
     cin >> aprice;
     cout << "\nEnter Home Care Equipment Details\n";
     cin >> adetails;

     buffer=aid+"|"+aname+"|"+adetails+"|"+aprice+" $\n";
     fp.open("homecare_equipment.txt",ios::out|ios::app);
     pos=fp.tellp();
     fp<<buffer;
     fp.close();
     aidlist[++count]=aid;
     addlist[count]=pos;
     sortindex();
     cout<<"\nHome Care Equipment Added Successfully....\n";
 }

 string homecare_a::extractaid(string buffer)
 {
     string aid;
     int i=0;
     aid.erase();
     while(buffer[i]!='|')
     aid+=buffer[i++];
     return aid;
 }

 void homecare_a::sortindex()
 {
     int i,j,tempadd;
     string tempid;
     for(i=0;i<=count;i++)
     {
           for(j=i+1;j<=count;j++)
           {
               if(aidlist[i]>aidlist[j])

                {
                      tempid=aidlist[i];
			          aidlist[i]=aidlist[j];
                      aidlist[j]=tempid;
                      tempadd=addlist[i];

                      addlist[i]=addlist[j];
                      addlist[j]=tempadd;
                }
           }
     }

 }

 void homecare_a::search(string key)
 {
     int pos=0,t;
     string buffer;
     fstream file;
     buffer.erase();
     pos=searchindex(key);
     if(pos==-1)
     	cout<<"Equipment not found\n";
     else if(pos>=0)
     {
           file.open("homecare_equipment.txt");
           t=addlist[pos];
           file.seekp(t,ios::beg);
           getline(file,buffer);
           cout<<"Equipment found\n";
           //cout<<"\nRecord:\n"<<buffer;
           file.close();
     }
 }

 int homecare_a::searchindex(string key)
 {
     int low=0,high=count,mid=0,flag=0;
     while(low<=high)
     {
           mid=(low+high)/2;
           if(aidlist[mid]==key)
           {
                flag=1;
                break;
           }
           else if(aidlist[mid]<key)
                low=mid+1;
           else if(aidlist[mid]>key)
                high=mid-1;
     }
     if(flag)
           return mid;
     else
           return -1;
 }

 void homecare_a::remove(string key)
 {
  	fstream fp;
 	char delch='*';
	int pos=0,i,address;
	string buffer,aid,aname,aprice,adetails;
	fstream file;
  	pos=searchindex(key);
  	if(pos>=0)
  	{
       file.open("homecare_equipment.txt");
       address=addlist[pos];
       file.seekp(address,ios::beg);
       file.put(delch);
       file.close();
       cout<<"Equipment has been deleted\n";
       for(i=pos;i<count;i++)
       {
       aidlist[i]=aidlist[i+1];
       addlist[i]=addlist[i+1];
       }
      count--;
  }  else
       cout<<"Equipment not found\n";

 }//////////
 int astric() {
  
      std::ifstream inputFile("homecare_equipment.txt"); // Replace "example.txt" with the actual file path

    
    if (!inputFile) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    std::string line;

    while (std::getline(inputFile, line)) {
        if (line.find('*') == std::string::npos) {
            std::cout << line << std::endl;
        }
    }

    inputFile.close();

    return 0;
}




////////////
  void homecare_a::display_equipment(){
    int x=astric();
    if(x)
     return;
     cout<<"2\n";

      std::ifstream f("homecare_equipment.txt");

   // if (f.is_open())
      //  std::cout << f.rdbuf();
 }
 void homecare_a::print()
 {
    
	cout<<"Equipment ID:"<<aid<<" Equipment Name:"<<aname<<" Details:"<<adetails<<" Price:"<<aprice<<endl;
 }

void hospitalcare_b::createindex() {
    fstream file;
	int pos;
	string buffer,bid;
    count=-1;
    file.open("hospitalcare_equipment.txt",ios::in);
    while(!file.eof())
	{
       pos=file.tellg();
       buffer.erase();
       getline(file,buffer);
       if(buffer[0]!='*')
       {
          if(buffer.empty())
             break;
          bid=extractbid(buffer);
          bidlist[++count]=bid;
          addlist[count]=pos;
       }
    }
    file.close();
    sortindex();
    buffer.erase();
 }

 void hospitalcare_b::insert()
 {
    string buffer,bname,bdetails,bid,bprice;
    int pos;
    fstream fp;

	cout << "\nEnter Hospital Care Equipment ID\n";
    cin >> bid;
    cout << "\nEnter Hospital Care Equipment Name\n";
    cin >> bname;
    cout << "\nEnter Hospital Care Equipment Details\n";
    cin >> bdetails;
    cout << "\nEnter Hospital Care Equipment Price\n";
    cin >> bprice;

    buffer=bid+"|"+bname+"|"+bdetails+"|"+bprice+" $\n";
    fp.open("hospitalcare_equipment.txt",ios::out|ios::app);
    pos=fp.tellp();
    fp<<buffer;
    fp.close();
    bidlist[++count]=bid;
    addlist[count]=pos;
    sortindex();
    cout<<"\nHospital Care Equipment Added Successfully....\n";
 }

 string hospitalcare_b::extractbid(string buffer)
 {
     string bid;
     int i=0;
     bid.erase();
     while(buffer[i]!='|')
     bid+=buffer[i++];
     return bid;
 }
 void hospitalcare_b::sortindex()
 {
     int i,j,tempadd;
     string tempid;
     for(i=0;i<=count;i++)
     {
           for(j=i+1;j<=count;j++)
           {
               if(bidlist[i]>bidlist[j])

                {
                      tempid=bidlist[i];
			          bidlist[i]=bidlist[j];
                      bidlist[j]=tempid;
                      tempadd=addlist[i];

                      addlist[i]=addlist[j];
                      addlist[j]=tempadd;
                }
           }
     }

 }

 void hospitalcare_b::search(string key)
 {
     int pos=0,t;
     string buffer;
     fstream file;
     buffer.erase();
     pos=searchindex(key);
     if(pos==-1)
         cout<<"Equipment not found\n";
     else if(pos>=0)
     {
           file.open("hospitalcare_equipment.txt");
           t=addlist[pos];
           file.seekp(t,ios::beg);
           getline(file,buffer);
           cout<<"Equipment found\n";
           //cout<<"\nRecord:"<<buffer;
           file.close();
     }
 }

 int hospitalcare_b::searchindex(string key)
 {
     int low=0,high=count,mid=0,flag=0;
     while(low<=high)
     {
           mid=(low+high)/2;
           if(bidlist[mid]==key)
           {
                flag=1;
                break;
           }
           else if(bidlist[mid]<key)
                low=mid+1;
           else if(bidlist[mid]>key)
                high=mid-1;
     }
     if(flag)
           return mid;
     else
           return -1;
 }

 void hospitalcare_b::remove(string key)
 {
  	fstream fp;
 	char delch='*';
	int pos=0,i,address;
	string buffer,bid,bname,bprice,bdetails;
	fstream file;
  	pos=searchindex(key);
  	if(pos>=0)
  	{
       file.open("hospitalcare_equipment.txt");
       address=addlist[pos];
       file.seekp(address,ios::beg);
       file.put(delch);
       file.close();
       cout<<"Equipment has been deleted\n";
       for(i=pos;i<count;i++)
       {
       bidlist[i]=bidlist[i+1];
       addlist[i]=addlist[i+1];
       }
      count--;
  }  else
       cout<<"Equipment not found\n";


 }
  void hospitalcare_b::display_b_record(){
     cout<<"The Hospital Care Equipment Details are\n";
     std::ifstream f("hospitalcare_equipment.txt");

    if (f.is_open())
        std::cout << f.rdbuf();

 }
 void hospitalcare_b::print()
 {
	cout<<"Equipment ID:"<<bid<<" Equipment Name:"<<bname<<" Equipment Details: "<<bdetails<<" Equipment Price:" <<bprice<<endl;
 }

/*------------------Main()----*/


 int main()
 {
     int ch;
     string key;
     string custname, custphno, custaddr, aprice, bprice;
     char ans;
     homecare_a a;
     hospitalcare_b b;


     a.createindex();
     b.createindex();

     mainpage:

    	while(1)
    	{
            int ach,bch,cch;
            string username="admin",password="admin",u,p;
            int i=0;
            char ab;
            cout<<"\n\t******* MEDICAL EQUIPMENT RENTAL SYSTEM *******\n";
            cout<<"\n\t\tEnter \n\t\t1. Admin\n\t\t2. Customers for Home Care\n\t\t3. Customers for Hospital Care\n\t\t0. Exit\n";
			cout<<"\n\t***************************************************************\n";
            cout<<"\nEnter your choice\n";
            cin>>ch;
            switch(ch)
            {
   		    	case 1: cout<<"Enter your username\n";
                    	cin>>u;
                    	cout<<"Enter your password\n";
                    	//cin>>p;


                    	while((ab = getch())!=13)
                        {



                                cout<<"*";
                                  p[i]=ab;
                                i++;


                            }
                            p[i]='\0';



                    	//if(u==username && p==password)
                    	{
                        	int adch;
                        	cout<<"\nWelcome Admin\n";
                        	admin:
          					while(1)
          					{
							cout<<"----------------------\n";
  								cout<<"|   ADMIN SECTION     |\n";
  								cout<<"----------------------\n";
  								cout<<"\n1. Home Care Equipment \n2. Hospital Care Equipment\n(0) <<-- BACK\n";
  								cout<<"\nEnter your choice\n";
  								cin>>adch;
  								switch(adch)
  								{
  									case 1: while(1)
  											{
  												int a_ch;
  	cout<<"-----------------------** HOME CARE EQUIPMENT **---------------------------\n";
  	cout<<"\n1. Add Equipment \t\t\t2. Display Equipment\n3. Delete Equipment\t\t4. View index List\n\n\t\t\t(0) <<-- BACK\n";
  	cout<<"--------------------------------------------------------------\n";
  	cout<<"\nEnter your choice\n";
  	cin>>a_ch;
  	switch(a_ch)
  	{
  		case 1:a.insert();
               break;
        case 2:a.display_equipment();
               break;
        case 3:cout<<"Enter Equipment ID :";
               cin>>key;
               a.remove(key);
               cout<<"File is Updated\n";

               break;
        case 4:a.index_create();
        	   break;
        case 0:goto admin;
         	   break;
        default: cout<<"Invalid choice";
  	}
  	}
  	break;
  	case 2: while(1)
  	{
  		int b_ch;
  	cout<<"-----------------------** HOSPITAL CARE EQUIPMENT **---------------------------\n";
  	cout<<"\n1. Add Equipment \t\t\t2. Display Equipment\n3. Delete Equipment\t\t4. View index list\n\n\t\t\t(0) <<-- BACK\n";
  	cout<<"--------------------------------------------------------------\n";
  	cout<<"\nEnter your choice\n";
  	cin>>b_ch;
  		switch(b_ch)
  		{
  			case 1: b.insert();
               		break;
        	case 2:	b.display_b_record();
               		break;
        	case 3:	cout<<"Enter Equipment ID :";
               		cin>>key;
               		b.remove(key);
               		cout<<"File is Updated :\n";

               		break;
        	case 4:	b.index_create();
        			break;
         	case 0:	goto admin;
         			break;
         	default: cout<<"Invalid choice";
  		}
  	}
  	break;

  	case 3: while(1)
  	{

  	break;


  	case 0: goto mainpage;
  			break;
  	default: cout<<"Invalid choice";
  			}
  		}
  }}
 // else
//cout<<"Invalid Credentials\n";
  //break;



        	case 2:cout<<"Welcome Customer for Home Care\n";
        		   cout<<"----------------------------\n";
  				   cout<<"|      CUSTOMER CREDENTIALS      |\n";
  				   cout<<"----------------------------\n";


                   cout<<"1. Enter Customer Details \n2. Display Catalogue\n\n\t\t(0) <<--BACK\n";
                   cout<<"------------------------\n";
                   cout<<"Enter your choice \n";
                   cin>>ach;
                   switch(ach)
                   {
                      case 1: cout<<"Enter Name\n";
                              cin>>custname;
                              cout<<"Enter Phone Number\n";
                              cin>>custphno;
                              cout<<"Enter Address\n";
                              cin>>custaddr;
                              cout<<"---------\n";
                              cout<<"Do you want to see the catalogue? Press Y or N \n";
                              cin>>ans;
                              if (ans =='Y'||ans=='y')
                              {
                                  a.display_equipment();
                              }
                              cout<<"\n\n";
                              cout<<"-------------------------------------------------\n";
                              cout<<"----------------PLACING THE ORDER-----------------\n";
                              cout<<"\n\n";
                              cout<<"Enter the ID of the Equipment you want to order\n";
                              cin>>key;
                              a.search(key);

                              cout<<"\n\n\n";
                              cout<<"-------------------------------------------------\n";
                              cout<<"------------------BILL GENERATED------------------\n";
                              cout<<"-------------------------------------------------\n";
                              cout<<"NAME: ";
                              cout<<custname;
                              cout<<"\n";
                              cout<<"PHONE: ";
                              cout<<custphno;
                              cout<<"\n";
                              cout<<"ADDRESS: ";
                              cout<<custaddr;
                              cout<<"\n";
                              cout<<"EQUIPMENT ID: ";
                              cout<<key;
                              cout<<"\n";
                              cout<<"EQUIPMENT DETAILS: ";
                              a.search(key);
                              cout<<"\n";
                              if (key=="1005")
                              {
                                  cout<<"PRICE: 2000";
                              }
                              else if (key=="1006")
                              {
                                  cout<<"PRICE: 5000";
                              }
                              else
                              {
                                  cout<<"PRICE: 1000";
                              }
                              cout<<"\n";

                              cout<<"--------------------------------------------------------------\n";


                            break;



            	      case 2: a.display_equipment();
            	      cout<<"------------------------------------------------------------------\n";
                              cout<<"Enter the ID of the Equipment you want to order\n";
                              cin>>key;
                              a.search(key);
             	              break;
             	      case 0: goto mainpage;
             	      default: cout<<"Invalid choice";
                   }
             break;

       		 case 3: cout<<"Welcome Customer for Hospital Care\n";
       		 		 cout<<"-----------------------\n";
  					 cout<<"|   CUSTOMER CREDENTIALS     |\n";
  					 cout<<"-----------------------\n";

                      cout<<"1. Enter Customer Details \n2. Display Catalogue\n\n\t\t(0) <<--BACK\n";
                   cout<<"------------------------\n";
                   cout<<"Enter your choice \n";
                     cin>>bch;
                     switch(bch)
                     {
                       case 1: cout<<"Enter Name\n";
                              cin>>custname;
                              cout<<"Enter Phone Number\n";
                              cin>>custphno;
                              cout<<"Enter Address\n";
                              cin>>custaddr;
                              cout<<"---------\n";
                              cout<<"Do you want to see the catalogue? Press Y or N \n";
                              cin>>ans;
                              if (ans =='Y'||ans=='y')
                              {
                                  b.display_b_record();
                              }
                              cout<<"\n\n";
                              cout<<"-------------------------------------------------\n";
                              cout<<"----------------PLACING THE ORDER-----------------\n";
                              cout<<"\n\n";
                              cout<<"Enter the ID of the Equipment you want to order\n";
                              cin>>key;
                              b.search(key);

                              cout<<"\n\n\n";
                              cout<<"-------------------------------------------------\n";
                              cout<<"------------------BILL GENERATED------------------\n";
                              cout<<"-------------------------------------------------\n";
                              cout<<"NAME: ";
                              cout<<custname;
                              cout<<"\n";
                              cout<<"PHONE: ";
                              cout<<custphno;
                              cout<<"\n";
                              cout<<"ADDRESS: ";
                              cout<<custaddr;
                              cout<<"\n";
                              cout<<"EQUIPMENT ID: ";
                              cout<<key;
                              cout<<"\n";
                              cout<<"EQUIPMENT DETAILS: ";
                              b.search(key);
                              cout<<"\n";

                              if (key=="1011")
                              {
                                  cout<<"PRICE: 4000";
                              }
                              else if (key=="1012")
                              {
                                  cout<<"PRICE: 2000";
                              }
                              else
                              {
                                  cout<<"PRICE: 1000";
                              }
                              cout<<"\n";




                              cout<<"--------------------------------------------------------------\n";


                            break;
   		       	       case 2: b.display_b_record();
   		       	       cout<<"--------------------------------------------------------\n";
                              cout<<"Enter the ID of the Equipment you want to order\n";
                              cin>>key;
                              b.search(key);
   		       	               break;
   		       	       case 0: goto mainpage;
   		       	       default: cout<<"Invalid choice";
                      }
              break;



        	  case 0:exit(0);
        	  default: cout<<"Invalid Choice";


     	}
 	}
 }
