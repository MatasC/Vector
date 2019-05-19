#include"function.h"
int main()
{
	cout<<"Prasome palaukti, generuojami tekstiniai failai."<<endl;
	int skaicius = 10000;
	for (int i = 0; i < 4; i++)
	{
		std::ofstream out("mokiniai" + std::to_string(i + 1) + ".txt");
		generavimas(out, skaicius);
		out.close();
		skaicius *= 10;
	}
	cout<<"Tekstiniai failai sugeneruoti."<<endl;
}
