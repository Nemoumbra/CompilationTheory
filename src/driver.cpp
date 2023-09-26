#include "parser.hh"
#include "driver.hh"

#include "visitors/PrintVisitor.hh"

#include "visitors/Interpreter.hh"

#include "visitors/SymbolTableVisitor.hh"


Driver::Driver() :
    trace_parsing(false),
    trace_scanning(false),
    scanner(*this),
    parser(scanner, *this) 
{
    // We can predefine available variables here
}

void Driver::scan_begin() {
    scanner.set_debug(trace_scanning);
    if (file.empty () || file == "-") {
        std::cerr << "file.empty() or file == \"-\"";
    }
    else {
        stream.open(file);
        std::cerr << "File name is " << file << std::endl;
        // Restart scanner resetting buffer!
        scanner.yyrestart(&stream);
    }
}

void Driver::scan_end() {
    stream.close();
}

int Driver::parse(const std::string& f) {
    file = f;

    // Initialize location positions
    location.initialize(&file);
    scan_begin();
    parser.set_debug_level(trace_parsing);

    int res = parser();

    scan_end();
    return res;
}

void Driver::printTree(const std::string& filename) {
    PrintVisitor visitor(filename);
    visitor.Visit(program.get());
}


void Driver::TestVariableScopes() {
    SymbolTableVisitor visitor;
    visitor.Visit(program.get());
}
void Driver::Interpret() {
    Interpreter interpreter;
    interpreter.GetResult(program);
}

