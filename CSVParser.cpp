#include <iostream>
#include <fstream>
#include <vector>
#include "CSVParser.h"

std::vector<std::vector<float>> CSVParser::parse(std::string fileName) {
    std::vector<std::vector<float>> table;
    std::ifstream file(fileName);
    std::string line;

    if (file.is_open()) {
        for (int i = 0; getline(file, line); i++) {
            table.push_back({});
            std::string element = "";
            for (int j = 0; j < line.size(); j++) {
                if (line[j] != ',') {
                    element += line[j];
                } else {
                    //std::cout << element << "\n";
                    table[i].push_back(std::stof(element));
                    element = "";
                }
            }
            table[i].push_back(std::stof(element));
        }
        file.close();
    } else {
        std::cout << "Failed to open file" << "\n";
    }
    return table;
}
