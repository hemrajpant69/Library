// Library Management System NCIT
#include<iostream>
#include<conio.h>
using namespace std;
class library
{ 
   private:
	struct Node
	{
		int id;
		string name,author,publisher;
		Node *next_add;
	};
	public:
		Node *head=NULL;
		void menu();
		void insert();
		void search();
		void update();
		void del();
		void sort();
		void show();
		
};
void library::menu()
{
p:
system("cls");
int choice;
cout<<"\n\n\t\t\t========================================";
cout<<"\n\n\t\t\t====LIBRARY MANAGEMENT SYSTEM NCIT=======";
cout<<"\n\n\t\t\t========================================";
cout<<"\n\n 1. Insert New Record";
cout<<"\n\n 2.Search Record";
cout<<"\n\n 3.Update Record";
cout<<"\n\n 4.Delte Record";
cout<<"\n\n 5.Show ALl Record";
cout<<"\n\n 6.Exit";
cout<<"\n\n Enter Your choice : ";
cin>>choice;
switch(choice)
{
	case 1:
		insert();
		break;
	case 2:
		search();
		break;
	case 3:
	    update();
		break;
	case 4:
	    del();
		break;
	case 5:
	     sort();
	     show();
		break;
	case 6:
	    exit(0);
	default:
	    cout<<"\n\n Invalid Choice..Please Try Again.....";
	}
	getch();
	goto p;
}
void library::insert()
{
system("cls");
cout<<"\n\n\t\t\t========================================";
cout<<"\n\n\t\t\t====LIBRARY MANAGEMENT SYSTEM NCIT=======";
cout<<"\n\n\t\t\t========================================";	
Node *new_node=new Node;
cout<<"\n\n Book Id:";
cin>>new_node ->id;
cout<<"\n\n Name:";
cin>>new_node -> name;
cout<<"\n\n Author Name:";
cin>>new_node -> author;
cout<<"\n\n Publisher Name:";
cin>>new_node -> publisher;
new_node -> next_add=NULL;
if(head==NULL)
{
 head=new_node;	
}
else{
	Node *ptr =head;
	while(ptr -> next_add !=NULL)
	{
		ptr =ptr -> next_add;
	}
	ptr -> next_add = new_node;

}
cout<<"\n\n\t\t\t New Book Inserted Successfully....";
}
void library::search()
{
system("cls");
int t_id,found=0;
cout<<"\n\n\t\t\t========================================";
cout<<"\n\n\t\t\t====LIBRARY MANAGEMENT SYSTEM NCIT=======";
cout<<"\n\n\t\t\t========================================";
if(head==NULL)
{
cout<<"\n\n Linked List is Empty....";
}
else{
	cout<<"\n\n BOOK ID:";
	cin>>t_id;
	 Node *ptr=head;
	 while(ptr !=NULL)
	 {
	 	if(t_id==ptr -> id)
	 	{
	 	system("cls");
        cout<<"\n\n\t\t\t========================================";
        cout<<"\n\n\t\t\t====LIBRARY MANAGEMENT SYSTEM NCIT=======";
        cout<<"\n\n\t\t\t========================================";  
		cout<<"\n\n BOOK ID : "<<ptr -> id;
		cout<<"\n\n BOOK NAME : "<<ptr -> name;
		cout<<"\n\n Author Name : "<<ptr -> author;
		cout<<"\n\n Publisher Name : "<<ptr -> publisher;
		found++;
		 }
		 ptr=ptr -> next_add;
	 }
	 if(found==0)
	 {
	 	cout<<"\n\n BOOK ID is Invalid......";
	 }
}	
}
void library::update()
{
system("cls");
int t_id,found=0;
cout<<"\n\n\t\t\t========================================";
cout<<"\n\n\t\t\t====LIBRARY MANAGEMENT SYSTEM NCIT=======";
cout<<"\n\n\t\t\t========================================";
if(head==NULL)
{
cout<<"\n\n Linked List is Empty....";
}
else{
	cout<<"\n\n BOOK ID:";
	cin>>t_id;
	 Node *ptr=head;
	 while(ptr !=NULL)
	 {
	 	if(t_id==ptr -> id)
	 	{
	 	system("cls");
        cout<<"\n\n\t\t\t========================================";
        cout<<"\n\n\t\t\t====LIBRARY MANAGEMENT SYSTEM NCIT=======";
        cout<<"\n\n\t\t\t========================================";  
		cout<<"\n\n Please Enter Details As Folloing Below...";
		cout<<"\n\n BOOK ID : ";
		cin>>ptr -> id;
		cout<<"\n\n BOOK NAME : ";
		cin>>ptr -> name;
		cout<<"\n\n Author Name : ";
		cin>>ptr -> author;
		cout<<"\n\n Publisher Name : ";
		cin>>ptr -> publisher;
		found++;
		cout<<"\n\n\t\t\t BOOK UPDATED SUCCESSFULLY...";
		 }
		 ptr=ptr -> next_add;
	 }
	 if(found==0)
	 {
	 	cout<<"\n\n BOOK ID is Invalid......";
	 }
}	
}
void library::del()
{
	system("cls");
int t_id,found=0;
cout<<"\n\n\t\t\t========================================";
cout<<"\n\n\t\t\t====LIBRARY MANAGEMENT SYSTEM NCIT=======";
cout<<"\n\n\t\t\t========================================";
if(head==NULL)
{
cout<<"\n\n Linked List is Empty....";
}
else{
	cout<<"\n\n BOOK ID:";
	cin>>t_id;	
	if(t_id==head -> id)
	{
		Node *ptr=head;
		head=head -> next_add;
		delete ptr;
		cout<<"\n\n BOOK DELETED SUCCESSFULLY....";
		found++;
	 }
	 else
	 {
	 Node *pre=head;
	 Node *ptr=head;
	 while(ptr !=NULL)
	 {
	 	if(t_id==ptr -> id)
	 	{
	 	  pre -> next_add = ptr -> next_add;
		   delete ptr;
		   cout<<"\n\n BOOK DELETED SUCCUSSFULLY....";
		   found++;
		   break;	
		 }
		 pre=ptr;
		 ptr=ptr -> next_add;
		 }	
	 } 
	 if(found==0)
	 {
	 	cout<<"\n\n BOOK ID IS INVALID......";
	 }
}
}
 void library::sort()
{

  if(head==NULL)
  {
  	system("cls");
  	cout<<"\n\n\t\t\t========================================";
    cout<<"\n\n\t\t\t====LIBRARY MANAGEMENT SYSTEM NCIT=======";
    cout<<"\n\n\t\t\t========================================";
  	cout<<"\n\n Linked List is Empty....";
  	getch();
  	menu();
   }
   	int count=0,t_id;
   	string t_name,t_author,t_publisher;
   Node *ptr =head;
   while(ptr!=NULL)
   {
   	 count++;
   	 ptr=ptr -> next_add;
   }
   for(int i=1;i<=count;i++)
   { 
      Node *ptr=head;
   	 for(int j=1;j<count;j++)
   	 {
   	 	if(ptr -> id >ptr -> next_add -> id)
   	 	{ 
   	 	    //save data into temp variable
   	 	   	t_id = ptr -> id;
   	 	   	t_name = ptr -> name;
   	 	   	t_author = ptr -> author;
   	 	   	t_publisher = ptr -> publisher;
   	 	   	//save data into current node
   	 	   	ptr -> id = ptr -> next_add -> id;
   	 	   	ptr -> name = ptr -> next_add -> name;
   	 	   	ptr -> author = ptr -> next_add -> author;
   	 	   	ptr -> publisher = ptr -> next_add -> publisher;
   	 	   	//save data into next node
   	 	   	ptr -> next_add -> id=t_id;
   	 	   	ptr -> next_add -> name=t_name;
   	 	   	ptr -> next_add -> author=t_author;
   	 	   	ptr -> next_add -> publisher=t_publisher;
		}
		ptr =ptr -> next_add;
	 }
   }
   	
} 
void library::show()
{
 system("cls");
cout<<"\n\n\t\t\t========================================";
cout<<"\n\n\t\t\t====LIBRARY MANAGEMENT SYSTEM NCIT=======";
cout<<"\n\n\t\t\t========================================";
	 Node *ptr=head;
	 while(ptr !=NULL)
	 {
	 
		cout<<"\n\n BOOK ID : "<<ptr -> id;
		cout<<"\n\n BOOK NAME : "<<ptr -> name;
		cout<<"\n\n Author Name : "<<ptr -> author;
		cout<<"\n\n Publisher Name : "<<ptr -> publisher;
		cout<<"\n\n=============================="; 
		ptr=ptr -> next_add;
	 }
	
}		
int main()
{
	library obj;
	obj.menu();
	return 0;
}
