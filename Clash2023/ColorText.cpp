#include "ColorText.h"
#include <iostream>


void ColorText::PrintToScreen(std::string text, ColorCode color, bool bright) {
    std::cout << "\033[1;" << color << "m" << text.c_str() << "\033[0m";

/*
    for (int i = 30; i < 38; i++) {
        std::cout << "\033[1;" << i << "mDrew's Color text bright\033[0m\n";
        std::cout << "\033[0;" << i << "mDrew's Color text dark\033[0m\n";
    }
*/
}

