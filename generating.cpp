#include "function.h"

void generavimas(std::ofstream& in, int skaicius)
{
    std::random_device r;
    std::default_random_engine el(r());
    std::uniform_int_distribution<int> uniform_dist(1, 10);
    for (int w = 0; w < skaicius; w++)
    {
        in << "Vardas" << w << "  Pavarde" << w << "  ";
        for (int w = 0; w < 10; w++)
        {
            in << uniform_dist(el) << " ";
        }
        in << uniform_dist(el) << endl;;
    }
}