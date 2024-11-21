// Baseado no exercício 3B, capítulo 4 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    setlocale(LC_ALL, ".1252");

    int n;

    std::cout << "Informe um valor: "; std::cin >> n;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    if (n < 0)
        n = n * (-1);

    std::cout << "Valor fornecido, em módulo = " << n << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
