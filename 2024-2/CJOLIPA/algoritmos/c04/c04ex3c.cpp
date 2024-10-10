// Baseado no exercício 3C, capítulo 4 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    setlocale (LC_ALL, ".1252");

    float n1, n2, n3, n4, md;

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

    md = (n1 + n2 + n3 + n4) / 4;

    if (md >= 5)
        std::cout << "Aprovado." << std::endl << std::endl;
    else
        std::cout << "Reprovado." << std::endl << std::endl;

    std::cout << "Média = " << md << std::endl << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
