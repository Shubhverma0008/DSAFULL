#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
class stack
{  
    node*top;
    public:
    stack(){top=nullptr;}
    void push(int x);
    void pop();
    int Top();
    void display();
    int isempty();




};
int stack::isempty()
{
    if(top==nullptr)
    return 1;
    return 0;
}
int stack::Top()
{
    if(top==nullptr)
    return -1;
    else
    return top->data;
}
void stack::pop()
{
    if(top==nullptr)
    return ;
    else
    {
        top=top->next;
    }
}
void stack::push(int x)
{

   node *t=new node;
   if(t==nullptr)
   return ;
   else
   {
       t->data=x;
       t->next=top;
       top=t;

      
       
   }


}
void stack::display()
{
node*p=top;
while(p)
{
    cout<<p->data<<" ";
    p=p->next;
}
}
int main()
{
    stack st;
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout<<st.isempty();



    cout<<endl;
    st.display();
    return 0;
}

