#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
void show(node *head)
{
    node *current = head;
    cout<<"The list is ";
    cout<<current->data<<" ";
    while(current->next!=head)
    {
       current = current->next;
       cout<<current->data<<" ";
    }
    cout<<endl;
}
void insert(node **head, int n)
{
    node *current;
    current = new node;
    current->data = n;
    current->next = NULL;
    if(*head==NULL)
    {
        *head = current;
        current->next = *head;
    }
    else
    {
        node *temp = *head;
        while(temp->next!=*head)
        {
            temp = temp->next;
        }
        temp->next = current;
        current->next = *head;
    }
    show(*head);
}
int length(node *head)
{
    node *current = head;
    int count =1;
    if(current==NULL)
        return 0;
    while(current->next!=head)
    {
        count++;
        current = current->next;
    }
    return count;
}
void josephusCircle(node *head, int m)
{
    node *current = head;
    int k = m;
    while(length(head)>1)
    {
        node *start = head->next;
        while(start->next != head)
            start = start->next;
        node *prev = start;
        start = head;
        while(k-1)
        {
            prev = start;
            start = start->next;
            k--;
        }
        node *eliminate = start;
        if(eliminate == head)
            head = eliminate->next;
        node *begin = eliminate->next;
        prev->next = begin;
        delete(eliminate);
        head = begin;
        k = m;
    }
    current = head;
    cout<<"The last element to be executed is "<<current->data;
}
int main()
{
    node *head = NULL;
    int n,m;
    cout<<"Enter the data to be inserted(0 to end)"<<endl;
    while(cin>>n)
        if(n)
            insert(&head,n);
        else
            break;
    cout<<"Enter the value of M"<<endl;
    cin>>m;
    josephusCircle(head,m);
    return 0;
}
