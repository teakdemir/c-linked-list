#include <iostream>
#include <stack>// stacklibrary
using namespace std;
int main()
{
stack <int> stack;
stack.push(1);//adds 1 top of the stack
stack.push(2);
stack.push(3);//adds 3 top of the stack

cout<<"Top element: "<<stack.top() << endl;

stack.pop();//removes top of the stack

cout<<"New top element: "<<stack.top() << endl;

if(stack.empty())
cout<<"Stack is empty"<<endl;
else
cout<<"Stack is not empty"<<endl;



return(0);
}

