#include<iostream>
using namespace std;
struct node{
    int data;
    node*next;
};
class circular{
    node*head;
    public:
    circular() { head = nullptr; }
    circular(int A[], int n);
    void display();
    void insert(int pos,int x);
    void Delete(int index);

};
circular::circular(int A[],int n)
{
    head=new node;
    head->data=A[0];
    head->next=head;
    node*last=head;
    for(int i=1;i<n;i++)
    {
        node*t=new node;
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }

}
void circular::display()
{
    node*p=head;
    do
    {
        /* code */
        cout<<p->data<<" ";
        p=p->next;
    } while (p!=head);
    
} 
void circular::insert(int pos,int x)
{ node*p=head;
node*t=new node;
t->data=x;
t->next=nullptr;
    if(pos==0)
    {
        while(p->next!=head)
        p=p->next;
        p->next=t;
        t->next=head;
        head=t;

        
    }
    else
    {
        for(int i=0;i<pos-1;i++)
        p=p->next;
        t->next=p->next;
        p->next=t;
    }
}
void circular::Delete(int index)
{
    node*p=head;
    if(index==0)
    {
        while(p->next!=head)
        p=p->next;
        p->next=head->next;
        node*q=head;
        head=head->next;
        delete q;

    }
    else
    {

        node*q=p;
        for(int i=0;i<index;i++)
        {q=p;
        p=p->next;}
        q->next=p->next;
        delete p;

    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("intput.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int A[]={1,2,3,4,5,6,7,8};
    circular l(A,8);
    l.Delete(9);

      l.display();









    
    
    
    
}