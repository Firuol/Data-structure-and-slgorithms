#include<iostream>
using namespace std;
struct node
    {
     int data;
     node *next;
     node *prev;
     };

 node *head = NULL;               
 node *tail = NULL;


 void insertatfirst(int value){
     node *newnode = new node(); 
     newnode->data = value;      
   if(head == NULL)
   {       
     newnode->next=newnode;
     newnode->prev=newnode;
     head=tail=newnode;
    }
   else
    {                    
     newnode->next = head;
     newnode->prev = tail;
     head->prev = newnode;
     tail->next = newnode;
     head=newnode; 
      }
 cout<<"The value after inserting " << value<< " at first is :"<<endl;
   }

 void insertatlast(int value){       
     node *newnode = new node();   
     newnode->data = value;      
   if(head == NULL)
    {          
     newnode->next=newnode;
     newnode->prev=newnode;
     tail=head=newnode; 
     }
   else
    {
     newnode->next=head;
     newnode->prev=tail;
     head->prev= newnode;
     tail->next=newnode;    
     tail = newnode;
     }
cout<<"The value after inserting "<<value<<" at last is :"<<endl;
    }
    
 void insertatspecific(int value, int location){
     int nodeLengthCounter();
     int length; 
     length=nodeLengthCounter();
  
   if(location>length+1 ||location<=0) 
    {
cout << "There is no location "<<location <<" to insert " <<value<<" at it."<<endl;
    }
   else 
    { 
    if(head == NULL)
   { node *newnode = new node();   
     newnode->data = value;   
     newnode->next=newnode;
     newnode->prev=newnode;
     tail=head=newnode; 
cout<<"The value after adding "<<value <<" at location "<<location<<" is"<<endl;
    }
   else
    {
     node *newnode = new node();
     newnode->data = value;
     node *temp = head;
   for (int i = 1; i < location-1; i++)
     {
      temp = temp->next; 
      }
     newnode->next= temp->next;
     newnode->prev = temp;
     temp->next->prev = newnode;
     temp->next = newnode;
       
cout<<"The value after inserting "<<value <<" at location "<<location<<" is"<<endl;}}
    }

void deletefirst(){
   if(head == NULL)
    {
     cout << "No node to be deleted."<<endl;
    }
   else
    {
     node *temp = head;
     head= head->next;
     head->prev = tail;
     tail->next = head;
     delete temp;} 
cout<<"The value after deleting the first value is : "<<endl;
  }

void deletelast(){ 
   if(head == NULL)
    {
     cout << "No node to e deleted."<<endl;
    }
   else 
    {
     node *temp = tail;
     tail = tail->prev;
     tail->next = head;
     head->prev = tail;
     delete temp;
     }
cout<<"The value after deleting the last value is : "<<endl;
  }
  
void deletespacific(int location){
     int nodeLengthCounter();
     int length=nodeLengthCounter();
   if(location>length || location<=0) 
    {
cout << "There is no location "<< location <<" to be deleted ."<<endl;
    }
   else
    {
     node *temp = head;
     if(location==1)
     {
     node *temp = head;
     head= head->next;
     head->prev = tail;
     tail->next = head;
     delete temp;
     }
     else
     {
   for(int i = 0;i < location-1;i++)
     {
     temp = temp->next;
     }
     temp->prev->next = temp->next;
     temp->next->prev = temp->prev;
     delete temp; } 
cout<<"The value after deleting the value of location "<<location<<" is:"<<endl;}
  }
  
 int nodeLengthCounter(){
     int x=0;
  if(head==NULL)
    {
     x=0;
    }
   else
    { 
     node *temp =head;
   do
   {   
     x++;
     temp=temp->next;
    }  
   while(temp!= head);
  }
  return x;
   }
    
  
void display(){
   if(head==NULL)
    {
     cout<<"There is no element to be displayed"<<endl;
    }
   else
    { 
     node *temp =head;
   do
    {   
     cout <<temp->data<<" ";
     temp = temp->next;
     }  
   while(temp!= head);
    cout<<endl;
    }
  }

int main (){

    insertatfirst(4);
    display();
    insertatfirst(6);
    display();
    insertatfirst(1);
    display();
    insertatlast(8);
    display();
    insertatlast(6);
    display();
    insertatlast(12);
    display();
    insertatspecific(7, 0);
    display();
    insertatspecific(11, 2);
    display();
    insertatspecific(9, 5);
    display();
    deletefirst();
    display();
    deletefirst();
    display();
    deletelast();
    display();
    deletelast();
    display();
    deletespacific(-2);
    display();
    deletespacific(0);
    display();
    deletespacific(5);
    display();
     return 0;
}
