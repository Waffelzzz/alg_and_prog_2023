#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	long max1, max2, x, m, k, water;
	cin >> x;
	vector<long> n(x);
	if(x > 2) {
		for(int i = 0; i < x; i++) {
			cin >> n[i];
		}
		
		vector<long> leftMax(x);
		vector<long> rightMax(x);
		
		leftMax[0] = n[0];
		for(int i = 1; i < x; i++) {
			leftMax[i] = max(leftMax[i - 1], n[i]);	
		}
		
		rightMax[x - 1] = n[x - 1];
		for(int i = x - 2; i >= 0; i--) {
			rightMax[i] = max(rightMax[i + 1], n[i]);
		}
		
		for(int i = 0; i < x; i++) {
			water += min(leftMax[i], rightMax[i]) - n[i];
		}
		cout << water;
	}
	return 0;
}
