Student make_student(std::string& str) {
    str = str + ';';
    Student student;
    size_t pos = str.find(';');
    student.name = str.substr(0, pos);
    str.erase(0, pos + 1);

    pos = str.find(';');
    student.group = str.substr(0, pos);
    str.erase(0, pos + 1);

    while (!str.empty()) {
        Course course;
        
        pos = str.find(';');
        course.name = str.substr(0, pos);
        str.erase(0, pos + 1);

        pos = str.find(';');
        course.semester = std::stoi(str.substr(0, pos));
        str.erase(0, pos + 1);

        pos = str.find(';');
        course.finished = (str.substr(0, pos) == "1");
        str.erase(0, pos + 1);

        student.courses.push_back(course);
    }

    return student;
}

bool is_upper(Student& s1, Student& s2) {
    if (s1.group < s2.group) {
        return true;
    }
    else if (s1.group == s2.group) {
        return s1.name < s2.name;
    }
    return false;
}

bool is_debtor(const Student& student, int cur_semester, int max_debt) {
    int debt_count = 0;
    for (const Course& course : student.courses) {
        if (course.semester < cur_semester && !course.finished) {
            debt_count++;
        }
    }
    return debt_count > max_debt;
}

void print(const std::vector<Student>& explusion_candidates) {
    if (explusion_candidates.empty()) {
        std::cout << "Empty list!";
        return;
    }

    std::string current_group = explusion_candidates[0].group;
    std::cout << current_group << std::endl;

    for (const Student& student : explusion_candidates) {
        if (student.group != current_group) {
            current_group = student.group;
            std::cout << current_group << std::endl;
        }
        std::cout << "- " << student.name << std::endl;
    }

}
