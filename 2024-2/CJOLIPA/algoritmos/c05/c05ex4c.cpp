// Baseado no exerc�cio 4C, cap�tulo 5 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

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

    std::cout << "Somat�rio dos 100 primeiros n�meros naturais = " << soma;
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
