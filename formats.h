#include <string>
int split_class_function_breakpoint_provider(std::string unsplit_function) {
    int char_count = 0;
    std::string length = std::to_string(unsplit_function.length());
    std::string length_length = std::to_string(length.length());
    while (true) {
        if (char_count >= unsplit_function.length()) {
            break;
        }
        if (unsplit_function[char_count] == '.') {
            return char_count;
            break;
        }
        char_count += 1;
    }
}
