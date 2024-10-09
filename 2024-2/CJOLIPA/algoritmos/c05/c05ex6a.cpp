// Baseado no exercício 6A, capítulo 5 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>
#include <cmath>

int main(void)
{
    int quadrado;

    for (int inteiro = 15; inteiro <= 200; ++inteiro)
        {
            quadrado = pow(inteiro, 2);
            std::cout << quadrado << std::endl;
        }

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
