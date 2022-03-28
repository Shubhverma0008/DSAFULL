#include<iostream>
using namespace std;
void merge(int A[],int l,int h,int mid)
{
    int i=l;
    int j=mid+1;
    int k=l;
    int B[100];
    while(i<=mid&&j<=h)
    {
        if(A[i]<A[j])
        B[k++]=A[i++];
        else if(A[i]>A[j])
        B[k++]=A[j++];


    }
         for(;i<=mid;i++)
         B[k++]=A[i];
         for(;j<=h;j++)
         B[k++]=A[j];
         for(int i=0;i<=h;i++)
         {
             A[i]=B[i];
         }

         

    
}
void mergesort(int A[],int n)
{  int p;
    for(p=2;p<=n;p=p*2)
    {
        for(int i=0;i+p-1<n;i=i+p)
        {
            int l=i;
            int h=i+p-1;
            int mid =(l+h)/2;
            merge(A,l,h,mid);
        }
    }
    if(p/2<n)
    {
        merge(A,0,n-1,p/2-1);
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
      int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    mergesort(A,9);
    for(auto i:A)
    cout<<i<<" ";
}