//How will you find the middle of the linked list?

#include<iostream>
using namespace std;
struct node{
int data;
node *next;
};
void findMiddle(node *head){
node *ptr1x, *ptr2x;
ptr1x = ptr2x = head;
while(ptr2x && ptr2x->next){
    ptr2x = ptr2x->next->next;
    ptr1x = ptr1x->next;
}
    cout<<"The middle element is "<<ptr1x->data<<endl;
}
void insert(node **head , int n){
node *link ;
link = new node;
link->data = n;
link->next = NULL;
node *current = *head;
if(!*head)
    *head = link;
else{
while(current->next!=NULL){
    current = current->next;
}
current->next = link;
}
findMiddle(*head);
}
int main(){
node *head = NULL;
int n;
cout<<"Enter the elements (0 to end) "<<endl;
while(cin>>n){
    if(n)
        insert(&head,n);
    else
        break;
}
return 0;
}

