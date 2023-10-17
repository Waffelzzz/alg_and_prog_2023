#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n;

    std::string word;
    std::set<std::string> words1;
    for (int i = 0; i < n; ++i) {
        std::cin >> word;
        words1.insert(word);
    }

    std::cin >> m;
    std::set<std::string> words2;
    for (int i = 0; i < m; ++i) {
        std::cin >> word;
        words2.insert(word);
    }

    std::vector<std::string> common_words;
    for (const std::string& w : words1) {
        if (words2.count(w) > 0) {
            common_words.push_back(w);
        }
    }

    if (!common_words.empty()) {
        std::sort(common_words.begin(), common_words.end());
        for (const std::string& w : common_words) {
            std::cout << w << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "-1" << std::endl;
    }

    return 0;
}

