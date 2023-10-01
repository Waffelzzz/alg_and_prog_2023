#include <iostream>

using namespace std;

int main() {
	
	int n, x, y, max, min;
	x = 0;
	y = 0;
	max = 1;
	min = 0;
	cin >> n;
	if(n >= 1 && n <= 1000) {
		for(int i = 1;i <= n;i++){
			if(x < y){
				cout << i << " ";
				x++;
			} else if(x == y){
				cout << i << endl;
				y++;
				x = 0;
			}
			if(y == max) {
				max++;
				for(int j = ++i;j <= n; j++){
					if(x < y){
						cout << j << " ";
						x++;
						i = j;
					} else if(x == y){
						cout << j << endl;
						y--;
						x = 0;
						if(y == min || j == n){
							i = j;
							break;
						}
					}
				}
			}
		}
	}
    return 0;
}
