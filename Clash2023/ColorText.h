#pragma once
#include <string>

class ColorText
{
public:
    enum ColorCode {
        FG_GRAY = 30,
        FG_RED = 31,
        FG_GREEN = 32,
        FG_YELLOW = 33,
        FG_BLUE = 34,
        FG_PINK = 35,
        FG_CYAN = 36,
        FG_WHITE = 37,
        FG_DEFAULT = 39,
        BG_RED = 41,
        BG_GREEN = 42,
        BG_BLUE = 44,
        BG_DEFAULT = 49
    };


    void PrintToScreen(std::string str, ColorCode color, bool bright);

};

