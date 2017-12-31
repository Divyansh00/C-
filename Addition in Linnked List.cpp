/*
Logic:

    12          Reverse:  21  The LSB of original number becomes MSB of reversed number
   +34          Reverse: +43  Add from MSB of Reverse we get 2+4=6 and 1+3=4 equals 64
   =46                    64  Reverse the answer obtained to get final answer 46!!


*/

#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
void show(node *head)   //Function to display the contents of linked list
{
    cout<<"The list is ";
    node *current = head;
    while(current!=nullptr)
    {
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;
}
void insert(node **head , int data) // function to insert an element in the list
{
    node *link = new node;
    link->data = data;
    link->next = nullptr;
    if(*head==nullptr) //if head is null then make the link as head else insert the node at last
        *head = link;
    else
    {
        node *current = *head;
        while(current->next!=nullptr)
            current = current->next;
        current->next = link;
    }
    show(*head);
}
int length(node *head) //return the number of nodes in list
{
    int count = 0;
    node *current = head;
    while(current)
    {
        count++;
        current = current->next;
    }
    return count;
}
node* reverse(node *head) //reverse the list and returns the new head of reversed list
{
    node *prev = nullptr;
    node *current = head;
    node *next = nullptr;
    while(current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
void add(node *head1 , node *head2) // add numbers in linked list
{
    int len1 = length(head1);
    int len2 = length(head2);
    node *end1 = reverse(head1); //reverse list1 so MSB becomes LSB and vice versa
    node *end2 = reverse(head2); //reverse list2
    node *head3 = nullptr;  // head to the new list containing sum
    node *link = nullptr;
    int carry = 0; // to store the carry , if generated
    while(end1!=nullptr && end2!=nullptr) //loop till the shorter list
    {
        node *temp = new node;
        node *next = end1->next;
        temp->data = end1->data + end2->data; //add the digits of both the linked list
        if(temp->data > 9) //if sum is greater than 9, then carry is to be generated
        {
            carry = 1; //carry will be 1 as maximum sum will be 18(9+9)
            temp->data = temp->data - 10; //adjust the result accordingly and generate carry, e.g :12 will be 12-10=2 and 1 as carry
            if(next!=nullptr) //if list1 is not yet over , add carry to the next digit of list1
                next->data = next->data + carry;
            else
            {
                if(end2->next!=nullptr)//if list2 is not yet over, add carry to the next digit of list2
                    end2->next->data = end2->next->data + carry;
            }
        }
        temp->next = nullptr;
        end1 = end1->next;
        end2 = end2->next;
        if(head3==nullptr)//insert the new node to head
            head3 = temp;
        else
        {
            node *link = head3;
            while(link->next!=nullptr)
                link = link->next;
            link->next =temp;
            if(next==nullptr && carry && end2==nullptr)//if both the list are over(e.g. in case of number with same digit) and we have a carry left , then create a new node and insert it in list3            {
            {   node *forward = new node;
                forward->next = nullptr;
                forward->data = 1;
                link->next->next = forward;
            }
        }
        carry = 0;//make carry 0
    }
    if(end1!=nullptr)//if list1 is of longer length, then add remaining digits to the head
    {
        node *link = head3;
        while(link->next!=nullptr)
            link = link->next;
        link->next = end1;
    }
    if(end2!=nullptr)//if list2 is of longer length, then add remaining digits to the head
    {
        node *link = head3;
        while(link->next!=nullptr)
            link = link->next;
        link->next = end2;
    }
    show(reverse(head3));//reverse the list and then print
}
int main()
{
    node *head1 = nullptr;
    node *head2 = nullptr;
    int n;
    cout<<"Enter the element of list1 (0 to end)"<<endl;
    while(cin>>n)
        if(n)
            insert(&head1,n);
        else
            break;
    cout<<"Enter the element of list2 (0 to end)"<<endl;
    while(cin>>n)
        if(n)
            insert(&head2,n);
        else
            break;
    cout<<"The sum is "<<endl;
    add(head1,head2);
    return 0;
}
