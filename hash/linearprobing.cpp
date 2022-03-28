#include<iostream>
#define size 10
using namespace std;
int haash(int key)
{
    return key%10;
}


int prob(int H[],int key)
{
    int index= haash(key);
    int i=0;
    while(H[(index+i)%size]!=0)i++;
    return (index+i)%size;

    
}
int search(int H[],int key)
{
    int index=haash(key);
    while(H[index]!=key||H[index]==0)
    {
        index++;
    }
    return H[index];
}
void insert(int H[],int key)
{
        int index=haash(key);
        if(H[index]!=0)
        {
            index=prob(H,key);
        }
       H[index]=key;
}
int main()
{
    int H[10]={0};
    insert(H,12);
    insert(H,25);
    insert(H,35);
    insert(H,45);
    
    insert(H,28);
    cout<<search(H,26);



}