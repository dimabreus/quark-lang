#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <stdexcept>

#include "logger.h"

using namespace utils::logger;

namespace utils::options {

    struct Options {
        bool emit_ir = false;
        bool emit_asm = false;
        bool build = false;
        bool run = false;
        bool no_compile = false;
        bool time = false;
        std::string input_file;
    };

    enum class Flag {
        EmitIR,
        EmitAsm,
        Build,
        Run,
        NoCompile,
        Time
    };

    Options parse_args(int argc, char** argv); 
}
