#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> parole{"Ciao", "dal", "C++", "su", "WSL!"};
    for (const auto& p : parole) {
        std::cout << p << ' ';
    }
    std::cout << '\n';
    std::cout << "Standard C++: " << __cplusplus << '\n';
    return 0;
}
