// Baseado no exercício 3E, capítulo 4 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>
#include <cmath>

int main(void)
{
    setlocale(LC_ALL, ".1252");

    float a, b, c, delta, solucao1, solucao2;

    std::cout << "Insira um primeiro valor: "; std::cin >> a;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Insira um segundo valor: "; std::cin >> b;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Insira um terceiro valor: "; std::cin >> c;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    if (a != 0 and b != 0 and c != 0)
    {
        delta = pow(b, 2) - (4 * a * c);
        if (delta < 0)
            std::cout << "Não há solução real." << std::endl << std::endl;
        else
        {
            solucao1 = (-b + sqrt(delta)) / (2 * a);
            solucao2 = (-b - sqrt(delta)) / (2 * a);
            if (delta == 0)
                std::cout << "Solução = " << solucao1 << std::endl << std::endl;
            else
                std::cout << "Soluções = " << solucao1 << " e " << solucao2 << std::endl << std::endl;
        }
    }

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
