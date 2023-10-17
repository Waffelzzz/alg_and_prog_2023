#include <iostream>
#include <string>

using namespace std;

bool isBalanced(const string& str) {
    string opened;

    for (char c : str) {
        if (c == '(' || c == '[' || c == '{') {
            opened += c;
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (opened.empty()) {
                return false;
            }

            char lastopened = opened.back();
            opened.pop_back();

            if ((c == ')' && lastopened != '(') ||
                (c == ']' && lastopened != '[') ||
                (c == '}' && lastopened != '{')) {
                return false;
            }
        }
    }

    return opened.empty();
}

int main() {
    string str;
    getline(cin, str, '!');

    if (isBalanced(str)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}

