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

#define UPPER_MENU_BOUND 6
#define LOWER_MENU_BOUND 0

struct selectionResult
{
    Vector2D resultantVector2D_;
    Vector3D resultantVector3D_;
    int resultantScalar;
    bool isScalar = false;
    bool is3D = false;
    std::pair<bool, std::string> errFlag = {false, ""};
};

struct vectorInput
{
    Vector2D vector2D_;
    Vector3D vector3D_;
    int x, y, z;
    bool is3D = false;
};

vectorInput readVector(std::string &line);
void setVector(vectorInput &vector);
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

            if (result.errFlag.first)
            {
                std::cout << result.errFlag.second << std::endl;
            }
            else
            {
                if (result.isScalar)
                {
                    ClearScreen();
                    std::cout << "Resultant Scalar: " << "[" << result.resultantScalar << "]" << std::endl;
                    _getch();
                }
                else
                {
                    if (result.is3D)
                    {
                        ClearScreen();
                        std::cout << "Resultant Vector: " << "[" << result.resultantVector3D_.x << ", " << result.resultantVector3D_.y << ", " << result.resultantVector3D_.z << "]" << std::endl;
                        _getch();
                    }
                    else
                    {
                        ClearScreen();
                        std::cout << "Resultant Vector: " << "[" << result.resultantVector2D_.x << ", " << result.resultantVector2D_.y << "]" << std::endl;
                        _getch();
                    }
                }
            }

            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

    } while (userSelection != 0);
    return 0;
}

vectorInput readVector(std::string &line)
{
    vectorInput vector;
    std::string x1;
    std::string x2;
    std::string x3;

    std::stringstream ss(line);

    std::getline(ss, x1, ' ');
    if (!checkNum(x1))
    {
        std::cout << "Enter Integers Only!" << std::endl;
        exit(EXIT_FAILURE);
    }
    vector.x = std::stoi(x1);

    std::getline(ss, x2, ' ');
    if (!checkNum(x2))
    {
        std::cout << "Enter Integers Only!" << std::endl;
        exit(EXIT_FAILURE);
    }
    vector.y = std::stoi(x2);

    if (std::getline(ss, x3, ' '))
    {
        if (!checkNum(x3))
        {
            std::cout << "Enter Integers Only!" << std::endl;
            exit(EXIT_FAILURE);
        }
        vector.z = std::stoi(x3);
        vector.is3D = true;
    }
    setVector(vector);
    return vector;
}

void setVector(vectorInput &vector)
{
    if (vector.is3D)
    {
        vector.vector3D_.x = vector.x;
        vector.vector3D_.y = vector.y;
        vector.vector3D_.z = vector.z;
    }
    else
    {
        vector.vector2D_.x = vector.x;
        vector.vector2D_.y = vector.y;
    }
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
    std::cout << "5. Cross Product (3D only)" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

selectionResult performSelection(int userSelection)
{
    std::string line;
    selectionResult resultant;
    vectorInput vectorUno;
    vectorInput vectorDos;
    int scalar; // Used in case 3 and 4 for 2 different things
    switch (userSelection)
    {
    case 1:
        std::cout << "Enter the First vector: ";
        std::getline(std::cin, line);
        vectorUno = readVector(line);

        std::cout << "Enter the Second vector: ";
        std::getline(std::cin, line);
        vectorDos = readVector(line);

        if ((vectorUno.is3D && !vectorDos.is3D) || (!vectorUno.is3D && vectorDos.is3D))
        {
            resultant.errFlag.first = true;
            resultant.errFlag.second = "Vectors Have to Be the Same Dimensions";
        }

        if (!resultant.errFlag.first)
        {
            if (vectorUno.is3D && vectorDos.is3D) // repetetive, errFlag already checks if vectors are the same, But Works for now.
            {
                resultant.resultantVector3D_ = vectorUno.vector3D_ + vectorDos.vector3D_;
                resultant.is3D = true;
            }
            else
            {
                resultant.resultantVector2D_ = vectorUno.vector2D_ + vectorDos.vector2D_;
            }
        }

        break;
    case 2:
        std::cout << "Enter the First vector: ";
        std::getline(std::cin, line);
        vectorUno = readVector(line);

        std::cout << "Enter the Second vector: ";
        std::getline(std::cin, line);
        vectorDos = readVector(line);

        if ((vectorUno.is3D && !vectorDos.is3D) || (!vectorUno.is3D && vectorDos.is3D))
        {
            resultant.errFlag.first = true;
            resultant.errFlag.second = "Vectors Have to Be the Same Dimensions";
        }

        if (!resultant.errFlag.first)
        {
            if (vectorUno.is3D && vectorDos.is3D) // repetetive, errFlag already checks if vectors are the same, But Works for now.
            {
                resultant.resultantVector3D_ = vectorUno.vector3D_ - vectorDos.vector3D_;
                resultant.is3D = true;
            }
            else
            {
                resultant.resultantVector2D_ = vectorUno.vector2D_ - vectorDos.vector2D_;
            }
        }

        break;
    case 3:
        std::cout << "Enter the vector: ";
        std::getline(std::cin, line);
        vectorUno = readVector(line);

        std::cout << "Enter the Scalar: ";
        std::cin >> scalar;

        if (vectorUno.is3D)
        {
            resultant.resultantVector3D_ = vectorUno.vector3D_ * scalar;
            resultant.is3D = true;
        }
        else
        {
            resultant.resultantVector2D_ = vectorUno.vector2D_ * scalar;
        }

        break;
    case 4:
        std::cout << "Enter the First vector: ";
        std::getline(std::cin, line);
        vectorUno = readVector(line);

        std::cout << "Enter the Second vector: ";
        std::getline(std::cin, line);
        vectorDos = readVector(line);

        if ((vectorUno.is3D && !vectorDos.is3D) || (!vectorUno.is3D && vectorDos.is3D))
        {
            resultant.errFlag.first = true;
            resultant.errFlag.second = "Vectors Have to Be the Same Dimensions";
        }

        if (!resultant.errFlag.first)
        {
            if (vectorUno.is3D && vectorDos.is3D) // repetetive, errFlag already checks if vectors are the same, But Works for now.
            {
                resultant.resultantScalar = vectorUno.vector3D_.dotProduct(vectorDos.vector3D_);
            }
            else
            {
                resultant.resultantScalar = vectorUno.vector2D_.dotProduct(vectorDos.vector2D_);
            }
            resultant.isScalar = true;
        }

        break;
    case 5:
        std::cout << "Enter the First vector: ";
        std::getline(std::cin, line);
        vectorUno = readVector(line);

        std::cout << "Enter the Second vector: ";
        std::getline(std::cin, line);
        vectorDos = readVector(line);

        if ((vectorUno.is3D && !vectorDos.is3D) || (!vectorUno.is3D && vectorDos.is3D))
        {
            resultant.errFlag.first = true;
            resultant.errFlag.second = "Vectors Have to Be the Same Dimensions";
        }

        if (!resultant.errFlag.first)
        {
            if (vectorUno.is3D && vectorDos.is3D) // repetetive, errFlag already checks if vectors are the same, But Works for now.
            {
                resultant.resultantVector3D_ = vectorUno.vector3D_.crossProduct(vectorDos.vector3D_);
                resultant.is3D = true;
            }
            else
                std::cout << "Cross Product Only On 3D vectors.";
        }

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