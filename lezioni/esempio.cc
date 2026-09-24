#include <iostream>
using namespace std;

string saluta(string &saluto)
{
    return saluto;
}
int main()
{
    /*char a;
    cin >> a;
    cout << a << std::endl;*/
    // string saluto = "ciao";
    // cout << saluta(saluto) << endl;
    /*bool y= (0==0);
     int a=7;
     int b=3;
     float x=7/3;
  */
    /* char lettera;
    cout << "inserisci una lettera " << endl;
    cin >> lettera;
bool is_valid= (int)(lettera)>=97 && (int)(lettera)<=122 || (int)(lettera) >=65 && (int)(lettera)<=90;
*/

// cout << (char)(lettera - 32) << endl;
//cout << is_valid  << endl;

// soluzione 
/*char din, dout;
int vin, vout;
int diff ='a'- 'A';
bool flag;
cout << "Inseriasci maiuscola o minuscola: ";
cin >> din;
flag=(din<'a');
dout = (din+diff)*flag + (din - diff)*(1-flag);
bool valido = (din>='A' && din<='Z') || (din>= 'a' && din <='z');
dout = dout*valido   + '?'*(1-valido);
cout << din << "->" << dout << endl;*/

// altro esercizio
int secondi;
cout << "Inserisci i secondi da mezzanotte ";
cin >> secondi;
int o, min,sec;
o = secondi / 3600;
min = (secondi % 3600) / 60; 
sec =secondi% 60;

cout << "ore: " << o << " minuti: " << min << " secondi: " << sec << endl;

    return 0;
}
