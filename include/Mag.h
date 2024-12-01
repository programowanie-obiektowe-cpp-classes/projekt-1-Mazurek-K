#pragma once
#include <string>
#include <iostream>
#include "Pracownik.h"

class Mag : public Pracownik {
private:
    bool obsl_widl_;

public:
    Mag(std::string imie, bool obsl_widl);

    void print() const override;
};