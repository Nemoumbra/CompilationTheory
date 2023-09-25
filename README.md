# CompilationTheory
That's my attempt at making a working compiler.

Current state: I've dropped LLVM support to move onto making my own bytecode compiler.

## Brief project explanation
* The code is in the src dir

* The folder "custom-codegens" contains a Python script for generating a pair of *.hh and *.cpp files for a new visitor class

* The target "DrawAutomaton" can be used to generate an image of the parser's automaton with the help of Bison and Graphviz

## Language
Language examples can be found in the **bin** folder.

Everything is located inside the main function. It's possible to declare variables, make assignments, if-else statements and call the void "print" function, which accepts only one numerical argument.

Else clauses can't be omitted. Variable declarations can't be located inside conditional clauses.

Note: in the interpreter mode the program intitializes variables with a default value of 0
