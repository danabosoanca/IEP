#include<iostream>
#include "Pasare.cpp"

class Rata : public Pasare {
private:
	std::string culoare = "galben";
	std::string  nume = "Donald";
	static int nr;
public:
	Rata() : Pasare() {
		nr++;
		std::cout << "S-a apelat constructorul fara parametri al clasei Rata" << std::endl;
	}//aici, am apelat si constructorul din clasa de baza

	
	Rata(const Rata& r)  : Pasare(r){
		std::cout << "S-a apelat copy constructorul din clasa Rata" << std::endl;
		this->culoare = r.culoare;
		this->nume = r.nume;
	}

	Rata& operator=(const Rata& r) {
		if (this == &r) { 
			std::cout << "Acelasi obiect - clasa Rata" << std::endl;
			return *this;
		}
		Pasare::operator=(r);
		std::cout << "S-a apelat copy assignment operator din clasa Rata" << std::endl;
		culoare = r.culoare;
		nume = r.nume;
		return *this;
	}
	~Rata() {
		std::cout << "S-a apelat destructorul clasei Rata" << std::endl;
	}
	std::string printCuloare() {
		std::cout << "Aceasta pasare are culoarea " << culoare << std::endl;
		return this->culoare;
	}
	std::string printNume() {
		std::cout << "Aceasta pasare se numeste " << nume << std::endl;
		return this->nume;
	}
	void setNume(std::string n) {
		this->nume = n;
	}
	void setCuloare(std::string c) {
		this->culoare = c;
	}
	void seteaza(int a) {
		this->nr = a;
	}
	int afiseazaNr() {
		return this->nr;
	}
};
