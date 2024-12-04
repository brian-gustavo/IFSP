// Baseado no exercício 4E, capítulo 10 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>
#include <cmath>

int somaquadrados(int valor1, int valor2, int valor3)
{
   int resultado;

   resultado = pow(valor1, 2) + pow(valor2, 2) + pow(valor3, 2);

   return resultado;
}

int main(void)
{
    int numero1, numero2, numero3;

    std::cout << "Insira um primeiro valor: "; std::cin >> numero1;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Insira um segundo valor: "; std::cin >> numero2;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Insira um terceiro valor: "; std::cin >> numero3;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Soma dos quadrados dos valores = " << somaquadrados(numero1, numero2, numero3) << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
