#include <iomanip>
#include <string>
#include <iostream>
#include "OnOptionsMenu.h"

OnOptionsMenu::OnOptionsMenu() {}

OnOptionsMenu::OnOptionsMenu(std::string title, int s) : title{title}, size{s}  {}

void OnOptionsMenu::menu(){
	std::cout << std::endl << "1. Sort by name.  \t(ascending | bubble)" << std::endl;
	std::cout << "2. Sort by SSN.  \t(ascending | selection) " << std::endl;
	std::cout << "3. Sort by salary. \t (descending | insertion)" << std::endl;
	std::cout << "4. Exit " << std::endl;
	std::cout << "Select an option: " ;
}

void OnOptionsMenu::line(int d){ 
	std::cout << std::string(d, '-') << std::endl;
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