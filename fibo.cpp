#include <iostream>
using namespace std;

int fib(int n){
if ( n==0) {
return 0;
} else if ( n==1) {
return 1;
} else {
return fib(n-2)+fib(n-1);
}
}

int main()
{
    int z;
    cout<<"Sex: ";
cin>>z;
    for(int i=0;i<z;i++)
    {
        cout<<" "<<fib(i);
    }
    
}

