#include<iostream>
#include<string>
#include<cstring>
#include<stack>
using namespace std;
int isoperand(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='('||x==')'||x=='^')
    return 0;
    return 1;
}
int inpredence(char x)
{
    if(x=='+'||x=='-')
    return 2;
    else if(x=='*'||x=='/')
    return 4;
    else if(x=='^')
    return 5;
    else if(x=='(')
    return 0;
    else return -1;
}
int outpredence(char x)
{
    if(x=='+'||x=='-')
    return 1;
    else if(x=='*'||x=='/')
    return 3;
    else if(x=='^')
    return 6;
    else if(x=='(')
    return 7;
    else if(x==')')
    return 0;
    else return -1;
}
string convert(string infix)
{
    string post="";
    post.resize(infix.length()+1);

    stack<char>st;
    st.push('#');
    string s;
    
    
    
    int j=0;
    int i=0;
    while(infix[j]!='\0')
    {
        if(isoperand(infix[j]))
         post+=infix[j++];
         else if(outpredence(infix[j])>inpredence(st.top()))
            st.push(infix[j++]);
            else if(outpredence(infix[j])==inpredence(st.top()))
            {
                st.pop();
                j++;
            }
            else {
                post+=st.top();
               
                st.pop();
            }

    }
    while(!st.empty())
    {post+=st.top();
    st.pop();}
    post[i]='\0';
    return post;



}
int main()
{
    string s="((a+b)*c)-d^e^f";
    cout<<convert(s);
}