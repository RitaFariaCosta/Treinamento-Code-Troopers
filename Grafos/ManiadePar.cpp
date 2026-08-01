#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define MAXV 10005

using namespace std;

vector<pair<int, int>> adj[MAXV]; //(vertice, peso)
int dist[MAXV][2];                // dist[vertice][0] = par, dist[vertice][1] = ímpar

void dijkstra(int origem)
{
    bool vis[MAXV][2] = {};
    priority_queue<pair<int, int>> pq;

    // Inicializa
    for (int i = 0; i < MAXV; i++)
    {
        dist[i][0] = INF;
        dist[i][1] = INF;
    }

    dist[origem][0] = 0;                   // começa com 0 pedágios (par)
    pq.push(make_pair(0, origem * 2 + 0)); // codifica vértice + paridade

    while (!pq.empty())
    {
        int codigo = pq.top().second;
        int u = codigo / 2;        // extrai o vértice
        int paridade = codigo % 2; // extrai a paridade (0=par, 1=ímpar)
        int custoAtual = -pq.top().first;
        pq.pop();

        if (vis[u][paridade])
            continue;
        vis[u][paridade] = true;

        for (int i = 0; i < (int)adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int duv = adj[u][i].second;

            int novaParidade = 1 - paridade; // inverte (0?1, 1?0)
            int novoCusto = custoAtual + duv;

            // verifica se achou caminho melhor
            if (novoCusto < dist[v][novaParidade])
            {
                dist[v][novaParidade] = novoCusto;
                pq.push(make_pair(-novoCusto, v * 2 + novaParidade)); // codifica novo estado
            }
        }
    }
}

int main()
{
    int nVertices, nArestas, x, y, custo;

    cin >> nVertices >> nArestas;

    for (int i = 0; i < nArestas; i++)
    {
        cin >> x >> y >> custo;
        adj[x].push_back(make_pair(y, custo));
        adj[y].push_back(make_pair(x, custo));
    }

    dijkstra(1);

    // pega dist[destino][0] (quantidade PAR de pedágios)
    if (dist[nVertices][0] == INF)
        cout << -1 << endl;
    else
        cout << dist[nVertices][0] << endl;

    return 0;
}