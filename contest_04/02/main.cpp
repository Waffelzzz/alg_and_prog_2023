#include <iostream>
#include "json.hpp"
#include <fstream>

using json = nlohmann::json;

int main() {
    std::ifstream input("data.json");

    json data;
    input >> data;

    int newUserID;
    std::cin >> newUserID;

    int completedTasks = 0;
    for (auto project : data) {
        for (auto task : project["tasks"]) {
            if (task["user_id"] == newUserID && task["completed"] == true) {
                completedTasks++;
            }
        }
    }

    std::cout << completedTasks << std::endl;

    return 0;
}

