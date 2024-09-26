// Baseado no exercício 4G, capítulo 3 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    int valor_a, valor_b, valor_c, valor_d;
    int resultado1, resultado2, resultado3, resultado4, resultado5, resultado6, resultado7, resultado8, resultado9, resultado10, resultado11, resultado12;

    std::cout << "Informe um valor A: "; std::cin >> valor_a;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe um valor B: "; std::cin >> valor_b;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe um valor C: "; std::cin >> valor_c;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe um valor D: "; std::cin >> valor_d;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    resultado1 = valor_a + valor_b;
    resultado2 = valor_a + valor_c;
    resultado3 = valor_a + valor_d;
    resultado4 = valor_b + valor_c;
    resultado5 = valor_b + valor_d;
    resultado6 = valor_c + valor_d;
    resultado7 = valor_a * valor_b;
    resultado8 = valor_a * valor_c;
    resultado9 = valor_a * valor_d;
    resultado10 = valor_b * valor_c;
    resultado11 = valor_b * valor_d;
    resultado12 = valor_c * valor_d;

    std::cout << "Resultados:" << std::endl;
    std::cout << "A + B = " << resultado1 << std::endl;
    std::cout << "A + C = " << resultado2 << std::endl;
    std::cout << "A + D = " << resultado3 << std::endl;
    std::cout << "B + C = " << resultado4 << std::endl;
    std::cout << "B + D = " << resultado5 << std::endl;
    std::cout << "C + D = " << resultado6 << std::endl;
    std::cout << "A * B = " << resultado7 << std::endl;
    std::cout << "A * C = " << resultado8 << std::endl;
    std::cout << "A * D = " << resultado9 << std::endl;
    std::cout << "B * C = " << resultado10 << std::endl;
    std::cout << "B * D = " << resultado11 << std::endl;
    std::cout << "C * D = " << resultado12 << std::endl;
    std::cout << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
