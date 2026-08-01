#include <bits/stdc++.h>

using namespace std;

int main(){
    int X;
    map <string, vector<string>> presente;
    
    while(cin >> X){
        for(int i=0; i<X; i++){
            string nome,p1,p2,p3;
            cin >> nome >> p1 >> p2 >> p3;
            presente[nome] = {p1,p2,p3};
        }
        
        string nometeste, presenteteste;
        
        while(cin >> nometeste >> presenteteste){
            
            bool acertou = false;
            
            for(string val: presente[nometeste]){
                
               if(val == presenteteste){
                   acertou =true;
               }  
            }
            if(acertou){
                cout << "Uhul! Seu amigo secreto vai adorar o/" << endl;
            }
            else {
                cout << "Tente Novamente!" << endl;
            }
            
            
        }    
        
    }
    
    return 0;
}