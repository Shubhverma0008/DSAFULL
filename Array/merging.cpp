#include<iostream>
using namespace std;
struct array{
    int *A;
    int size;
    int length;

};
void insert(array *A,int x)

{
    if(A->length>=A->size)
    return ;
    else
    {
        A->A[A->length]=x;
        A->length++;
    }

}
void display(array A)
{
    for(int i=0;i<A.length;i++)
    {
        cout<<A.A[i]<<" ";
    }
}
int duplicate(array *A)
{
    int dup=0;
    int duplic;
    int i=0;
    int j=0;
    int k;
   
    
    while(i<A->length-1)
    {
        if(A->A[i]==A->A[i+1]&&duplic!=A->A[i])
          {duplic=A->A[i];
           dup++;}
           i++;
    }
    return dup;
}

void intersection(array *A,array *B)
{
    array arr3;
    arr3.size=A->size+B->size;
    arr3.length=0;
    int i=0,j=0,k=0;
    while(i<A->length&&j<B->length)
{
    if(A->A[i]<B->A[j])
    i++;
    else if(A->A[i]>B->A[j])
    j++;
    else if(A->A[i]==B->A[j])
   { arr3.A[k++]=A->A[i++];
    j++;}
    }
    arr3.length=k;
    display(arr3);
}
array merging(array *A,array *B)
{
    array arr3;
    arr3.size=A->size+B->size;
    arr3.length=0;
    arr3.A=new int[arr3.size];
    int i=0;
    int j=0;
    int k=0;
    while(i<A->length&&j<B->length)
    {
        if(A->A[i]<B->A[j])
        {
            arr3.A[k++]=A->A[i++];
        }
        else if(A->A[i]>B->A[j])
        arr3.A[k++]=B->A[j++];
        else if(A->A[i]==B->A[j])
        {
            arr3.A[k++]=B->A[j++];
            i++;
        }
    }
    for(;i<A->length;i++)
    arr3.A[k++]=A->A[i];
    for(;j<B->length;j++)
    arr3.A[k++]=B->A[j];
    arr3.length=k;
    return arr3;
}
int main()
{
    array arr;
    arr.size=5;
    arr.length=0;
    arr.A=new int[arr.size];
    insert(&arr,3);
    insert(&arr,8);
    insert(&arr,16);
    insert(&arr,20);
    insert(&arr,25);
    array arr1;
    arr1.size=6;
    arr1.length=0;
    arr1.A=new int[arr1.size];
     insert(&arr1,4);
    insert(&arr1,12);
    insert(&arr1,12);
    insert(&arr1,12);
    insert(&arr1,15);
    insert(&arr1,25);
    // array k=merging(&arr,&arr1);
    // display(k);
    // cout<<endl;
    // intersection(&arr,&arr1);
    cout<<duplicate(&arr1);
    
    cout<<endl;    


    // display(arr);
    // cout<<endl;
    display(arr1);

}