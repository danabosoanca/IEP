#include<iostream>
#include "Rata.cpp"


int Rata::nr = 0;
int main() {
	std::cout << "--------------------------ITEM10-----------------------------" << std::endl;
	Pasare cocos;
	cocos.setSunet("CotCodac");
	Pasare gasca(3, "GaGa");
	Pasare ciocanitoare(4, "CiocCioc");
	Pasare gaina = cocos;
	std::cout << "-------------------------------------------------------------" << std::endl;
	gasca = gaina = ciocanitoare;
	gasca.printAripi();
	std::cout << "-------------------------------------------------------------" << std::endl;

	cocos += gasca += ciocanitoare;
	cocos.printAripi();
	std::cout << std::endl;
	//privighetoarea are 4 aripi, gasca are 4 aripi, cocosul are 2 aripi => 10 aripi va acea cocosul

	std::cout << "--------------------------ITEM11-----------------------------" << std::endl;

	Pasare curcan;
	std::cout << "-------------------------------------------------------------" << std::endl;
	curcan.setSunet("GluGlu");
	curcan.printSunet();
	curcan.printAripi();
	std::cout << "-------------------------------------------------------------" << std::endl;
	curcan = curcan;
	
	std::cout << std::endl;
	std::cout << "--------------------------ITEM12-----------------------------" << std::endl;


	Rata r1;
	Rata r2;
	
	r1.printSunet();
	r2.printSunet();
	r2.setSunet("CipCirip");
	r1 = r2; //daca nu am fi apelat copy-ass-op din clasa de baza, in sunet am fi avut Lala
	r1.printSunet();
	std::cout << "-------------------------" << std::endl;


}

