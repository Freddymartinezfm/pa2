#include "Employee.h"
#include "errorcode.h"
#include <string>
#include <iomanip>
#include <iostream>
#include "OnOptionsMenu.h"
#include <cstring>
#include <fstream>
#include <string>

const std::string input = "employees.txt";
static const int MAX_CAPACITY {22};
void getRawData();

void clear(Employee *list[], int size);
void print(Employee *list[], int size);
void swapObj(Employee &, Employee &);

void sortT(Employee *arr[], int size, void (*sortType)(Employee *arr[], int size));

void bubbleT(Employee *arr[], int size);
bool selection(Employee  &lhs, Employee &rhs);
bool insertion(Employee  &lhs, Employee &rhs);

Employee *list [MAX_CAPACITY];

int main(){
	void (*ptr)( Employee *arr[], int size);
	getRawData();
	print(list, MAX_CAPACITY);
	bool running = true;

	while (running){		
		OnOptionsMenu menuOptions("PA2");
		menuOptions.show();
		int menuSelection;
		
		if (!(std::cin >> menuSelection).good()){
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> menuSelection;
		} else {
			switch (menuSelection){
			case 1:
				ptr = &bubbleT;
				sortT(list, MAX_CAPACITY, ptr);
				print(list, MAX_CAPACITY);
				break;
			case 2:
				print(list, MAX_CAPACITY);
				break;
			case 3:
				print(list, MAX_CAPACITY);
				break;
			case 4:
				print(list, MAX_CAPACITY);
				clear(list, MAX_CAPACITY);
				running = false;
				break;
			default:
				std::cout << "Error with selection \n";
			}
		}
	}
}

void print(Employee *list[], int size){
	for (int i = 0; i < MAX_CAPACITY; i++) { 
		std::cout << *list[i];
	} 
}

void clear(Employee *list[], int size){
	for (int i =0; i < MAX_CAPACITY; i++){
		delete list[i];
	}
}

void getRawData(){
	std::string empCode, ssn, first, last, dept, role, salary;
	int count = 0;
	std::ifstream inFile {input}; 

	while ((inFile >> empCode >> ssn >> first >> last >> dept >> role >> salary)){
		list[count] = new Employee;
		list[count]->setEmpCode(empCode);
		list[count]->setSSN(ssn);
		list[count]->setName(first, last);
		list[count]->setDept(dept);
		list[count]->setRole(role);
		list[count++]->setSalary(std::stof(salary));
	}
	std::cout << "The size of Employees is " << count  << std::endl;
	inFile.close();
}

	void sortT(Employee *arr[], int size,  void (*compareFncPtr)(Employee *arr[], int size)){
	compareFncPtr(arr, size);
}

void swapObj(Employee &a, Employee &b){
	Employee temp (a);
	a = b;
	b  = temp;

}
void bubbleT(Employee *arr[], int size){
	for (int i = 0; i < MAX_CAPACITY; i++){
		for (int j = 0; j < MAX_CAPACITY - i - 1; j++){
			if (list[j]->getName() > list[j+1]->getName()){
				swapObj(*list[j], *list[j+1]);

			}
		}
	}
}

void two(Employee *arr[], int size){
	for (int i = 0; i < MAX_CAPACITY; i++){
		for (int j = 0; j < (MAX_CAPACITY - 1) - i; j++){
			if (list[i]->getName() > list[j+1]->getName()){
				swapObj(*list[j], *list[j+1]);

			}
		}
	}
}

bool selection(Employee &l, Employee &r){
	return l.getSSN() > r.getSSN();
}