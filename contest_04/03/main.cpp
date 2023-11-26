#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

std::string processName(const std::string& name) {
    std::string processedName = name;
    if (processedName.front() == '"') {
        processedName.erase(0, 1);
    }
    if (processedName.back() == '"') {
        processedName.pop_back();
    }
    size_t pos = processedName.find("\"\"");
    while (pos != std::string::npos) {
        processedName.replace(pos, 2, "\"");
        pos = processedName.find("\"\"", pos + 1);
    }
    return processedName;
}

struct Person {
    std::string name;
    int age;
};

bool comparePersons(const Person &a, const Person&b) {
    if(a.age == b.age) {
        return a.name < b.name;
    }
    return a.age < b.age;
}

int main() {
    setlocale(LC_ALL, "");
    std::ifstream file("train.csv");
    std::string str, delstr;
    std::getline(file, delstr, '\r'); // Пропускаем первую строку с заголовками столбцов

    int pclass, age;
    std::cin >> pclass >> age;
    std::vector<Person> people;
    while (std::getline(file, str, '\r')) {
        
        int commas = 0;
        int pos, pos1, pos2, pos3;
        std::vector<std::string> Fpclass;
        std::vector<std::string> Fsex;
        std::vector<std::string> Fname;
        std::vector<std::string> Fage;
        std::string substr;

        for(int i = 0; i < str.size(); i++) {
            if(str[i] == ',') {
                ++commas;
                if(commas == 2) {
                    pos = i;
                }
                else if(commas == 3) {
                    substr = str.substr(pos + 1, 1);
                    Fpclass.push_back(substr);
                    pos1 = i;
                }
                else if(commas == 5) {
                    substr = str.substr(pos1 + 1, i - pos1 - 1);
                    Fname.push_back(substr);
                    pos2 = i;
                }
                else if(commas == 6) {
                    substr = str.substr(pos2 + 1, i - pos2 - 1);
                    Fsex.push_back(substr);
                    pos3 = i;
                }
                else if(commas == 7) {
                    if(str[pos3 + 1] == ',') {
                        Fage.push_back("0");
                    } 
                    else {
                        substr = str.substr(pos3 + 1, i - pos3 - 1);
                        Fage.push_back(substr);
                    }
                }
            }
        }

        for(int i = 0; i < Fname.size(); i++) {
            if(Fsex[i] == "female" && stoi(Fage[i]) > age && stoi(Fpclass[i]) == pclass) {
                Person newPerson;
                newPerson.name = processName(Fname[i]);
                newPerson.age = stoi(Fage[i]);
                people.push_back(newPerson);
            }
        }
    }
    
    std::sort(people.begin(), people.end(), comparePersons);
        
    for(const auto &person : people) {
        std::cout << person.name << std::endl;
    }
    
    return 0;
}
