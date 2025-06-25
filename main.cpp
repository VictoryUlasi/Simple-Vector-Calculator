#define NOMINMAX
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <limits>
#include <Windows.h> // For ClearScreen()
#include <conio.h>   // For getch() to capture keyboard input
#include "vector.hpp"

#define UPPER_MENU_BOUND 5
#define LOWER_MENU_BOUND 0

struct selectionResult
{
    Vector2D resultantVector;
    int resultantScalar;
    bool isScalar = false;
};

std::pair<int, int> readVector(std::string &line);
bool checkNum(std::string &element);
void displayMenu();
selectionResult performSelection(int userSelection);
void ClearScreen();

int main()
{
    unsigned int userSelection;

    do
    {
        ClearScreen();
        displayMenu();

        std::cout << "Option: ";
        std::cin >> userSelection;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        while (!std::cin.good())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            userSelection = -1;
        }
        if ((userSelection > LOWER_MENU_BOUND) && (userSelection < UPPER_MENU_BOUND)) // IF YOU ADD MORE MENU ITEMS CHANGE THE BOUNDS :) TRASH IMPLEMENTATION IK
        {
            auto result = performSelection(userSelection);
            if (result.isScalar)
            {
                ClearScreen();
                std::cout << "Resultant Scalar: " << "[" << result.resultantScalar << "]" << std::endl;
                _getch();
            }
            else
            {
                ClearScreen();
                std::cout << "Resultant Vector: " << "[" << result.resultantVector.x << ", " << result.resultantVector.y << "]" << std::endl;
                _getch();
            }

            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

    } while (userSelection != 0);
    return 0;
}

std::pair<int, int> readVector(std::string &line)
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
    for (auto &i : element) // Use a regular for loop to check if - sign is in the first position, that is i has to be 0 because negative can only be in  the first position
    {
        if (!isdigit(i) && i != '-')
        {
            return false;
        }
    }
    return true;
}

void displayMenu()
{
    // Display the available options in the menu
    std::cout << "----SIMPLE VECTOR CALCULATOR----" << std::endl;
    std::cout << "1. Vector Addition" << std::endl;
    std::cout << "2. Vector Subtraction" << std::endl;
    std::cout << "3. Vector Multiplication" << std::endl;
    std::cout << "4. Dot Product" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

selectionResult performSelection(int userSelection)
{
    std::string line;
    selectionResult resultant;
    Vector2D vectorUno;
    Vector2D vectorDos;
    int scalar; // Used in case 3 and 4 for 2 different things
    switch (userSelection)
    {
    case 1:
        std::cout << "Enter the First vector: ";
        std::getline(std::cin, line);
        vectorUno.x = readVector(line).first;
        vectorUno.y = readVector(line).second;

        std::cout << "Enter the Second vector: ";
        std::getline(std::cin, line);
        vectorDos.x = readVector(line).first;
        vectorDos.y = readVector(line).second;

        resultant.resultantVector = vectorUno + vectorDos;
        break;
    case 2:
        std::cout << "Enter the First vector: ";
        std::getline(std::cin, line);
        vectorUno.x = readVector(line).first;
        vectorUno.y = readVector(line).second;

        std::cout << "Enter the Second vector: ";
        std::getline(std::cin, line);
        vectorDos.x = readVector(line).first;
        vectorDos.y = readVector(line).second;

        resultant.resultantVector = vectorUno - vectorDos;
        break;
    case 3:
        std::cout << "Enter the vector: ";
        std::getline(std::cin, line);
        vectorUno.x = readVector(line).first;
        vectorUno.y = readVector(line).second;

        std::cout << "Enter the Scalar: ";
        std::cin >> scalar;

        resultant.resultantVector = vectorUno * scalar;
        break;
    case 4:
        std::cout << "Enter the First vector: ";
        std::getline(std::cin, line);
        vectorUno.x = readVector(line).first;
        vectorUno.y = readVector(line).second;

        std::cout << "Enter the Second vector: ";
        std::getline(std::cin, line);
        vectorDos.x = readVector(line).first;
        vectorDos.y = readVector(line).second;

        resultant.resultantScalar = vectorUno.dotProduct(vectorDos); // How to project this to screen? can only return pair
        resultant.isScalar = true;
        break;
    }

    return resultant;
}

void ClearScreen()
{
    HANDLE hStdOut;                  // Handle to the standard output
    CONSOLE_SCREEN_BUFFER_INFO csbi; // Console screen buffer info
    DWORD count;                     // Number of cells written to
    DWORD cellCount;                 // Total number of cells in the console
    COORD homeCoords = {0, 0};       // Home coordinates to move cursor to top left

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // Get handle to console output
    if (hStdOut == INVALID_HANDLE_VALUE)
        return;

    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) // Get buffer info
        return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y; // Calculate total cell count

    if (!FillConsoleOutputCharacter(hStdOut, (TCHAR)' ', cellCount, homeCoords, &count)) // Fill console with spaces
        return;

    if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count)) // Reset attributes
        return;

    SetConsoleCursorPosition(hStdOut, homeCoords); // Move cursor to top-left corner
}