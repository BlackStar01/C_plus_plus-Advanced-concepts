#include <iostream>
#include <vector>
using namespace std;

// Tableau pour stocker les résultats intermédiaires
vector<int> memo; 

int fibonacci(const int n)
{
    // Si fibo pour n est déjà calculé, retournez-le
    if (memo[n] != -1)
    {
        return memo[n];
    }

    if (n == 0 || n == 1)
    {
        return n;
    }
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main()
{
    int number = 11;

    memo.resize(number + 1, -1);
    cout << fibonacci(number) << endl;

    return 0;
}
