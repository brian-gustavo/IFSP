// Baseado no exercício 3G, capítulo 4 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    setlocale (LC_ALL, ".1252");

    int a, b, c, d, r1, r2;

    std::cout << "Informe um primeiro número: "; std::cin >> a;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe um segundo número: "; std::cin >> b;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe um terceiro número: "; std::cin >> c;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe um quarto número: "; std::cin >> d;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Valores divisíveis por 2 e 3: " << std::endl << std::endl;

    r1 = a - 2 * (a / 2);
    r2 = a - 3 * (a / 3);

    if (r1 == 0 and r2 == 0)
        std::cout << a << std::endl << std::endl;

    r1 = b - 2 * (b / 2);
    r2 = b - 3 * (b / 3);

    if (r1 == 0 and r2 == 0)
        std::cout << b << std::endl << std::endl;

    r1 = c - 2 * (c / 2);
    r2 = c - 3 * (c / 3);

    if (r1 == 0 and r2 == 0)
        std::cout << c << std::endl << std::endl;

    r1 = d - 2 * (d / 2);
    r2 = d - 3 * (d / 3);

    if (r1 == 0 and r2 == 0)
        std::cout << d << std::endl << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
