#include <iostream>

#include "driver.hh"

#include <unistd.h>
// for getcwd


int main(int argc, char** argv) {
    int result = 0;
    Driver driver;
    //std::cout << "Program started!\n";
    //std::cout << "argv[0] == " << argv[0] << "\n";
    //char buff[FILENAME_MAX];
    //getcwd(buff, FILENAME_MAX);
    //std::cout << "cwd        " << buff << "\n";

    if (argc == 1) {
        std::cout << "Usage: filename [-tree output_tree_filename]\n";
    }


    for (int i = 1; i < argc; ++i) {
        if (argv[i] == std::string("-tree")) {
            std::cout << "Found positional argument \"-tree\" where it shouldn't be...\n";
            return result;
        }

        auto res = driver.parse(argv[i]);

        if (res) {
            std::cout << "Compilation error!\n";
            continue;
        }

        // Let's make some more checks...
        try {
            driver.TestVariableScopes(); // will be removed later
            driver.BuildSymbolTable();
            driver.TestBreakContinue();
        }
        catch(const std::runtime_error& error) {
            std::cout << "Compilation error!\n";
            std::cout << error.what() << "\n";
            continue;
        }

        // Let's run the code!
        std::cout << "Starting interpreter...\n";
        try {
            driver.Interpret();
            std::cout << "Interpreter is done!\n";
        }
        catch (const std::runtime_error& error) {
            std::cout << "Fatal error during program execution:\n";
            std::cout << error.what() << "\n";
            result = -1;
        }
        
        if (i + 2 < argc) {
            // We only make the tree if it can be made AND the user explicitly requested that
            if (argv[i+1] == std::string("-tree")) {
                std::cout << "Printing the tree to " << argv[i+2] << "...\n";
                driver.printTree(argv[i+2]);
                i += 2;
                std::cout << "Done!\n";
            }
        }
    }

    return result;
}