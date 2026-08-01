#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, K;
    cin >> n >> K;

    long long soma = 0;
    long long contador = 0;

    unordered_map<long long, int> freq; //freq[valor] = quantas vezes apareceu

    freq[0] = 1;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        soma += x;

        if (freq.count(soma - K)) { //freq.count(x) retorna 1 se existe e 0 se nao existe
            contador += freq[soma - K];
        }

        freq[soma]++;
    }

    cout << contador << endl;
    return 0;
}