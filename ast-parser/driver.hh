#pragma once

#include <map>
#include <string>
#include <fstream>

#include "scanner.hh"
#include "parser.hh"

#include "Program.h"



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
    // bool location_debug;
    Program* program;

    Driver();
    
    int parse(const std::string& f);

    void scan_begin();
    void scan_end();
};