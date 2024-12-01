#include "Mag.h"

Mag::Mag(std::string imie, bool obsl_widl) : Pracownik(imie), obsl_widl_(obsl_widl) {}

void Mag::print() const {

    if (obsl_widl_ == true) {
        std::cout << "Imie: " << imie_ << "\t"  << "Obsluguje wozek" << std::endl;
    }
    else {
        std::cout << "Imie: " << imie_ << "\t"  << "nie obslugije wozka" << std::endl;
    }
    
}