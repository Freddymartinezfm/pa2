#include <string>

class OnOptionsMenu {

public:
	OnOptionsMenu();
	OnOptionsMenu(std::string title);
	void show();

private:
	std::string title;
};