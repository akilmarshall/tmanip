#include <tuple>

#include "tmanip.h"

static std::string STR = "tmanip by Akil Marshall\n";

int main() {
    // Cursor* cur = Cursor::getInstance();
    auto color = std::tuple<int, int, int>(204, 0, 0);
    std::cout << STR;
    std::cout << fg(color, STR);
    std::cout << bg(204, 0, 0, STR);
    std::cout << STR;
    return 0;
}
