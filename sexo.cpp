#include <iostream>
using namespace std;

int func(int x)
{
if(x==0)
{
return 1;
}
else {    return x*func(x-1);
}
return(0);
}

int main()
{
int x=5;
cout<<func(x);
    
}
