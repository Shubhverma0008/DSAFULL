#include<bits/stdc++.h>
using namespace std;
    bool canThreePartsEqualSum(vector<int>& arr) {
        int x=accumulate(arr.begin(),arr.end(),0);
        if(accumulate(arr.begin(),arr.end(),0)%3!=0)
        return false;
        int y=accumulate(arr.begin(),arr.end(),0)/3;
        int z=0;
        int sum=0;
        for(int  i=0;i<arr.size();i++)
        {
           
                sum+=arr[i];
                 if(y==sum)
            {
                sum=0;
                z++;
            }
        }
        if(z==3)
            return true;
        return false;
        
    }
 
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

vector<int>v{1,-1,1,-1};
cout<<canThreePartsEqualSum(v);     
       

}