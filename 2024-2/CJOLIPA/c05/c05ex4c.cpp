// Baseado no exercício 4C, capítulo 5 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    setlocale(LC_ALL, ".1252");

    int soma = 0, contador = 1;

    do
    {
        soma += contador;
        contador++;
    }
    while (not(contador > 100));

    std::cout << "Somatório dos 100 primeiros números naturais = " << soma;
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
