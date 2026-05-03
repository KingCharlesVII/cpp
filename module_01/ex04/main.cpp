#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(const std::string& content, const std::string& s1, const std::string& s2) {
    if (s1.empty())
        return (content);
    std::string result;
    size_t pos = 0;
    size_t found;

    while ((found = content.find(s1, pos)) != std::string::npos) {
        result.append(content, pos, found - pos);
        result.append(s2);
        pos = found + s1.length();
    }
    result.append(content, pos, std::string::npos);
    return (result);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Error: wrong number of arguments" << std::endl;
        return (1);
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream input(filename.c_str());
    if (!input) {
        std::cerr << "Error: cannot open file" << std::endl;
        return (1);
    }
    std::string content;
    std::string line;

    while (std::getline(input, line)) {
        content += line;
        if (!input.eof())
            content += "\n";
    }
    input.close();
    std::string replaced = replaceAll(content, s1, s2);
    std::ofstream output((filename + ".replace").c_str());
    if (!output) {
        std::cerr << "Error: cannot create output file" << std::endl;
        return (1);
    }
    output << replaced;
    output.close();
}