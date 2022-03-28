#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node* next;
};
class circular
{
    node *head;

public:
    circular() { head = nullptr; }
    circular(int A[], int n);
    void display();
    void insert(int pos,int x);
    void Delete(int index);


};
void circular::insert(int pos,int x)
{  node *p=head;
node *t;
    if(pos==0)
    {
       
        do 
        { 
            p=p->next;

        }while(p->next!=head);
        t=new  node;
        t->data=x;
        t->next=head;
        p->next=t;
        head=t;

    }
    else if(pos>0)
    {
        
       for(int i=0;i<pos-1&&p->next!=head;i++)
       {
          
           p=p->next;
       }
       if(p->next!=head)
       {
           t=new node;
           t->data=x;
           t->next=p->next;
           p->next=t;
       }

    }
}
circular::circular(int A[], int n)
{
    node *p, *last;
    head = new node;
    head->data = A[0];
    head->next = head;
    last = head;
    for (int i = 1; i < n; i++)
    {
        p = new node;
        p->data=A[i];
        p->next=head;
        last->next=p;
        last=p;

        
    }
}
void circular::display()
{
    node *p=head;
    do
    {
        cout<<p->data<<" ";
        p=p->next;
    } while (p!=head);
    
}
void circular::Delete(int index)
{  node *p=head;
    if(index==0)
    {
        while(p->next!=head)
        {
            p=p->next;
        }
        p->next=head->next;
        delete head;
        head=p->next;

    }
    else 
    {
         node *q;
         for(int i=0;i<index;i++)
         { q=p;
          p=p->next;}


         
            { q->next=p->next;
             delete p;
             p=q->next;}
         
    }

}


int main()
{
    int A[]={1,2,3,4,5,6,7};
    circular c(A,7);
    // c.insert(7,9);
    // c.Delete();
    c.display();
    return 0;
}