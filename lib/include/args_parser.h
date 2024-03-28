#ifndef GRAPHGHETTI_ARGS_PARSER_H
#define GRAPHGHETTI_ARGS_PARSER_H

#include "string"
#include "iostream"

bool parse_args(int argc, char *argv[], std::string &input, std::string &output, size_t &iterations, int &width,
                int &height) {
    // set default values to parameters
    width = 1000;
    height = 1000;
    iterations = 1000;

    bool have_input = false;
    bool have_output = false;

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (i + 1 < argc && arg == "-input") {
            have_input = true;
            input = argv[i + 1];
            i++;
            continue;
        }
        if (i + 1 < argc && arg == "-output") {
            have_output = true;
            output = argv[i + 1];
            i++;
            continue;
        }
        if (i + 1 < argc && arg == "-width") {
            width = atoi(argv[i + 1]);
            i++;
            continue;
        }
        if (i + 1 < argc && arg == "-height") {
            height = atoi(argv[i + 1]);
            i++;
            continue;
        }
        if (i + 1 < argc && arg == "-iter") {
            iterations = atoi(argv[i + 1]);
            i++;
            continue;
        }
    }
    if (!have_input) {
        std::cerr << "No input path was given\n";
        return false;
    }
    if (!have_output) {
        std::cerr << "No output path was given\n";
        return false;
    }
    return true;
}

#endif //GRAPHGHETTI_ARGS_PARSER_H
