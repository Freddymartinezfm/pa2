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
// void sort(Employee *arr[], int size, bool (*sortType)(Employee &, Employee&));
void sortT(Employee *arr[], int size, void (*sortType)(Employee *arr[], int size));

// template <typename T>
// bool bubble(Employee &l, Employee &r);
void bubbleT(Employee *arr[], int size);

bool selection(Employee  &lhs, Employee &rhs);
bool insertion(Employee  &lhs, Employee &rhs);

Employee *list [MAX_CAPACITY];

int main(){

	bool (*typeOfAction)(Employee &, Employee &);
	void (*ptr)( Employee *arr[], int size);
	getRawData();

	// TODO: Add input from arguments from command line 
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
				// typeOfAction = &bubble;
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
		std::cout << *list[i]; // 
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

// void sort(Employee *arr[], int size, bool (*compareFncPtr)(Employee &, Employee&)){
// 	for (int i = 0; i < MAX_CAPACITY -1; i++){
// 		for (int j = 0; j < MAX_CAPACITY - i -1; j++){
// 			if (compareFncPtr(*list[j], *list[j+1])){

// 				// std::swap(list[j], list[j+1]);
// 				swapObj(*list[j], *list[j+1]);

// 			}
// 		}
// 	}
// }

	void sortT(Employee *arr[], int size,  void (*compareFncPtr)(Employee *arr[], int size)){
	// for (int i = 0; i < MAX_CAPACITY; i++){
	// 	for (int j = 0; j < (MAX_CAPACITY - 1) - i; j++){
	// 		if (compareFncPtr(*list[j], *list[j+1])){

	// 			// std::swap(list[j], list[j+1]);
	// 			swapObj(*list[j], *list[j+1]);

	// 		}
	// 	}
	// }

	compareFncPtr(arr, size);
	
	
	
	// for (int i = 0; i < MAX_CAPACITY; i++){
	// 	int best = i;
	// 	for (int curr = i + 1; curr < MAX_CAPACITY; curr ++){
	// 		Employee *temp = list[best];
	// 		Employee *t = list[curr];
	// 		if (compareFncPtr(*temp, *t)){
	// 			best = curr;
	// 		}
	// 	}
	// 	std::swap(list[i], list[best]);
	// }

}

void swapObj(Employee &a, Employee &b){
	Employee temp (a);
	a = b;
	b  = temp;

}


// using last name 
// template <typename T>
// bool bubble(Employee &l, Employee &r){
// 	return l.getName() > r.getName();

// }

void bubbleT(Employee *arr[], int size){
	for (int i = 0; i < MAX_CAPACITY; i++){
		for (int j = 0; j < MAX_CAPACITY - i - 1; j++){
			if (list[j]->getName() > list[j+1]->getName()){
				// std::swap(list[j], list[j+1]);
				swapObj(*list[j], *list[j+1]);

			}
		}
	}
	// for (int i = 0; i < MAX_CAPACITY; i++){
	// 	int best = i;
	// 	for (int curr = i + 1; curr < MAX_CAPACITY; curr ++){
	// 		Employee *temp = list[best];
	// 		Employee *t = list[curr];
	// 		if (list[i]->getName() > list[curr+1]->getName()){
	// 			best = curr;
	// 		}
	// 	}
	// 	std::swap(list[i], list[best]);
	// }

}

void two(Employee *arr[], int size){
	for (int i = 0; i < MAX_CAPACITY; i++){
		for (int j = 0; j < (MAX_CAPACITY - 1) - i; j++){
			if (list[i]->getName() > list[j+1]->getName()){
				// std::swap(list[j], list[j+1]);
				swapObj(*list[j], *list[j+1]);

			}
		}
	}
	// for (int i = 0; i < MAX_CAPACITY; i++){
	// 	int best = i;
	// 	for (int curr = i + 1; curr < MAX_CAPACITY; curr ++){
	// 		Employee *temp = list[best];
	// 		Employee *t = list[curr];
	// 		if (list[i]->getName() > list[curr+1]->getName()){
	// 			best = curr;
	// 		}
	// 	}
	// 	std::swap(list[i], list[best]);
	// }

}

bool selection(Employee &l, Employee &r){
	return l.getSSN() > r.getSSN();

}

// using SSN
// bool insertionSort(Employee *arr[], int size){
// 	return lhs.getSSN() < rhs.getSSN();
// }


// using salary
// bool selectionSort(Employee *arr[], int size){
// 	return lhs.getSSN() < rhs.getSSN();
// }



// bool ascendingSSN(Employee & lhs, Employee& rhs){
// 	return lhs > rhs;
// }

// bool descendingSSN(Employee & lhs, Employee& rhs){
// 	return lhs.getSSN() < rhs.getSSN();
// }
