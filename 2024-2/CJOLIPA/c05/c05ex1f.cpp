// Baseado no exercício 1F, capítulo 5 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    int resto, numero = 1;

    while (numero < 200)
    {
        resto = numero - 4 * (numero / 4);
        if (resto == 0)
            std::cout << numero << std::endl;
        numero++;
    }

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
