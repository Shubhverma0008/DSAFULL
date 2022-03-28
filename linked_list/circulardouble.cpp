#include<iostream>
using namespace std;
class node{
    public:
    node *prev;
    int data;
    node*next;
};
class cirdouble
{
    node*head;
    public:
    cirdouble(int A[],int n);
      void display();
      void insert(int pos,int x);
};
void cirdouble::insert(int pos,int x)
{ node*p=head;
    if(pos==0)
    {
        node*t=new node;
        t->data=x;
        t->next=head;
        head->prev->next=t;
        t->prev=head->prev;
        head->prev=t;
        head=t;

    }
    else if(pos>0)
    {
        for(int i=0;i<pos-1;i++)
        {
            p=p->next;
        }
        node*t=new node;
        t->data=x;
        t->next=p->next;
        if(p->next)
        p->next->prev=t;
        p->next=t;
        t->prev=p;
    }
}
cirdouble::cirdouble(int A[],int n)
{
    head=new node;
    node*last;
    head->data=A[0];
    head->next=head;
    head->prev=head;
    last=head;
    for(int i=1;i<n;i++)
    {
        node*t=new node;
        t->data=A[i];
        t->next=last->next;
        head->prev=t;
        t->prev=last;
        last->next=t;
        last=t;
        
    }
}
void cirdouble::display()
{
    node*p=head;
   do {
       cout<<p->data<<" ";
       p=p->next;
   
    

}while(p!=head);
}
int main()
{
    int A[]={1,2,3,4,5,6,7};
    cirdouble cd(A,7);
    cd.insert(7,22);
    cd.display();


}