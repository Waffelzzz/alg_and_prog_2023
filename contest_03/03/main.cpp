#include <iostream>
#include <string>
#include <stack>

int Priority(char x) {
    if (x == '^') {
        return 3;
    }
    if (x == '*' || x == '/' || x == '%') {
        return 2;
    }
    if (x == '+' || x == '-') {
        return 1;
    }
    return 0;
}

int main() {
    std::stack<char> st;
    std::string input;
    std::string output;

    std::getline(std::cin, input);

    bool isPrevDigit = false;

    for (char c : input) {
        if (std::isdigit(c)) {
            if (isPrevDigit) {
                output += c;
            }
            else {
                output += ' ';
                output += c;
            }
            isPrevDigit = true;
        }
        else {
            isPrevDigit = false;
            if (c == '(') {
                st.push(c);
            }
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    output += ' ';
                    output += st.top();
                    st.pop();
                }
                st.pop();
            }
            else if (ispunct(c)) {
                if (c == '^') {
                    while (!st.empty() && Priority(c) < Priority(st.top())) {
                        output += ' ';
                        output += st.top();
                        st.pop();
                    }
                    st.push(c);
                }
                else {
                    while (!st.empty() && Priority(c) <= Priority(st.top())) {
                        output += ' ';
                        output += st.top();
                        st.pop();
                    }
                    st.push(c);
                }
            }
        }
    }

    while (!st.empty()) {
        output += ' ';
        output += st.top();
        st.pop();
    }

    output.erase(output.begin());

    std::cout << output << std::endl;

    return 0;
}
