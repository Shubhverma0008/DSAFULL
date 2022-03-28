#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
}*first=nullptr,*second=nullptr;
node * insert(node*A,int x)
{  node *last;
    node *t=new node;
    t->data=x;
    t->next=nullptr;
    if(A==nullptr)
    A=last=t;
    else
    {last->next=t;
    last=t;}
    return t;

}
void display(node *A)
{
    node*p=A;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    
}
void merging(node *A,node *B)
{
    while(A->next!=nullptr)
    {
        A=A->next;
    }
    A->next=B;
}
void mergingsort(node*first,node*second)
{
    node *third,*last;
    if(first->data>second->data)
    {
        third=last=first;
        first=first->next;
        last->next=nullptr;
    }
    else
    {
        third=last=second;
        second=second->next;
        last->next=nullptr;
    }
    while(first&&second)
    {
        if(first->data<second->data)
        {
            last->next=first;
            last=first;
            first=first->next;
            last->next=nullptr;
            
        }
        else if(first->data>second->data)
        {
            last->next=second;
            last=second;
            second=second->next;
            last->next=nullptr;
        }
        else if(first->data==second->data)
        {
            last->next=second;
            last=second;
            second=second->next;
            first=first->next;
            last->next=nullptr;
        }
        if(first)
        {
            last->next=first;
        }
        else last->next=second;


    }

}



int main()
{
   first= insert(first,2);
    insert(first,8);
    insert(first,10);
    insert(first,15);
    display(first);
    cout<<endl;
   second= insert(second,4);
    insert(second,7);
    insert(second,12);
    insert(second,15);
    insert(second,18);
    insert(second,19);
    display(second);
    mergingsort(second,first);
    cout<<endl;
    display(second);
}