// Baseado no exercício 4M, capítulo 3 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>
#include <cmath>

int main(void)
{
    int valor1, valor2, valor3, somaquadrados;

    std::cout << "Informe um valor: "; std::cin >> valor1;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe um segundo valor: "; std::cin >> valor2;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe um terceiro valor: "; std::cin >> valor3;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    somaquadrados = pow(valor1, 2) + pow(valor2, 2) + pow(valor3, 2);

    std::cout << "Soma dos quadrados dos valores = " << somaquadrados << std::endl;
    std::cout << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
