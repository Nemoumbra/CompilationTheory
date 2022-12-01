#include "parser.hh"
#include "driver.hh"
// again, why do we request it?



Driver::Driver() :
    trace_parsing(false),
    trace_scanning(false),
    location_debug(false),
    scanner(*this),
    parser(scanner, *this) 
{
    variables["one"] = 1;
    variables["two"] = 2;
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
    scan_end();
    return res;
}
