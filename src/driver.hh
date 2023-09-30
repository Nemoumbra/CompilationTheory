#pragma once

#include <map>
#include <string>
#include <fstream>

#include "scanner.hh"
#include "generated/parser.hh"

#include "Program.h"

#include "utils/utils.hh"


class Driver {
private:
    std::ifstream stream;
 public:
    std::map<std::string, int> variables;
    int result;
    
    std::string file;
    bool trace_parsing;
    bool trace_scanning;
    LocationManager locman;

    friend class Scanner;
    Scanner scanner;
    yy::parser parser;
    std::shared_ptr<Program> program;

    Driver();
    
    int parse(const std::string& f);

    void scan_begin();
    void scan_end();

    void printTree(const std::string& fileaname);

    void TestVariableScopes();
    void Interpret();
};