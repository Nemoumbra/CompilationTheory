clang -emit-llvm -S main.cpp -o main.ll
clang main.ll -o main
