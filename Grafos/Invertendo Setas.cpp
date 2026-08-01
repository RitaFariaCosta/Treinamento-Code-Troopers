#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct Aresta {
    int destino;
    int custo;
};

int bfs01(int origem, int destino, vector<vector<Aresta>> &adj)
{
    int n = adj.size() - 1;

    vector<int> dist(n + 1, INF);
    deque<int> fila;

    dist[origem] = 0;
    fila.push_front(origem);

    while(!fila.empty())
    {
        int u = fila.front();
        fila.pop_front();

        for(auto aresta : adj[u])
        {
            int v = aresta.destino;
            int custo = aresta.custo;

            if(dist[u] + custo < dist[v])
            {
                dist[v] = dist[u] + custo;

                if(custo == 0)
                    fila.push_front(v);
                else
                    fila.push_back(v);
            }
        }
    }

    return dist[destino];
}

int main()
{
    int C, S, A, B;

    while(cin >> C >> S >> A >> B)
    {
        vector<vector<Aresta>> adj(C + 1);

        for(int i = 0; i < S; i++)
        {
            int u, v;
            cin >> u >> v;

            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }

        int X = bfs01(A, B, adj);
        int Y = bfs01(B, A, adj);

        if(X == INF && Y == INF)
        {
            cout << "Bibibibika" << endl;
        }
        else if(X < Y)
        {
            cout << "Bibi: " << X << endl;
        }
        else if(Y < X)
        {
            cout << "Bibika: " << Y << endl;
        }
        else
        {
            cout << "Bibibibika" << endl;
        }
    }

    return 0;
}