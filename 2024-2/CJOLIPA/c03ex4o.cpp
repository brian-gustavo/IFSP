// Baseado no exercício 4O, capítulo 3 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    int a, b, c, d, p, s;

    std::cout << "Informe o primeiro valor: "; std::cin >> a;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe o segundo valor: "; std::cin >> b;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe o terceiro valor: "; std::cin >> c;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe o quarto valor: "; std::cin >> d;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    p = a * c;
    s = b + d;

    std::cout << "Produto do primeiro e do terceiro valor = " << p << std::endl;
    std::cout << std::endl;

    std::cout << "Soma do segundo e do quarto valor = " << s << std::endl;
    std::cout << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
