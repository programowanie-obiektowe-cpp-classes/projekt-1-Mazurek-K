#include "Inz.h"
Inz::Inz():Pracownik(), wydzial_("brak") {}
Inz::Inz(std::string imie, std::string wydzial) : Pracownik(imie), wydzial_(wydzial) {}

void Inz::print() const {
    std::cout << "Imie: "<<imie_ << "\t" << "Wydzial: " << wydzial_ << std::endl;
}
