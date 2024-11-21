/*
    Baseado no exercício 3M, capítulo 4 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.
    Optei por não usar o comando "toupper" neste exercício por necessitar de laço, que é de um capítulo posterior.
*/

#include <iostream>

int main(void)
{
    setlocale(LC_ALL, ".1252");

    char nome[15], sexo;

    std::cout << "Insira seu primeiro nome: "; std::cin >> nome;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Insira seu sexo (M ou F, atentando ao uso de letra maiúscula): "; std::cin >> sexo;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    if (sexo == 'M' or sexo == 'F')
    {
        if (sexo == 'M')
            std::cout << "Ilmo Sr. " << nome << std::endl << std::endl;
        else
            std::cout << "Ilma Sra. " << nome << std::endl << std::endl;
    }
    else
        std::cout << "Sexo informado inválido." << std::endl << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
