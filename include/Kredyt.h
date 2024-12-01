#pragma once
class Kredyt {
private:
	unsigned int czas_;
	double wartosc_;
	double intrest_;
	double m_ ;// rata
public:
	Kredyt(unsigned int czas, double wartosc);
	
	double splac();
	double get_kredyt();
};
    
