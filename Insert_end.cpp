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
void insertEnd(Node **head, int x)
{
Node* newNode= new Node();
newNode->value= x;
    if(*head==NULL){
        *head==newNode;
        return;
    }//if the list is empty, our newly created list becomes head.
//we need to find the last node
Node* current= *head;
while(current->next!=NULL)//checking if the currents next element is NULL
{
current=current->next;
}
current->next=newNode;
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
insertEnd(&head,4);
printList(head);
return(0);
}