#include <iostream>

using namespace std;
/*
//sum between m-n with out recursion

int main()
{
    int m=2,n=4;
    int sum=0;
for(int i=m;i<=n;i++)
{
    sum+=i;
}
    
    cout<<" "<<sum;

return(0);
}*/

int recursive_func(int m, int n)
{
if(m==n)
    return m;
    // top is basecase, it stops recursion. never forget this.

    return m+ recursive_func(m+1,n);
}

int main()
{
    
    int m=1, n=555;
    
cout<<"sum= "<<recursive_func(m,n);

    return(0);
}