#include <bits/stdc++.h>
using namespace std;
int maxway(vector<int> &v, int sum)
{
    int dp[v.size() + 1][sum + 1];
    for (int i = 0; i <= v.size(); i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    }
    for (int i = 1; i <= v.size(); i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (v[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - v[i - 1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    for (int i = 0; i <= v.size(); i++)
    {
        for (int j = 0; j <= sum; j++)
            cout << dp[i][j] << " ";

        cout << endl;
    }
    return dp[v.size()][sum];
}
int mincoin(vector<int> &v, int sum)
{
    int dp[v.size() + 1][sum + 1];
    for (int i = 0; i <= v.size(); i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
                dp[i][j] = INT_MAX - 1;
            if (j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= v.size(); i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (v[i - 1] <= j)
                dp[i][j] = min(dp[i][j - v[i - 1]] + 1, dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    for(int i=0;i<=v.size();i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(dp[i][j]==INT_MAX-1)
            cout<<"$"<<" ";

            else
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[v.size()][sum];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
   vector<int>v{1,2,3};
cout<<mincoin(v,5);
}