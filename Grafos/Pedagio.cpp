#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    // Otimização de I/O para evitar Time Limit Exceeded
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int teste = 1;
    int C, E, L, P;

    while (cin >> C >> E >> L >> P && (C != 0 || E != 0 || L != 0 || P != 0)) {
        vector<vector<int>> adj(C + 1);
        for (int i = 0; i < E; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> distancia(C + 1, -1);
        queue<int> fila;

        distancia[L] = 0;
        fila.push(L);

        while (!fila.empty()) {
            int atual = fila.front();
            fila.pop();

            for (int vizinho : adj[atual]) {
                if (distancia[vizinho] == -1) {
                    distancia[vizinho] = distancia[atual] + 1;
                    fila.push(vizinho);
                }
            }
        }

        vector<int> alcancaveis;
        for (int i = 1; i <= C; ++i) {
            if (i != L && distancia[i] != -1 && distancia[i] <= P) {
                alcancaveis.push_back(i);
            }
        }

        sort(alcancaveis.begin(), alcancaveis.end());

        // FORMATAÇÃO DO JUIZ ELETRÔNICO:
        cout << "Teste " << teste++ << "\n";
        
        for (size_t i = 0; i < alcancaveis.size(); ++i) {
            cout << alcancaveis[i] << " "; // Sempre imprime o número seguido de um espaço
        }
        
        // Duas quebras de linha: uma para fechar a linha das cidades e outra para a linha em branco obrigatória
        cout << "\n\n"; 
    }

    return 0;
}