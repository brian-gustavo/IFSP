// Baseado no exercício 4D, capítulo 5 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    setlocale(LC_ALL, ".1252");

    int resto, soma = 0, contador = 1;

    do
    {
        resto = contador - 2 * (contador / 2);
        if (resto == 0)
            soma += contador;
        contador++;
    }
    while (not(contador > 500));

    std::cout << "Somatório dos valores pares entre 1 e 500 = " << soma;
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
