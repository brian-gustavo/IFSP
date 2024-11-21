// Baseado no exercício 3E, capítulo 10 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>
#include <string>

void paridade(int valor, std::string &resultado)
{
   int resto;

   resto = valor - 2 * (valor / 2);

   if (resto == 0)
    resultado = "O número inserido é par.";
   else
    resultado = "O número inserido é ímpar.";
}

int main(void)
{
    setlocale(LC_ALL, ".1252");

    int numero;
    std::string resultado;

    std::cout << "Insira um valor: "; std::cin >> numero;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    paridade(numero, resultado);

    std::cout << resultado << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
