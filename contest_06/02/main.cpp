#include<cmath>

class Employee {
public:
    Employee(std::string name, std::string position, int salary)
        : name(name), position(position), salary(salary) {}

    virtual int bonus(double percent) const {
        return std::round(salary * percent);
    }

    int getSalary() const {
        return salary + bonus(bonuses.at(position));
    }

    friend std::ostream& operator<<(std::ostream& os, const Employee& employee) {
        os << employee.name << " (" << employee.position << "): " << employee.getSalary();
        return os;
    }

private:
    std::string name;
    std::string position;
    int salary;
};

class Manager : public Employee {
public:
    Manager(std::string name, int salary = 16242)
        : Employee(name, "manager", salary) {}

    int bonus(double percent) const override {
        double managerBonus = std::max(0.1, percent); // Ensure the bonus is not less than 10%
        return static_cast<int>(Employee::bonus(managerBonus));
    }
};
