//Reverse the linked list in pairs. If you have a linked list that holds 1 → 2 → 3 → 4 →-X, then after the function has been called the linked list would hold 2 → 1 → 4 → 3 → X.

#include<iostream>
using namespace std;
struct node{
int data;
node *next;
};
void show(node *head)
{
    node *current = head;
    cout<<"The list is ";
    while(current)
    {
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;
}
void insert(node **head, int n)
{
    node *link = new node;
    link->data = n;
    link->next = NULL;
    if(!*head)
    {
        *head = link;
    }
    else
    {
        node *temp = *head;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = link;
    }
    show(*head);
}
node* reverse(node *head)
{
    int count = 0;
    node *current=head;
    node *prev=NULL;
    node *next=NULL;
    while(count<2 && current)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        count++;
    }
    if(current!=NULL)
    head->next=reverse(current);
    return prev;
}
int main()
{
    node *head = NULL;
    int n;
    cout<<"Enter the element (0 to end)"<<endl;
    while(cin>>n)
        if(n)
            insert(&head,n);
        else
            break;
    head =(reverse(head));
    cout<<"The reversed list "<<endl;
    show(head);
    return 0;
}
