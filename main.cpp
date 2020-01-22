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
const int MAX_CAPACITY {22};
void getRawData();

void clear(Employee *list[], int size);
void print(Employee *list[], int size);

void sort(Employee *arr[], int size, bool (*sortType)(Employee &, Employee&));

bool ascendingSSN(Employee  &lhs, Employee &rhs);
bool descendingSSN(Employee  &lhs, Employee &rhs);

Employee *list [MAX_CAPACITY];

int main(){
	getRawData();
	print(list, MAX_CAPACITY);
	bool running = true;

	while (running){		
		OnOptionsMenu menuOptions("Search Menu");
		menuOptions.show();
		int menuSelection;
		if (!(std::cin >> menuSelection).good()){
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> menuSelection;
		} else {
			switch (menuSelection){
			case 1:
				// sortType = &bubbleSort;
				break;
			case 2:
				sort(list, MAX_CAPACITY, descendingSSN);
			// sortType = &bubbleSort;
				break;
			case 3:
				sort(list, MAX_CAPACITY,  ascendingSSN);
			// sortType = &bubbleSort;
				break;
			case 7:
				clear(list, MAX_CAPACITY);
				running = false;
				break;
			default:
				std::cout << "Error with selection \n";
			}
		}
	}

}

// function ptr for records(Employee *list[], int size, void (*fp)()); // to either print, or clear or sort 

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

void action(Employee *arr[], int size, bool (*typeOfAction)(Employee &, Employee&)){
	for (int i = 0; i < MAX_CAPACITY; i++){
		int best = i;
		for (int curr = i + 1; curr < MAX_CAPACITY; curr ++){
			Employee *temp = list[best];
			Employee *t = list[curr];
			if (typeOfAction(*temp, *t)){
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

// bool bubbleSort(Employee *arr[], int size){
// 	return lhs > rhs;
// }

// bool insertionSort(Employee *arr[], int size){
// 	return lhs.getSSN() < rhs.getSSN();
// }

// bool selectionSort(Employee *arr[], int size){
// 	return lhs.getSSN() < rhs.getSSN();
// }