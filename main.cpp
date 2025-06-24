#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <limits>

std::pair<int, int> readLine(std::string &line);
bool checkNum(std::string &element);

int main()
{

    std::vector<double> a;
    std::vector<double> b;
    std::string line;

    std::cout << "----Simple Vector Addition----" << std::endl;

    std::cout << "Enter the First vector: ";
    std::getline(std::cin, line);

    a.push_back(readLine(line).first);
    a.push_back(readLine(line).second);

    std::cout << "Enter the Second vector: ";
    std::getline(std::cin, line);
    b.push_back(readLine(line).first);
    b.push_back(readLine(line).second);

    std::cout << "Resultant Vector: " << a.at(0) + b.at(0) << " " << a.at(1) + b.at(1) << std::endl;

    return 0;
}

std::pair<int, int> readLine(std::string &line)
{
    std::string x1;
    std::string x2;

    std::stringstream ss(line);

    std::getline(ss, x1, ' ');
    if (!checkNum(x1))
    {
        std::cout << "Enter Integers Only!";
        exit(EXIT_FAILURE);
    }

    std::getline(ss, x2);
    if (!checkNum(x2))
    {
        std::cout << "Enter Integers Only!";
        exit(EXIT_FAILURE);
    }

    return {std::stoi(x1), std::stoi(x2)};
}

bool checkNum(std::string &element)
{
    for (auto &i : element)
    {
        if (!isdigit(i))
        {
            return false;
        }
    }
    return true;
}