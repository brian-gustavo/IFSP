// Baseado no exerc�cio 4P, cap�tulo 5 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    setlocale(LC_ALL, ".1252");

    int resto, contador = 0, soma = 0, numero = 50;
    float media;


    do
        {
            resto = numero - 2 * (numero / 2);
            if (resto == 0)
            {
                contador++;
                soma += numero;
            }
            numero++;
        }
    while (not(numero > 70));

    media = soma / contador;

    std::cout << "Somat�rio dos valores = " << soma << std::endl;
    std::cout << "M�dia dos valores = " << media << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
