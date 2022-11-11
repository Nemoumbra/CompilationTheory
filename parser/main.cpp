#include <iostream>

#include "driver.hh"

int main(int argc, chat** argv) {
    int result; // decompilation flashbacks
    Driver driver;

    if (argc == 1) {
        std::cout << "Usage: [options] filename\n";
        std::cout << "Options:\n";
        std::cout << "-p : test\n";
        std::cout << "-s : test\n";
        std::cout << "-l : test\n";
        result = -1;
    }
    for (int i = 0; i < argc; ++i) {
        if (argv[i] == std::string("-p")) {
            driver.trace_parsing = true;
        }
        else if (argv[i] == std::string("-s")) {
            driver.trace_scanning = true;
        }
        else if (argv[i] == std::string("-l")) {
            driver.location_debug = true;
        }
        else if (!driver.parse(argv[i])) {
            std::cout << driver.result << "\n";
        }
        else {
            std::cout << ""
        }
    }

    return result;
}