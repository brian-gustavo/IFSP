// Baseado no exerc�cio 6C, cap�tulo 5 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    setlocale(LC_ALL, ".1252");

    int soma = 0;

    for (int contador = 1; contador <= 100; ++contador)
        soma += contador;

    std::cout << "Somat�rio dos 100 primeiros n�meros naturais = " << soma;
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
