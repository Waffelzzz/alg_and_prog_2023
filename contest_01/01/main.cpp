#include <iostream>
#include <math.h>

using namespace std;


int main() {
	
	float firstNumber = sqrt(12);
	float secondNumber = (1 / (3.0*3.0));
	float thirdNumber = (1 / (5*3.0*3.0));
	float fourthNumber = (1 / (7*3.0*3.0*3.0));
	float fifthNumber = (1 / (9*3.0*3.0*3.0*3.0));
	float sixthNUmber = (1 / (11*3.0*3.0*3.0*3.0*3.0));
	
	double answer = (firstNumber * (1 - secondNumber + thirdNumber - fourthNumber + fifthNumber - sixthNUmber));
	
	printf("%f", answer);
	
	return 0;
}
