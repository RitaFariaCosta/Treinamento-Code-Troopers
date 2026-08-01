#include <bits/stdc++.h>

#define MAXV 64

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
    int dx[] = {-2,-2,-1,-1,1,1,2,2};
    int dy[] = {-1,1,-2,2,-2,2,-1,1};

    // monta o grafo do tabuleiro
    for(int x = 0; x < 8; x++)
    {
        for(int y = 0; y < 8; y++)
        {
            int u = x * 8 + y;

            for(int k = 0; k < 8; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
                {
                    int v = nx * 8 + ny;
                    adj[u].push_back(v);
                }
            }
        }
    }

    string a, b;

    while(cin >> a >> b)
    {
        int x1 = a[0] - 'a';
        int y1 = a[1] - '1';

        int x2 = b[0] - 'a';
        int y2 = b[1] - '1';

        int origem = x1 * 8 + y1;
        int destino = x2 * 8 + y2;

        bfs(origem);

        cout << "To get from " << a << " to " << b << " takes " << dist[destino] << " knight moves." << endl;
    }

    return 0;
}