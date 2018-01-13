#include<iostream>
#include<stack>
#include<string>
using namespace std;
int Prec(char op)
{
    switch(op)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
    }
    return -1;
}
int result(int a, char op, int b)
{
    switch(op)
    {
        case '+':return a+b;
        case '-':return a-b;
        case '*':return a*b;
        case '/':return a/b;
        case '^':return a^b;
    }
}
int infixEval(string in)
{
    stack<char> operate;
    stack<int> operand;
    for(int i=0;i<in.length();i++)
    {
        if(isdigit(in[i]))
        {
            operand.push(in[i]-'0');
        }
        else if(in[i] == '(')
            operate.push(in[i]);
        else if(in[i] == ')')
        {
            while(operate.top()!='(')
            {
                int res;
                int a = operand.top();
                operand.pop();
                int b = operand.top();
                operand.pop();
                char op = operate.top();
                operate.pop();
                res = result(a,op,b);
                operand.push(res);
            }
            operate.pop();
        }
        else
        {
            while(!operate.empty() && Prec(in[i])<=Prec(operate.top()))
            {
                int res;
                int a = operand.top();
                operand.pop();
                int b = operand.top();
                operand.pop();
                char op = operate.top();
                operate.pop();
                res = result(a,op,b);
                operand.push(res);
            }
            operate.push(in[i]);
        }
    }
    while(!operate.empty())
    {
        int res;
        int b = operand.top();
        operand.pop();
        int a = operand.top();
        operand.pop();
        char op = operate.top();
        operate.pop();
        res = result(a,op,b);
        operand.push(res);
    }
    return operand.top();
}
int main()
{
    string infix;
    cout<<"Enter the infix expression"<<endl;
    cin>>infix;
    cout<<"The value of expression is "<<infixEval(infix);
    return 0;
}
