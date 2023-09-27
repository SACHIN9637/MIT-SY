#include<iostream>
#include<cstring>
using namespace std;

class Node{ 

	public: 
	char trainame[10];
	int id;
	int trainnumber;	
	Node *next;
		
};

class sll{ 

	public: 
	Node *head;
	sll(){
	head = NULL;
	int len=0;
	}
	
	void create();
	void display();
	void insert();
	void del();
	void update();
	void search();
	void sort();
	void reverse();
};

void sll::create(){ 
	
	
	
	Node *temp, *p ; char ch;
  do{
  
	temp = new Node;
	cout<<"Enter Your Trainname: "<<endl;
	cin>>temp->trainame;
		
	cout<<"Enter your Trainnumber: "<<endl;
	cin>>temp->trainnumber;
	
	cout<<"Enter Your id: "<<endl;
	cin>>temp->id;
	
	temp->next = NULL;
	
	if(head==NULL){ 
	head=temp;
	}
	else{ 
	p=head;
	while(p->next!=NULL)
		p=p->next;
	p->next=temp;

	}
	cout<<"\n Do you want to add more nodes (y/n):  ";
	cin>>ch;
}while(ch=='y');
	
}


void sll::display(){
	
	Node *temp;
	temp = head;
	
	cout<<"Trainname \tTrainnumber \tid"<<endl;
	while(temp!=NULL){ 
	cout<<temp->trainame<<"\t\t"<<temp->trainnumber<<"\t\t"<<temp->id;
	cout<<endl;
	temp = temp->next;
	}
	
}

void sll::insert(){ 

	Node *temp,*p;
	temp = new Node;
	char ch;
	char info[50];
	
	cout<<"Enter Values to insert"<<endl;
	
	cout<<"Enter Your Trainname: "<<endl;
	cin>>temp->trainame;
		
	cout<<"Enter your Trainnumber: "<<endl;
	cin>>temp->trainnumber;
	
	cout<<"Enter Your id: "<<endl;
	cin>>temp->id;
	
	temp->next=NULL;
	
	cout<<"Do you want to insert at first Node: (y/n)"<<endl;
	cin>>ch;
	p=head;
	
	if(ch=='y'){ 

	temp->next = p;
	head = temp;
	
	}
	else{
	cout<<"Enter  TrainName After Which you want to add: "<<endl;
	cin>>info;	
	while(p!=NULL){ 
		if(strcmp((p->trainame),info)==0)
		{
			temp->next = p->next;
			p->next = temp;	
			break;
		}
		
		else
			p=p->next;
		
	}	
}	
	
}

void sll::del(){ 

	Node *temp,*prev;
	
	char key[50];
	
	temp = head;
	prev = NULL;

	cout<<"Enter TrainName Whose Record You want to Delete: "<<endl;
	cin>>key;
	
	
	while(temp!=NULL){ 
		
		if(strcmp((temp->trainame),key)==0)
	{
		if(temp==head){ 
		head = head->next;
		delete(temp);
		break;
		}
		
		else{
		
	
		prev->next = temp->next;
		delete(temp);
		break;
}
	}
	else{
		prev=temp;
		temp = temp->next;
		}
	}
	
	
}

void sll::search(){
	
	char key[50];
	Node *temp =head;
	cout<<"Enter trainname to Search"<<endl;
	cin>>key;
	while(temp!=NULL){ 
	if(strcmp(temp->trainame,key)==0){ 
	
		cout<<"Record Found"<<endl;
		cout<<"Trainname \tTrainnumber \tid"<<endl;
		cout<<temp->trainame<<"\t\t"<<temp->trainnumber<<"\t\t"<<temp->id;
		cout<<endl;
		break;
	
	}
	else
	temp=temp->next;
	
	
	if(temp==NULL)
	{
	cout<<"Record Not Found"<<endl;
	break;					
}
		}
	
	
}


int main(){ 

	int choice;
 	
 	sll s1;
 	
	cout<<"Welcome Train Management System"<<endl;
	cout<<"Menu"<<endl;
	
	cout<<"1.Create Entry\n2.Add Entry\n3.Delete Entry\n4.Search Entry\n5.Update Entry\n6.Delete Entry\n7.Reverse\n8.Exit"<<endl;
	cin>>choice;
	
	
		s1.create();
		s1.display();
		s1.insert();
		s1.display();
		s1.del();
		s1.display();

	
	return 0;
}

















