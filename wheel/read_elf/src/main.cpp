#include "func.h"
#include <iostream>
#include <cstring>
#include <functional>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
    Elf_func elf_func;
    if (2 == argc && strcmp(argv[1], "-H")) {
        elf_func.help();
        exit(EXIT_SUCCESS);
    }
    if (3 != argc) {
        std::cout << "Usage:    ./elf  -<options> [filepath]" << std::endl;
        elf_func.help();
        exit(EXIT_FAILURE);
    }

    int fd = open(argv[2], O_RDONLY); 
    if (-1 == fd) {
        std::cerr << "open file failed" << std::endl;
        exit(EXIT_FAILURE);
    }          
    elf_func.bind(OPTION_HELP, STR_HELP);
    elf_func.bind(OPTION_HEADER, STR_HEADER);
    elf_func.bind(OPTION_PRO_HEADER, STR_PRO_HEADER);
    elf_func.bind(OPTION_RELO_HEADER, STR_RELO_HEADER);
    elf_func.bind(OPTION_SMB_HEADER, STR_SMB_HEADER);
    elf_func.bind(OPTION_SECTION, STR_SECTION);
    if (elf_func.bind_hash.find(argv[1]) == elf_func.bind_hash.end()) {
        std::cerr << "Invalid options_!" << std::endl;
        exit(EXIT_FAILURE);
    }
    switch (elf_func.bind_hash[argv[1]]) {
        case OPTION_HELP: elf_func.help(); break;
        case OPTION_HEADER: break;
        case OPTION_PRO_HEADER: break;
        case OPTION_RELO_HEADER: break;
        case OPTION_SECTION: break;
        case OPTION_SMB_HEADER: break;
        default:
                std::cerr << "Invalid options_!" << std::endl;
                exit(EXIT_FAILURE);
    }; 
    return 0;
}
