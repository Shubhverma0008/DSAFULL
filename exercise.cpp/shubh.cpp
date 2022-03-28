#include<bits/stdc++.h>
using namespace std;
struct node
{
    node*lchild;
    int data;
    node*rchild;
}*root=NULL;
void create()
{
    // cout<<"enter root value";
    int x;
    cin>>x;
    root=new node;
    root->data=x;
    root->lchild=root->rchild=nullptr;
    queue<node*>q;
    node*p=root;
    q.push(root);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        cin>>x;
        if(x==-10)return ;
        if(x!=-1)
        {
            node*t=new node;
            t->data=x;
            t->lchild=t->rchild=nullptr;
            p->lchild=t;
            q.push(t);
        }
        cin>>x;
        if(x==-10)return ;
        if(x!=-1)
        {
            node*t=new node;
            t->data=x;
            t->lchild=t->rchild=nullptr;
            p->rchild=t;
            q.push(t);
        }
    }

}
void inorder(node*p)
{
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);

    }
}
void preorder(node*p)
{
    if(p)
    {
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);

    }
}
int main()
{
       #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
       #endif
string s="icodeinpython";
vector<int>spaces{1,5,7,9};
// for(int i=0;i<spaces.size();i++)
// s.insert(i+spaces[i]," ");
// s.insert(14," ");
string res="";
int add=0;
int i=0;
while(i<s.length())
{
    if(i==spaces[add])
    {res+=" ";
    add++;}
    else
    res+=s[i++];

}
cout<<res;
   


}






