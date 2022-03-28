#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;

};
class linkedlist{
    public:
    node*first;
    public:
    linkedlist() { first = nullptr; }
    linkedlist(int A[], int n);
    void display();
    void rdisplay(node *p);
    void rdisplay(){rdisplay(first);}
    int countnode();
    int rcountnode(node *p);
    int rcountnode() { rcountnode(first); }
    int sum(node *p);
    int sum() { sum(first); }
    int max(node *p);
    int max() { max(first); }
    void insert(int pos, int x);
    void sortedinsert(int x);
    void Delete(int pos);
    bool sort();
    int duplicate();
    void reverselist();
    void rrverse(node *q, node *p);

};
linkedlist::linkedlist(int A[],int n)
{
    first=new node;
    first->data=A[0];
    node*last;
    last=first;
    for(int i=1;i<n;i++)
    {
        node*p=new node;
        p->data=A[i];
        p->next=nullptr;
        last->next=p;
        last=p;

    }
}
void linkedlist::display()
{
    node*p=first;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
void linkedlist::rdisplay(node*p)
{
    if(p==nullptr)
    return ;
    else
    {
        rdisplay(p->next);
        cout<<p->data<<" ";
    }
}
int linkedlist::rcountnode(node*p)
{
    if(p==nullptr)
    return 0;
    else
    {
        return rcountnode(p->next)+1;
    }
}
int linkedlist::countnode()
{
    int c=0;
    node*p=first;
    while(p)
    {
        c++;
        p=p->next;
    }
    return c;
}
int linkedlist::sum(node*p)
{
    if(p==nullptr)
    return 0;
    else
    {
        return sum(p->next)+p->data;
    }
}
int linkedlist::max(node*p)
{
    if(p==nullptr)
    return INT8_MIN;
    else
    {
        int x=max(p->next);
        return x>p->data?x:p->data;

    }
}
void linkedlist::insert(int pos,int x)
{
    node*t=new node;
    node*p=first;
    t->data=x;
    t->next=nullptr;
    if(pos==0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(int i=0;i<pos-1&&p;i++)
        p=p->next;
        if(p)
        {
            t->next=p->next;
            p->next=t;
        }
        else
        cout<<"plz enter a valid point";
    }
}
void linkedlist::sortedinsert(int x)
{ 
    node*p=first;
    node*t=new node;
    t->data=x;
    t->next=nullptr;
    if(x<p->data)
    {
        t->next=first;
        first=t;

    }
    else
    {   node*q;
        while(p->next&&x>p->next->data)
        // {q=p;
        p=p->next;

        t->next=p->next;
        p->next=t;
    }

}
void linkedlist::Delete(int pos)
{
        node*p=first;
    if(pos==0)
    {
        first=first->next;
        delete p;
    }
    else{
        node*q;
        for(int i=0;i<pos&&p;i++)
        {q=p;
        p=p->next;}
        if(p)
        {
            q->next=p->next;
            delete p;

        }
        else cout<<"kindly enter valid point";
    }
}
bool linkedlist::sort()
{
    node*p=first;
    while(p->next&&p)
    {
        if(p->next->data<p->data)
        return false;
        p=p->next;
    }
    return true;
}
int linkedlist::duplicate()
{ int c=0;
    node*p=first;
    node*q=p->next;
    while(q)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {p->next=q->next;
        delete q;
        c++;
        q=p->next;}
        
        
        
    }
    return c;
}
void linkedlist::reverselist()
{
    node*p=first;
    node*q=nullptr,*r=nullptr;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
        
    }
    first=q;
}
void linkedlist::rrverse(node*q,node*p)
{
    if(p)
    {
        rrverse(p,p->next);
        p->next=q;
    }
    else
    {
        first=q;
    }
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
   int A[9]={10,20,30,40,50,60,70,80,90};
   linkedlist l(A,9);
   l.rrverse(nullptr,l.first);
  
   cout<<endl;



   l.display();

   
    return 0;
}
