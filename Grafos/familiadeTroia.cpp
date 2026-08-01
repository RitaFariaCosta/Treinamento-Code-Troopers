#include <bits/stdc++.h>

#define MAXV 50005

using namespace std;

vector <int> adj[MAXV];
bool vis[MAXV];

void dfs(int u)
{
    vis[u] = true;

    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];

        if (vis[v] == false)
            dfs(v);
    }
}

int main(){
	
	int contador=0;
	int nVertices, nArestas, x, y;
	
	cin >> nVertices;
	cin >> nArestas;
	
    for (int i = 0; i < nArestas; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    //logica da questao
    for(int j=1; j<=nVertices; j++){
		if(vis[j] == false){
			dfs(j);
			contador++;
		}
	}
	//Saida
    cout << contador << endl;

	return 0;
}