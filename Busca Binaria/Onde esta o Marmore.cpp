#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n,q,x,pos,caso=1;
	
	cin >> n >> q;
	
	while(n!=0 && q!=0){
		int v[10005];
		
		for(int i=0; i<n; i++){
			cin >> v[i];
		}
		
		sort(v, v+n);
		
		cout << "CASE# " << caso << ":" << endl;
		
		for(int i=0; i<q; i++){
			pos = -1;
			cin >> x;
			int baixo=0, alto = n-1;
			
			while(baixo <= alto){
				
				int meio = (alto + baixo)/2;
				if(x==v[meio]){
					pos = meio;
					alto = meio-1;
				}
				if(x > v[meio]){
					baixo = meio + 1;
				}
				if(x < v[meio]){
					alto = meio-1;
				}
				
			}
			if(pos!=-1){
				cout << x << " found at " << pos+1 << endl;
			}
			else {
				cout << x << " not found" << endl;
			}
		}
		cin >> n >> q;
		caso++;
	}
	return 0;
}