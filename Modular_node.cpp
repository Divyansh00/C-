#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
void show(node *head)
{
    node *current = head;
    cout<<"The list is: ";
    while(current!=NULL)
    {
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;
}
void insert(node **head , int n)
{
    node *link = new node;
    link->data = n;
    link->next = NULL;
    if(*head==NULL)
        *head = link;
    else
    {
        node *current = *head;
        while(current->next!=NULL)
            current = current->next;
        current->next = link;
    }
    show(*head);
}
int length(node* head)
{
    int count=0;
    node *current = head;
    if(!current)
        return 0;
    while(current!=NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
void modularNode(node *head, int k)
{
    int len = length(head);
    int point = (len/k)*k;
    node *current = head;
    while(current!=NULL && point-1)
    {
        current = current->next;
        point--;
    }
    cout<<"The modular node is "<<current->data;
}
int main()
{
    node *head = NULL;
    cout<<"Enter the element to be entered in list(0 to end)"<<endl;
    int n;
    while(cin>>n)
    if(n)
        insert(&head,n);
    else
        break;
    cout<<"Enter the value of k whose n%k=0"<<endl;
    int k;
    cin>>k;
    modularNode(head,k);
}
