#include<iostream>
#include<memory>
#include "Pasare.cpp"
#include "Rata.cpp"

void lock(Rata& r) {
	std::cout << "Se blocheaza rata.." << std::endl;
	r.setIsLocked(true);
}
void unlock(Rata& r) {
	std::cout << "Se deblocheaza rata.." << std::endl;
	r.setIsLocked(false);
}

class LockRata { 
	//cand se creeaza un obiect de tipul lock, o sa se apeleze functia lock
	//si pe destructorul clasei respective o sa se apeleze functia
	//noastra de unlock
	private:
		Rata& lockPtr;
	public:
		LockRata(Rata& ptr):
		lockPtr(ptr) {
			lock(lockPtr);
		}
		~LockRata() {
			unlock(lockPtr);
		}
};

using namespace std;
Pasare* createPasareInstance() {
	return (new Pasare);
}
int main() {
	//--------------------------------ITEM13-----------------------------------
	std::cout << "-----------Item 13-start-------------" << std::endl;
	std::cout << "-----------Folosirea lui auto_ptr-------------" << std::endl;
	{
		auto_ptr<Pasare> autoPasare1(createPasareInstance()); //modul asta e deprecated
														   //exista unique_ptr in loc
		autoPasare1->printAripi();
		auto_ptr<Pasare> autoPasare2(autoPasare1);

		autoPasare2->printAripi();
		//pasare1->printAripi();//daca apelam si pe asta,
		//ne da SegmentationFault
		//deoarece autoPasare1 este null
	}
	std::cout << "-----------Folosirea lui unique_ptr-------------" << std::endl;
	{
		unique_ptr<Pasare> uniquePasare1(createPasareInstance()); //modul asta e deprecated
														   //exista unique_ptr in loc
		uniquePasare1->printAripi();
		unique_ptr<Pasare> uniquePasare2=move(uniquePasare1);

		uniquePasare2->printAripi();
		//uniquePasare1->printAripi();
		//pasare1->printAripi();
		//un unique_ptr nu o sa poata sa fie copiat;
		//daca incercam sa facem copierea, cum am vazut la auto_ptr,
		//o sa ni se spuna ca nu ne putem folosi de respectiva copiere(de acel
		//copy-constructor--it is a deleted function (ca atunci cand marcam
		//o functie cu =deleted))
		//daca nuu putem sa facem copierea, noi, totusi, putem sa facem partea de move
		//move o sa faca explicit transferul de ownership, 
	}
	std::cout << "-----------Folosirea lui shared_ptr-------------" << std::endl;
	{
		shared_ptr<Pasare> sharedPasare1(createPasareInstance()); //modul asta e deprecated
														   //exista unique_ptr in loc
		sharedPasare1->printAripi();
		std::cout << "sharedPasare1 count = " << sharedPasare1.use_count() << std::endl;
		shared_ptr<Pasare> sharedPasare2(sharedPasare1);
		std::cout << "sharedPasare1 count = " << sharedPasare1.use_count() << std::endl;
		sharedPasare2->printSunet();
		sharedPasare2->setSunet("BlaBla");
		sharedPasare1->printSunet();

		shared_ptr<Pasare> sharedPasare3 = move(sharedPasare1);
		//cand am facut aici schimbarea de ownership, sharedPasare1 o sa ddevina
		//null, iar sharedPasare3 o sa contina proprietatile lui sharedPasare1

		//dupa operatia de move, count-ul lui sharedPasare devine 0(ceea ce
		//inseamna ca obiectul nostru poate fi sters acum)
		//sharedPasare1 nu are zona de memorie null, ci doar pointeaza catre
		//null(nu se sterge zona de memorie)

		//daca incerci sa apelezi, de exemplu, printSunet pe sharedPasare1,
		//iti va da SegmentationFault, deoarece apelezi o functie pe un obiect
		//ce nu exista(nu poti apela o functie pe null, pe nimic)

		//poti apela functiile specfice unui sharedPointer, dar nu le poti apela pe cele
		//specifice obiectului de tipul Pasare(cel care crezi tu ca sta in acest pointer)
		std::cout << "sharedPasare1 count = " << sharedPasare1.use_count() << std::endl;
		
		std::cout << "sharedPasare3 count = " << sharedPasare3.use_count() << std::endl;
		//are count-ul pe care il avea sharedPasare1 inainte
		sharedPasare3->setSunet("CriCri");
		sharedPasare3->printSunet();
		//daca facem modificari in sharedPasare3, acestea vor aparea si in
		//sharedPasare2, deoarece aceasta era o copie a lui sharedPasare1
		sharedPasare2->printSunet();

		//pentru acest caz de ptr, ne intereseaza acel user_count(), care ne 
		//va spune numarul de instante pe care le are un anume pointer
		//adica, in momentul in care noi o sa-i facem copierea, count-ul acela
		//o sa se incrementeze
	}
	std::cout << "-----------Item 13-end-------------" << std::endl;
	std::cout << "-----------Item 14-start-------------" << std::endl;
	//--------------------------------ITEM14-----------------------------------
	Rata r1(4); //se creeaza o rata
	LockRata* lockedRata = new LockRata(r1); //blocam rata
	r1.askRata(); //apelam functia asta, pentru a vedea ca s-a intamplat ceva pe rata
	delete lockedRata; //stergem obiectul de locked
	r1.askRata();
	std::cout << "Yaay, am reusit" << std::endl;
	std::cout << "-----------Item 14-end-------------" << std::endl;


}
