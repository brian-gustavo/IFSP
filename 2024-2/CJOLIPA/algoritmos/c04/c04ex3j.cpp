// Baseado no exerc�cio 3J, cap�tulo 4 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    setlocale(LC_ALL, ".1252");

    int valor, resto;

    std::cout << "Informe um valor: "; std::cin >> valor;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    resto = valor - 2 * (valor / 2);

    if (resto == 0)
        std::cout << "Par." << std::endl;
    else
        std::cout << "�mpar." << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
