// Baseado no exercício 4A, capítulo 5 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>
#include <cmath>

int main(void)
{
    int quadrado, inteiro = 15;

    do
    {
        quadrado = pow(inteiro, 2);
        std::cout << quadrado << std::endl << std::endl;
        inteiro++;
    }
    while (not(inteiro > 200));

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
