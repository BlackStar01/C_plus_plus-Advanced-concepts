/*
    Écrivez une fonction récursive en C++ pour calculer le nombre de façons de choisir k éléments
    parmi un ensemble de n éléments (nCk). Utilisez la mémoïsation pour éviter de recalculer les mêmes
    valeurs intermédiaires lors de l'appel récursif. Par exemple, calculez le nombre de façons de
    choisir 3 cartes parmi un jeu de 52 cartes.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> memo; 

int factorial(const int n) {
    if(n == 0 || n == 1) {
        return 1;
    }
    else {
        if (memo[n] != -1) {
            return memo[n];
        }
        memo[n] = n * factorial(n-1);
        return memo[n];
    }
}

float combinaison(const int n, const int p)
{
    return factorial(n)/(factorial(p)*factorial(n-p));
}

int main()
{
    int n = 10;

    memo.resize(n + 1, -1);
    cout << combinaison(n, 4) << endl;

    return 0;
}
