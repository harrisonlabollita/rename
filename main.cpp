#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::__fs::filesystem;
using str  = std::string;

int main(int argc, char* argv[]) {

    if (argc != 3) {
        std::cout << "Usage: rename <old_prefix> <new_prefix>" << std::endl;
        return 1;
    }

    str old_prefix = argv[1];
    str new_prefix = argv[2];

    for (const auto& entry : fs::directory_iterator(".") ) {

        if (!entry.is_directory() ) {

            str old_name = entry.path().filename().string();
            str new_name = old_name;
            size_t found = old_name.find(old_prefix);

            if (found != std::string::npos) {
                new_name.replace(found, old_prefix.length(), new_prefix);
                fs::rename(entry.path(), fs::path(new_name) );

            }
        }
    }
    return 0;
}
