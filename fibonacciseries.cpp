#include <iostream>
using namespace std;

int main() {
    int  a = 0, b = 1, nextTerm = 0, sum = 0;

    cout << "Fibonacci Series: ";

    for (int i = 1; i <= 12; ++i) {
        if(i == 1) {
            cout << a << ", ";
            continue;
        }
        if(i == 2) {
            cout << b << ", ";
            continue;
        }
        nextTerm = a + b;
        a = b;
        b = nextTerm;
        if(b%3 == 0){
            sum += b;
        }
        if(i == 12){
            cout << nextTerm << endl;
        }
        else{
            cout << nextTerm << ", ";
        }
    }

    cout << "Sum: " << sum << endl;
    return 0;
}

