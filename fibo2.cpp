#include <iostream>
using namespace std;


pow(int a, int b)
{
if(b==0)
{
    return 1;
} else{

    return a*pow(a,b-1);
}

}

int main()
{
int a,b;
cout<<"Enter two num: ";
cin>>a>>b;
cout<<" "<<pow(a,b);

}