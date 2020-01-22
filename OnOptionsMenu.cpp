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

	std::cout << "1. Sort by last name using bubble sort " << std::endl;
	std::cout << "2. Sort by SSN using selection sort " << std::endl;
	std::cout << "3. Sort by last salary using insertion sort " << std::endl;
	std::cout << "4. Exit " << std::endl;
	std::cout << "Select an option: " << std::setfill(' ') ;
}