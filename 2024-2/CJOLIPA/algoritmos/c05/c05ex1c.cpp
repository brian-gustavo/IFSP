// Baseado no exerc�cio 1C, cap�tulo 5 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    setlocale(LC_ALL, ".1252");

    int soma = 0, contador = 1;

    while (contador <= 100)
    {
        soma = soma + contador;
        contador++;
    }

    std::cout << "Somat�rio dos 100 primeiros n�meros naturais = " << soma;
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
