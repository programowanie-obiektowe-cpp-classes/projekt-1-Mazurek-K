#include "Rob.h"
Rob::Rob(): Pracownik(), but_(0){}
Rob::Rob(std::string imie, double but) : Pracownik(imie), but_(but) {}

void Rob::print() const {
    std::cout << "Imie: " << imie_ << "\t" << "But: " << but_ << std::endl;
}