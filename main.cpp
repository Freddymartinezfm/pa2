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
Employee *list [MAX_CAPACITY];
const std::string TAG {"Employee"};

void getRawData(const std::string&);
void clear(Employee *list[], int size);
void print(Employee *list[], int size);
void swapObj(Employee &, Employee &);

void sort(Employee *arr[], int size, void (*sortType)(Employee *arr[], int size));

void bubble(Employee *arr[], int size);
void selection(Employee *arr[], int size);
void insertion(Employee *arr[], int size);

int main(int argc, char *argv[]){
	void (*ptr)( Employee *arr[], int size);
	if (argc < 2){
		getRawData(input);
		print(list, MAX_CAPACITY);
		bool running = true;
		OnOptionsMenu menuOptions("PA2", 85);

		while (running){		
			menuOptions.menu();
			int menuSelection;
			
			if ((std::cin >> menuSelection).fail()){
				ERROR_CODE::INPUT_INVALID();
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
					menuOptions.line();
					break;
				default:
					ERROR_CODE::INPUT_NOT_A_VALID_SELECTION();
				}
			}
		}
	} else if (argc > 1){
		char *i = argv[1];
		std::string input {i};
		std::fstream{input};
		getRawData(input);
		print(list, MAX_CAPACITY); 
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

void getRawData(const std::string &input){
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
	std::cout << std::endl  << "The size of Employees is " << count  << std::endl;
	inFile.close();
}

void sort(Employee *arr[], int size,  void (*sortFunc)(Employee *arr[], int size)){
	sortFunc(arr, size);
}

void bubble(Employee *arr[], int size){
	for (int i = 0; i < size -1; i++){
		for (int j = 0; j < size - i - 1; j++){
			if (list[j]->getName() > list[j+1]->getName()){
				swapObj(*list[j], *list[j+1]);
			}	
		}		
	}
}

void swapObj(Employee &a, Employee &b){
	Employee temp (a);
	a = b;
	b  = temp;
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
	}
}
	
void insertion(Employee *arr[], int n){
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j > 0; j--){
			if (arr[j]->getSalary() > arr[j-1]->getSalary()){
				swapObj(*arr[j], *arr[j-1]);
			}
		}
	}
}

