#include<iostream>
#include<string>
#include<stack>
using namespace std;
int isoperand(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/')
    return 0;
    return 1;
}
int evaluation(string s)
{   stack<char>st;
  int i=0;
  int x1,x2,r;
    while(s[i]!='\0')

   { 
       if(isoperand(s[i]))
    st.push(s[i++]-'0');
    else {
        x2=st.top();
        st.pop();
        x1=st.top();
        st.pop();
        switch (s[i])
        {
        case '+':r=x1+x2;
            break;
        case '-':r=x1-x2;
            break;
        case '*':r=x2*x1;
            break;
        case '/':r=x1/x2;
            break;
        
        default:
            break;
        }
        st.push(r);
        i++;
    }
    }
    return st.top();

}
int main()
{
    string s="35*62/+4-";
    cout<<evaluation(s);
}
