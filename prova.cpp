#include <iostream>
#include <random>
using namespace std;

int main()
{
    /*  int a = 0;
     for (int i = 0; i < 10; i++)
     {
         a = a + 1;

     }
     string risultato= "risultato "+ to_string(a);
     cout << risultato  << endl;*/
    random_device rd;  // seme vero dall'hardware
    mt19937 gen(rd()); // generatore (Mersenne Twister)
    uniform_int_distribution<int> dist(1, 10);
    int n_generato = dist(gen);
    int n_indovinato;
    cout << "Indovina il numero fra 1 e 100: ";
    cin >> n_indovinato;
    if (n_generato == n_indovinato)
    {
        cout << "Bravo hai indovinato !!!";
    }
    else
    {
        if (n_generato > n_indovinato)
        {
            cout << "Il numero è maggiore di questo !";
        }
        else
        {
            cout << "Il numero è minore di questo ! ";
        }
    }

    return 0;
}