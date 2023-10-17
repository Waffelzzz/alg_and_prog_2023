#include <iostream>
#include <vector>
#include <algorithm>

int main() {

	int x, y;
	std::cin >> x;
	std::vector<int> first(x);

	for (int i = 0; i < x; i++) {
		std::cin >> first[i];
	}

	std::cin >> y;
	std::vector<int> second(y);

	for (int j = 0; j < y; j++) {
		std::cin >> second[j];
	}

	std::vector<int> result;
	
	for (int i = 0; i < x; i++) {
		result.push_back(first[i]);
	}

	for (int i = 0; i < y; i++) {
		result.push_back(second[i]);
	}

	sort(begin(result), end(result));

	for (auto c : result) {
		std::cout << c << ' ';
	}

	return 0;
}
