// Baseado no exercício extra fornecido em vídeo sobre o capítulo 5 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    setlocale(LC_ALL, ".1252");

    int numero, resto2, resto3;

    do
    {
        std::cout << "Insira um valor qualquer até que a condição seja cumprida: "; std::cin >> numero;
        std::cin.ignore(80, '\n');
        std::cout << std::endl;

        resto2 = numero - 2 * (numero / 2);
        resto3 = numero - 3 * (numero / 3);
    }
    while (numero < 0 or resto2 == 0 or resto3 != 0);

    std::cout << "Condição cumprida, o valor foi " << numero << std::endl << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
