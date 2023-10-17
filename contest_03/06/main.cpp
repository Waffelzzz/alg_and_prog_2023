#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

int main() {
    int x;
    std::cin >> x;
    std::cin.ignore();
    std::unordered_map<std::string, int> userBalance;
    std::string input;

    for (int i = 0; i < x; i++) {
        std::getline(std::cin, input);

        size_t dac = input.find(";");
        std::string login;
        int balance;

        login = input.substr(0, dac);
        balance = stoi(input.substr(dac + 1));

        userBalance[login] = balance;
    }

    int y;
    std::cin >> y;

    std::vector<std::string> vec;
    std::string word;

    for (int i = 0; i < y; i++) {
        std::cin >> word;
        vec.push_back(word);
    }

    for (const std::string& login : vec) {
        std::cout << userBalance[login] << " ";
    }

    return 0;
}

