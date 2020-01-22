#include "Employee.h"
#include "errorcode.h"
#include <string>
#include <iomanip>
#include <iostream>
#include "OnOptionsMenu.h"
#include <cstring>
#include <fstream>
#include <string>

//#define LOG(x) { std::cout << x <<  std::endl; }


void getRawData();
void clear(Employee *list, int size);

Error_code search();

void sort(Employee *arr[], int size, bool (*compareFncPtr)(Employee &, Employee&));

bool ascendingSSN(Employee  &lhs, Employee &rhs);

bool descendingSSN(Employee  &lhs, Employee &rhs);

const std::string fileName = "employees.txt";
const int MAX_CAPACITY {22};

Employee *list [MAX_CAPACITY];

//int argc, char *argv[]
int main(){
	//LOG("main");
	getRawData();
	bool running = true;

	while (running){
		OnOptionsMenu menuOptions("Search Menu");
		menuOptions.show();
		int menuSelection;

		if (!(std::cin >> menuSelection).good()){
			std::cin.clear();
			std::cin.ignore(256, '\n');
		} else {
			switch (menuSelection){
			case 1:
				search();
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:

				break;
			case 5:
				sort(list, MAX_CAPACITY,  ascendingSSN);
				break;
			case 6:
				sort(list, MAX_CAPACITY, descendingSSN);
				break;
			case 7:
				std::cout << "Program ended " << std::endl;
				running = false;
				break;
			default:
				std::cout << "Error \n";
			}
		}

		// clear data??
		// TODO 
		//clear(*list, MAX_CAPACITY);
	}
}


void getRawData(){
	std::string empCode, ssn, first, last, dept, role, salary;
	int count = 0;
	Employee *temp;
	std::ifstream inFile {fileName}; // ifstream not on CS
	while (!inFile.eof()){
		if ((inFile >> empCode >> ssn >> first >> last >> dept >> role >> salary)){
			temp = new Employee;
			// temp = new Employee(empCode);
			temp->setEmpCode(empCode);
			temp->setSSN(ssn);
			temp->setName(first, last);
			temp->setDept(dept);
			temp->setRole(role);
			temp->setSalary(std::stof(salary));

			list[count++] = temp;
			delete temp; 
			
		} else {
			std::cout << "Error reading file " << std::endl;
			exit(1);
		} 


	}
	std::cout << "The size of Employees is " << count  << std::endl;
	//print();
	inFile.close();
}

Error_code search(){ 
	std::string  criteria;
	std::cout << "Enter a SSN: ";

	while (!(std::cin >> criteria).good()){
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Enter a SSN: ";	
	} 

	for (int i =0; i <= MAX_CAPACITY; i++){
		Employee *item = list[i];
		std::string s = item->getSSN();
		if (s.compare(criteria) == 0){
			std::cout << *item;
			return success;
		}
	}
	std::cerr << "Not found " << std::endl;
	return not_present;
}








void sort(Employee *arr[], int size, bool (*compareFncPtr)(Employee &, Employee&)){
	for (int i = 0; i < MAX_CAPACITY; i++){
		int best = i;
		for (int curr = i + 1; curr < MAX_CAPACITY; curr ++){
			Employee *temp = list[best];
			Employee *t = list[curr];
			if (compareFncPtr(*temp, *t)){
				best = curr;
			}
		}
		std::swap(list[i], list[best]);
	}
}

bool ascendingSSN(Employee & lhs, Employee& rhs){
	return lhs > rhs;
}

bool descendingSSN(Employee & lhs, Employee& rhs){
	return lhs.getSSN() < rhs.getSSN();
}

void clear(Employee *list, int size){
	for (int i=0; i < size; i++){
		Employee *discard = (list + i);
		delete [] discard;
	}

}