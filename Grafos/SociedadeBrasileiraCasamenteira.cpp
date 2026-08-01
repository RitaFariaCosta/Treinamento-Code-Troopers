#include <bits/stdc++.h>

#define MAXV 100005

using namespace std;

vector<int> adj[MAXV];
int estado[MAXV]; //0 = não visitado 1 = visitando 2 = processado
int profundidade[MAXV];

int casamentos = 0;

void dfs(int u, int nivel)
{
    estado[u] = 1;
    profundidade[u] = nivel;

    int v = adj[u][0];

    if(estado[v] == 0)
    {
        dfs(v, nivel + 1);
    }
    else if(estado[v] == 1)
    {
        int tamCiclo = profundidade[u] - profundidade[v] + 1;

        if(tamCiclo >= 2)
            casamentos++;
    }

    estado[u] = 2;
}

int main()
{
    map<string,int> id; //tranforma nomes em numeros
    string a, b;
    int contador = 0;

    while(cin >> a >> b)
    {
        if(id.count(a) == 0)
            id[a] = contador++;

        if(id.count(b) == 0)
            id[b] = contador++;

        adj[id[a]].push_back(id[b]); // adicionando aresta direcionado
    }

    for(int i = 0; i < contador; i++)
    {
        if(estado[i] == 0)
            dfs(i, 0);
    }

    cout << casamentos << endl;

    return 0;
}