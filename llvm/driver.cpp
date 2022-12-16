#include "parser.hh"
#include "driver.hh"

#include "visitors/PrintVisitor.hh"

#include "visitors/Interpreter.hh"
#include "visitors/IrGeneratorVisitor.hh"


Driver::Driver() :
    trace_parsing(false),
    trace_scanning(false),
    //location_debug(false),
    scanner(*this),
    parser(scanner, *this) 
{
    // variables["one"] = 1;
    // variables["two"] = 2;

    // Why is this a cool idea to predefine variables here
    // if that's not a scripting language?
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
    // initialize location positions
    location.initialize(&file);
    scan_begin();
    parser.set_debug_level(trace_parsing);
    int res = parser();

    // Uncomment for debugging
    // std::cout << program << std::endl;
    

    scan_end();
    return res;
}

void Driver::printTree(const std::string& filename) {
    PrintVisitor visitor(filename);
    visitor.Visit(program);
}

void Driver::Evaluate() {
    Interpreter interpreter;
    interpreter.GetResult(program);
}

void Driver::Compile(const std::string& filename) {
    IrGeneratorVisitor IR_generator;
    IR_generator.Visit(program);

    auto module = IR_generator.getModule();
    std::error_code code;
    llvm::raw_fd_ostream ll(filename, code);

    module->print(ll, nullptr);
    module->print(llvm::errs(), nullptr);
}
