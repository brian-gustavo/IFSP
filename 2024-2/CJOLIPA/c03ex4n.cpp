// Baseado no exercício 4N, capítulo 3 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>
#include <cmath>

int main(void)
{
    int valor1, valor2, valor3, valor_final;

    std::cout << "Informe um valor: "; std::cin >> valor1;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe um segundo valor: "; std::cin >> valor2;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe um terceiro valor: "; std::cin >> valor3;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    valor_final = pow((valor1 + valor2 + valor3), 2);

    std::cout << "Quadrado da soma dos valores = " << valor_final << std::endl;
    std::cout << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
