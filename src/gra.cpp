#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include <iostream>
#include "Firma.h"
#include "RandomNameGenerator.hpp"
#include <windows.h> // tylko do koloru tekstu w konsoli


void setConsoleTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}


int main() {
    {
        Firma firma;
        std::string command;
        std::string info1;
        std::string info2;

        while (true) {
            std::cout << "Please enter a command (print, zat, stan, kred, wart, next, exit): \n \n";
            std::cin >> command;

            if (command == "print") {

                firma.print_all();
            }
            else if (command == "exit") {
                break;
            }
            else if (command == "zat") {
                std::cout << "Type of worker (Mag, Rob, Mkt, Inz): ";
                std::cin >> info1;
                if (info1 != "Mag" && info1 != "Rob" && info1 != "Mkt" && info1 != "Inz") {
                    std::cout << "Invalid worker type!" << std::endl;
                    continue;
                }
                std::cout << "Enter the worker's feature Mag-true/false, Rob- double, Mkr- int, Inz- string ";
                std::cin >> info2;

                firma.zatrudnij(info1, getRandomName(), info2);
            }
            else if (command == "stan") {
                firma.get_stankonta();
            }
            else if (command == "kred") {
                int czas;
                double wartosc;


                std::cout << "Na tyle lat: ";
                std::cin >> czas;
                if (std::cin.fail()) {  
                    std::cout << "Niepoprawna liczba miesiecy!" << std::endl;
                    std::cin.clear(); 
                    continue;
                }
                std::cout << "Wartosc: ";
                std::cin >> wartosc;
                if (std::cin.fail()) {
                    std::cout << "Niepoprawna wartosc!" << std::endl;
                    std::cin.clear();
                    continue;  
                }

                firma.wez_kredyt(czas, wartosc);
            }
            else if (command == "wart") {
                firma.wartosc();
            }
            else if (command == "next") {
                if (firma.month_End()) {
                    setConsoleTextColor(4);
                    std::cout << "Przegrales" << std::endl;

                    break;

                }
            }
            else {
                std::cout << "Invalid command!" << std::endl;
            }
        }

    }
    _CrtDumpMemoryLeaks();
    return 0;
}
