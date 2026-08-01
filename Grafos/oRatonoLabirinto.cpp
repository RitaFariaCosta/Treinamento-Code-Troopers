#include <bits/stdc++.h>

#define MAXV 10005

using namespace std;

vector<int> adj[MAXV];
int dist[MAXV];

void bfs(int origem)
{
    memset(dist, -1, sizeof(dist));

    queue<int> fila;

    dist[origem] = 0;
    fila.push(origem);

    while (!fila.empty())
    {
        int u = fila.front();
        fila.pop();

        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];

            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                fila.push(v);
            }
        }
    }
}

int main()
{
    int Pontos, Ligacoes;
    cin >> Pontos >> Ligacoes;

    map<string, int> id;
    int prox = 0;

    string a, b;

    for (int i = 0; i < Ligacoes; i++)
    {
        cin >> a >> b;

        if (!id.count(a))
            id[a] = prox++;

        if (!id.count(b))
            id[b] = prox++;

        int u = id[a];
        int v = id[b];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int entrada = id["Entrada"];
    int queijo = id["*"];
    int saida = id["Saida"];

    bfs(entrada);
    int distEntradaQueijo = dist[queijo];

    bfs(queijo);
    int distQueijoSaida = dist[saida];

    cout << distEntradaQueijo + distQueijoSaida << endl;

    return 0;
}