/*Day 5 [LINKED LIST]
1. REVERSE A LINKED LIST*/

//RECURSIVE METHOD
//Time Complexity: O(n) 

#include <iostream>
using namespace std; 

//Node Creation
struct Node 
{
    int data;
    struct Node* next;
};
  

class LinkedList
{
	public:
    struct Node* head;
 
    //Constructor
 	LinkedList()
 	{
 		head=NULL;
	}
	
	//Push operation
	void push(int x)
	{
   	struct Node* p;
   	p=new struct Node;
   	
   	if(p!=NULL)
   	{
   	p->data=x;
   	p->next=NULL;
   	}
    
    else
    {
    	cout<<"\n Allocation failure";
    	return;
	}
	
	if(head==NULL)
	 head=p;
	
	else
	 {
	 	p->next=head;
	 	head=p;
	 	
	 }
	 
	 return;
}
  
    //Reverse Operation
 	struct Node* reverse(struct Node* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
 
        struct Node* r = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
 
        return r;
    }
 
    //To print the LinkedList
    void print()
    {
        struct Node* temp = head;
        while (temp != NULL) 
		{
            cout << temp->data << "--->";
            temp = temp->next;
        }
        cout<<"NULL";
    }
};

//ITERATIVE METHOD
//Time Complexity: O(n) 

#include <iostream>
using namespace std; 

//Node Creation
struct Node 
{
 int data;
 struct Node* next;
};

typedef struct Node* Nodeptr;

class LinkedList
{
public:
Nodeptr head;

//Constructor
LinkedList()
{
head=NULL;
}

//Push Function
void push(int x)
{
 Nodeptr p;
 p=new struct Node;
 if(p!=NULL)
 {
 p->data=x;
 p->next=NULL;
 }
 
 else
 {
 cout<<"\n Allocation failure";
 return;
}

if(head==NULL)
head=p;
else
{
p->next=head;
head=p;
}
return;
}
 
//Reverse Function
void reverse()
 {
 
 Nodeptr curr = head;
 Nodeptr prev = NULL, next = NULL;
 while (curr != NULL) 
{
 next = curr->next;
 curr->next = prev;
prev = curr;
 curr = next;
 }
 head = prev;
 }
 
 //Print Function
 void print()
 {
 Nodeptr temp = head;
 while (temp != NULL) 
{
 cout << temp->data << "--->";
 temp = temp->next;
 }
 cout<<"NULL";
 }
};



