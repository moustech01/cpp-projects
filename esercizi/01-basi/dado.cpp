// ESERCIZIO: lancio del dado
// Lancia un dado a 6 facce 1000 volte e conta quante volte esce ogni faccia.
// Output atteso (i numeri cambieranno a ogni esecuzione):
//   Faccia 1: 168
//   Faccia 2: 171
//   ...
//   Faccia 6: 160
//
// Compila ed esegui con:
//   g++ -std=c++17 -Wall -Wextra -o dado dado.cpp && ./dado

#include <iostream>
#include <random>

using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 6);
    int conteggi[6] = {0};
    for (int i = 1; i <= 1000; i++)
    {

        int num_generato = dist(gen);
        conteggi[num_generato-1]++;
    }
    for (size_t i = 0; i < 6; i++)
    {
        cout << "faccia: " << i+1 << " " << conteggi[i] << endl;
    }
    
    return 0;
}
