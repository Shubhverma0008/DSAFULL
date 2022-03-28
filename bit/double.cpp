#include<iostream>
using namespace std;
struct node
{
    int data;
    node*next;

};
class circular
{
    node*head;
    public:
    circular()
    {
        head=nullptr;
    }
    circular(int A[],int n);
    void insert(int pos,int x);
    void Delete(int index);
    void display();

};

circular::circular(int A[],int n)
{
    head=new node;
    node*last;
    head->data=A[0];
    head->next=head;
    last=head;
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
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
}
void circular::insert(int pos,int x)
{   node*p=head;
    if(pos==0)
    {
        do{
            p=p->next;
        }while(p->next!=head);
    
        node*t=new node;
        p->next=t;
        t->data=x;
         t->next=head;
         head=t;
    }
    else
    {
        for(int i=0;i<pos-1;i++)
        {  p=p->next;

        }
        node*t=new node;
        t->data=x;
        t->next=p->next;
        p->next=t;

    }
}

int main()
{

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
     #endif
    int A[]={1,2,3,4,5,6,7,8};
    circular c(A,8);
    //  c.insert(8,233);
  



    c.display();

}