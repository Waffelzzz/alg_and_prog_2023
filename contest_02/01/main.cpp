#include <math.h>

int is_prime(int n) {

	for(int i = 2;;i++){
		if(i<=sqrt(n)) {
			if(n % i == 0) {
				return 0;
			}
		} else {
			return 1;
		}
	}
}
