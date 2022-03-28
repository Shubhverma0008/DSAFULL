#include <bits/stdc++.h>
using namespace std;
#define I INT_MAX
vector<int> nextSmaller(vector<int>&nums){
    stack<int>st;
    vector<int>nextmin(nums.size(),nums.size()-1);
int i=0;
while(i<nums.size()){
    if(st.empty())st.push(i++);
    else{
        if(nums[i]<nums[st.top()])
      {  nextmin[st.top()]=i;st.pop();}
        else
        st.push(i++);
    }
    // t=st.top();
 
    
}
// while(!st.empty())
// {nextmin[st.top()]=-1;st.pop();}
   
    return nextmin;

}
vector<int>presmaller(vector<int>&nums){
    vector<int>res(nums.size(),0);
    stack<int>st;
    int i=nums.size()-1;
    while(i>=0){
        if(st.empty())st.push(i--);
        else{
            while(!st.empty()&&nums[st.top()]>nums[i]){
                res[st.top()]=i;
                st.pop();
            }
            st.push(i--);
        }
    }
    // while(!st.empty()){
    //     res[st.top()]=-1;
    //     st.pop();
    // }
    return res;

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif        //0 1 2 3 4 5 6
string temp="1";
int k=temp.size()/2;
string s1=temp.substr(0,k)+to_string(9)+temp.substr(k);
cout<<s1<<endl;






    
}