#include<iostream>
#include<math.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
void intialize(node**bins)
{
    for(int i=0;i<10;i++)
    bins[i]=nullptr;
}
int countdigit(int x)
{  int c=0;
    while(x!=0)
    {
        x=x/10;
        c++;
    }
    return c;
}
int findmax(int A[],int n)
{
    int max=A[0];
    for(int i=1;i<n;i++)
    {
        if(A[i]>max)
        max=A[i];
    }
    return max;
}
void insert(node**bins,int value,int index)
{
    node*temp;
    temp=new node;
    temp->data=value;
    temp->next=nullptr;
    if(bins[index]==nullptr)
    bins[index]=temp;
    else
    {
        node*p=bins[index];
        while(p->next)
        p=p->next;
        p->next=temp;
    }

}
int Delete(node**bins,int x)
{
    node*p=bins[x];
    bins[x]=bins[x]->next;
    int k=p->data;
    delete p;
    return k;
}
int getindex(int value,int pass)
{
    int k=value/pow(10,pass);
    return k%10;
}
void radix(int A[],int n)
{
    node**bins;
    bins=new node*[10];
    intialize(bins);
   int max=findmax(A,n)  ;
      int tpass=countdigit(max);
      for(int pass=0;pass<tpass;pass++)
      {
          for(int i=0;i<n;i++)
          {
             int index=getindex(A[i],pass);
              insert(bins,A[i],index);
          }
          int i=0,j=0;
          while(i<10)
          {
              while(bins[i])
              A[j++]=Delete(bins,i);
              i++;
          }
          intialize(bins);
      }
}
int main()
{
    int A[]={237,146,259,348,152,163,235,48,36,62};
    radix(A,10);
    for(auto i:A)
    cout<<i<<" ";
}