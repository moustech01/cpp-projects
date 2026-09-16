# C++ — Concetti fondamentali e parole chiave

> Guida di riferimento per Programmazione 1. Leggila una volta per intero, poi torna qui ogni volta che incontri qualcosa che non ricordi. Non serve memorizzare tutto subito: le cose si fissano scrivendo codice.

---

## Parte 1 — Concetti generali

### 1.1 Cos'è il C++
Il C++ è un linguaggio **compilato**: il codice che scrivi (file `.cpp`) viene tradotto da un programma chiamato *compilatore* (`g++`) in un file eseguibile che la macchina esegue direttamente. Questo lo rende veloce, ma significa anche che molti errori vengono scoperti **prima** di eseguire il programma (errori di compilazione) e altri solo **durante** l'esecuzione (errori a runtime, es. accesso fuori da un array).

```
hello.cpp  --[g++]-->  hello  --[esecuzione]-->  output
```

Comando base per compilare:
```bash

./hello
```
- `-Wall -Wextra` attiva gli avvisi: **usali sempre**, ti segnalano errori logici prima dell'esame.

### 1.2 Struttura di un programma
```cpp
#include <iostream>      // 1. inclusione delle librerie che servono
using namespace std;     // 2. (opzionale) evita di scrivere std:: ogni volta

int main() {             // 3. punto di ingresso: l'esecuzione parte da qui
    cout << "Ciao" << endl;
    return 0;            // 4. 0 = "tutto ok" al sistema operativo
}
```
- Ogni istruzione termina con `;`.
- Le graffe `{ }` delimitano un **blocco** di codice.
- `//` commento su una riga, `/* ... */` commento su più righe.

### 1.3 Variabili e tipi
Una **variabile** è un contenitore con un nome, un tipo e un valore. In C++ il tipo è fisso: una variabile `int` conterrà sempre e solo interi (*tipizzazione statica*).

```cpp
int eta = 20;            // dichiarazione + inizializzazione
double prezzo = 9.99;
char lettera = 'A';      // apici singoli per i char
bool acceso = true;
string nome = "Mario";   // doppi apici per le stringhe (serve #include <string>)
```

**Regola d'oro: inizializza sempre le variabili.** Una variabile non inizializzata contiene spazzatura, e questo è una delle fonti di errore più comuni.

| Tipo | Cosa contiene | Esempio | Dimensione tipica |
|---|---|---|---|
| `int` | interi | `42`, `-7` | 4 byte |
| `long long` | interi grandi | `10000000000` | 8 byte |
| `double` | numeri decimali | `3.14` | 8 byte |
| `float` | decimali (meno precisi) | `3.14f` | 4 byte |
| `char` | un singolo carattere | `'a'` | 1 byte |
| `bool` | vero/falso | `true`, `false` | 1 byte |
| `string` | testo (libreria) | `"ciao"` | variabile |

Attenzione alle **divisioni tra interi**: `7 / 2` fa `3`, non `3.5`. Per avere il decimale serve almeno un `double`: `7.0 / 2` oppure `7 / 2.0`. Il resto si ottiene con `%`: `7 % 2` fa `1`.

### 1.4 Input e output
```cpp
int n;
cout << "Inserisci un numero: ";   // << "manda verso" lo schermo
cin >> n;                          // >> "prende da" tastiera
cout << "Hai scritto " << n << endl;
```
- `endl` va a capo (equivale a `'\n'`).
- `cin >> s` con una `string` legge **una sola parola**. Per leggere una riga intera: `getline(cin, s);`.

### 1.5 Operatori

| Categoria | Operatori | Note |
|---|---|---|
| Aritmetici | `+ - * / %` | `%` = resto della divisione, solo tra interi |
| Assegnazione | `= += -= *= /= %=` | `x += 3` equivale a `x = x + 3` |
| Incremento | `++ --` | `i++` aumenta di 1 |
| Confronto | `== != < > <= >=` | **`==` confronta, `=` assegna** (errore classico!) |
| Logici | `&& \|\| !` | AND, OR, NOT |

### 1.6 Controllo del flusso
Il programma normalmente esegue le istruzioni dall'alto verso il basso. Le strutture di controllo cambiano questo ordine.

**Selezione** — scegliere cosa fare:
```cpp
if (voto >= 18) {
    cout << "Promosso";
} else if (voto >= 15) {
    cout << "Recupero";
} else {
    cout << "Bocciato";
}
```

**Iterazione** — ripetere:
```cpp
for (int i = 0; i < 10; i++) { ... }   // sai quante volte ripetere
while (n > 0) { ... }                   // ripeti finché la condizione è vera
do { ... } while (cond);                // come while, ma esegue almeno una volta
```

### 1.7 Funzioni
Una funzione è un blocco di codice con un nome, che riceve **parametri** e (opzionalmente) **restituisce** un valore. Servono a scomporre un problema in pezzi piccoli e riutilizzabili.

```cpp
// tipo_ritorno nome(parametri)
int somma(int a, int b) {
    return a + b;
}

int main() {
    int r = somma(3, 4);   // chiamata: r vale 7
}
```

**Passaggio per valore vs per riferimento** (concetto chiave d'esame):
```cpp
void raddoppia_val(int x)  { x = x * 2; }   // lavora su una COPIA: l'originale non cambia
void raddoppia_ref(int& x) { x = x * 2; }   // lavora sull'ORIGINALE grazie a &

int n = 5;
raddoppia_val(n);  // n vale ancora 5
raddoppia_ref(n);  // n ora vale 10
```

**Ricorsione**: una funzione che chiama se stessa. Serve sempre un *caso base* che ferma la ricorsione.
```cpp
int fattoriale(int n) {
    if (n <= 1) return 1;            // caso base
    return n * fattoriale(n - 1);    // passo ricorsivo
}
```

### 1.8 Scope (visibilità)
Una variabile esiste solo dentro il blocco `{ }` in cui è dichiarata. Dichiarata dentro un `for` o una funzione, sparisce quando il blocco finisce. Le variabili **globali** (fuori da ogni funzione) sono visibili ovunque, ma vanno evitate: rendono il codice difficile da capire.

### 1.9 Array e stringhe
Un **array** è una sequenza di elementi dello stesso tipo, di dimensione fissa, con indici che partono da **0**.
```cpp
int v[5] = {10, 20, 30, 40, 50};
cout << v[0];      // 10  (primo elemento)
cout << v[4];      // 50  (ultimo elemento: dimensione - 1)
v[5] = 1;          // ERRORE: fuori dai limiti! Il compilatore non ti avvisa.
```
Il C++ **non controlla** gli indici: uscire dall'array è un errore a runtime dal comportamento imprevedibile. Questo è il motivo per cui in pratica si preferisce `vector`.

**Matrici** (array bidimensionali): `int m[3][4];` → 3 righe, 4 colonne, `m[riga][colonna]`.

**`vector`** — l'array "moderno", che sa la propria dimensione e può crescere:
```cpp
#include <vector>
vector<int> v = {1, 2, 3};
v.push_back(4);         // aggiunge in fondo → {1,2,3,4}
v.size();               // 4
v[0];                   // 1
v.at(10);               // lancia un errore se fuori limiti (v[10] no!)
```

**`string`**:
```cpp
string s = "ciao";
s.length();             // 4 (anche s.size())
s[0];                   // 'c'
s + " mondo";           // concatenazione → "ciao mondo"
s == "ciao";            // confronto → true
s.substr(1, 2);         // "ia"  (da indice 1, lunghezza 2)
```

### 1.10 Puntatori e memoria
Ogni variabile occupa una posizione in memoria, che ha un **indirizzo**. Un **puntatore** è una variabile che contiene un indirizzo.

```cpp
int x = 10;
int* p = &x;    // & = "indirizzo di": p contiene l'indirizzo di x
cout << *p;     // * = "valore puntato": stampa 10
*p = 20;        // modifica x tramite il puntatore: ora x vale 20
```

Due simboli, due significati a seconda del contesto:
- `&x` → indirizzo di `x`; `int& r = x` → riferimento (alias) di `x`.
- `int* p` → dichiara un puntatore; `*p` → accede al valore puntato.

`nullptr` è il puntatore "che non punta a niente". Dereferenziare un `nullptr` fa crashare il programma.

**Memoria dinamica** — allocare memoria a runtime, quando la dimensione non è nota in anticipo:
```cpp
int* arr = new int[n];   // crea un array di n interi nello heap
// ... uso ...
delete[] arr;            // OBBLIGATORIO liberare, altrimenti memory leak
arr = nullptr;
```
- Regola: ogni `new` ha il suo `delete`, ogni `new[]` ha il suo `delete[]`.

Stack vs Heap:
- **Stack**: variabili locali, gestite automaticamente, veloci, dimensione fissa.
- **Heap**: memoria richiesta con `new`, gestita da te, dimensione decisa a runtime.

**Array e puntatori**: il nome di un array è (quasi) un puntatore al suo primo elemento. Per questo quando passi un array a una funzione devi passare anche la dimensione:
```cpp
void stampa(int v[], int n) { for (int i = 0; i < n; i++) cout << v[i]; }
```

### 1.11 Struct e classi
Una **struct** raggruppa dati diversi in un unico tipo:
```cpp
struct Studente {
    string nome;
    int matricola;
    double media;
};

Studente s;
s.nome = "Anna";
s.matricola = 12345;
```

Una **classe** aggiunge alla struct l'idea di **incapsulamento**: i dati sono nascosti (`private`) e si accede solo tramite funzioni (`public`), chiamate *metodi*.
```cpp
class ContoBancario {
private:
    double saldo;                       // nessuno può toccarlo direttamente

public:
    ContoBancario() : saldo(0) {}       // costruttore: inizializza l'oggetto
    void deposita(double x) { saldo += x; }
    double getSaldo() const { return saldo; }   // const: non modifica l'oggetto
};

ContoBancario c;
c.deposita(100);
cout << c.getSaldo();   // 100
```
- **Costruttore**: funzione con lo stesso nome della classe, chiamata quando l'oggetto viene creato.
- **Distruttore** `~ContoBancario()`: chiamato quando l'oggetto muore, serve per liberare memoria allocata con `new`.
- `struct` e `class` sono identiche tranne il default: `struct` è `public`, `class` è `private`.

Con i puntatori a oggetti si usa `->` invece di `.`:
```cpp
Studente* p = new Studente;
p->nome = "Luca";      // equivale a (*p).nome
delete p;
```

### 1.12 Strutture dati classiche (spesso all'esame)
Con struct + puntatori si costruiscono le **liste concatenate**:
```cpp
struct Nodo {
    int valore;
    Nodo* next;     // puntatore al nodo successivo (nullptr se è l'ultimo)
};
```
Da qui derivano **pila** (stack: LIFO, ultimo entrato primo uscito), **coda** (queue: FIFO) e **alberi**.

### 1.13 File
```cpp
#include <fstream>
ifstream in("dati.txt");     // file in lettura
ofstream out("ris.txt");     // file in scrittura
int x;
while (in >> x) { out << x * 2 << endl; }   // legge finché ci sono numeri
in.close(); out.close();
```

### 1.14 Errori tipici da evitare
1. `=` al posto di `==` dentro un `if`.
2. Variabili non inizializzate.
3. Indice fuori dall'array (`v[n]` quando la dimensione è `n`).
4. Divisione tra interi quando serviva un decimale.
5. `;` dopo `if (...)` o `for (...)` → il blocco sotto viene sempre eseguito.
6. Dimenticare il caso base nella ricorsione → stack overflow.
7. `new` senza `delete` → memory leak.
8. Usare un puntatore dopo il `delete` (dangling pointer).
9. Ciclo `while` in cui la condizione non cambia mai → ciclo infinito.
10. Passare per valore quando volevi modificare l'originale.

---

## Parte 2 — Parole chiave (keyword)

Le parole chiave sono riservate: non puoi usarle come nomi di variabili. Qui sotto quelle che **devi** conoscere, divise per gruppo. In grassetto quelle indispensabili per Programmazione 1.

### Tipi fondamentali
| Keyword | Funzione |
|---|---|
| **`int`** | numero intero |
| **`double`** | numero decimale a doppia precisione |
| `float` | numero decimale a singola precisione (meno usato) |
| **`char`** | singolo carattere (internamente è un piccolo intero: `'A'` = 65) |
| **`bool`** | valore logico `true` / `false` |
| **`void`** | "nessun tipo": per funzioni che non restituiscono niente |
| `long`, `short` | modificano la dimensione di `int` (`long long` per interi molto grandi) |
| `unsigned` | solo valori ≥ 0, raddoppia il massimo rappresentabile |
| `signed` | con segno (default, si omette) |
| **`auto`** | il compilatore deduce il tipo dall'inizializzazione: `auto x = 3.5;` → `double` |

### Valori letterali
| Keyword | Funzione |
|---|---|
| **`true`**, **`false`** | i due valori di `bool` |
| **`nullptr`** | puntatore nullo (non usare `NULL` o `0`) |

### Controllo del flusso
| Keyword | Funzione |
|---|---|
| **`if`**, **`else`** | esecuzione condizionale |
| **`switch`**, **`case`**, **`default`** | selezione multipla su un valore intero/char; ogni `case` finisce con `break` |
| **`for`** | ciclo con contatore |
| **`while`** | ciclo con condizione controllata prima |
| **`do`** | `do { } while (cond);` — condizione controllata dopo, esegue almeno una volta |
| **`break`** | esce immediatamente dal ciclo o dallo `switch` |
| **`continue`** | salta al prossimo giro del ciclo |
| **`return`** | termina la funzione e restituisce un valore |
| `goto` | salto incondizionato — **non usarlo mai** |

### Funzioni e variabili
| Keyword | Funzione |
|---|---|
| **`const`** | valore che non può cambiare: `const int MAX = 100;`. Su un parametro (`const string& s`) significa "lo leggo ma non lo modifico" |
| `constexpr` | costante calcolata a tempo di compilazione |
| `static` | dentro una funzione: la variabile sopravvive tra le chiamate; in una classe: condivisa tra tutti gli oggetti |
| `inline` | suggerisce al compilatore di espandere la funzione sul posto (ottimizzazione) |
| `extern` | dichiara una variabile definita in un altro file |
| **`sizeof`** | dimensione in byte di un tipo o variabile: `sizeof(int)` → 4 |

### Memoria e puntatori
| Keyword | Funzione |
|---|---|
| **`new`** | alloca memoria nello heap, restituisce un puntatore |
| **`delete`** | libera la memoria allocata con `new` (`delete[]` per gli array) |
| **`this`** | dentro un metodo, puntatore all'oggetto corrente |

### Tipi definiti dall'utente
| Keyword | Funzione |
|---|---|
| **`struct`** | tipo aggregato con membri pubblici di default |
| **`class`** | tipo aggregato con membri privati di default |
| **`public`** | membri accessibili da fuori |
| **`private`** | membri accessibili solo dentro la classe |
| `protected` | come `private`, ma accessibile dalle classi derivate |
| `enum` | insieme di costanti con nome: `enum Colore { ROSSO, VERDE, BLU };` (meglio `enum class`) |
| `union` | membri che condividono la stessa memoria (raro) |
| `typedef`, **`using`** | dare un alias a un tipo: `using Matrice = vector<vector<int>>;` |
| `friend` | dà a una funzione/classe esterna accesso ai membri privati |
| `virtual` | metodo che può essere ridefinito nelle classi derivate (polimorfismo) |
| `override` | segnala che stai ridefinendo un metodo `virtual` |
| `operator` | ridefinisce un operatore per la tua classe: `operator+`, `operator==` |
| `explicit` | impedisce conversioni implicite tramite costruttore |

### Namespace e template
| Keyword | Funzione |
|---|---|
| **`namespace`** | raggruppa nomi per evitare conflitti; `std` è quello della libreria standard |
| **`using`** | `using namespace std;` rende visibili i nomi di `std` senza prefisso |
| `template`, `typename` | funzioni/classi generiche su qualunque tipo (`vector<int>` è un template) |

### Eccezioni
| Keyword | Funzione |
|---|---|
| `try` | blocco in cui possono verificarsi errori |
| `throw` | lancia un'eccezione |
| `catch` | gestisce l'eccezione lanciata |
| `noexcept` | promette che la funzione non lancia eccezioni |

### Conversioni (cast)
| Keyword | Funzione |
|---|---|
| **`static_cast<T>(x)`** | conversione esplicita e sicura: `static_cast<double>(7) / 2` → `3.5` |
| `const_cast`, `reinterpret_cast`, `dynamic_cast` | cast speciali (avanzati) |

### Non sono keyword, ma vanno saputi
Questi vengono dalla libreria standard (`std`), non sono parole del linguaggio, ma li userai ogni giorno:

| Nome | Header | Funzione |
|---|---|---|
| `cout`, `cin`, `endl` | `<iostream>` | output, input, a capo |
| `string`, `getline` | `<string>` | stringhe e lettura di una riga |
| `vector` | `<vector>` | array dinamico |
| `ifstream`, `ofstream` | `<fstream>` | file in lettura/scrittura |
| `sqrt`, `pow`, `abs` | `<cmath>` | funzioni matematiche |
| `sort`, `max`, `min`, `swap` | `<algorithm>` | algoritmi pronti |
| `setw`, `setprecision`, `fixed` | `<iomanip>` | formattazione dell'output |
| `size_t` | — | tipo intero senza segno restituito da `.size()` |
| `main` | — | la funzione di ingresso (non è una keyword ma è obbligatoria) |

---

## Parte 3 — Simboli da riconoscere a colpo d'occhio

| Simbolo | Significati |
|---|---|
| `&` | indirizzo-di (`&x`), riferimento (`int& r`), AND bit a bit |
| `*` | moltiplicazione, dichiarazione puntatore (`int* p`), dereferenziazione (`*p`) |
| `->` | accesso a membro tramite puntatore (`p->nome`) |
| `.` | accesso a membro tramite oggetto (`s.nome`) |
| `::` | risoluzione di ambito: `std::cout`, `Classe::metodo` |
| `<<` `>>` | stream (output/input); anche shift di bit |
| `[]` | indice di array |
| `{}` | blocco di codice; inizializzazione (`int x{5};`) |
| `?:` | operatore ternario: `(a > b) ? a : b` = "se a>b allora a altrimenti b" |
| `#` | direttiva per il preprocessore (`#include`, `#define`) |

---

## Come usare questo documento
- **Ora**: leggilo tutto, senza preoccuparti di capire ogni dettaglio.
- **Durante lo studio**: ogni fase del piano approfondisce una sezione; torna qui per ripassare.
- **Prima dell'esame**: rileggi la sezione 1.14 (errori tipici) e le keyword in grassetto.
