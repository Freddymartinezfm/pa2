#include <iomanip>
#include <string>
#include <iostream>
#include "OnOptionsMenu.h"

OnOptionsMenu::OnOptionsMenu(){
	
}

OnOptionsMenu::OnOptionsMenu(std::string title) : title{title} {}

void OnOptionsMenu::show(){
	std::cout << "\n" <<  std::setw(17)  << std::setfill('=') << title;
	std::cout << std::setw(17)  << std::setfill('=') << " "  << std::endl;

	std::cout << "1. Search an Employee by SSN " << std::endl;
	std::cout << "2. View only SecOps team " << std::endl;
	std::cout << "3. View only DevOps Developers " << std::endl;
	std::cout << "4. Print " << std::endl;
	std::cout << "5. Sort - ascending " << std::endl;
	std::cout << "6. Sort - descending " << std::endl;
	std::cout << "7. Exit " << std::endl;
	
	std::cout << std::setw(17)  << std::setfill('=') << title;
	std::cout << std::setw(17)  << std::setfill('=') << " "  << std::endl;
	std::cout << std::setfill(' ');
	
	std::cout << "Select an option: " ;


}