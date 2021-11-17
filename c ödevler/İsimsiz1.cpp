#include <iostream>

using namespace std;

class A
{
    public: 
    int i; 
};
A* f()
{
    A* x;
    return x;
}
int main()
{
    A* pA = f();
    pA->i = 10;
}
