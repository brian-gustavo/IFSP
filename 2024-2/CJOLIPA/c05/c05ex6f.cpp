// Baseado no exercício 6F, capítulo 5 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    int resto;

    for (int numero = 1; numero <= 199; ++numero)
    {
        resto = numero - 4 * (numero / 4);
        if (resto == 0)
            std::cout << numero << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
