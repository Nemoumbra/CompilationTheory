# CompilationTheory
That's my attempt at making a working compiler.

Current state: first iteration done (LLVM implemented).

# Brief project explanation
The final Cmake target is located in the llmv folder
scanner-only is the 0th step (pretty useless machine without the parser)
parser is still not even close to something that resembles a compiler
ast-parser can parse the code and iterate over it to print its structure or interpret it
The folder "custom-codegens" contains a Python script for generating a pair of *.hh and *.cpp files for a new visitor class

The target "DrawAutomaton" can be used to generate an image of the parser's automaton with the help of Bison and Graphviz

After the program makes an LLVM IR file, it can be compiled with clang (check ExamplesCompileLLVM)

# Language
Language examples can be found in the "bin" folder.
Everything is located inside the main function. It's possible to declare varibles, make assignments, "if else" statements and call the print function, which accepts only one numerical argument.
Else clauses can't be omitted. Variable declarations can't be located inside conditional clauses.

Note: in the interpreter mode the program intitializes variables with a default value of 0