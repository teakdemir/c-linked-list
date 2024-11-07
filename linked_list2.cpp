#include <iostream>
using namespace std;

class Node{
public:
int value;
Node* next;//same name as the class dont forget
};

void printList(Node* n)//do not forget to put your node variable 
{
while(n!=NULL)
{
cout<<n->value<<endl;//our public int variable
n=n->next;// our node pointer
}
}
void insertAtFront(Node** head, int x)//address of the pointer head thus the **
{
//things the do
//first create a new node
Node* newNode= new Node();
newNode->value= x;
//second put the new node in front of the head-- new node point to the current head
newNode->next= *head;
// move head of the to point to the new node
*head= newNode;
}
int main()
{
int x,y;
cout<<"What will you add at the front? "<<endl;
cin>>x;
Node* head=new Node();//creating our head element
Node* second=new Node();
Node* third=new Node();

head->value= 1;
head->next= second;
second-> value= 31;
second-> next= third;
third->value =45;
third->next=NULL;

insertAtFront(&head,x);

printList(head);
return(0);
}