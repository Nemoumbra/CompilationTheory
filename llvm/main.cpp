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
        std::cout << "Usage: [options] filename [-tree output_tree_filename]\n";
        std::cout << "Options:\n";
        std::cout << "-p : enable \"trace parcing\" debug mode\n";
        std::cout << "-s : enable \"trace scanning\" debug mode\n";
        std::cout << "-c : compile (create file \"{filename}.ll\")\n";
        // std::cout << "-l : test\n";
        // Why do we remove location debugging?

        // result = -1;
    }

    // int max_args_count = 4;
    bool compile = false;
    for (int i = 1; i < argc; ++i) {
        if (argv[i] == std::string("-p")) {
            driver.trace_parsing = true;
        }
        else if (argv[i] == std::string("-s")) {
            driver.trace_scanning = true;
        }
        else if (argv[i] == std::string("-c")) {
            compile = true;
        }
        else if (argv[i] == std::string("-tree")) {
            std::cout << "Found positional argument \"-tree\" where it shouldn't be...\n";
            return result;
        }
        // else if (argv[i] == std::string("-l")) {
        //     driver.location_debug = true;
        // }
        else {
            auto res = driver.parse(argv[i]);
            
            if (!res) {
                // Let's run the code!
                std::cout << "Starting interpreter...\n";
                try {
                    driver.Evaluate();
                    std::cout << "Interpreter is done!\n";
                }
                catch (const std::runtime_error& error) {
                    std::cout << "Fatal error during program execution:\n";
                    std::cout << error.what() << "\n";
                    result = -1;
                }
                
                if (i + 2 < argc) {
                    // we only make the tree if it can be made AND the user explicitly requested that
                    if (argv[i+1] == std::string("-tree")) {
                        std::cout << "Printing the tree to " << argv[i+2] << "...\n";
                        driver.printTree(argv[i+2]);
                        i += 2;
                        std::cout << "Done!\n";
                    }
                }

                if (result != -1 && compile) {
                    std::cout << "Starting IR generator...\n";
                    driver.Compile(argv[i] + std::string(".ll"));
                    std::cout << "Generation complete!\n";
                }
            }
            else {
                std::cout << "Compilation error!\n";
            }
        }
    }

    return result;
}