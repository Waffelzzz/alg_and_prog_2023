#include <cmath>

int perevod(const std::string& str) {
	int answer = 0;
	int dlina = str.size();
	for (int i = 0; i < dlina; i++) {
		if (str[i] == '1') {
			answer += pow(2, dlina - 1 - i);
		}
	}
	return answer;
}

bool compare(const std::string& left, const std::string& right) {
	int count1 = 0, count2 = 0, value1 = 0, value2 = 0;
	for (auto& it : left) {
		if (it == '1') {
			count1++;
		}
	}

	for (auto& it : right) {
		if (it == '1') {
			count2++;
		}
	}

	if (count1 == count2) {
		value1 = perevod(left);
		value2 = perevod(right);

		return value1 < value2;
	}
	return count1 > count2;
}
