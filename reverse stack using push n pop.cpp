#include<iostream>
#include<stack>
using namespace std;
void show(stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
        cout<<" \t";
    }
}
void insertAtBottom(stack<int> *s, int data)
{
    if((*s).empty())
    {
        (*s).push(data);
        return;
    }
    else
    {
        int temp = (*s).top();
        (*s).pop();
        insertAtBottom(s,data);
        (*s).push(temp);
    }
}
void reverse(stack<int> *s)
{
    int data;
    if((*s).empty())
        return;
    else
    {
        data = (*s).top();
        (*s).pop();
        reverse(s);
    }
    insertAtBottom(s,data);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<"Original Stack ";
    show(s);
    cout<<endl;
    reverse(&s);
    cout<<"Reversed Stack ";
    show(s);
    cout<<endl;
    return 0;
}
