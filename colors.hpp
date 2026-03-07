#pragma once
#include<string>
// B = Bright
// BG = BackGround

namespace Color{
    const std::string BOLD = "\033[1m";
    const std::string DIM = "\033[2m";
    const std::string RESET = "\033[0m";  
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string BLUE = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN = "\033[36m";
    const std::string WHITE = "\033[37m";
    const std::string BGREEN   = "\033[92m";
    const std::string BRED     = "\033[91m";
    const std::string BBLUE    = "\033[94m";
    const std::string BYELLOW  = "\033[93m";
    const std::string BMAGENTA = "\033[95m";
    const std::string BCYAN    = "\033[96m";
    const std::string BWHITE   = "\033[97m";
    const std::string BG_RED = "\033[41m";
    const std::string BG_GREEN = "\033[42m";
    const std::string BG_YELLOW = "\033[43m";
    const std::string BG_BLUE = "\033[44m";
}