#include<iostream>
#include<stack>
#include<string>
using namespace std;
int parenthesis(string exp)
{
   int i=0;
   stack<char>st;
   while(exp[i]!='\0')
   {
       if(exp[i]=='(')
       st.push(exp[i]);
       else if(exp[i]==')')
       {
           if(st.empty())
           return 0;
           else
           st.pop();
       }
       i++;
   }
   if(st.empty())
   return 1;
   else return 0;
}

int main()
{
    string s="((a+b)*(c-d))";
    cout<<parenthesis(s);
    return 0;
    
}
