// Baseado no exerc�cio 2M, cap�tulo 10 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

void modulo(int valor)
{
   if (valor > 0)
      std::cout << "N�mero inserido, em m�dulo = " << valor << std::endl;
   else
   {
      valor -= (2 * valor);
      std::cout << "N�mero inserido, em m�dulo = " << valor << std::endl;
   }
}

int main(void)
{
    setlocale(LC_ALL, ".1252");

    int numero;

    std::cout << "Insira um n�mero: "; std::cin >> numero;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    modulo(numero);

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
