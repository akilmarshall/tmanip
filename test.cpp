#include "tmanip.h"

static std::string STR = "tmanip by Akil Marshall\n";

int main() {
		Cursor* cur = Cursor::getInstance();
		std::cout << STR;
		cur->fg(102, 255, 255);
		cur->invert();
		std::cout << STR;
		cur->blink();
		std::cout << STR;
		cur->unset_all();
		cur->down(5);
		cur->forward(10);
		std::cout << STR;
		return 0;
}
