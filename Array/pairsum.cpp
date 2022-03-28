#include<iostream>
using namespace std;
int main()
{
    int A[]={1,2,3,4,5,6,-7,8,90,10,11,12};
    cout<<"enter which number pair you want";
    int x;
    cin>>x;
    for(int i=0;i<12;i++)
    {
        for(int j=i+1;j<12;j++)
        if(A[i]+A[j]==x)
        cout<<A[i]<<" "<<A[j]<<endl;
    }
    int max=A[0];
    int min=A[0];
    for(int i=0;i<12;i++)
    {
        if(A[i]>max)
        max=A[i];
        if(A[i]<min)
        min=A[i];
        
    }
    cout<<"max "<<max<<"min "<<min<<endl;
    return 0;
}