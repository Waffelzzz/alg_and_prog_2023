#include <iostream>
#include <math.h>
using namespace std;

int main(){
	
	int a, b, c;
	
	cin >> a >> b >> c;
	
	if(abs(a - b) < abs(a - c)) {
		printf("B %d", abs(a - b));
	} else {
		printf("C %d", abs(a - c));	
	}
	return 0;
}
