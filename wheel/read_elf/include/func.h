#pragma once
#include <elf.h>
#include <unordered_map>
#include <string>

#define STR_HELP            "-H"
#define STR_HEADER          "-h"
#define STR_SECTION         "-S"
#define STR_SMB_HEADER      "-s"
#define STR_PRO_HEADER      "-l"
#define STR_RELO_HEADER     "-r"
enum OPTION_TYPE 
{
    OPTION_HELP = 0,
    OPTION_HEADER,
    OPTION_SECTION,
    OPTION_SMB_HEADER,
    OPTION_PRO_HEADER,
    OPTION_RELO_HEADER
};

class Elf_func {
public:
    Elf_func();
    void bind(int type, const char* str_type) ;
    void help();
    void fileheader(const char* buf);
    void sectionheader(const char* buf);
    void symbolheader(const char* buf); // 符号表
    void programheader(const char* buf); 
    void relocheader(const char* buf);  // 重定位
    void outputsysinfo(const Elf64_Sym* sym, char* bufstr, int ncount);
    std::unordered_map<std::string, int> bind_hash;
};
