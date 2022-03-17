#include "func.h"
#include <stdio.h>
#include <unordered_map>
#include <iostream>
#include <fmt/core.h>
Elf_func::Elf_func(){}
void Elf_func::bind(int type, const char *str_type) 
{
    bind_hash[str_type] = type;
} 
// -H
void Elf_func::help() {
    std::cout << "read_elf demo\n";
    std::cout << "  -H             :帮助信息\n";
    std::cout << "  -h             :头部信息\n";
    std::cout << "  -S             :节区表信息\n";
    std::cout << "  -s             :符号表信息\n";
    std::cout << "  -l             :程序头信息\n";
    std::cout << "  -r             :重定位表信息\n";
}
