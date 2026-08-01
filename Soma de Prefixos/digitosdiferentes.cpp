#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
	
    while (cin >> N >> M) {
        int contador = 0;

        for (int i = N; i <= M; i++) {
            char s[10]; 
            sprintf(s, "%d", i); // converte int p/ char[]

            bool repetido = false;

            for (int j = 0; s[j] != '\0'; j++) { // \0 é o fim da string
                for (int k = j + 1; s[k] != '\0'; k++) {
                    if (s[j] == s[k]) {
                        repetido = true;
                    }
                }
            }

            if (!repetido) {
                contador++;
            }
        }

        cout << contador << endl;
    }

    return 0;
}