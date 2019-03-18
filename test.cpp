#include "tmanip.h"


static std::string STR = "tmanip by Akil Marshall\n";

int main() {
		//Cursor* cur = Cursor::getInstance();
		std::cout << STR;
		std::cout << fg(204, 0, 0, STR);
		std::cout << bg(204, 0, 0, STR);
		std::cout << STR;
		return 0;
}
