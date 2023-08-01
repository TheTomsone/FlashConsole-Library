#include <iostream>
#include "Enums.h"
#include "Vector2.h"
#include "BaseInterface.h"

#include <Windows.h>

// Fonction pour obtenir la taille de la console en lignes et en colonnes
void getConsoleSize(Vector2& vector)
{
    HWND consoleWindow{ GetConsoleWindow() };
    //Vector2 screenSize(1600, 900);

    //SetWindowPos(consoleWindow, 0, 0, 0, screenSize.GetWidth(), screenSize.GetHeight(), SWP_NOMOVE | SWP_NOZORDER);

    // Mettre la console en plein écran
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    vector.setVector(csbi.srWindow.Right - csbi.srWindow.Left + 1, csbi.srWindow.Bottom - csbi.srWindow.Top + 1);

    // Ajuster la taille du buffer d'écran à la taille de la fenêtre console
    COORD coord;
    coord.X = csbi.srWindow.Right + 1;
    coord.Y = csbi.srWindow.Bottom + 1;
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    // Désactiver le défilement vertical
    CONSOLE_SCREEN_BUFFER_INFOEX csbiex;
    csbiex.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
    GetConsoleScreenBufferInfoEx(GetStdHandle(STD_OUTPUT_HANDLE), &csbiex);
    csbiex.bFullscreenSupported = TRUE; // Activer le mode plein écran
    csbiex.srWindow.Right = coord.X;
    csbiex.srWindow.Bottom = coord.Y;
    csbiex.srWindow.Right = csbiex.dwSize.X;
    csbiex.srWindow.Bottom = csbiex.dwSize.Y;
    SetConsoleScreenBufferInfoEx(GetStdHandle(STD_OUTPUT_HANDLE), &csbiex);
}

void clearConsole() {
    system("cls");
}

int main()
{
    std::shared_ptr<Vector2> window_size{new Vector2{ 50,20 }};
    getConsoleSize(*window_size);

    std::cout << "X: " << window_size->getX() << " | Y: " << window_size->getY() << std::endl;

    std::cout << "=======================================================================================\n";

    BaseInterface test{ window_size, CENTER_H, CENTER_V };
    std::cout << "BASE INTERFACE :\n";
    std::cout << "Container : X: " << test.getVectors(CONTAINER_SIZE)->getX() << " | Y: " << test.getVectors(CONTAINER_SIZE)->getY() << std::endl;
    std::cout << "Content   : X: " << test.getVectors(CONTENT_SIZE)->getX() << " | Y: " << test.getVectors(CONTENT_SIZE)->getY() << std::endl;
    std::cout << "Position  : X: " << test.getVectors(POSITION)->getX() << " | Y: " << test.getVectors(POSITION)->getY() << std::endl;

    test.lineConstructor(10, '-', '|', '|', '*', "FLASH CONSOLE", CENTER_H);

    std::cout << "BASE INTERFACE :\n";
    std::cout << "Container : X: " << test.getVectors(CONTAINER_SIZE)->getX() << " | Y: " << test.getVectors(CONTAINER_SIZE)->getY() << std::endl;
    std::cout << "Content   : X: " << test.getVectors(CONTENT_SIZE)->getX() << " | Y: " << test.getVectors(CONTENT_SIZE)->getY() << std::endl;
    std::cout << "Position  : X: " << test.getVectors(POSITION)->getX() << " | Y: " << test.getVectors(POSITION)->getY() << std::endl;

    clearConsole();

    test.displayInterface();

    return 0;
}