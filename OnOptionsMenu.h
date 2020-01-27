#include <string>
#include <sstream>

class OnOptionsMenu {
public:
	OnOptionsMenu();
	OnOptionsMenu(std::string title, int);
	void menu();
	void header();

	class INPUT_INVALID {
    public:
        INPUT_INVALID() {
			std::cerr << "INVALID_INPUT:" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		} 
    };

	class INPUT_NOT_A_VALID_SELECTION {
    public:
        INPUT_NOT_A_VALID_SELECTION() { std::cerr << "INPUT_NOT_A_VALID_SELECTION: " << std::endl; } 
    };

private:
	std::string title;
	int size;
};