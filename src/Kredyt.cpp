#include <cmath> // For std::pow
#include "Kredyt.h"
#include <iostream>
#include<cmath>
Kredyt::Kredyt(unsigned int czas, double wartosc) :
    czas_(czas),
    wartosc_(wartosc),
    intrest_(0.05 + 0.1* std::tanh(double(czas)/24))
{
    double r = intrest_ / 12;
    int n = czas * 12;
    m_ = (wartosc * r * std::pow(1 + r, n)) / (std::pow(1 + r, n) - 1);
    std::cout << "Rata miesieczna: " <<m_<< " Odsetki: "<<intrest_ <<std::endl;
}


double Kredyt::splac() {
    if (czas_ == 0) {
        std::cout << "Kredyt splacono!" << std::endl;
        return 0;
    }
    else {
        wartosc_ = wartosc_ - m_;
        czas_ = czas_*12 - 1;
        std::cout << "Splaconoo: " << m_ << std::endl;
        return m_;
    }
}


double Kredyt::get_kredyt() {

    return wartosc_;;
}
 