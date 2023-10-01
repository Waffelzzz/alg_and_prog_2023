#include <iostream>

using namespace std;

int main(){
	
	double i, h, answer;
	int m;

	cin >> m >> h;	
	answer = (m / (h * h));
	printf("%0.15f", answer);
	
	return 0;
}
