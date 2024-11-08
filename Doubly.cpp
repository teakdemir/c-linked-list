#include <iostream>
using namespace std;
//single link list has one pointer
//doubly link lists has two pointers  one point to the next node the other points to the first node. 
//apart from these two pointer they also store a value.
//why do we need doubly?- can be traversed two directions
//we can add new nods at the beginning, end ,behind a specific node and after a specific node
// it holds more memory compar4ed to the single link lists
// how to create a node? this time it has 3 parts instead of two
//you can use strcut also ( automatically public)
class Node{
public:
int value;
Node* next;
Node* previous;
};
void PrintNext(Node* head){

    Node* moveTonext= head;
    while(moveTonext!= nullptr)
    {
cout<<moveTonext->value<<endl;
moveTonext=moveTonext->next;
    }
}
void PrintPrev(Node* tail){

    Node* prev= tail;
    while(prev!=nullptr)
    {
        cout<<prev->value<<endl;
        prev=prev->previous;
    }
}
int main()
{
    // creating a head doubly node
Node* head;
Node* tail;
Node *node= new Node();
node->value= 31;
head->next= nullptr;
head->previous=nullptr;
head= node;
tail= node;
//creating a new node after the head
node=new Node();
node->value=5;
node->next=nullptr;
node->previous= tail;
tail->next=node;
tail=node;
// creating another one
node=new Node();
node->value=6;
node->next=nullptr;
node->previous= tail;
tail->next=node;
tail=node;
PrintNext(head);
PrintPrev(tail);

    return(0);
}