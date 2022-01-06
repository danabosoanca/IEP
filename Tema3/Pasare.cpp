#include<iostream>

class Pasare {
private:
	int aripi = 2;
	std::string sunet = "Lala";
public:
	Pasare() {
		std::cout << "S-a apelat constructorul fara parametri al clasei Pasare" << std::endl;
	}
	Pasare(int a, std::string s) :aripi(a), sunet(s)
	{
		std::cout << "S-a apelat constructorul cu parametri al clasei Pasare" << std::endl;
	}
	Pasare(const Pasare& p) {
		std::cout << "S-a apelat copy-constructorul din clasa Pasare" << std::endl;
		this->aripi = p.aripi;
		this->sunet = p.sunet;
	}
	//--------------------------------ITEM10-----------------------------------
	/*Pasare& operator=(const Pasare& p) {
		std::cout << "S-a apelat copy-assignment operator cu return" << std::endl;
		aripi += p.aripi;
		sunet += p.sunet;
		return *this;
	}*/
	//-------------------------------------------------------------------------
	/*Pasare& operator+=(const Pasare& p) { //item10
		std::cout << "S-a apelat operator += din clasa Pasare" << std::endl;
		aripi += p.aripi;
		sunet += p.sunet;
		return *this;
	}*/
	//--------------------------------ITEM11-----------------------------------
	Pasare& operator=(const Pasare& p) { //oare ar trebui asta?
		if (this == &p) {
			std::cout << "Acelasi obiect - clasa Pasare" << std::endl;
			return *this;
		}
		std::cout << "S-a apelat copy assignment operator din clasa Pasare" << std::endl;
		aripi = p.aripi;
		sunet = p.sunet;
		return *this;

	}
	//-------------------------------------------------------------------------

	virtual ~Pasare() {
		std::cout << "S-a apelat destructorul clasei Pasare" << std::endl;
	}
	int printAripi() {
		std::cout << "Pasarea are " << aripi << " aripi" << std::endl;
		return this->aripi;
	}
	std::string printSunet() {
		std::cout << "Sunetul scos de aceasta pasare este " << sunet << std::endl;
		return this->sunet;
	}
	void setSunet(std::string sunet) {
		this->sunet = sunet;
	}
};

