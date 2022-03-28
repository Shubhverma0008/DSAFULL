#include<bits/stdc++.h>
using namespace std;
int maximumprofit(vector<int>&val,vector<int>&wt,int W)
{
    int dp[val.size()+1][W+1];
    for(int i=0;i<=val.size();i++)
    for(int j=0;j<=W;j++)
    if(i==0||j==0)dp[i][j]=0;
    for(int i=1;i<=val.size();i++)
    {
        for(int j=1;j<=W;j++)
        if(wt[i-1]<=j)
        dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
        else
        dp[i][j]=dp[i-1][j];
    }
    return dp[val.size()][W];


}
bool subsetsum(vector<int>&v,int sum)
{
   bool dp[v.size()+1][sum+1];
    for(int i=0;i<=v.size();i++)
    for(int j=0;j<=sum;j++)
    {
        if(i==0)
        dp[i][j]=false;
        if(j==0)
        dp[i][j]=true;

    }
    for(int i=1;i<=v.size();i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(v[i-1]<=j)
            dp[i][j]=dp[i-1][j-v[i-1]]||dp[i-1][j];
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[v.size()][sum];
}
bool equalsum(vector<int>&v)
{
    int sum=accumulate(v.begin(),v.end(),0);
    if(sum&1)return 0;
    return subsetsum(v,sum/2);
}
int countsubset(vector<int>&v,int sum)
{
   int dp[v.size()+1][sum+1];
    for(int i=0;i<=v.size();i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0)dp[i][j]=0;
            if(j==0)dp[i][j]=1;
        }
    }
    for(int i=1;i<=v.size();i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(v[i-1]<=j)
            dp[i][j]=dp[i-1][j-v[i-1]]+dp[i-1][j];
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    
    return dp[v.size()][sum];

}
int minimumsubsetsum(vector<int>&v)
{
    int sum=accumulate(v.begin(),v.end(),0);
   bool dp[v.size()+1][sum+1];
    for(int i=0;i<=v.size();i++)
    {
        for(int j=0;j<=sum;j++)
       { if(i==0)dp[i][j]=false;
        if(j==0)dp[i][j]=true;}
    }
    for(int i=1;i<=v.size();i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(v[i-1]<=j)
            dp[i][j]=dp[i-1][j-v[i-1]]||dp[i-1][j];
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    vector<int>temp;
    for(int i=0;i<=sum/2;i++)
    {
        temp.push_back(dp[v.size()][i]);

    }
     for(auto i:temp)
    cout<<i<<" ";
   

    int res=INT_MAX;
    for(int i=0;i<temp.size();i++)
    {
        if(temp[i])
        {
            if(sum-2*i<=sum)
            res=sum-2*i;
        }

    }
    return res;


    
}
int countsubsetdiff(vector<int>&v,int diff)
{
    int s=(diff+accumulate(v.begin(),v.end(),0))/2;
    return countsubset(v,s);
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    vector<int>v{2,3,5,6,8,10};
    int sum=9;
    cout<<countsubset(v,sum);
    // cout<<space(v);

    cout<<endl;
   

  


  
    

}