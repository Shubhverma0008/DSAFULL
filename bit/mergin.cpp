#include<iostream>
using namespace std;
struct node
{
    int data;
    node*next;

}*first=nullptr,*second=nullptr,*third=nullptr;
node* insert(node*p,int x)
{
    node*last,*temp;
    temp=new  node;
    temp->data=x;
    temp->next=nullptr;
    if(p==nullptr)
    last=p=temp;
    else
    {
        last->next=temp;
        last=temp;
    }
    return temp;
}
void display(node*p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
void concate(node*p,node*q)
{
    while(p->next)
    p=p->next;
    p->next=second;
}
void merge(node*first,node*second)
{
    node*last;
    if(first->data<second->data)
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
        else{
            last->next=first;
            last=first;
            first=first->next;
            second=second->next;
            last->next=nullptr;
        }
        
    }
    if(first)
    last->next=first;
    if(second)
    last->next=second;
}

int main()
{
    first=insert(first,2);
    insert(first,8);
    insert(first,10);
    insert(first,12);
    insert(first,15);
    second=insert(second,4);
    insert(second,7);
    insert(second,12);
    insert(second,15);
    insert(second,18);
    insert(second,19);
    merge(first,second);
    display(third);


}