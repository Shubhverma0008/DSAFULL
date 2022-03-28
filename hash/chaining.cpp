 #include<iostream>
 using namespace std;
 struct node
 {
     int data;
     node*next;
 };
 void intialize(node**H)
 {
for(int i=0;i<10;i++)
H[i]=nullptr;
 }
 void sortedinsert(node* H,int key)
 {
    node**chain;
    chain=new node*[10];
    intialize(chain);
    node*t=new node;
    t->data=key;
    t->next=nullptr;
    if(chain[0]==nullptr)
    chain[0]=t;
    H=chain;



           
     

   
     

 }


 int main()
 {
      node *H;
      sortedinsert(H,7);
      sortedinsert(H,8);
      sortedinsert(H,9);

      
     
   
    
     
 }