#include <iomanip>
#include <string>
#include <iostream>
#include "OnOptionsMenu.h"

OnOptionsMenu::OnOptionsMenu() {}

OnOptionsMenu::OnOptionsMenu(std::string title, int s) : title{title}, size{s}  {}

void OnOptionsMenu::menu(){
	std::cout << "1. Sort by last name using bubble sort " << std::endl;
	std::cout << "2. Sort by SSN using selection sort " << std::endl;
	std::cout << "3. Sort by last salary using insertion sort " << std::endl;
	std::cout << "4. Exit " << std::endl;
	std::cout << "Select an option: " ;
}

void OnOptionsMenu::header(){
	std::cout << std::string(size, '-') << std::endl;

	std::cout
		<< std::setw(8) 
		<< std::setfill(' ')
		<< std::left <<  "EmpCode"  
		<< std::setw(15) <<  "SSN"
		<< std::setw(18) << "Name"
		<< std::setw(16) << "Dept"
		<< std::setw(19) << "Role"
		<< std::setw(9) << std::right << "Salary" 
		<< std::endl;

	std::cout << std::string(size, '-') << std::endl;	
}