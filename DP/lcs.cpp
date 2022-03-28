#include <bits/stdc++.h>
using namespace std;
int lcs(string s,string k,int sl,int kl)
{
    int dp[sl+1][kl+1];
    for(int i=0;i<=sl;i++)
    {
        for(int j=0;j<=kl;j++)
        if(i==0||j==0)
        dp[i][j]=0;
    }
    for(int i=1;i<=sl;i++)
    {
        for(int j=1;j<=kl;j++)
        {
            if(s[i-1]==k[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    for(int i=0;i<=sl;i++)
    {
        for(int j=0;j<=kl;j++)
        cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    int i=sl,j=kl;
    string res="";
    while(i&&j)
    {
        if(s[i-1]==k[j-1])
        {
            res.push_back(s[i-1]);
            i--,j--;
        }
        else
       { if(dp[i-1][j]>dp[i][j-1])
        i--;
        else
        j--;}
    }
    reverse(res.begin(),res.end());
    cout<<res;
    return dp[sl][kl];
}
int scs(string s,string k,int sl,int kl)
{
    return  sl+kl-lcs(s,k,sl,kl);

}
int minimuminsertion(string s,string k,int sl,int kl)
{
    return kl-lcs(s,k,sl,kl);
}
int minimumdeletion(string s,string k,int sl,int kl)
{
    return sl-lcs(s,k,sl,kl);
}
int longestpalinsubse(string s)
{
    string k= s;
    reverse(k.begin(),k.end());
     lcs(s,k,s.length(),s.length());

}
int minimumdeletionpalindr(string s)
{
    string k=s;
    reverse(k.begin(),k.end());
    return s.length()-lcs(s,k,s.length(),s.length());

}
void printscs(string s,string k,int sl,int kl)
{
    int dp[sl+1][kl+1];
    for(int i=0;i<=sl;i++)
    {
        for(int j=0;j<=kl;j++)
        if(i==0||j==0)
        dp[i][j]=0;
    }
    for(int i=1;i<=sl;i++)
    {
        for(int j=1;j<=kl;j++)
        {
            if(s[i-1]==k[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    // for(int i=0;i<=sl;i++)
    // {
    //     for(int j=0;j<=kl;j++)
    //     cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    
    int i=sl,j=kl;
    string res="";
    char c,d;
    while(i>0&&j>0)
    {
        if(s[i-1]==k[j-1])
        {res.push_back(s[i-1]);i--;j--;}
        else
        {
            if(dp[i][j-1]>dp[i-1][j])
            {
                res.push_back(c=k[j-1]);
                j--;
            }
            else
            {
                res.push_back(d=s[i-1]);
                i--;
            }
        }
    }
    while(i>0)
    {
        res.push_back(s[i-1]);
        i--;
    }
    while(j>0)
    {
        res.push_back(k[j-1]);
        j--;
    }

    reverse(res.begin(),res.end());
    cout<<res;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
string s="AGGTAB";

string t="GXTXAYB";
printscs(s,t,s.length(),t.length());




   

}