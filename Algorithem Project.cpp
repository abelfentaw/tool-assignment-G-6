#include<iostream>
#include<conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <dos.h>
#define max 50
using namespace std;
void EmployeeInfo();
void DisplayEmployee();
void AddEmpAtTheBeginning();
void AddEmpAttTheEnd();
struct dllstud
{
    int age;
    int size;
    char na[20];
    char brand[20];
    char name[20];
    char job[20];
    dllstud *nxt,*prv;
};
dllstud *start=NULL,*last=NULL;

void main2()//abel
{
    int ch;
     system("Color B");
cout<<"1. Employee Information\n";
cout<<"2. Shoes Information\n";
cout<<"3. Group Members Of The Project\n";
    cout<<"Insert Your Choice \n";
    cin>>ch;
    system("CLS");
    switch(ch)
    {
  case 1:
        EmployeeInfo();
        break;
   case 2:
    	ShoesInfo();
    	break;
	case 3:
	    GroupMembers();
	    break;
	default:
	{
		cout<<"invalid number\n";
		main2();
	}
		break;
    }
}
void EmployeeInfo()
{
    int em;
    cout<<"1.To Add Employee"<<endl;
    cout<<"2.To Delete Employee"<<endl;
    cout<<"3.To Display Employee"<<endl;
    cout<<"4.To Search An Employee"<<endl;
    cout<<"5.Back To Main"<<endl;
    cin>>em;
    system("CLS");
    switch (em)
    {
   case 1:
    int add;
    cout<<"1.Add Employee At The Beginning"<<endl;
    cout<<"2.Add Employee At The Middle"<<endl;
    cout<<"3.Add Employee At The End"<<endl;
    cout<<"4.Back To Previous"<<endl;
    cin>>add;
    system("CLS");
    if (add==1)
        AddEmpAtTheBeginning();
        if (add==2){
        		cout<<"enter the node number you went to insert"<<endl;
			 	int k;
			 	cin>>k;
			 	    system("CLS");
			 AddEmpAtTheMiddle(k);
		}
    else if(add==3)
        AddEmpAttTheEnd();
     else if(add==4)
     	EmployeeInfo();
	break;
   case 2:
    int de;
    cout<<"1.Delete Employee At The Beginning"<<endl;
    cout<<"2.Delete Employee At The End"<<endl;
      cout<<"3.Back To Previous"<<endl;
    cout<<"4.Back To Main"<<endl;
    cin>>de;
    system("CLS");
    if (de==1)
        DeleteEmpAtTheBeginning();
    else if(de==2)
    	 DeleteEmpAtTheEnd();
     else if(de==3)
     EmployeeInfo();
      else if(de==4)
     	main2();
	break;
case 3:
	{
        DisplayEmployee();
    EmployeeInfo();
	}
		break;
   case 4:
	{
    	SearchEmployee();
     EmployeeInfo();
	}
		break;
    case 5:
    	main2();
}
}

void DisplayEmployee()
{
    dllstud *temp2;
    if(start==NULL||last==NULL)
        cout<<"list is empty \n";
    else
    {
        temp2=start;
        while(temp2!=NULL)
        {

            cout<<"Your name is "<<temp2->name<<endl;
         cout<<"Your age is "<<temp2->age<<endl;
               cout<<"Your job is "<<temp2->job<<endl;
            cout<<endl;
            temp2=temp2->nxt;
        }
    }
}
void AddEmpAtTheBeginning()
{
    dllstud *temp;
    temp=new dllstud;
    cout<<"Enter Name \n";
    cin>>temp->name;
    system("CLS");
    cout<<"Enter Age\n";
    cin>>temp->age;
    system("CLS");
    cout<<"Enter Job\n";
    cin>>temp->job;
    system("CLS");
    temp->nxt=NULL;
    temp->prv=NULL;
    if(start==NULL||last==NULL)
    {
        start=temp;
        last=temp;
    }
    else
    {
        temp->nxt=start;
        start->prv=temp;
        start=temp;
    }
    EmployeeInfo();
}
	void AddEmpAtTheMiddle(int key)
	{

			dllstud *temp=new dllstud;
	   cout<<"Enter Name \n";
    cin>>temp->name;
    system("CLS");
    cout<<"Enter Age\n";
    cin>>temp->age;
    system("CLS");
    cout<<"Enter Job\n";
    cin>>temp->job;
    system("CLS");
    int c=1;
    dllstud *x=start,*y;
    while(c<key)
	{
	y=x;
	x=x->nxt;
	c++;
	}
x->prv=temp;
temp->nxt=x;
y->nxt=temp;
temp->prv=y;

 EmployeeInfo();
	}
	void AddEmpAttTheEnd()
{
    dllstud *temp;
    temp=new dllstud;
    cout<<"Enter Name \n";
    cin>>temp->name;
    system("CLS");
    cout<<"Enter Age\n";
    cin>>temp->age;
    system("CLS");
    cout<<"Enter Job\n";
    cin>>temp->job;
    system("CLS");
    temp->nxt=NULL;
    temp->prv=NULL;
    if(start==NULL||last==NULL)
        start=last=temp;
    else
    {
        last->nxt=temp;
        temp->prv=last;
        last=temp;
    }
    EmployeeInfo();
}