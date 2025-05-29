#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <iostream>
#include <vector>

class CSVParser {
public:
    std::vector<std::vector<float>> parse(std::string fileName);
};

#endif
