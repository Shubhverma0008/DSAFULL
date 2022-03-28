#include <bits/stdc++.h>
using namespace std;
// static int dp[7][7];
// // int res=INT_MAX;
// int MCM(vector<int>v,int i,int j)
// {
//     if(i>=j)return 0;
//     if(dp[i][j]!=-1)
//     return dp[i][j];
//     int res=INT_MAX;
//     for(int k=i;k<j;k++)
//     {
//        int temp=(MCM(v,i,k)+MCM(v,k+1,j)+v[i - 1] * v[k] * v[j]);
//        res=min(res,temp);
//     //    dp[i][j]=min(dp[i][j],MCM(v,i,k)+MCM(v,k+1,j)+v[i - 1] * v[k] * v[j]);
//     }
//     return dp[i][j]=res;
//     // dp[i][j] = INT_MAX;
//     // for (int k = i; k < j; k++)
//     // {
//     //     dp[i][j] = min(
//     //         dp[i][j], MCM(v, i, k)
//     //                  + MCM(v, k + 1, j)
//     //                    + v[i - 1] * v[k] * v[j]);
//     // }
//     // return dp[i][j];
// }
//  int t[501][501];
//  multiset<string>se;
//     bool isPalindrome(string String, int i, int j){
//         while(i < j)
//           if(String[i++] != String[j--])
//             return false;
//         return true;
//     }
//     int minPalPartion(string &String, int i, int j){
//         if(t[i][j]!=-1)
//             return t[i][j];
//         if(  isPalindrome(String, i, j))
//            {se.insert(String.substr(i,j-i+1));
//             }
//             if(i>=j)
//             return 0;
//         int ans = INT_MAX, count;
//         for(int k = i; k < j; k++){
//           count = 1 + minPalPartion(String, i, k) + minPalPartion(String, k + 1, j);
//           ans = min(ans, count);
//         }
//         t[i][j]=ans;
//         return t[i][j];
//     }
//     int palindromicPartition(string str)
//     {
//         // code here

//             memset(t,-1,sizeof(t));
//         return minPalPartion(str,0,str.length()-1);
//     }

// bool checksum(vector<int>&v,int sum)
// {
//     int dp[v.size()+1][sum+1];
//     for(int i=0;i<=v.size();i++)
//     {
//         for(int j=0;j<=sum;j++)
//         {
//             if(i==0)
//             dp[i][j]=false;
//             if(j==0)
//             dp[i][j]=true;
//         }
//     }
//     for(int i=1;i<=v.size();i++)
//     {
//         for(int j=1;j<=sum;j++)
//         {
//             if(v[i-1]<=j)
//             {
//                 dp[i][j]=dp[i-1][j-v[i-1]]+dp[i-1][j];

//             }
//             else
//             dp[i][j]=dp[i-1][j];
//         }
//     }
//     return dp[v.size()][sum];
int res=INT_MIN;
int solve(vector<int>&nums,int i,int curr)
{
    if(i>=nums.size())
    {  if(curr%3==0)
        return curr;
        return 0;
    }
    if((curr+nums[i])%3==0)
   return  solve(nums,i+1,curr+nums[i]);
   if((curr+nums[i])%3)
       {
           int x=solve(nums,i+1,curr);
           int y=solve(nums,i+1,curr+nums[i]);
           return max(x,y);
       }
    
    

}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
vector<int>nums{1,4,3,1};

solve(nums,0,0);
cout<<res;






}

    