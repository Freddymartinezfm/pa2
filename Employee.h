#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <cstring>

class Employee {
protected:
    std::string code;
    std::string ssn;
    std::string first;
    std::string last;
    std::string department;
    std::string role;
    double salary;
public:
    Employee();
    ~Employee();
    std::string getName() const;
    void setName(std::string, std::string);

    std::string getSSN() const;
    void setSSN(std::string);

    std::string getDept() const;
    void setDept(std::string);

    std::string getEmpCode() const;
    void setEmpCode(std::string);

    std::string getRole() const;
    void setRole(std::string);

    double getSalary() const;
    void setSalary(double);
    bool operator<(const Employee&);
    bool operator>(const Employee&);
    bool operator==(Employee&);
    Employee(const Employee&);

    friend  std::ostream& operator<<(std::ostream&, const Employee&);
};

