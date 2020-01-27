#include <iostream>
#include <iomanip>
#include "Employee.h"

Employee::Employee() {}

Employee::~Employee() {}

std::string Employee::getEmpCode() const { return code; }

void Employee::setEmpCode(std::string newCode){ code = newCode; }

std::string Employee::getName() const { return last + "," + first; }

std::string Employee::getSSN() const{ return ssn; }

void Employee::setSSN(std::string ssn){ this->ssn = ssn; }

std::string Employee::getDept() const { return department; }

void Employee::setDept(std::string dept){ this->department = dept; }

std::string Employee::getRole() const{ return role; }

void Employee::setRole(std::string role){ this->role = role; }

double Employee::getSalary() const{return salary; }

void Employee::setSalary(double salary){ this->salary = salary; }

void Employee::setName(std::string first, std::string last){
    this->first = first;
    this->last = last;
}

Employee::Employee(const Employee& rhs) {
    this->setName(rhs.first, rhs.last);
    this->setSSN(rhs.getSSN());
    this->setDept(rhs.getDept());
    this->setSalary(rhs.getSalary());
    this->setEmpCode(rhs.getEmpCode());
    this->setRole(rhs.role);
}

std::ostream& operator<<(std::ostream& os, const Employee& employee) {
    os  
        << std::setw(8) << std::left << employee.getEmpCode()
        << std::setw(15) << std::left <<  employee.getSSN() 
        << std::setw(18) << std::left << employee.getName()
        << std::setw(16) << std::left << employee.getDept()
        << std::setw(19) << std::left << employee.getRole()
        << std::setw(9) << std::right << employee.getSalary()
        << std::endl;
        

    return os;
}
