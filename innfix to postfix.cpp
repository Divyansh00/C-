#include<iostream>
#include<stack>
#include<string>
using namespace std;
int Prec(char ch)
{
    switch(ch)
    {
    case '+':
    case '-': return 1;
    case '*':
    case '/': return 2;
    case '^': return 3;
    }
    return -1;
}
string Infix2Postfix(string in)
{
    stack<char> post;
    string postexp;
    for(int i=0;i<in.size();i++)
    {
        if(isalpha(in[i]))
        {
            //cout<<in[i];
            postexp.push_back(in[i]);
        }
        else if(in[i] == ')')
        {
            while(post.top()!= '(')
            {
                //cout<<post.top();
                postexp.push_back(post.top());
                post.pop();
            }
            post.pop();
        }
        else
        {
            while(!post.empty() && in[i] != '(' && Prec(in[i])<= Prec(post.top()))
            {
                    //cout<<post.top();
                    postexp.push_back(post.top());
                    post.pop();
            }
            post.push(in[i]);
        }
    }
    while(!post.empty())
    {
        postexp.push_back(post.top());
        //cout<<post.top();
        post.pop();
    }
    return postexp;
}
int main()
{
    string inexp , postexp;
    cout<<"Enter the infix expression"<<endl;
    cin>>inexp;
    postexp = Infix2Postfix(inexp);
    cout<<"The postfix expression is "<<postexp<<endl;
    return 0;
}
