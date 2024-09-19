// Baseado no exercício 1A, capítulo 5 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>
#include <cmath>

int main(void)
{
    int quadrado, inteiro = 15;

    while (inteiro <= 200)
        {
            quadrado = pow(inteiro, 2);
            std::cout << quadrado << std::endl << std::endl;
            inteiro++;
        }

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
