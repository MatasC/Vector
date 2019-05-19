#include "function.h"
#include "Time.h"
int main()
{
    char pasirinkimas, pasirinkimas_str;
    std::ofstream lout;
    lout.open("Laiku_suvestine.txt", std::fstream::app);
    lout << "2 strategija - Vector: " << endl;
    cout << "Ar galutini pazymi isvesti pagal mediana (m), ar pagal vidurki (v): ";
    pasirinkimas = Ivestis_kr(pasirinkimas);
    int skaicius = 10000;
    for (int i = 0; i < 4; i++)
    {
        cout << "Apdorojami " << i + 1 << "-ieji duomenys." << endl;
        vector <Studentas> studentai, blogi;
        Time laikas;
        laikas.Start_clock();
        studentai.reserve(skaicius);
        skaitymas(studentai, i, pasirinkimas);
        int ilgiausias_vardas = 6, ilgiausia_pavarde = 7;
        ilgio_nustatymas(studentai, ilgiausias_vardas, ilgiausia_pavarde);
        atrinkimas_2(studentai, blogi);
        isvedimas(studentai, blogi, ilgiausias_vardas, ilgiausia_pavarde);
        blogi.clear();
        laikas.Stop_clock();
        laikas.Get_time(lout, skaicius);
    }
    lout.close();
    cout << "Programos darbas baigtas." << endl;
}
