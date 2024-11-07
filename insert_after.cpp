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
void insertAfter(Node* previous,int x)
{
// first check if the previous node is null. It should not be null.
if(previous==NULL)
{
    cout<<"Error";
    return;

}
//create new node
Node* newNode= new Node();
newNode->value=x;
//insert newNode after the previous node but be careful. first store the address of the next node. only the previous node knows it.
newNode->next= previous->next;
previous->next=newNode;
}

int main()
{
Node* head=new Node();//creating our head element
Node* second=new Node();
Node* third=new Node();
head->value= 1;
head->next= second;
second-> value= 31;
second-> next= third;
third->value =45;
third->next=NULL;
insertAfter(head,69);//insert after the head element.
printList(head);
return(0);
}