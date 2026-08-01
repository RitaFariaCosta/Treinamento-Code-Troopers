#include <bits/stdc++.h>

using namespace std;

int main(){
	int receita[55], valordia[55], soma[55];
	int n, custoPorDia;
	
	while(cin >> n >> custoPorDia){
		
		for(int i=0; i<n; i++){
			cin >> receita[i];
			valordia[i] = receita[i] - custoPorDia;
		}
		
		soma[0] = valordia[0];
		int maiorvalor = max(0, soma[0]);
		
		for(int i=1; i<n; i++){
			soma[i] = max(valordia[i], soma[i-1] + valordia[i]);
			if(soma[i] > maiorvalor){
				maiorvalor = soma[i];
			}
		}
		cout << maiorvalor << endl;	
	}
	
	
	return 0;
}
