#include <iostream>

void compras (int a, int b)
{
    int precototal, quantidadeA, quantidadeB;
    bool certificador = true;

    std::cout << "Quantas unidades do produto A deseja? ";
    while (certificador == true)
    {
        std::cin >> quantidadeA;
        std::cin.ignore(80, '\n');

        if (quantidadeA < 0)
            std::cout << "Insira um valor válido. ";
        else
            certificador = false;
    }

    certificador = true;

    std::cout << "Quantas unidades do produto B deseja? ";
    while (certificador == true)
    {
        std::cin >> quantidadeB;
        std::cin.ignore(80, '\n');

        if (quantidadeB < 0)
            std::cout << "Insira um valor válido. ";
        else
            certificador = false;
    }

    if (quantidadeA == 0 and quantidadeB == 0)
    {
        std::cout << std::endl << "Compra inválida. ";
    }
    else if (quantidadeA > 0 and quantidadeB == 0)
        precototal = quantidadeA * a * 0.9;
    else if (quantidadeB > 0 and quantidadeA == 0)
        precototal = quantidadeB * b * 0.9;
    else
        precototal = ((quantidadeA * a) + (quantidadeB * b)) * 0.85;

    std::cout << std::endl;
    std::cout << "O valor total das compras é " << precototal << " reais." << std::endl;
}

int main(void)
{
    setlocale(LC_ALL, ".1252");

    int produtoA = 10, produtoB = 20;

    compras(produtoA, produtoB);

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
