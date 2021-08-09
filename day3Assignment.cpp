/*
LetsUpgrade
Day3Assignment
DJsmk123@gmail.com
MD MOBIN
 Assignment:
Implement the following functions for a single linked list:
1. Insert at end
2. Delete from beginning
3. Delete from end
 */ 
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
// To create new node in linked-list
Node * create(int);
//Insertion at the end  of the linked-List
Node *insert_end(Node *,int);
//Delete node from  beginning in linked-list
Node *delete_beg(Node * head)
{
	if(!head)
	{
		cout<<"Empty List !!!!"<<endl;
		return NULL;
	}
 Node *temp=head;
   head=head->next;
   free(temp);
   return head;
}
//Delete node from  end in linked-list
Node *delete_end(Node * head)
{
	if(!head)
	{
		cout<<"Empty List !!!!"<<endl;
		return NULL;
	}
	if (head->next == NULL) {
        delete(head);
        return NULL;
    }
		Node *temp=head;
		while(temp->next->next!=NULL)
		temp=temp->next;
		delete(temp->next);
		temp->next=NULL;
	     return  head;
}
void display_list(Node *head);
Node *create(int item)
{
    Node * nptr = new Node;
    nptr -> data = item;
    nptr -> next = NULL;

    return nptr;

}
int main()
{
    Node * head = NULL;
	int data;
	 char ch;
	  cout<<"Enter element in Linked-List at the end:\n";
	  do
	  {
		  cin>>data;
		  head=insert_end(head,data);
		  cout<<"Do you want to add more elements('y' or 'Y') or not('n' or 'N'):";
		  cin>>ch;
	   }while(ch=='y' || ch=='Y');
		cout<<"Linked-List elements are:\n";
		display_list(head);
		cout<<"\nEnter 1 for deleting elements from beginning and 2 for deleting elements from end:";
		int x;
		cin>>x;
		do
		{
			if(x==1)
			head=delete_beg(head);
			else if(x==2)
				head=delete_end(head);
		cout<<"\nLinked-List After deleting elements:\n";
		display_list(head);
		cout<<"\nDo you want to delete more elements('y' or 'Y') or not('n' or 'N'):";
		  cin>>ch;
		}while(ch=='y' || ch=='Y');

    return 0;
}
Node * insert_end(Node *head, int data)
{
    Node *np = create(data);
    if(!head)
    {
        head = np;
        return head;
    }
		Node *temp=head;
		while(temp->next!=NULL)
		temp=temp->next;
		temp->next=np;
      return head;
}
void display_list(Node *head)
{
    if(!head)
    {
        cout<<"\nList is empty"<<endl;
        return;
    }
    Node *temp = head;
    while(temp != NULL)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }

}
