#include <iostream>

#include "driver.hh"

int main(int argc, char** argv) {
    int result = 0; // decompilation flashbacks
    Driver driver;
    std::cout << "Program started!\n";
    // std::cout << argc << "\n";

    if (argc == 1) {
        std::cout << "Usage: [options] filename\n";
        std::cout << "Options:\n";
        std::cout << "-p : test\n";
        std::cout << "-s : test\n";
        // std::cout << "-l : test\n";
        // Why do we remove location debugging?

        // result = -1;
    }
    for (int i = 1; i < argc; ++i) {
        if (argv[i] == std::string("-p")) {
            driver.trace_parsing = true;
        }
        else if (argv[i] == std::string("-s")) {
            driver.trace_scanning = true;
        }
        // else if (argv[i] == std::string("-l")) {
        //     driver.location_debug = true;
        // }
        else if (!driver.parse(argv[i])) {
            std::cout << driver.result << "\n";
        }
        else {
            std::cout << "driver.parse(" << argv[i] << ") returned true";
            result = 1;
        }
    }

    return result;
}