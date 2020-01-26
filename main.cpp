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
static const int MAX_CAPACITY {23};
void getRawData();

void clear(Employee *list[], int size);
void print(Employee *list[], int size);

void swapObj(Employee &, Employee &);

void sort(Employee *arr[], int size, void (*sortType)(Employee *arr[], int size));

void bubble(Employee *arr[], int size);
void selection(Employee *arr[], int size);
void insertion(Employee *arr[], int size);

Employee *list [MAX_CAPACITY];

int main(){
	void (*ptr)( Employee *arr[], int size);
	getRawData();
	print(list, MAX_CAPACITY);
	bool running = true;

	while (running){		
		OnOptionsMenu menuOptions("PA2", 85);
		menuOptions.menu();
		int menuSelection;
		
		if (!(std::cin >> menuSelection).good()){
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> menuSelection;
		} else {
			switch (menuSelection){
			case 1:
				ptr = &bubble;
				sort(list, MAX_CAPACITY, ptr);
				menuOptions.header();
				print(list, MAX_CAPACITY);
				break;
			case 2:
				ptr = &selection;
				sort(list, MAX_CAPACITY, ptr);
				menuOptions.header();
				print(list, MAX_CAPACITY);
				break;
			case 3:
				ptr = &insertion;
				sort(list, MAX_CAPACITY, ptr);
				menuOptions.header();
				print(list, MAX_CAPACITY);
				break;
			case 4:
				running = false;
				break;
			
			default:
				std::cout << "Error with selection \n";
			}

			
		}
	}
}

void print(Employee *list[], int size){
	for (int i = 0; i < size; i++) { 
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

void sort(Employee *arr[], int size,  void (*sortFunc)(Employee *arr[], int size)){
		sortFunc(arr, size);
}


void swapObj(Employee &a, Employee &b){
	Employee temp (a);
	a = b;
	b  = temp;

}
void bubble(Employee *arr[], int size){
	// for (int i = 0; i < size; i++){
	// 	for (int j = 0; j < size - i - 1; j++){
	// 		if (list[j]->getName() > list[j+1]->getName()){
	// 			swapObj(*list[j], *list[j+1]);

	// 		}
	// 	}
	// }

	for (int i = 0; i < size -1; i++){
		for (int j = 0; j < size - i - 1; j++){
			if (list[j]->getName() > list[j+1]->getName()){
				swapObj(*list[j], *list[j+1]);
			}
			
		}		

	}
}

void selection(Employee *arr[], int size){
		

		for (int i = 0; i < size - 1; i++){
			int maxIndex = 0;
			for (int j = 1; j <= size - 1 - i  ; j++){
				if (arr[j]->getSSN() > arr[maxIndex]->getSSN()){
					maxIndex = j;
				}
			}
			swapObj(*arr[size - 1 -  i], *arr[maxIndex]);
			std::cout << arr[size -1 -i]->getSSN() << " \n" ;
	}

// another way
	// for (int i = 0; i < size - 1; i++){
	// 		int maxIndex = i;
	// 		for (int j = i; j < size; j++){
	// 			if (arr[j]->getSSN() > arr[maxIndex]->getSSN()){
	// 				maxIndex = j;
	// 			}
	// 		}
	// 		swapObj(*arr[i], *arr[maxIndex]);
	// }
}
	

void insertion(Employee *arr[], int size){
	// TODO - finish insertion on salary 

	
	for (int i = 0; i < size; i++){


	}
}

