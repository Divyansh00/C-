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
    do
    {
        cout<<current->data<<" ";
        current=current->next;
    }while(current!=head);
    cout<<endl;
}
void insert(node **head,int n)
{
    node *link = new node;
    link->data=n;
    link->next=nullptr;
    if(!*head){
        link->next=link;
        *head=link;
    }
    else
    {
        node *current = *head;
        while(current->next!=*head)
        {
            current=current->next;
        }
        current->next=link;
        link->next=*head;
    }
    show(*head);
}
void split(node *head)
{
    node *fastptr = head;
    node *slowptr = head;
    node *prevslow=nullptr;
    node *prevfast=nullptr;
    if(!head)
        return;
    do
    {
        prevslow=slowptr;
        prevfast=fastptr->next;
        fastptr=fastptr->next->next;
        slowptr=slowptr->next;
    }while(fastptr!=head && fastptr->next!=head);
    if(fastptr==head)
    {
    prevslow->next=head;
    prevfast->next=slowptr;
    show(head);
    show(slowptr);
    }
    else
    {
        fastptr->next=slowptr->next;
        node *head2 = slowptr->next;
        slowptr->next=head;
        show(head);
        show(head2);
    }
}
int main()
{
    node *head=nullptr;
    int n;
    cout<<"Enter the element (0 to end)"<<endl;
    while(cin>>n)
        if(n)
            insert(&head,n);
        else
            break;
    split(head);
    return 0;
}
