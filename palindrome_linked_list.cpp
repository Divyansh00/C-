#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
void show(node *head)
{
	node *current=head;
	cout<<"The list is ";
	while(current)
	{
		cout<<current->data<<" ";
		current=current->next;
	}
	cout<<endl;
}
void insert(node **head,int n)
{
	node *link=new node;
	link->data=n;
	link->next=NULL;
	if(!*head)
		*head=link;
	else
	{
		node *current = *head;
		while(current->next!=NULL)
			current= current->next;
		current->next=link;
	}
	show(*head);
}
void palindrome(node *head)
{
	node *fast=head;
	node *slow=head;
	node *prevslow =NULL;
	do
	{
		prevslow=slow;
		fast = fast->next->next;
		slow = slow->next;
	}while(fast!=NULL && fast->next!=NULL);
	node *head1 =head;
	node *head2 = NULL;
	if(fast==NULL)
	{
		prevslow->next=NULL;
		head2=slow;
	}
	else
	{
		if(fast->next==NULL)
		{
			node *temp=head1;
			while(temp->next!=slow)
				temp=temp->next;
			temp->next=NULL;
			head2=slow->next;
		}
	}
	node *current=head2;
	node *prev=NULL;
	node *next=NULL;
	while(current)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head2=prev;
	node *temp1 =head1;
	node *temp2 =head2;
	int flag=1;
	while(temp1 && temp2)
	{
		if(temp1->data != temp2->data)
		{
			flag=0;
			break;
		}
		temp1=temp1->next;
		temp2=temp2->next;
	}
	if(flag)
		cout<<"Palindrome";
	else
		cout<<"Not Palindrome";
}
int main()
{
	node *head=NULL;
	int n;
	cout<<"Enter the element (0 to end)"<<endl;
	while(cin>>n)
		if(n)
			insert(&head,n);
		else
			break;
		palindrome(head);
        return 0;
	}

