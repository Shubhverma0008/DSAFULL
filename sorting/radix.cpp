#include<iostream>
#include<math.h>
using  namespace std;
struct node
{
    int data;
    node*next;

};
void intialize(node**bin)
{
    for(int i=0;i<10;i++)
    {
        bin[i]=nullptr;
    }
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
int countdigit(int n)
{   int c=0;
    while(n!=0)
    {
        n=n/10;
        c++;
    }
    return c;
}
void insert(node**bin,int index,int value)
{
    node*temp=new node;
    temp->data=value;
    temp->next=nullptr;
    if(bin[index]==nullptr)
    bin[index]=temp;
    else
    {
        node*p=bin[index];
        while(p->next)
        {
            p=p->next;
        }
        p->next=temp;
    }
}
int Delete(node**bin,int index)
{
    node*p=bin[index];
    bin[index]=bin[index]->next;
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
     node**bin;
     bin=new node*[10];
     intialize(bin);
     int max=findmax(A,n);
     int tpass=countdigit(max);
     for(int pass=0;pass<tpass;pass++)
     {
         for(int i=0;i<n;i++)
         {  int index=getindex(A[i],pass);
             insert(bin,index,A[i]);
         }
         int i=0,j=0;
         while(i<10)
         {
             while(bin[i])
            A[j++]=Delete(bin,i);
             i++;
         }
         intialize(bin);
     }

}
int main()
{
    int A[]={237,146,259,348,152,163,235,48,36,63};
    radix(A,10);
    for(auto i:A)
    cout<<i<<" ";
}