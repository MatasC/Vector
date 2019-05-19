#include "function.h"
int main()
{
	vector <Studentas> bandom_nx, bandom_px;
	int vard = 0, pavard = 0;
	char pasirinkimas = 'v';
	skaitymas(bandom_nx, 0 , pasirinkimas);
	cout << "size " << bandom_nx.size() << endl;
	cout << "capacity " << bandom_nx.capacity() << endl;
	cout << "last elem " << bandom_nx.back() << endl;
	cout << endl << "Ilgio nustatymas: " << endl;
	ilgio_nustatymas(bandom_nx, vard, pavard);
	cout << vard << " " << pavard << endl;
	cout << endl << "Atrinkimas: " << endl;
	atrinkimas_2(bandom_nx, bandom_px);
	cout << endl << "Spausdinimas: " << endl;
	isvedimas(bandom_nx, bandom_px, vard, pavard);
	cout << "done." << endl;
}