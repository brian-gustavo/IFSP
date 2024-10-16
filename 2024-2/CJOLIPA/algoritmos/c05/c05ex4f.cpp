// Baseado no exercício 4F, capítulo 5 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    int resto, numero = 1;

    do
        {
            resto = numero - 4 * (numero / 4);
            if (resto == 0)
                std::cout << numero << std::endl;
            numero++;
        }
    while (not(numero > 200));

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
