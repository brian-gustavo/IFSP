// Baseado no exerc�cio 3O, cap�tulo 4 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    setlocale (LC_ALL, ".1252");

    int inteiro, resultado;

    std::cout << "Informe um n�mero inteiro: "; std::cin >> inteiro;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    resultado = inteiro * 2;

    if (resultado > 30)
        std::cout << "Resultado = " << resultado << std::endl << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
