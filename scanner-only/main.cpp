#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <unordered_map>

#include "lexer.hh"
#include "TestCommands.h"



int main() {
    std::cout << "Program started!\n";

    Lexer scanner;
    scanner.set_debug(true);
    bool ending = false;
    while (!ending) {
        int token = scanner.ScanToken();
        std::cout << "Token scanned...\n";
        if (token == TOKEN_EXIT) {
            ending = true;
        }
    }
    std::cout << "Program finished!\n";
}