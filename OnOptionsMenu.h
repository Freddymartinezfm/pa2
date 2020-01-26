#include <string>

class OnOptionsMenu {

public:
	OnOptionsMenu();
	OnOptionsMenu(std::string title, int);
	void menu();
	void header();

private:
	std::string title;
	int size;
};