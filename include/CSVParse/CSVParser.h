#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <iostream>
#include <vector>

class CSVParser {
public:
    std::vector<std::vector<double>>& parse(std::string fileName);
};

#endif
