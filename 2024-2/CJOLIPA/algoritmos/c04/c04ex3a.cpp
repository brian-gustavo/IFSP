// Baseado no exerc�cio 3A, cap�tulo 4 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    setlocale (LC_ALL, ".1252");

    int a, b, resultado;

    std::cout << "Informe um primeiro valor: "; std::cin >> a;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe um segundo valor: "; std::cin >> b;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    if (a > b)
        resultado = a - b;
    else
        resultado = b - a;

    std::cout << "Diferen�a do maior pro menor valor = " << resultado << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
