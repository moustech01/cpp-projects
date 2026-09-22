#include <iostream>
using namespace std;


string saluta(string& saluto){
    return saluto;
} 
int main()
{
    /*char a;
    cin >> a;
    cout << a << std::endl;*/
    string saluto = "ciao";
   cout << saluta(saluto) << endl;
    return 0;
}




