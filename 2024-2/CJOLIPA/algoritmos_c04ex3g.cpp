// Baseado no exerc�cio 3G, cap�tulo 4 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    setlocale (LC_ALL, ".1252");

    int a, b, c, d, r1, r2;

    std::cout << "Informe um primeiro n�mero: "; std::cin >> a;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe um segundo n�mero: "; std::cin >> b;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe um terceiro n�mero: "; std::cin >> c;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe um quarto n�mero: "; std::cin >> d;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Valores divis�veis por 2 e 3: " << std::endl << std::endl;

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
