#include<bits/stdc++.h>
#define ll long long
using namespace std;
int solve(int n)
{
    if(n<=1)return 0;
    if(n%2==0)return 1+solve(n/2);
    else return 1+solve(n-1);
   
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

         vector<int>nums{1,2,4,3,5,7};
         vector<vector<int>>dp(nums.size(),vector<int>(8,0));
         for(int i=0;i<nums.size();i++)
         {
             for(int j=i+1;j<nums.size();j++)
             {
                 int diff=nums[j]-nums[i];
                 dp[j][diff]=max(2,dp[i][diff]+1);
             }
         }
         for(auto i:dp)
         {
             for(auto x:i)
             cout<<x<<" ";
             cout<<endl;
         }







}

   

