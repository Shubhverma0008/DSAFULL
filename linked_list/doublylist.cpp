#include<iostream>
using namespace std;
class node{
    public:
    node *prev;
    int data;
    node *next;
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
void doublee::insert(int pos,int x){
    if(pos==0)
    {
        node*t=new node;
        t->prev=nullptr;
        t->data=x;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else if(pos>0)
    {   node*p=first;
        for(int i=0;i<pos-1&&p;i++)
        {
            p=p->next;

        }
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
doublee::doublee(int A[],int n)
{   node*last;

    first=new node;
    first->prev=nullptr;
    first->data=A[0];
    first->next=nullptr;
    last=first;
    for(int i=1;i<n;i++)
    {
        node*t=new node;
        t->prev=last;
        t->data=A[i];
        t->next=nullptr;
        last->next=t;
        last=t;
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
void doublee::Delete(int index)
{  node*p=first;
    if(index==0)
    { 
        first=first->next;
        first->prev=nullptr;
        delete p;


    }
    else if(index>0)
    {
        for(int i=0;i<index&&p;i++)
        {
            p=p->next;
        }
        if(p)
        {
            p->prev->next=p->next;
            if(p->next)
            p->next->prev=p->prev;
            delete p;
            
        }

    }
}
void doublee::reverse()
{
    node*temp;
    node*p=first;
    while(p)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p&&p->next==nullptr)
        first=p;
        
    }
    

}

int main()
{
    int A[]={1,2,3,4,5,6,7};
    doublee d(A,7);
    // d.Delete(8);
    d.reverse();
     
   
    d.display();
}
