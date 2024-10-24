// Baseado no exercício 6E, capítulo 5 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    int resto;

    for (int numero = 0; numero <= 20; ++numero)
    {
        resto = numero - 2 * (numero / 2);
        if (resto != 0)
            std::cout << numero << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
