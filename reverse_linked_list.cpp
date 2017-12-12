#include<iostream>
using namespace std;
struct node{
int data;
node *next;
};
void show(node *head){
node *current = head;
cout<<"The list is ";
while(current){
    cout<<current->data<<" ";
    current = current->next;
}
cout<<endl;
}
void insert(node **head,int n){
node *link;
link = new node;
link->data = n;
link->next = NULL;
if(*head){
    node *current = *head;
    while(current->next!=NULL)
        current = current->next;
    current->next = link;
}
else
    *head = link;
show(*head);
}
void reverse(node *head){
node *current = head;
node *prev = NULL;
node *next;
while(current){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
}
head = prev;
show(head);
}
int main(){
int n;
cout<<"Enter the element (0 to end) "<<endl;
node *head = nullptr;
while(cin>>n){
    if(n)
        insert(&head,n);
    else
        break;
}
reverse(head);
return 0;}
