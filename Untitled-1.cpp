#include <iostream>

using namespace std;

// a linked list is a data structure to store and organize data. Unlike arrays it is not continuous. It does not come one after the other like arrays.
// elements store value and the address of the nest element.(via pointers)
// last element on the linked list, stores the value and NULL---> the is no next element.( first part value second part address of the next)
// linked list has dynamic size. You can add and delete elements. -advantage
// you cant access the n th element directly. You have to all the necessary elements to access n th element. -disadvantage
// linked lists needs more memory compared to arrays. -disadvantage
// both have useful sides to use depending on the situation


// how to implement a basic linked list?

class node {
public:
int value;
node* next;

};

// needs head element--> head element starts the link up
void printList(node* n){

while (n!=NULL)
{
    cout<<n->value<<endl;
    n=n->next;
}

} 

int main()
{
// creating list elements
node* head= new node();
node* element2= new node();
node* element3= new node();
node* current=new node();
// assigning values of the list elements
head->value=1;

// linking elements
head->next=element2;

element2->value=2;
element2->next=element3;
element3->value=31;
element3->next=NULL;
current=head;

printList(head);
cout<<current<<endl; 
cout<<head<<endl;
cout<<element2<<endl;// to show that the printed value is the address of head not the element1
//this copys the address of head to the current

current= element2;
cout<<"this is how you can print via another variable "<<current->value<<endl;
//using current to print element 2
return(0);
}

