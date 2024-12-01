#pragma once
#include <string>
#include <iostream>
#include "Pracownik.h"

class Rob : public Pracownik {
private:
    double but_;

public:
    Rob();
    Rob(std::string imie, double but);

    void print() const override;
};

