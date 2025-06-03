#include <iostream>
#include <fstream>
#include <vector>
#include "CSVParse/CSVParser.h"

std::vector<std::vector<float>>& CSVParser::parse(std::string fileName) {
    std::vector<std::vector<float>>* table = new std::vector<std::vector<float>>;
    std::ifstream file(fileName);
    std::string line;

    if (file.is_open()) {
        for (int i = 0; getline(file, line); i++) {
            table->push_back({});
            std::string element = "";
            for (int j = 0; j < line.size(); j++) {
                if (std::isdigit(line[j]) || line[j] == '.') {
                    element += line[j];
                } else if (line[j] == ',') {
                    std::cout << element << "\n";
                    table->at(i).push_back(std::stof(element));
                    element = "";
                } else {
                    break;
                }
            }
            if (element != "") {
                table->at(i).push_back(std::stof(element));
            }
        }
        file.close();
    } else {
        std::cout << "Failed to open file" << "\n";
    }
    return *table;
}
