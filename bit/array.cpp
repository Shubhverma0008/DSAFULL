#include<iostream>
using namespace std;
class array
{   public:

    int *A;
    int size;
    int length;
    public:
    array(int size)
    {
        this->size=size;
        A=new int[size];
        length=0;


    }
    
    void insert(int index,int key);
    void Delete(int index);
    int linearsearch(int key);
    int binarysearch(int l,int h,int key);
    void reverse();
    void insertsort(int key);
    void display();
    void posneg();
    void duplicate();
    int dup();
    
};
int array::dup()
{
    int i=0;
    for(int i=0;i<length;i++)
    {
        if(A[i]==A[i+1])
        {
            int j=i;
            while(A[j]==A[j+1])j++;
              cout<<"dup of "<<A[j-1]<<" is "<<j-i<<endl;
              i=j-1;

        }
    }
}
void array::duplicate()
{
    int i=0;
    int dup=-1;
    for(int i=0;i<length;i++)
    {
        if(A[i]==A[i+1]&&dup!=A[i])
        {cout<<A[i]<<endl;
        dup=A[i];}
    }
}
void array::posneg()
{
    int i=0;
    int j=length-1;
    while(i<j)
    {while(A[i]<0)i++;
    while(A[j]>0)j--;
    if(i<j)
    swap(A[i],A[j]);}
}
void array::insertsort(int key)
{  int i=length-1;
    while(key<A[i]&&i>=0)
    {
        A[i+1]=A[i];
        i--;
    }
    i++;
    A[i]=key;
    length++;


}
void array::reverse()
{
    int i=0;
    int j=length-1;
    while(i<=j)
    {
        swap(A[i],A[j]);
        i++;
        j--;
    }
}
int array::binarysearch(int l,int h,int key)
{
    while(l<=h)
    {
        int  mid=(l+h)/2;
        if(A[mid]==key)
        return 1;
        if(A[mid]>key)
        h=mid-1;
        else
        l=mid+1;
    }
    return 0;
}
int array::linearsearch(int key)
{
    for(int i=0;i<length;i++)
    {
        if(A[i]==key)
        return 1;
    }
    return 0;
}
void array::Delete(int index)
{
    for(int i=index;i<length;i++)
    {
        A[i]=A[i+1];
    }
    length--;
}
void array::insert(int index,int key)
{
    for(int i=length-1;i>=index;i--)
   { A[i+1]=A[i];}
   A[index]=key;
   length++;


}
void array::display()
{
    int i=0;
    while(i<length)
    {
        cout<<A[i]<<endl;
        i++;
    }
}
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
     #endif
    class array arr(10);
    for(int i=0;i<11;i++)
    {
        int x;
        cin>>x;
        arr.A[i]=x;
        arr.length++;
    }
    int index;
    int key;
    // cin>>key;
    // arr.insertsort(key);
    // arr.posneg();
//    cout<< arr.linearsearch(key)<<endl;
// cout<<arr.binarysearch(0,6,90)<<endl;
    
    // arr.insert(index,key);
    // arr.Delete(index);
    // arr.reverse();
    // arr.duplicate();
    // arr.dup();
    cout<<"array"<<endl;
    arr.display();
   
    
    
    

    

}