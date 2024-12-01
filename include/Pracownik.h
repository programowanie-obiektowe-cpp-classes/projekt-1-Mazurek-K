#pragma once
#include <string>
#include <iostream>

class Pracownik {
public:
    std::string imie_;
    Pracownik() : imie_("brak") {}
    Pracownik(std::string imie) : imie_(imie) {}

    
    virtual void print() const {
        std::cout << "Imie pracownika: " << imie_ << std::endl;
    }
    //virtual void print() const = 0;
    

};
