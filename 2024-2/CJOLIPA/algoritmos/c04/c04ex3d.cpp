// Baseado no exercício 3D, capítulo 4 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    setlocale (LC_ALL, ".1252");

    float n1, n2, n3, n4, md1, md2, ne;

    std::cout << "Informe a nota do primeiro bimestre: "; std::cin >> n1;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe a nota do segundo bimestre: "; std::cin >> n2;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe a nota do terceiro bimestre: "; std::cin >> n3;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe a nota do quarto bimestre: "; std::cin >> n4;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    md1 = (n1 + n2 + n3 + n4) / 4;

    if (md1 >= 7)
        std::cout << "Aprovado com média " << md1 << std::endl << std::endl;
    else
        {
            std::cout << "Média abaixo de 7, informe a nota de exame: "; std::cin >> ne;
            std::cin.ignore(80, '\n');
            std::cout << std::endl;

            md2 = (ne + md1) / 2;

            if (md2 >= 5)
                std::cout << "Aprovado em exame, com média " << md2 << std::endl << std::endl;
            else
                std::cout << "Reprovado com média " << md2 << std::endl << std::endl;
        }

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
