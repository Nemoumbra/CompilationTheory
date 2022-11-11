#pragma once

#include <map>
#include <string>
#include <fstream>

#include "scanner.hh"
#include "parser.hh"
// wait, but doesn't scanner.hh request parser.hh on its own?

// Now we declare Driver
// copied from CompilersCourse/02-parsers

class Driver {
private:
    std::ifstream stream;
public:
    std::map<std::string, int> variables;
    int result;
    std::string file;
    bool trace_parsing;
    bool trace_scanning;
    yy::location location;

    friend class Scanner;
    Scanner scanner;
    yy::parser parser;
    bool location_debug;

    Driver();
    int parse(const std::string& f);

    void scan_begin();
    void scan_end();
}
