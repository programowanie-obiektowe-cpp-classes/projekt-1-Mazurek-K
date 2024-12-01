#include "Mkt.h"

Mkt::Mkt(std::string imie, int follows) : Pracownik(imie), follows_(follows) {}

void Mkt::print() const {
    std::cout << "Imie: " << imie_ << "\t" << "Followers: " << follows_ << std::endl;
}