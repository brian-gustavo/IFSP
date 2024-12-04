// Baseado no exercício 2M, capítulo 10 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

void modulo(int valor)
{
   if (valor > 0)
      std::cout << "Número inserido, em módulo = " << valor << std::endl;
   else
   {
      valor -= (2 * valor);
      std::cout << "Número inserido, em módulo = " << valor << std::endl;
   }
}

int main(void)
{
    setlocale(LC_ALL, ".1252");

    int numero;

    std::cout << "Insira um número: "; std::cin >> numero;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    modulo(numero);

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
