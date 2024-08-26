// Baseado no exercício 4I, capítulo 3 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>
#include <cmath>

int main(void)
{
    int numeral;

    std::cout << "Informe valor que deseja elevar ao quadrado: "; std::cin >> numeral;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Resultado = " << pow(numeral, 2) << std::endl;
    std::cout << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
