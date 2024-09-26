// Baseado no exercício 3L, capítulo 4 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    int valor;

    std::cout << "Insira um valor: "; std::cin >> valor;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    if (not(valor > 3))
        std::cout << valor << std::endl << std::endl;

    std::cout << "Tecle <Enter> para encerrar...";
    std::cin.get();
    return 0;
}
