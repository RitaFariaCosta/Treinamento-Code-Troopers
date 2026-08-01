#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int casos;
    cin >> casos;
    
    for(int c = 0; c < casos; c++){
        
        int nPaineis, caminhoes;
        long long frete;
        
        cin >> nPaineis >> caminhoes >> frete;
        
        long long peso[nPaineis];
        long long baixo = 0, alto = 0;
        
        for(int i = 0; i < nPaineis; i++){
            cin >> peso[i];
            baixo = max(baixo, peso[i]);
            alto += peso[i];
        }
        
        long long resposta = alto;
        
        while(baixo <= alto){
            
            long long meio = (baixo + alto) / 2;
            
            int caminhao = 1;
            long long soma = 0;
            bool ok = true;
            
            for(int i = 0; i < nPaineis; i++){
                
                if(peso[i] > meio){
                    ok = false;
                    break;
                }
                
                if(soma + peso[i] <= meio){
                    soma += peso[i];
                }
                else{
                    caminhao++;
                    soma = peso[i];
                }
            }
            
            if(ok && caminhao <= caminhoes){
                resposta = meio;
                alto = meio - 1;
            }
            else{
                baixo = meio + 1;
            }
        }
        
        long long custo = resposta * caminhoes * frete;
        
        cout << resposta << " $" << custo << endl;
    }
    
    return 0;
}