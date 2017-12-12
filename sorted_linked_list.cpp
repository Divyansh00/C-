#include<iostream>
using namespace std;
struct node{
int data;
node *next;
};
void show(node *head){
node *temp = head;
cout<<"The list is ";
while(temp){
    cout<<temp->data<<" ";
    temp = temp->next;
}
cout<<endl;
}
void insert(node **head,int n){
node *link;
link = new node;
link->data = n;
link->next = NULL;
if(!*head){
    *head = link;
}
else{
    node *temp = *head;
    node *prev = *head;
    node *h = *head;
    while(temp){
        if(temp->data < n){
            prev = temp;
            temp = temp->next;
        }
        else{
            break;
        }
    }
    if(h->data > n)
    {
        link->next = h;
        *head = link;
    }
    else{
    link->next = prev->next;
    prev->next = link;
   }
}
show(*head);
}
int main(){
node *head = NULL;
int n;
cout<<"Enter the element(0 to end) ";
while(cin>>n){
    if(n)
        insert(&head,n);
    else
        break;
}
return 0;
}
