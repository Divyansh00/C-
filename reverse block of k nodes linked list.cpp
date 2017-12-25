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
void insert(node **head, int n)
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
            current=current->next;
        current->next=link;
    }
    show(*head);
}
node* reverse_block(node *start)//reverse the block within list
{
    node* current = start;
    node* prev = nullptr;
    node* next = nullptr;
    while(current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
node* reverse_list(node* head,int k)
{
    node *start = nullptr;
    node *end = nullptr;
    node *next = head;
    head = nullptr;
    while(next!=NULL)
    {
        start = next;
        end = next;
        while(end!=NULL && k-1)
        {
            end = end->next;
            k--;
        }
        if(end!=NULL)
        {
            next = end->next;
            end->next = nullptr;
            start = reverse_block(start);
        }
        else
        {
            next = nullptr;
        }
        if(head==nullptr)
        {
            head = start;
        }
        else
        {
            node *curr = head;
            while(curr->next!=NULL)
                curr = curr->next;
            curr->next = start;
        }
    }
    return head;
}
int main()
{
    node *head=NULL;
    int n;
    int k;
    cout<<"Enter the element (0 to end)"<<endl;
    while(cin>>n)
        if(n)
            insert(&head,n);
        else
            break;
    cout<<"Enter the block size"<<endl;
    cin>>k;
    head=reverse_list(head,k);
    show(head);
    return 0;
}
