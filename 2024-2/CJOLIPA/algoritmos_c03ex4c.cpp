// Baseado no exercício 4C, capítulo 3 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>
#include <cmath>

int main(void)
{
    setlocale(LC_ALL, ".1252");

    float altura, r, volume;

    std::cout << "Informe a altura: "; std::cin >> altura;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe a área da base: "; std::cin >> r;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    volume = 3.14159 * pow(r, 2) * altura;

    std::cout << "Volume da lata = " << volume << std::endl;
    std::cout << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
