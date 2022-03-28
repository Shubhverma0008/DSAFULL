#include <iostream>
using namespace std;
class array
{
public:
    int *A;
    int size;
    int length;

public:
    array()
    {
        size = 10;
        length = 0;
        int *A = new int[size];
    }
    array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }
    void insert(int x);
    void display();
    void insert(int index, int x);
    void delet(int index);
    int linear(int key);
    int binary(int key, int l, int h);
    void reverse();
    void sortinsert(int x);
    bool checksort();
    void posneg();
};
void swap(int *x,int *y);
void array::posneg()
{
    int i=0;
    int j=length-1;
    while(i<j)
    {   if(i<j)
       { while(A[i]<0){i++;}
        while(A[j]>0){j--;}}
        if(i<j)
        swap(&A[i],&A[j]);
    }

}
bool array::checksort()
{
    int i=0;
    while(i<length-1)
    {
        if(A[i]>A[i+1])
        return false;
        i++;
    }
    return true;
}
void array::sortinsert(int x)
{

    int i=length-1;
    while(A[i]>x&&i>=0)
    {
        A[i+1]=A[i];
        i--;
    }
    length++;
    
    A[i+1]=x;
}
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void array::reverse()
{
    int i=0;
    int j=length-1;
    while(i<j)
    {
        swap(&A[i],&A[j]);
        i++;
        j--;
    }
    
}
int array::binary(int key, int l, int h)
{
    if (l <= h)
    {
        int mid = (l + h) / 2;
        if (A[mid] == key)
            return A[mid];
        if (A[mid] > key)
            return binary(key, l, mid - 1);
        else
            return binary(key, mid + 1, h);
    }
    return -1;
}
int array::linear(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (A[i] == key)
            return A[i];
    }
    return 0;
}
void array::display()
{
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
}
void array::insert(int x)
{
    if (length >= size)
        return;
    else
    {
        A[length] = x;
        
            length++;
    }
}
void array::insert(int index, int x)
{
    if (index > size)
        return;
    else
    {
        for (int i = length - 1; i >= index; i--)
        {
            A[i + 1] = A[i];
        }
        A[index] = x;
        length++;
    }
}
void array::delet(int index)
{
    if (index < 0 || index > length)
        return;
    else
    {
        for (int i = index; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
    }
}
int main()
{
    array A(11);
    A.insert(1);
    A.insert(-10);
    A.insert(20);
    A.insert(30);
    A.insert(-40);
    A.insert(50);
    A.insert(-60);
    A.insert(-70);
    A.insert(-80);
    A.posneg();
    // cout<<A.length;
    // cout<<A.checksort();
    

    A.display();

    return 0;
}