#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


class Employee {

protected:
    string code;
    string ssn;
    string first;
    string last;
    string department;
    string   role;
    double   salary;
public:
    Employee();
    ~Employee();
    string getName() const;
    void   setName(string, string);

    string getSSN() const;
    void setSSN(string);

    string getDept() const;
    void setDept(string);

    string getEmpCode() const;
    void setEmpCode(string);

    string getRole() const;
    void setRole(string);

    double getSalary() const;
    void setSalary(double);
    bool operator<(const Employee&);
    bool operator>(const Employee&);
    bool operator==(Employee&);
    Employee(const Employee&);

    class INVALID {
    public:
        INVALID(){}; 
        INVALID(int selection){ 
            std::string s = std::to_string(selection);
            std::cout << "Invalid Input " << s << std::endl; } 
    };

    friend  ostream& operator<<(ostream&, const Employee&);
};
#endif

