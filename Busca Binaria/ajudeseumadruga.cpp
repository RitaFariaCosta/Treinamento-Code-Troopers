#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	double A;
	double C[100005];
	
	cin >> N >> A;
	
	while(A!=0 && N!=0){
		double soma =0;
		double maior =0;
		
		for(int i=0; i<N; i++){
			cin >> C[i];
			soma += C[i];
			maior = max(maior,C[i]);
		}
		if(soma == A){
			cout << ":D" << endl;
			cin >> N >> A;
			continue;
		}
		if(soma < A){
			cout << "-.-" << endl;
			cin >> N >> A;
			continue;
		}
		double esquerda = 0;
		double direita = maior;
		
		for(int i = 0; i < 100; i++){
			
			double meio = (esquerda + direita)/2.0;
			
			double area =0;
			
			for(int i=0; i<N; i++){
				
				if(C[i]>meio){
					area += C[i] - meio;
				}
			}
			if(area > A){
				esquerda = meio;
			}
			else {
				direita = meio;
			}
		}
		
		cout << fixed << setprecision(4);
		cout << direita << endl;
		
		cin >> N >> A;   	
	}
	
	return 0;
}