#include<iostream>
using namespace std;
struct node{
    node*prev;
    int data;
    node*next;
};
class doublee
{

      node *first;
     public:
     doublee(){first==nullptr;}
     doublee(int A[],int n);
     void display();
     void insert(int pos,int x);
     void Delete(int index);
     void  reverse();
};
doublee::doublee(int A[],int n)
{
    first=new node;
    first->prev=nullptr;
    first->data=A[0];
    first->next=nullptr;
    node*last=first;
    for(int i=1;i<n;i++)
    {
        node*p=new node;
        p->data=A[i];
        p->prev=last;
        last->next=p;
        p->next=nullptr;
        last=p;
        
    }
}
void doublee::display()
{
    node*p=first;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
void doublee::insert(int pos,int x)
{
    node*t=new node;
    t->prev=t->next=nullptr;
    t->data=x;
    node*p=first;
    if(pos==0)
    {
        t->next=p;
        p->prev=t;
        first=t;

    }
    else
    {
        for(int i=0;i<pos-1&&p;i++)
        p=p->next;
        if(p)
        {
            
            node*t=new node;
            t->prev=p;
            t->data=x;
            t->next=p->next;
            if(p->next)
            p->next->prev=t;

            p->next=t;
        }
    }
}
void doublee::Delete(int index)
{node*p=first;
    if(index==0)
    {
        node*q=first;
        first=first->next;
        first->prev=nullptr;
        delete q;
        



    }
    else
    {
        for(int i=0;i<index&&p;i++)
        p=p->next;
        if(p)
        {
            p->prev->next=p->next;
            if(p->next)
            p->next->prev=p->prev;


         
        }
    }
}
void doublee::reverse()
{
    node*p=first;
    while(p)
    {
       node*temp=p->next;
        p->next=p->prev;
        p->prev=temp;       
        p=p->prev;
        if(p&&p->next==nullptr)
         first=p;
    }


}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int A[]={1,2,3,4,5,6};
    doublee d(A,6);
   d.reverse();

    d.display();
}