#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    int x;
    std::cin >> x;
    std::map<std::string, int> maper;
    for (int i = 0; i < x; i++) {
        std::string word;
        std::cin >> word;
        maper[word]++;
    }

    int max_count = 0;
    std::vector<std::string> frequent;

    for (const auto& [wrd, num] : maper) {
        if (maper[wrd] > max_count) {
            max_count = maper[wrd];
            frequent = { wrd };
        }
        else if (maper[wrd] == max_count) {
            frequent.push_back(wrd);
        }
    }

    std::sort(frequent.begin(), frequent.end());

    
    for (const std::string& word : frequent) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    return 0;
}

