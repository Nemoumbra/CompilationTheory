#include <iostream>

#include "driver.hh"

#include <unistd.h>
// for getcwd


int main(int argc, char** argv) {
    int result = 0; // decompilation flashbacks
    Driver driver;
    std::cout << "Program started!\n";
    // std::cout << argc << "\n";
    std::cout << "argv[0] == " << argv[0] << "\n";
    char buff[FILENAME_MAX];
    getcwd(buff, FILENAME_MAX);
    std::cout << "cwd        " << buff << "\n";

    if (argc == 1) {
        std::cout << "Usage: [options] filename [output_tree_filename]\n";
        std::cout << "Options:\n";
        std::cout << "-p : enable \"trace parcing\" debug mode\n";
        std::cout << "-s : enable \"trace scanning\" debug mode\n";
        // std::cout << "-l : test\n";
        // Why do we remove location debugging?

        // result = -1;
    }
    int max_args_count = 4;
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
        else {
            auto res = driver.parse(argv[i]);
            
            // Now let's run the code!
            if (!res) {
                std::cout << "Starting interpreter...\n";
                try {
                    driver.Evaluate();
                }
                catch (const std::runtime_error& error) {
                    std::cout << "Fatal error during program execution:\n";
                    std::cout << error.what() << "\n";
                }
                std::cout << "Interpreter is done!\n";

                if (i + 1 < argc) {
                    driver.printTree(argv[i+1]);
                    ++i;
                }
            }
            else {
                std::cout << "\"Compilation\" error!\n";
            }
        }
    }

    return result;
}