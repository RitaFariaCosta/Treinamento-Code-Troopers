#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define MAXV 260

using namespace std;

vector<pair<int,int> > adj[MAXV]; // lista de adjacencia (vertice, peso)
int dist_[MAXV];
bool isRoute[MAXV]; // marca se a cidade pertence a rota de servico

void dijkstra(int origem, int N)
{
    vector<bool> vis(N, false);
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    
    for (int i = 0; i < N; i++){
		dist_[i] = INF;
	}
    dist_[origem] = 0;
    pq.push(make_pair(0, origem));
    
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) {
			continue; // ja processado, ignora
		}
        vis[u] = true;

        // Se "u" eh uma cidade da rota de servico (e nao a origem K),
        // o veiculo eh "capturado" ao chegar nela e deve seguir a rota
        // a partir dali, entao nao expandimos mais a busca a partir de u.
        if (isRoute[u] && u != origem) {
			continue;
		}

        for (size_t i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int duv = adj[u][i].second; // custo de u para v
            
            if (dist_[u] + duv < dist_[v]) // achou caminho menor
            {
                dist_[v] = dist_[u] + duv;
                pq.push(make_pair(dist_[v], v));
            }
        }
    }
}

int main()
{
    int N, M, C, K;
    
    cin >> N >> M >> C >> K;
    
    while (N != 0 || M != 0 || C != 0 || K != 0)
    {
        for (int i = 0; i < N; i++) 
		{ 
		adj[i].clear(); 
		isRoute[i] = false; 
		}

        for (int i = 0; i < M; i++)
        {
            int u, v, p;
            cin >> u >> v >> p;
            adj[u].push_back(make_pair(v, p));
            adj[v].push_back(make_pair(u, p));
        }

        // marca as cidades 0..C-1 como pertencentes a rota de servico
        for (int i = 0; i < C; i++) {
			isRoute[i] = true;
		}

        // calcula a menor distancia de K até cada cidade, parando de
        // expandir ao alcancar a primeira cidade da rota de servico
        dijkstra(K, N);

        // calcula o custo de cada trecho da rota de servico
        // routeCost[i] = custo da estrada entre a cidade i e a cidade i+1 da rota
        vector<int> routeCost(C, 0);
        
        for (int i = 0; i < C-1; i++)
        {
            for (size_t j = 0; j < adj[i].size(); j++)
            {
                if (adj[i][j].first == i+1)
                {
                    routeCost[i] = adj[i][j].second;
                    break;
                }
            }
        }

        // soma sufixo: custo restante da rota a partir da cidade i até C-1
        vector<long long> rem(C, 0);
        
        for (int i = C-2; i >= 0; i--){
			rem[i] = rem[i+1] + routeCost[i];
		}
  
        // para cada cidade i da rota de servico, calcula:
        // custo de K até i (capturado pela primeira vez em i) + custo restante da rota
        
        long long ans = LLONG_MAX;
        
        for (int i = 0; i < C; i++)
        {
            if (dist_[i] == INF) continue; // cidade i inalcancavel
            ans = min(ans, (long long)dist_[i] + rem[i]);
        }

        cout << ans << endl;
        cin >> N >> M >> C >> K;
    }
    return 0;
}