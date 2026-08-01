#include <iostream>

using namespace std;

int main(){
	int comeco,fim,soma=0;
	
	cin >> comeco >> fim;
	
	for(int i=comeco; i<=fim; i++){
		soma +=i;
	}
	cout << soma << endl;
	
	
	return 0;
}