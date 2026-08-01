#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    map<string, string> idioma;
    int n;
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        string idiom;
        string traducao;
        
        getline(cin >> ws,idiom);
        getline(cin >> ws,traducao);
        
        idioma[idiom] = traducao;
    }
    int M;
    string nome;
    string busca;
    
    cin >> M;
    
    
    for(int i=0; i<M; i++){
       getline(cin >> ws,nome);
       getline(cin >> ws,busca);
       
       cout << nome << endl;
       cout << idioma[busca] << endl << endl;
    }
    
    return 0;
}