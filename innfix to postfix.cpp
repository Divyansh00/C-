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
        if(isalpha(in[i]) || isdigit(in[i]))
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
char operate(int r1,char op,int r2)
{
    switch(op)
    {
        case '+': return r1+r2+'0';
        case '-': return r1-r2+'0';
        case '*': return r1*r2+'0';
        case '/': return r1/r2+'0';
        case '^': return r1^r2+'0';
    }
}
char evalPost(string post)
{
    stack<char> eval;
    int result;
    char r1,r2;
    int t1,t2;
    for(int i=0;i<post.length();i++)
    {
        if(isalpha(post[i]) || isdigit(post[i]))
        {

            eval.push(post[i]);
        }
        else
        {
            r1 = eval.top();
            eval.pop();
            r2 = eval.top();
            eval.pop();
            t1 = r1-48; //converting r1 and r2 to int
            t2 = r2-48;
            eval.push(operate(t1,post[i],t2));
        }
    }
    return eval.top();
}
int main()
{
    string inexp , postexp;
    cout<<"Enter the infix expression"<<endl;
    cin>>inexp;
    postexp = Infix2Postfix(inexp);
    cout<<"The postfix expression is "<<postexp<<endl;
    cout<<"The evaluation of postfix is "<<evalPost(postexp)<<endl;
    return 0;
}
