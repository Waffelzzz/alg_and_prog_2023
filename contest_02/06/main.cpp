Student make_student(const std::string& line) {
    Student student;
    student.name = "";
    student.group = "";

    bool foundSeparator = false;
    for (char c : line) {
        if (c == ';') {
            foundSeparator = true;
        } else {
            if (!foundSeparator) {
                student.name += c;
            } else {
                student.group += c;
            }
        }
    }

    return student;
}

bool is_upper(const Student& student1, const Student& student2) {
    if (student1.group != student2.group) {
        return student1.group < student2.group;
    }
    return student1.name < student2.name;
}


void print(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "Empty list!" << std::endl;
        return;
    }

    std::string current_group = students[0].group;
    std::cout << current_group << std::endl;

    for (const Student& student : students) {
        if (student.group != current_group) {
            current_group = student.group;
            std::cout << current_group << std::endl;
        }
        std::cout << "- " << student.name << std::endl;
    }
}
