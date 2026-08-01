#include <bits/stdc++.h>

using namespace std;

int main(){
    set <string> joias;
    string j;
    
    while(cin >> j){
        joias.insert(j);
    }
    cout << joias.size() << endl;
    
    
    return 0;
}