#pragma once
#include <string>
#include <iostream>
#include "Pracownik.h"

class Mkt : public Pracownik {
private:
    int follows_;

public:
    Mkt(std::string imie, int follows);

    void print() const override;
};

