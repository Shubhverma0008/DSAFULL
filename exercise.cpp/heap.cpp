#include<iostream>
#include<vector>
using namespace std;
void inseert(vector<int>&A,int n)
{
    int temp;
    int i=n;
    temp=A[n];
    while(i>1&&temp>A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}
void insert(vector<int>&A,int n,int key)
{
    int temp;
    int i=n;
    temp=A[n]=key;
    while(i>1&&temp>A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
   
}
void Delete(vector<int>&A,int n)
{
    int x,i,j;
    i=1;
    j=2*i;
    x=A[i];
    A[i]=A[n];
    while(j<n-1)
    {
        if(A[j+1]>A[j])
        j=j+1;
        if(A[i]<A[j])
        {swap(A[i],A[j]);
        i=j;
        j=2*i;}
        else break;
    }
    A[n]=x;
}
void heap(vector<int>&A,int n)
{
    int i;
    for(int k=n/2;k>=1;k--)
    {
        i=k;
        int j=2*i;
        while(j<n-1)
        {
            if(A[j]<A[j+1])
            j=j+1;
            if(A[i]<A[j])
           { swap(A[i],A[j]);
            i=j;
            j=2*i;}
            else 
            break;
        }

    }

}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    // cout<<"enter a value";
    cin>>n;
    
    vector<int> A(n);
    for(int i=0;i<n;i++)
    {  
        



        cin>>A[i];
        // A[i]=x;
    }
    vector<int>heapfy=A;
    // A.push_back(35)
    heap(heapfy,A.size());
    for(int i=2;i<A.size();i++)
    {
        inseert(A,i);
    }
    // A.resize(A.size()+1);
    // insert(A,9,35);
    for(int i=1;i<A.size()-1;i++)
    {
        Delete(A,A.size()-i);
    }
    for(int i=1;i<A.size()-1;i++)
    {
        Delete(heapfy,A.size()-i);
    }
    
    for(auto i:A)
    cout<<i<<" ";
    cout<<endl<<endl;
    for(auto i:heapfy)
    cout<<i<<" ";
    

}