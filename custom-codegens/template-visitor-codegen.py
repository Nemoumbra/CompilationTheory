from typing import List
from pathlib import Path


output_filename = input("Please enter the name for *.hh and *.cpp files\n")

methods_filename = input("Now enter the path to the file with the tree nodes description\n")

save_to = Path(input("Finally, please enter the path to the dir where to put the files\n"))

try:
    print("Making files...")
    hh_lines: List[str] = []
    cpp_lines: List[str] = []

    hh_lines.append("#pragma once\n")
    hh_lines.append("#include \"BaseVisitor.hh\"\n")
    hh_lines.append("#include \"../includes_for_parser.hh\"\n")
    hh_lines.append("\n")
    hh_lines.append("class {0} : public BaseVisitor {{\n".format(output_filename))
    hh_lines.append("private:\n")
    hh_lines.append("    //\n")
    hh_lines.append("public:\n")
    hh_lines.append("    // {0}();\n".format(output_filename))
    hh_lines.append("    // ~{0}();\n".format(output_filename))
    hh_lines.append("\n")

    cpp_lines.append("#include \"{0}.hh\"\n".format(output_filename))
    cpp_lines.append("\n")

    with open(methods_filename) as input:
        template_hh_line = "    void Visit({0}* {1}) override;\n"
        template_cpp_line = "void {0}::Visit({1}* {2}) {{\n"
        for line in input:
            typename, var_name = line.strip().split(';')

            hh_lines.append(template_hh_line.format(typename, var_name))
            cpp_lines.append(template_cpp_line.format(output_filename, typename, var_name))
            cpp_lines.append("    \n")
            cpp_lines.append("}\n")
            cpp_lines.append("\n")

    hh_lines.append("};")

    with open((save_to / output_filename).with_suffix(".hh"), "w") as output:
        output.writelines(hh_lines)
    with open((save_to / output_filename).with_suffix(".cpp"), "w") as output:
        output.writelines(cpp_lines)
    
    print("Done!")
except Exception as e:
    print("Exception occured: ", e)