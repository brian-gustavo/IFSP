// Baseado no exercício 1E, capítulo 5 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    int resto, numero = 0;

    while (numero <= 20)
    {
        resto = numero - 2 * (numero / 2);
        if (resto != 0)
            std::cout << numero << std::endl;
        numero++;
    }

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
