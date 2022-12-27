#include <iostream>
using namespace std;

struct node{
	int item;
	node *prev;
	node * next;
};

node *head=NULL;

void iatb(int val)
{
		node *newnode=new node();
		newnode->item=val;
		if(head==NULL)
		{
		head=newnode;	
		newnode->next=NULL;
		newnode->prev=NULL;
		}
		else
		{
			newnode->next=head;
			head->prev=newnode;
			newnode->prev=NULL;
			head=newnode;
		}		
}

void iate(int val)
{
	node *temp=head; 	
	node *newnode=new node();
	newnode->item=val;
	if(head==NULL)
	{
		head=newnode;
		newnode->next=NULL;
		newnode->prev=NULL;
	}
	
	else
	{
	node *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
		temp->next=newnode;
		newnode->next=NULL;
		newnode->prev=temp;

	}	
}

void iatal(int val,int location)
	{
		node *newnode=new node();
		node *temp=head;
		newnode->item=val;
		for(int i=0;i<location-2;i++)
			{temp=temp->next;}
		newnode->next=temp->next;
		temp->next->prev=newnode;
		temp->next=newnode;
		newnode->prev=temp;
		
		
	 } 
	 
	 void datb()
{
		node *temp=head;
		if(head==NULL)
		{
		cout<<"There is no item to delete :";
		}
		else
		{  
		cout<<"value after deleted from the beginning:"<<endl;
			head=head->next;
			delete temp;
			 head->prev=NULL;
		}
		
}

	 void date()
	 {
	 	cout<<"value after deleted from the end:"<<endl;
	 	node *abe,*chala;
	 	abe=head;
	 	while(abe->next!=NULL)
	 	{
	 		chala=abe;
	 		abe=abe->next;
		 }
		 chala->next=NULL;
		 
		 delete abe;
	 }
	 
	  void dasl(int location)
	{
		node *temp1,*temp2;
		temp1=head;
		for(int i=0;i<location-2 ;i++)
		{	temp1=temp1->next;}
			temp2=temp1->next;
		    temp1->next=temp2->next;
		    temp2->next->prev=temp1;
			delete temp2;
		cout<<"value after deleted from the location "<<location<<":"<<endl;
	 }
	 
	 
void display()
{
	node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->item<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

void display_backward()
{
	node *temp=head;
		while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	
	while(temp!=NULL)
	{
		cout<<temp->item<<" ";
		temp=temp->prev;
	}
	cout<<endl;
}

int main(){
	iatb(5);
	iatb(6);
	display();
	
	iate(4);
	iate(3);
	iate(2);
	iatal(8,3);
	iatal(9,1);
	display();
	datb();
	display();
	date();
	display();
	dasl(2);
	display();
	display_backward();
	
	return 0;
}