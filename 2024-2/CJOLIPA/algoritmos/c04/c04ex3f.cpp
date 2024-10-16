// Baseado no exercício 3F, capítulo 4 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    int a, b, c, trocador;

    std::cout << "Informe um primeiro valor: "; std::cin >> a;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe um segundo valor: "; std::cin >> b;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe um terceiro valor: "; std::cin >> c;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    if (a > b)
    {
        trocador = a;
        a = b;
        b = trocador;
    }

    if (a > c)
    {
        trocador = a;
        a = c;
        c = trocador;
    }

    if (b > c)
    {
        trocador = b;
        b = c;
        c = trocador;
    }

    std::cout << "Valores em ordem crescente = " << a << ", " << b << ", " << c;
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
