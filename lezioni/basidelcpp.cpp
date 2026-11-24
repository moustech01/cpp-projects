#include <iostream>
#include <ostream>
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
  /*   char lettera = 0;
    cout << "Inserisci una lettera minuscola: ";
    cin >> lettera;
    if (lettera >= 'a' && lettera <= 'z') {
      char lettera_successiva = (lettera - 'a' + 1) % 26 + 'a';
      cout << " " << lettera_successiva << endl;
    } else {
      cerr << "Input invalido" << endl;
    } */

  // Scrivi su carta cosa stampa ogni riga, poi esegui e confronta. Per ogni
  // riga sbagliata, scrivi in una frase il perché
  /*  cout << 'a' + 1 << endl;              // 98
    cout << (char)('0' + 5) << endl;      // 5
    cout << 7 / 2 * 2.0 << endl;          // 6.0
    cout << 7 / 2.0 * 2 << endl;          // 7
    cout << -7 % 3 << endl;               // -1
    cout << (3 < 2 < 1) << endl;          // 1
    cout << 'A' + 'B' << endl;            // 131 of ascii table
    cout << true + true << endl;          // 2
    double d = 1 / 3;
    cout << d << endl;                    // 0
    int k = 9.99;
    cout << k << endl;                    // 9
    bool b = -5;
    cout << b << endl;                    //  1
    int x = 5;
    int y = x++;
    int z = ++x;
    cout << x << " " << y << " " << z << endl;   // 7 - 5 - 7
    char c = 'a' + 25;
    cout << c << endl;                    // z
    cout << 10 / 3 * 3 + 10 % 3 << endl;  // 10
    cout << ('z' - 'a') << endl;   //  25 */

  // Leggi un intero e stampa il carattere P se è pari, D se è dispari, usando
  // lo schema A * cond + B * (1 - cond). Deve funzionare anche con i negativi.

  /* int num=0;
  cout << "Insersci un numero: ";
  cin >> num;
  char esito='P'*(num%2==0)+(num%2!=0)*'D';
  cout << esito << endl; */

  // Leggi un intero e stampane il valore assoluto, senza if.
  /* int num=0;
    cout << "Insersci un numero: ";
    cin >> num;
  int val_abs=((num<0)*-1)*num+(num>=0)*num;
    cout << val_abs << endl; */

  // Questo programma compila ma ha tre errori semantici. Trovali tutti, spiega
  // cosa stampa con input 17 18 e m, e correggilo.
  /*   int a, b;
    double media;
    cout << "Due voti: ";
    cin >> a >> b;
    media = (a + b) / 2; // si perde precisione perché si sta facendo divisione
                         // fra interi per calcolare una media; correzione (a +
    b) / 2.0 char c; cout << "Iniziale (minuscola): "; cin >> c; cout <<
    "Maiuscola: " << c - 32 << endl; // stampa un numero, correzione
    (char)(c-32) if (media = 18) // = assegna, l'operatore di confronto è ==
      cout << "Esattamente 18" << endl;
    cout << "Media: " << media << endl; */

  /* Leggi tre voti interi (da 0 a 30). Stampa:
  • la media con la virgola;
  • quanti voti sono sufficienti (≥ 18), senza if: sfrutta il fatto che un
  confronto vale 0 o 1; • la percentuale di voti sufficienti, con la virgola. */

  /* int voto_1=0, voto_2=0, voto_3=0;
  cout << "Inserisci 3 voti:  "<< endl;
  cin >> voto_1;
  cin >> voto_2;
  cin >> voto_3;
  if(voto_1 >=18 && voto_1<=30 && voto_2 >=18 && voto_2<=30 && voto_3 >=18 &&
  voto_3<=30){ int somma=voto_1+voto_2+voto_3; double media=somma/3.0; int
  contatore=(voto_1>=18)+(voto_2>=18)+(voto_3>=18); double
  percent=((contatore*1.0)/3)*100; cout << "Media: " << media << endl; cout <<
  "Sufficienti: " << contatore << endl; cout << "Percentuale sufficienti: " <<
  percent << endl; }else { cerr << "Range non valido";
  }
   */

  return 0;
}
