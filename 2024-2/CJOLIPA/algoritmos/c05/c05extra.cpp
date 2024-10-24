// Baseado no exerc�cio extra fornecido em v�deo sobre o cap�tulo 5 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    setlocale(LC_ALL, ".1252");

    int numero, resto2, resto3;

    do
    {
        std::cout << "Insira um valor qualquer at� que a condi��o seja cumprida: "; std::cin >> numero;
        std::cin.ignore(80, '\n');
        std::cout << std::endl;

        resto2 = numero - 2 * (numero / 2);
        resto3 = numero - 3 * (numero / 3);
    }
    while (numero < 0 or resto2 == 0 or resto3 != 0);

    std::cout << "Condi��o cumprida, o valor foi " << numero << std::endl << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
