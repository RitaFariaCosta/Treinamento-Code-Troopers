#include <bits/stdc++.h>

#define MAXV 10005

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
	
	int casos,contador;
	int nVertices, nArestas, x, y;
	
	cin >> casos;
	
	for(int l=0; l<casos; l++){
		contador = 0;
	    cin >> nVertices >> nArestas;
	
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
	    cout << "Caso #" << l+1 << ": "; 
	    if(contador == 1)
	    cout << "a promessa foi cumprida" << endl;
	    else
	    cout << "ainda falta(m) "<< contador - 1 << " estrada(s)"<<endl;
	
	    //Limpando
	    for(int j = 1; j <= nVertices; j++){
	        vis[j] = false;
	        adj[j].clear();
	    }
	}
	return 0;
}