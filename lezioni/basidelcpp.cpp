#include <iostream>
using namespace std;
#include <limits>

int main() {

  //  char chars[4]; // 3 caratteri + '\0'
  //
  //  // se prima hai usato cin >> ..., scarta il resto della riga
  // // cin.ignore(numeric_limits<streamsize>::max(), '\n');
  //
  //  for (int i = 0; i < 3; i++) {
  //    int c = cin.get(); // int, non char
  //    if (c == EOF) {
  //      cout << "Input terminato" << endl;
  //      return 1;
  //    }
  //    chars[i] = c;
  //  }
  //  chars[3] = '\0';
  //
  //  // scarta quello che resta della riga (compreso il \n)
  //  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  //
  //  cout << chars << endl;

  /*
   int num;
     cout << "Insersci un numero";
     if (cin >> num) {
         cout << num << endl;
     }else {
         cerr << "Errore numero" << endl;
     }
  */

  // cifra specchiata

  /*if (c >= '0' && c <= '9') {
      char s = '9' - (c - '0');
      cout << s << endl;           // stampa la cifra specchiata
  } else {
      cerr << "Non è una cifra" << endl;
  }*/
  /* if(c>='0' && c<='9'){
  char s= c - '0';
  if(s=='9'){
      cout << '0' << endl;
  }else {


  }
  cout << s << endl;
  }else {
  cerr << "Il carattere non è valido";
  } */

  // esercizio 1
  /* char c1;
    cout << "Inserisci una cifra: ";
    cin >> c1; // legge un carattere saltando spazi e a capo
    if (c1 >= '0' && c1 <= '9') {
      if (c1 == '9') {
        cout << '0' << endl;
      } else {
        char s = ('0' + 1) + (c1 - '0');

        cout << s << endl;
      }
    } */
  // esercizio 2
  /*   char c2;
  cout << "Insersici una lettera minuscola: ";
  cin >> c2;

  if (c2>=97 && c2<=122){
  char s= 'z' - (c2- 'a');
  cout << s << endl;
  }else {
  cerr << "Input non valido" << endl;
  } */

  // Leggi un numero di secondi e stampalo in ore, minuti, secondi.

  /*   int ore = 0, minuti = 0, secondi = 0;
    cout << "Inserisci un numero di secondi: ";
    if (!(cin >> secondi) || secondi < 0) {
      cerr << "Input non valido" << endl;
      return 1;
    }

    minuti = secondi / 60;
    secondi = secondi % 60;
    ore = minuti / 60;
    minuti = minuti % 60;

    cout << ore << " ore, " << minuti << " minuti, " << secondi << " secondi"
         << endl; */

  // Leggi un intero di 3 cifre e stampa la somma delle cifre
  /* int num_intero=0;
  cout << "Inserisci un numero intero di 3 cifre: ";
  cin >> num_intero;
  int prima_cifra=num_intero/100;
  int seconda_cifra=(num_intero/10)%10;
  int terza_cifra=num_intero%10;
  int somma=prima_cifra+seconda_cifra+terza_cifra;
  cout << "Somma: " << somma<< endl; */

  // Leggi un intero di 3 cifre e stampalo al contrario come numero. 472 → 274.
  // Bonus: cosa succede con 120
  /*   cout << "Inserisci un numero intero di 3 cifre: ";
    int num_intero = 0;
    cin >> num_intero;
    int num_rovesciato = 0;
    if (num_intero >= 100 && num_intero <= 999) {
      int prima_cifra = num_intero % 10;
      num_rovesciato += prima_cifra;
      int seconda_cifra = (num_intero / 10) % 10;
      num_rovesciato = (num_rovesciato * 10) + seconda_cifra;
      int terza_cifra = num_intero / 100;
      num_rovesciato = num_rovesciato * 10 + terza_cifra;

      cout << " " << num_rovesciato << endl;

    } else {
      cerr << "Intervallo non valido" << endl;
    } */

  // Leggi una lettera minuscola e stampala maiuscola senza librerie
  /*   char l;
    cout << "Inserisci una lettera minuscola: ";
    cin >> l;
    if (l >= 'a' && l <= 'z') {
      int pos = l - 'a';
      char maiuscola = 'A' + pos;
      cout << " " << maiuscola << endl;
    } else {
      cerr << "Input invalido" << endl;
    } */

  // Leggi una lettera minuscola e stampa la successiva, con 'z' che torna ad
  // 'a'. Usa %. c → d, z → a
  char lettera = 0;
  cout << "Inserisci una lettera minuscola: ";
  cin >> lettera;
  if (lettera >= 'a' && lettera <= 'z') {
    char lettera_successiva = (lettera - 'a' + 1) % 26 + 'a';
    cout << " " << lettera_successiva << endl;
  } else {
    cerr << "Input invalido" << endl;
  }
  return 0;
}
