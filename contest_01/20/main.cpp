#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    string num1, num2;

    cin >> num1;

    cin >> num2;

    string sortedNum1 = num1;
    string sortedNum2 = num2;
    sort(sortedNum1.begin(), sortedNum1.end());
    sort(sortedNum2.begin(), sortedNum2.end());

    if (sortedNum1 == sortedNum2) {
        cout << "YES";
    } else {
        cout <<  "NO";
    }

    return 0;
}
