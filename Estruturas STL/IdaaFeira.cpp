#include <bits/stdc++.h>

using namespace std;

int main(){
    map <string,double> produtos;
    
    int N,M,P;
    double custo=0;
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> M;
        for(int j=0; j<M;j++){
            string fruta;
            double valor;
            
            cin >> fruta;
            cin >> valor;
            
            produtos[fruta] = valor;
        }
        cin >> P;
        for(int j=0; j<P;j++){
            string fruta2;
            int quantidade;
            
            cin >> fruta2;
            cin >> quantidade;
            
            custo += (produtos[fruta2] * 1.0 * quantidade);
        }
        cout << fixed << setprecision(2);
        cout << "R$ " << custo << endl;
        
        custo = 0;
        produtos.clear();
    }
    
    return 0;
}