std::string code, ssn, first, last, dept, role,  salary;

	p->setEmpCode(code);
	p->setSSN(ssn);
	p->setName(first, last);
	p->setDept(dept);
	p->setRole(role);
	p->setSalary(std::stoi(salary));

	

	while (running){
		std::string menuSelection;
		std::cin >> menuSelection;

		switch(std::stoi(menuSelection)){
			case 1: // R1 - Display
				std::cout << "option one selected results shown here " << std::endl;
				//TODO search by SSN
				menuOptions.menu();
				break; 
			case 6: // view
				std::cout << "option six selected results shown here " << std::endl;
				// show();
				


				menuOptions.menu();

				break;
			case 7: // exit
				std::cout << "Program ended " << std::endl;
				//TODO size and display
				running = false;
				
				break;
			default:
				std::cout << "Invalid " << std::endl;
				menuOptions.menu();
				break;
		}
	}