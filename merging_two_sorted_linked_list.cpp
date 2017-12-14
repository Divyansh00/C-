#include<iostream>
using namespace std;
struct node{
int data;
node *next;
};
void show(node *head){
node *current = head;
cout<<"The list is ";
while(current)
    {
        cout<<current->data<<" ";
        current = current->next;
    }
cout<<endl;
}
int length(node *head){
int count =0;
while(head){
    count++;
    head = head->next;
}
return count;
}
void insert(node **head, int n){
    node *link = new node;
    link->data = n;
    link->next = nullptr;
    node *current = *head;
    if(!*head)
        *head = link;
    else
    {
        while(current->next!=nullptr)
        {
            current = current->next;
        }
        current->next = link;
    }
    show(*head);
}
void merge(node *head1, node *head2)
{
    int len1 = length(head1);
    int len2 = length(head2);
    node *big = (len1 > len2)? head1 : head2;
    node *shor = (len1 < len2)? head2 : head1;
    node *head = NULL;
    while(big && shor){
        if(big->data >= shor->data){
            insert(&head,shor->data);
             shor = shor->next;
        }
        else{
            insert(&head,big->data);
            big = big->next;
        }
    }
    while(big){
        insert(&head,big->data);
        big = big->next;
    }
}
int main()
{
    node *head1=NULL , *head2=NULL;;
    int n;
    cout<<"Enter the elements of first list in sorted order(0 to end)"<<endl;
    while(cin>>n)
        if(n)
            insert(&head1,n);
        else
            break;
    cout<<"Enter the elements of second list in sorted order(0 to end)"<<endl;
    while(cin>>n)
        if(n)
            insert(&head2,n);
        else
            break;
    merge(head1,head2);
    return 0;
}
