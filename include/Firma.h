#pragma once
#include <iostream>
#include <memory>
#include <string>
#include "Mag.h"
#include "Inz.h"
#include "Mkt.h"
#include "Rob.h"
#include "Pracownik.h"
#include "Kredyt.h"
#include <vector>

class Firma {
private:
    double stan_konta_;
    double wartosc_firmy_;
    int wiek_firmy_;
    double czas_const_;
    std::vector<double> przychod_history_; // Declare the vector
    int  max_czas_kred_;
    double max_zadl_;


    double ci_;
    double cmag_;
    double cmkt_;
    double cr_;

    double rob_wyn_;
    double inz_wyn_;
    double mkt_wyn_;
    double mag_wyn_;

    int n_inz_;
    int n_mag_;
    int n_mkt_;
    int n_rob_;

    int i_;
    int k_;
    int l_prod_; // liczba produktów wyprodukowana w miesi¹cu
    int l_stock_; // liczba produktów w magazynie
    int l_sprzed_; //liczba sprzedanych prod
    double przych_; //przycod

    std::unique_ptr<std::unique_ptr<Pracownik>[]> pracownik; 
    std::unique_ptr<std::unique_ptr<Kredyt>[]> kredyt;

    double zaplac_wynagrodzenie();
    double splac_rate();
    double przychod();

public:
   
    Firma();
    void zatrudnij(std::string posada, std::string name, std::string cecha);
    void print_all();
    void get_stankonta();
    void wez_kredyt(int czas, double wartosc);
    bool month_End();
    void wartosc();
};
