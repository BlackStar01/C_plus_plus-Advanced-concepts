#include <iostream>
using namespace std;

int fibonacci(const int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    cout << fibonacci(11) << endl;

    return 0;
}