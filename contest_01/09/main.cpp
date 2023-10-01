#include <iostream>
#include <math.h>
using namespace std;

int main(){
	
	double a, b, c;
	
	cin >> a >> b;
	
	if(a > 0 && b > 0){
		
		c = sqrt(a*a + b*b);
		printf("%0.14f", c);
	}
	return 0;
}
