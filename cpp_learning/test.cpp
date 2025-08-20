#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{   int a=10;
    int &re=a;
    re=40;
    int b=23;
    cout<<"b="<<b<<endl;
    cout<<a<<endl;
}
