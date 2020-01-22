#include <iostream>
#include <iomanip>
#include "Employee.h"


Employee::Employee(){
    // std::cout << "Employee()";
    
}
Employee::Employee(vector<string>& fields){
    code = fields[0];
    ssn = fields[1];
    first = fields[2];
    last = fields[3];
    department = fields[4];
    role = fields[5];
    salary = stof(fields[6]);
}


Employee::~Employee(){
    

    
}

string Employee::getEmpCode() const{
    return code;
}

void Employee::setEmpCode(string newCode){
    code = newCode;
}

string Employee::getName() const
{
    return last + "," + first;
}

void Employee::setName(string first, string last){
    this->first = first;
    this->last = last;
}

string Employee::getSSN() const{
    return ssn;
}

void Employee::setSSN(string ssn){
    this->ssn = ssn;
}

string Employee::getDept() const{
    return department;
}

void Employee::setDept(string dept){
    this->department = dept;
}


string Employee::getRole() const{
    return role;
}

void Employee::setRole(string role){
    this->role = role;
}

double Employee::getSalary() const{
    return salary;
}

void Employee::setSalary(double salary){
    this->salary = salary;
}

bool Employee::operator<(const Employee& right){
    return this->getSSN() < right.getSSN();
}

bool Employee::operator>(const Employee& right){
    return this->getSSN() > right.getSSN();
}

// bool Employee::operator==(Employee& right){
//     return this->getSSN() == right.getSSN();
// }

// copy constructor and operator = 

Employee::Employee(const Employee& rhs) {
        Employee *newE = new Employee;

    for (int i = 0; i < 22; i++){
        newE->setDept(rhs.getDept());
    }     
    std::cout << "Copy constructor " ;

}



ostream& operator<<(ostream& os, const Employee& employee) {
    os 
        // debug
        // << std::setw(1) << employee.getEmpCode() << ""
        // << std::setw(14) << std::setfill('*')  << employee.getSSN() << ""
        // << std::setw(16) << std::setfill('*') << employee.getName() << ""
        // << std::setw(15) << std::setfill('*')   << employee.getDept() << ""
        // << std::setw(18) << std::setfill('*')  << employee.getRole() << ""
        // << std::setw(14) << std::setfill('*')  << employee.getSalary() << "";

        << std::setw(1)  << employee.getEmpCode() << " "
        << std::setw(14) << employee.getSSN() << ""
        << std::setw(16) << employee.getName() << ""
        << std::setw(15)  << employee.getDept() << ""
        << std::setw(18) << std::right << employee.getRole() << ""
        << std::setw(14) << employee.getSalary() << std::fixed << setprecision(2) << std::endl;

    return os;
}
