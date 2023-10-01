#include <iostream>
#include <string>

using namespace std;

int main(){
	
	
	string str;
	cin >> str;
	str = str + "\n";
	
	int x = str.size();
	char k;
	int count = 0;
	
	for(int i = 0;i<(x-1);i++){
		
		if(str[i] == str[i+1]){
			k = str[i];
			count++; 
		} else {
			k = str[i];
			if(count > 0){
				cout << k << ++count;
				count = 0;
			} else {
				cout << k;
				count = 0;
			}
		}
	}
	return 0;
}
