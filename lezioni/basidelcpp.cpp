#include <iostream>
using namespace std;
#include <limits>

int main() {

  char chars[4]; // 3 caratteri + '\0'

  // se prima hai usato cin >> ..., scarta il resto della riga
 // cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int i = 0; i < 3; i++) {
    int c = cin.get(); // int, non char
    if (c == EOF) {
      cout << "Input terminato" << endl;
      return 1;
    }
    chars[i] = c;
  }
  chars[3] = '\0';

  // scarta quello che resta della riga (compreso il \n)
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  cout << chars << endl;
  return 0;
}
