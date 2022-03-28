#include<iostream>
using namespace std;
#define ll long long
struct node
{
    int data;
    node*next;
}*first=nullptr;
void create(int A[],int n)
{
    first=new node;
    first->data=A[0];
    first->next=nullptr;
    node*last=first;

    for(int i=1;i<n;i++)
    {
        node*t=new node;
        t->data=A[i];
        t->next=nullptr;
        last->next=t;
        last=t;

    }
    // making loop in list=>
    // node*p=first;
    // while(p->data!=5)
    // {
    //     p=p->next;

    // }
    // last->next=p;
   
}
void display(node*p)
{  int i=0;
    while(p&&i<17)
    {
        cout<<p->data<<" ";
        p=p->next;
        i++;
    }
}
int half(node*p)
{  node*r=p;
    node*q=p;
    while(q&&q->next)
    {
        r=r->next;
        q=q->next->next;
    }
    return r->data;

}
bool checkloop(node*p)
{
    node*q=p;
    do{
        p=p->next;
        q=q->next;
        q=q!=nullptr?q->next:nullptr;
    }while(p&&q&&p!=q);
    if(p==q)
    return true;
    return false;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    // int A[]={1,2,3,4,5,6,7,8,9,10};
    // create(A,10);
    // display(first);
    // cout<<endl;
    // //find half a list
    // // cout<<half(first);
    // cout<<checkloop(first);
    int tc;
   cin >> tc;

   while(tc--){

       ll n;
       cin >> n;

       string s;
       cin >> s;

       bool flag = true;

       ll cnt0 = 0, cnt1 = 0;
       for(auto x: s){
           if(x == '0'){
               cnt0++;
           }else{
               cnt1++;
           }
       }

       if (min(cnt0, cnt1) == 0) {
           flag = false;
       }
       
       if (min(cnt0, cnt1) >= 2) {
           ll move = cnt0 + cnt1 - (2LL * min(cnt0, cnt1));
           if (move % 2 == 0) {
               flag = false;
           }
       }

       if(flag){
           cout << "Alice" << endl;
       }else{
           cout << "Bob" << endl;
       }




   }

}