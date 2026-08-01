#include <bits/stdc++.h>

using namespace std;

int main(){
    vector <int> A;
    vector <int> B;
    int M,N,aux;
    
    cin >> N;
    
    for(int i=0; i < N; i++){
        int dif=0;
        cin >> M;
        for(int j=0; j< M; j++){
            cin >> aux;
            A.push_back(aux);
            B.push_back(aux);
        }
        sort(B.begin(),B.end(), greater<int>());
        for(int j=0; j< M; j++){
            if(A[j] == B[j]) {
                dif++;
            }
        }
        cout << dif << endl;
        A.clear();
        B.clear();
    }
    
    return 0;
}