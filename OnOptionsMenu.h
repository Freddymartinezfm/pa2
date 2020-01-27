#include <string>
#include <sstream>

class OnOptionsMenu {
public:
	OnOptionsMenu();
	OnOptionsMenu(std::string title, int);
	void menu();
	void header();
	void line(int d = 85);
private:
	std::string title;
	int size;
};