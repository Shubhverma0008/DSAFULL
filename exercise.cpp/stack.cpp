#include<iostream>
#include<stack>
#include<unordered_map>
#include<string>
using namespace std;
int isoperand(char x)
{
    // if(x=='('||x=='{'||x=='['||x==')'||x=='}'||x==']') 
    if(x=='+'||x=='-'||x=='*'||x=='/')
    return 0;
    return 1;
}
int preinstack(char x)
{
    if(x=='+'||x=='-')
    return 1;
    else if(x=='*'||x=='/')
    return 2;
    else return -1;
}
string ismatch(string s)
{
    stack<char>st;
    int i=0;
    string s1;
    
    unordered_map<char,int>symbols={{'(',1},{'{',2},{'[',3},{')',-1},{'}',-2},{']',-3}};
    for(auto bracket:s)
    { 
        if(isoperand(bracket))i++;

        
        else
        if(symbols[bracket]>0)
        st.push(bracket);
        else
        {
            if(st.empty())return "NO";
            else
            {
                char top=st.top();
                st.pop();
                if(symbols[top]+symbols[bracket]!=0)
                return "NO";
            }
        }
    }
    if(st.empty())
    return "YES";
    return "NO";

    
}
string postfix(string s)
{  
    string post="";
    int k=s.length();
    post.resize(k+1);
    
    stack<char>st;
    // st.push('#');
    int i=0;
   while(s[i]!='\0')
    {
        if(isoperand(s[i]))
         post=post+s[i++];
          
        else
        {
            char top=st.top();
            if(preinstack(s[i])>preinstack (top))
             st.push(s[i++]);
             else
             {
                 st.pop();
                 post+=top;
             }


        }


    }
    while(!st.empty())
   { post+=st.top();
    st.pop();}
    return post;

}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    #endif
    // cout<<"ramram ji";
    string str;
    cin>>str;
    cout<<postfix(str);
    

}