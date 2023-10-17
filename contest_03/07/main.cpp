#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>

int main() {
    std::ifstream file("data.txt");
    
    std::string word;
    std::vector<std::string> vec;
    while (file >> word) {
        if (word == "stopword") {
            break;
        }
        vec.push_back(word);
    }

    if (vec.empty()) {
        std::cout << "-";
    }

    std::string prevword = "";
    std::string target;
    std::map<std::string, int> mmpp;
    std::cin >> target;
    for (auto c : vec) {
        if (prevword == target) {
            mmpp[c]++;
        }
        prevword = c;
    }

    if (mmpp.empty()) {
        std::cout << "-";
    }
    
    std::map<int, std::set<std::string>> result;
    for (auto [word, count] : mmpp) {
        result[count].insert(word);
    }

    int n = 0;
    for (auto it = result.rbegin(); it != result.rend(); it++) {
        for (auto word : it->second) {
            std::cout << word << " ";
            if (++n >= 3) {
                break;
            }
        }
        if (n >= 3) {
            break;
        }
    }

    return 0;
}
