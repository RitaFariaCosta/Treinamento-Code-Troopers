#include <bits/stdc++.h>

using namespace std;

int main(){
    
    multiset<int>par;
    multiset<int,greater<int>>impar; //o greater serve para inverter o multiset, ou seja, ordenar em ordem decrescente
    
    int N,numero;
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> numero;
        if(numero%2==0){
            par.insert(numero);
        }
        else {
            impar.insert(numero);
        }
    }
    for(int val: par){
        cout << val << endl;
    }
    for(int val: impar){
        cout << val << endl;
    }
    
    return 0;
}