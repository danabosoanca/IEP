#include<iostream>
#include<memory>

class Rata {
private:
	int aripi = 2;
	bool isLocked = false;
public:
	Rata() {
		std::cout << "S-a apelat constructorul fara parametri al clasei Rata" << std::endl;
	}
	Rata(int a) :aripi(a)
	{
		std::cout << "S-a apelat constructorul cu parametri al clasei Rata" << std::endl;
	}
	Rata(const Rata& p) {
		std::cout << "S-a apelat copy-constructorul din clasa Rata" << std::endl;
		this->aripi = p.aripi;
		this->isLocked = p.isLocked;
	}
	//--------------------------------ITEM10-----------------------------------
	/*Rata& operator=(const Rata& p) {
		std::cout << "S-a apelat copy-assignment operator cu return" << std::endl;
		aripi += p.aripi;
		this->isLocked = p.isLocked;
		return *this;
	}*/
	//-------------------------------------------------------------------------
	/*Rata& operator+=(const Rata& p) { //item10
		std::cout << "S-a apelat operator += din clasa Rata" << std::endl;
		aripi += p.aripi;
		sunet += p.sunet;
		return *this;
	}*/
	//--------------------------------ITEM11-----------------------------------
	Rata& operator=(const Rata& p) { //oare ar trebui asta?
		if (this == &p) {
			std::cout << "Assignment to self- clasa Rata" << std::endl;
			return *this;
		}
		std::cout << "S-a apelat copy assignment operator din clasa Rata" << std::endl;
		aripi = p.aripi;
		isLocked = p.isLocked;
		return *this;

	}
	//-------------------------------------------------------------------------

	virtual ~Rata() {
		std::cout << "S-a apelat destructorul clasei Rata" << std::endl;
	}
	int printAripi() {
		std::cout << "Rata are " << aripi << " aripi" << std::endl;
		return this->aripi;
	}
	bool printIsLocked() {
		std::cout << "Rata : isLocked = " <<isLocked << std::endl;
		return this->isLocked;
	}
	void setIsLocked(bool isLocked) {
		this->isLocked = isLocked;
	}
	void askRata() {
		if (this->isLocked) {
			std::cout << "Off, resursa e blocata" << std::endl;
		}
		else {
			std::cout << "Yay, poti folosi resursa" << std::endl;
		}
	}
};

