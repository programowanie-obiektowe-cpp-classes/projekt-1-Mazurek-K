#include "Firma.h"
#include "RandomNameGenerator.hpp"

Firma::Firma() :
    stan_konta_(100000.0),
    wartosc_firmy_(0),
    czas_const_(3),
    wiek_firmy_(0),
    przychod_history_(),
    max_czas_kred_(4),
    max_zadl_(1000000),

    ci_(1200),
    cmag_(1000),
    cmkt_(1000),
    cr_(1000),

    rob_wyn_(5000),
    inz_wyn_(12000),
    mkt_wyn_(7000),
    mag_wyn_(6000),

    n_inz_(0),
    n_mag_(0),
    n_mkt_(0),
    n_rob_(0),

    l_prod_(0),
    l_sprzed_(0),
    l_stock_(0),

    przych_(0),
    i_(0), // liczba pracowników
    k_(0), //licza kredytów
    pracownik(std::make_unique<std::unique_ptr<Pracownik>[]>(100)), 
    kredyt(std::make_unique<std::unique_ptr<Kredyt>[]>(100))
{
    
    zatrudnij("Mag", getRandomName(), "true");
    zatrudnij("Inz", getRandomName(),  "meil");
    zatrudnij("Rob", getRandomName(),  "43.5");
    zatrudnij("Mkt", getRandomName(), "4000");
}

void Firma::zatrudnij(std::string posada, std::string name, std::string cecha) {
    if (posada == "Mag") {
        if (cecha == "true") {
            pracownik[i_] = std::make_unique<Mag>(name, true);
            n_mag_=n_mag_ + 1;
            i_++;
        }
        else if (cecha == "false") {
            pracownik[i_] = std::make_unique<Mag>(name, false);
            n_mag_=n_mag_ + 1;
            i_++;
        }
        else {
            std::cout << "Nieprawidlowa cecha" << std::endl;
            return;
        }
    }
    else if (posada == "Inz") {
        pracownik[i_] = std::make_unique<Inz>(name, cecha);
        n_inz_=n_inz_ + 1;
        i_++;
    }
    else if (posada == "Mkt") {
        try {
            int value = std::stoi(cecha);
            pracownik[i_] = std::make_unique<Mkt>(name, value);
            n_mkt_=n_mkt_ + 1;
            i_++;
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Invalid Mkt val: " << cecha << std::endl;
            return;
        }
    }
    else if (posada == "Rob") {
        try {
            double value = std::stod(cecha); 
            pracownik[i_] = std::make_unique<Rob>(name, value);
            n_rob_=n_rob_ + 1;
            i_++;
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Invalid Rob val: " << cecha << std::endl;
            return;
        }
    }
    else {
        std::cerr << "Unknown posada: " << posada << std::endl;
        return;
    }

      
}

void Firma::print_all( ) {
    for (int k = 0; k < i_; k++) {
        pracownik[k]->print();
    }
    
}

double Firma::zaplac_wynagrodzenie() {
    double wydatki = 0;
    for (int k = 0; k < i_; k++) {
        if (dynamic_cast<Mag*>(pracownik[k].get())) {
            wydatki = wydatki + mag_wyn_;;
        }
        else if (dynamic_cast<Inz*>(pracownik[k].get())) {
            wydatki=wydatki+inz_wyn_;
        }
        else if (dynamic_cast<Mkt*>(pracownik[k].get())) {
            wydatki = wydatki + mkt_wyn_;
        }
        else if (dynamic_cast<Rob*>(pracownik[k].get())) {
            wydatki=wydatki+rob_wyn_;
        }
        else {
            std::cout << "Index " << k << ": Unknown type." << std::endl;
        }
    }

    return wydatki;
}

void Firma::get_stankonta(){
    std::cout << "Stan konta: " << stan_konta_ << std::endl;
}


void Firma::wez_kredyt(int czas, double wartosc) {
    double zadluzenie=0;

    if (k_ > 0) {
        for (int j = 0; j < k_; j++) {
            zadluzenie = zadluzenie + kredyt[j]->get_kredyt();
        }
    }

    if (czas > max_czas_kred_ || wartosc+zadluzenie > max_zadl_) {
        std::cout << "Zbyt dugi czas kredytu lub zbyt duze zadluzenie (max czas to 3)" << std::endl;
    }
    else {
        kredyt[k_] = std::make_unique<Kredyt>(czas, wartosc);
        stan_konta_ = stan_konta_ + wartosc;
        k_++;
    }
    

}

double Firma::splac_rate() {
    double suma_rat_ = 0;
    if (k_ > 0) {
        for (int j = 0; j < k_; j++) {
            suma_rat_ = suma_rat_ + kredyt[j]->splac();
        }
    }
    return suma_rat_;
}

double Firma::przychod() {
    l_prod_ = n_rob_ * cr_;
    l_stock_ = n_mag_ * cmag_;
    l_sprzed_ = n_mkt_ * cmkt_;
    double a = (l_prod_ > l_stock_) ? l_prod_ : l_stock_;
    przych_= (l_prod_ > a) ? l_prod_ : a;
    return przych_;
}

void Firma::wartosc() {

    if (wiek_firmy_ == 0){
        std::cout << "Firma zbyt mloda, nie ma wartosci" << std::endl;
    }
    else {
        double wart = 0;
        int czas;

        wiek_firmy_ >= czas_const_ ? czas = czas_const_ : czas = wiek_firmy_;

        for (auto it = przychod_history_.rbegin(); it != przychod_history_.rbegin() + czas; ++it) {
            wart = wart + *it;
        }

        wart = wart / czas;
        std::cout << "Wartosc firmy: " << wart << std::endl;
    }
    

}

bool Firma::month_End() {
    wiek_firmy_++;
    double przych = przychod();
    przychod_history_.push_back(przych);


    double raty = splac_rate();
    double wynagrodzenia = zaplac_wynagrodzenie();
    stan_konta_ = stan_konta_ + przych - raty - wynagrodzenia;
    std::cout << "Przychod: " << przych << "  Wynagrodzenia: " << wynagrodzenia << "  Raty kredytow: " << raty << "\n Stan konta: " << stan_konta_ << std::endl;
    if (stan_konta_ >= 0) { 

        return false;
    }
    else {
        return true;
        //ugabuga
    }




}