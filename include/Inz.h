#pragma once
#include <string>
#include <iostream>
#include "Pracownik.h"

class Inz : public Pracownik {  
private:
    std::string wydzial_; 

public:
    Inz();
    Inz(std::string imie, std::string wydzial);

    void print() const override;
};
