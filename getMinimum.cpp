#include<iostream>
#include<stack>
using namespace std;
class AdvanceStack
{
private:
    stack<int> mainStack;
    stack<int> minStack;
public:
    void Push(int data);
    void Pop();
    int getMinimum();
};
void AdvanceStack::Push(int data)
{
    mainStack.push(data);
    if(minStack.empty())
        minStack.push(data);
    else
    {
        if (data<minStack.top())
            minStack.push(data);
        else
            minStack.push(minStack.top());
    }
}
void AdvanceStack::Pop()
{
    mainStack.pop();
    minStack.pop();
}
int AdvanceStack::getMinimum()
{
    return minStack.top();
}
int main()
{
    AdvanceStack as;
    as.Push(2);
    as.Push(6);
    as.Push(4);
    as.Push(1);
    as.Push(5);
    cout<<"The minimum element is "<<as.getMinimum();
    as.Pop();
    as.Pop();
    cout<<"\nThe minimum element after popping twice is "<<as.getMinimum();
    return 0;
}
