// working code but not actively used in code 


// overloaded operators
// bool Employee::operator<(const Employee& right){ return this->getSSN() < right.getSSN(); }
// bool Employee::operator>(const Employee& right){ return this->getSSN() > right.getSSN(); }
// bool Employee::operator==(Employee& right){ return this->getSSN() == right.getSSN(); }



// print outs for headers and displaying to user 

//replaced with std::string(numCharacters, '-'); << more efficient

// std::cout <<  std::setw(85)  << std::setfill('=') << "=" << std::endl;
// std::cout 
// std::cout <<  std::setw(85) << std::setfill('=') << "=" << std::endl;
// std::cout << std::setfill(' ') << std::endl;


// int to string conversion 

			// int a
			// std::stringstream ss ;
			// ss << a;
			// std::string newA = ss.str();