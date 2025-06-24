#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <limits>
#include <Windows.h> // For ClearScreen()
#include <conio.h>   // For getch() to capture keyboard input
#include "vector.hpp"

std::pair<int, int> readLine(std::string &line);
bool checkNum(std::string &element);
void displayMenu();
std::pair<int, int> performSelection(int userSelection);
void ClearScreen();

int main()
{
    std::string userSelection;
    std::pair<int, int> resultantVector;

    do
    {
        ClearScreen();
        displayMenu();

        std::cout << "Option: ";
        std::getline(std::cin, userSelection);
        if (!checkNum(userSelection))
        {
            std::cout << "Bad Input\n";
            userSelection = "-1";
            continue;
        }
        if ((std::stoi(userSelection) > 0) && (std::stoi(userSelection) < 3)) // IF YOU ADD MORE MENU ITEMS CHANGE THE BOUNDS :) TRASH IMPLEMENTATION IK
        {
            resultantVector = performSelection(stoi(userSelection));
            std::cout << "Resultant Vector: " << "[" << resultantVector.first << ", " << resultantVector.second << "]" << std::endl;
            getch();
        }

    } while (std::stoi(userSelection) != 0);
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
    std::cout << "0. Exit" << std::endl;
}

std::pair<int, int> performSelection(int userSelection)
{
    std::string line;
    Vector2D resultantVector;
    Vector2D vectorUno;
    Vector2D vectorDos;
    switch (userSelection)
    {
    case 1:
        std::cout << "Enter the First vector: ";
        std::getline(std::cin, line);
        vectorUno.x = readLine(line).first;
        vectorUno.y = readLine(line).second;

        std::cout << "Enter the Second vector: ";
        std::getline(std::cin, line);
        vectorDos.x = readLine(line).first;
        vectorDos.y = readLine(line).second;

        resultantVector = vectorUno + vectorDos;
        break;
    case 2:
        std::cout << "Enter the First vector: ";
        std::getline(std::cin, line);
        vectorUno.x = readLine(line).first;
        vectorUno.y = readLine(line).second;

        std::cout << "Enter the Second vector: ";
        std::getline(std::cin, line);
        vectorDos.x = readLine(line).first;
        vectorDos.y = readLine(line).second;

        resultantVector = vectorUno - vectorDos;
        break;
    }

    return {resultantVector.x, resultantVector.y};
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