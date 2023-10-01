#include <iostream>
#include <set>
#include <string>
#include <map>
using namespace std;

int main() {
	
	set <string> slova;
	set <string>::iterator it;
	set <string>::iterator it2;
	map <string, int> countMap;
	string a;
	int count = 0;
	
	while(a != "end") {
		cin >> a;
		if(a == "end") {
			break;
		}
		
		slova.insert(a);
		
		countMap[a]++;
	}
	
	for (it = slova.begin(); it != slova.end(); ++it) {
		if(countMap[*it] > 1) {
			cout << *it << " ";
		}
	}
	return 0;
}
