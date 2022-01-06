#include<iostream>
class Uncopyable {
protected: // allow construction
	Uncopyable() {} // and destruction of
	~Uncopyable() {} // derived objects...
private:
	Uncopyable(const Uncopyable&); // ...but prevent copying
	Uncopyable& operator=(const Uncopyable&);
};

class Salariat{
private:
	int id;
	std::string nume;
	std::string prenume;
	int salariu;
	int bonus;
	int oreMuncite;
	int vechimeAni;
public:
	Salariat(int i, std::string n, std::string p, int s, int b, int o, int v); //constructor
	virtual ~Salariat(); //destructor
	Salariat(const Salariat& s); //copy-constructor
	Salariat& operator=(const Salariat& s); //copy-assignment operator
	int getID();
	std::string getNume();
	std::string getPrenume();
	int getSalariu();
	int getBonus();
	int getOreMuncite();
	int getVechimeAni();
};

Salariat::Salariat(int i, std::string n, std::string p, int s, int b, int o, int v) :
	id(i),
	nume(n),
	prenume(p),
	salariu(s),
	bonus(b),
	oreMuncite(o),
	vechimeAni(v)
{
	std::cout << "S-a apelat constructorul clasei Salariat " << std::endl;
}

Salariat::Salariat(const Salariat &s) {
	std::cout << "Copy Constructor " << std::endl;
	this->id = s.id;
	this->nume = s.nume;
	this->prenume = s.prenume;
	this->salariu = s.salariu;
	this->bonus = s.bonus;
	this->oreMuncite = s.oreMuncite;
	this->vechimeAni = s.vechimeAni;
}

Salariat::~Salariat() {
	std::cout << "S-a apelat destructorul clasei Salariat" << std::endl;
}

Salariat& Salariat::operator=(const Salariat &s) {
	std::cout << "S-a apelat copy assignment operator " << std::endl;
	this->id = s.id;
	this->nume = s.nume;
	this->prenume = s.prenume;
	this->salariu = s.salariu;
	this->bonus = s.bonus;
	this->oreMuncite = s.oreMuncite;
	this->vechimeAni = s.vechimeAni;
	return *this;
}
int Salariat::getID() {
	return id;
}
std::string Salariat::getNume() {
	return nume;
}
std::string Salariat::getPrenume() {
	return prenume;
}
int Salariat::getBonus() {
	return bonus;
}
int Salariat::getOreMuncite() {
	return oreMuncite;
}
int Salariat::getSalariu() {
	return salariu;
}
int Salariat::getVechimeAni() {
	return vechimeAni;
}

class Programator :public Salariat {
private:
	std::string companie;
public:
	std::string getCompanie() {
		return companie;
	}
	~Programator() {
		std::cout << "S-a apelat destructorul clasei Programator" << std::endl;
	}
	Programator(int i, std::string n, std::string p, int s, int b, int o, int v, std::string c) :
		Salariat(i, n, p, s, b, o, v),
		companie(c)
	{
		std::cout << " + constructorul clasei Programator" << std::endl;
	}
};
class Profesor :public Salariat {
private:
	std::string facultate;
public:
	std::string getFacultate() {
		return facultate;
	}
	~Profesor() {
		std::cout << "S-a apelat destructorul clasei Profesor\n";
	}
	Profesor(int i, std::string n, std::string p, int s, int b, int o, int v, std::string f) :
		Salariat(i, n, p, s, b, o, v),
		facultate(f)
	{
		std::cout << " + constructorul clasei Profesor" << std::endl;
	}
};
int main() {
	Programator p1(1, "Popescu", "Ionel", 5000, 1000, 160, 10, "Nokia");
	std::cout << "----------------------------------------------------------------------------------------" << std::endl;
	std::cout << "Primul programator este " << p1.getNume() << " " << p1.getPrenume() << " si lucreaza de " << p1.getVechimeAni() << " ani." << "In acest moment, lucreaza la compania " << p1.getCompanie() << " ,iar luna aceasta a lucrat " << p1.getOreMuncite() << " de ore. Salariul sau este " << p1.getSalariu() << " de lei si primeste un bonus de " << p1.getBonus() << " de lei " << std::endl;
	std::cout << "----------------------------------------------------------------------------------------" << std::endl;
	Profesor prof1(1, "Tomescu", "Adrian", 3500, 800, 128, 20, "AC");
	std::cout << "----------------------------------------------------------------------------------------" << std::endl;
	std::cout << "Primul profesor este " << prof1.getNume() << " " << prof1.getPrenume() << " si lucreaza de " << prof1.getVechimeAni() << " ani." << "In acest moment, preda la facultatea " << prof1.getFacultate() << " ,iar luna aceasta a lucrat " << prof1.getOreMuncite() << "de ore. Salariul sau este " << prof1.getSalariu() << " de lei si primeste un bonus de " << prof1.getBonus() << " de lei " << std::endl;
	std::cout << "----------------------------------------------------------------------------------------" << std::endl;
	Salariat s2(2, "Ionescu", "Andreea", 1500, 300, 80, 1); //constructor Salariat
	std::cout << "----------------------------------------------------------------------------------------" << std::endl;
	Salariat sa3(2, "Ionescu", "Andreea", 1500, 300, 80, 1);
	std::cout << "----------------------------------------------------------------------------------------" << std::endl;
	sa3= s2; //copy-assignment operator
	std::cout << "----------------------------------------------------------------------------------------" << std::endl;
	Salariat s4(s2); //copy-constructor
	std::cout << "----------------------------------------------------------------------------------------" << std::endl;
	
}

