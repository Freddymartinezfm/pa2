#include <string>

class OnOptionsMenu {

public:
	OnOptionsMenu();
	OnOptionsMenu(std::string title);
	void menu();
	void header();

private:
	std::string title;
};