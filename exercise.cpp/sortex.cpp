#include <iostream>
#include<math.h>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
void bubble(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)

    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
                swap(A[j], A[j + 1]);
        }
    }
}
void insertion(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = A[i];
        int j = i - 1;
        while (j >= 0 && temp < A[j])
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
    }
}
void selection(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int k = i;
        for (int j = i; j < n; j++)
        {
            if (A[j] < A[k])
                k = j;
        }
        swap(A[i], A[k]);
    }
}
void merge(int A[], int l, int mid, int h)
{
    int i = l;
    int j = mid + 1;
    int k = l;
    int B[100];
    while (i <= mid && j <= h)
    {
        if(A[i]<A[j])
        B[k++]=A[i++];
        else if(A[i]>A[j])
        B[k++]=A[j++];
        else if(A[i]==A[j])
        {B[k++]=A[i++];
        j++;}
        

    }
    for(;i<=mid;i++)
    B[k++]=A[i];
    for(;j<=h;j++)
    B[k++]=A[j];
    for(int i=0;i<=h;i++)
    A[i]=B[i];
}
void mergesort(int A[],int n)
{
    int p;
    for(p=2;p<=n;p=p*2)
    {
        for(int i=0;i+p-1<n;i=i+p)
        {
            int l=i;
            int h=i+p-1;
            int mid=(l+h)/2;
            merge(A,l,mid,h);
        }
    }
    if(p/2<n)
    {
        merge(A,0,p/2-1,n-1);
    }
}
void rmerge(int A[],int l,int h)
{
    if(l<h)

    {
        int mid=(l+h)/2;
        rmerge(A,l,mid);
        rmerge(A,mid+1,h);
        merge(A,l,mid,h);
    }
}
void shellsort(int A[],int n)
{
    for(int gap=n/2;gap>=1;gap/=2)
    {
        for(int j=gap;j<n;j++)
        {
            int i=j-gap;
            int temp=A[j];
            while(i>=0&&A[i]>temp)
            {
                A[i+gap]=A[i];
                i=i-gap;
            }
            A[i+gap]=temp;
        }
    }
}
struct node{
    int data;
    node*next;


};
void intialize(node**bins)
{
    for(int i=0;i<10;i++)
    bins[i]=nullptr;
}
int count(int x)
{ int c=0;
    while(x)
    {
        x/=10;
        c++;

    }
    return c;
}
int getindex(int value,int pass)
{
    int k=value/pow(10,pass);
    return k%10;
}
int max(int A[],int  n)
{
    int x=INT8_MIN;
    for(int i=0;i<n;i++)
    {
        if(A[i]>x)
        x=A[i];
    }
    return x;
}
void insert(node**bins,int value,int index)
{
    node*temp=new node;
    temp->data=value;
    temp->next=nullptr;
    if(!bins[index])
    bins[index]=temp;
    else
    {
        node*p=bins[index];
        while(p->next)
        p=p->next;
        p->next=temp;
    }


}
int Delete(node**bins,int index)
{
    node*p=bins[index];
    bins[index]=bins[index]->next;
    int x=p->data;
    delete p;
    return x;
}
void radix(int A[],int n)
{
    node**bins=new node*[10];
    int pass=count(max(A,n));
    for(int p=0;p<pass;p++)
    {
        intialize(bins);
        for(int i=0;i<n;i++)
        {
            int index=getindex(A[i],p);
            insert(bins,A[i],index);

        }
        int i=0,j=0;
        while(i<10)
        {
            if(bins[i])
            A[j++]=Delete(bins,i);
            else 
            i++;
        }
        intialize(bins);



    }



}
 bool cmp(pair<int,int> a,pair<int,int> b) {
        
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
    
vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        vector<vector<int>>v1;
        vector<int>v;
        for(int i=arr.size()-1;i>=3;i--)
        {
            for(int j=i-1;j>=2;j--)
            {
                int l=0;
                int r=j-1;
                int x=arr[j];
                int x1=arr[i];
                while(l<r)
                {
                    if(x+x1+arr[l]+arr[r]==k)
                    {
                        v.push_back(arr[l]);
                        v.push_back(arr[r]);
                        v.push_back(x);
                        v.push_back(x1);
                        v1.push_back(v);
                        v.clear();
                        l++;
                        r--;
                        
                        
                    }
                    else if(x+x1+arr[l]+arr[r]<k)
                    l++;
                    else r--;
                    
                }
            }
        }
        return v1;
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
        // cout<<&A[]-A;
    // bubble(A,n);
    // insertion(A,n);
    // selection(A,n);
    // rmerge(A,0,10);
    // shellsort(A,n);
    // radix(A,n);
    // merge(A,0,3,8);
    // vector<vector<int>>v=fourSum(A,k);
    // for(int i=0;i<v.size();i++)
    // {
    //     for(int j=0;j<v[i].size();j++)
    //     cout<<v[i][j]<<" ";
    // }

   
   
}