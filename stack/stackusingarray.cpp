#include<iostream>
using namespace std;
class stack
{  public:
    int Top;
    int size;
    int *A;
    public:
    stack();
    void push(int x);
    void pop();
    int top();
    int isempty();
    void display();
};
stack::stack()
{
    size=5;
    Top=-1;
    A=new int[size];
}
void stack::push(int x)
{
    if(Top==size-1)
    return ;
    else
    {
        Top++;
        A[Top]=x;

    }
}
void stack::pop()
{
    if(Top==-1)
    return ;
    else
    {
        Top--;
    }
}
int stack::isempty()
{
    if(Top==-1)
    return 1;
    return 0;
}
int stack::top()
{
    if(Top==-1)
    return -1;
    else
    return A[Top];
}
void stack::display()
{
    while(Top!=-1)
    {
        cout<<A[Top]<<" ";
        Top--;
    }
}
int main()
{
    stack st;
    st.push(3);
    st.push(22);
    st.push(22);
    st.push(22);
    st.push(24);
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.push(23);
    st.pop();
    st.pop();

    cout<<st.top();
    cout<<endl<<st.isempty();



    cout<<endl;
    st.display();

}
