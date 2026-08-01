#include <bits/stdc++.h>

using namespace std;

long int valorNome(string nome){
	long int soma = 0;
	
	for(int i=0; i< nome.size(); i++){
		char c = nome[i];
		soma += (int)c;
	}
	
	return soma;
}

int main(){
	int N;
	cin >> N;
	
	while(N!=0){
		
		string nome[100005];
		int valor[100005];
		
		for(int i=0; i<N; i++){
			cin >> nome[i];
			valor[i] = valorNome(nome[i]);
		}
		long int soma[100005];
		long int somaPonderada[100005];
		
		soma[0] = valor[0];
		somaPonderada[0] = valor[0];
		
		for(int i=1; i<N; i++){
			soma[i] = soma[i-1] + valor[i];
			somaPonderada[i] = somaPonderada[i-1] + ((i+1)* valor[i]);
		}
		
		bool achou = false;
		
		for(int k = 0; k < N; k++)
        {
            long int somaA = (k + 2) * soma[k]- somaPonderada[k];

            long int somaB = 0;

            if(k < N - 1)
            {
                long int somaDireita = soma[N-1] - soma[k];

                long int pesoDireita = somaPonderada[N-1] - somaPonderada[k];

                somaB = pesoDireita - ((k + 1) * somaDireita);
            }

            if(somaA == somaB)
            {
                cout << nome[k] << endl;
                achou = true;
                break;
            }
        }
        if(!achou){
        	cout << "Impossibilidade de empate." << endl;
		}  
		cin >> N;
	}
	
	return 0;
}