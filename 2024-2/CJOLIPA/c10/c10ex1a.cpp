#include <iostream>
#include <string>

struct registro
{
    std::string nome, endereco, telefone;
};

registro pessoa[10];

void cadastraRegistros(void)
{
    std::cout << std::endl << "Cadastro de pessoas" << std::endl << std::endl;

    for (int i = 0; i <= 9; ++i)
    {
        std::cout << "Entre " << i + 1 << "o. nome: ";
        getline(std::cin, pessoa[i].nome);

        std::cout << "Entre " << i + 1 << "o. endereço: ";
        getline(std::cin, pessoa[i].endereco);

        std::cout << "Entre " << i + 1 << "o. telefone: ";
        getline(std::cin, pessoa[i].telefone);

        std::cout << std::endl;
    }
}

void pesquisaRegistros(void)
{
    std::string pesq;

    std::cout << std::endl << "Insira nome que deseja pesquisar: ";
    getline(std::cin, pesq);

    for (int i = 0; i <= 9; ++i)
    {
        if (pessoa[i].nome == pesq)
        {
            std::cout << std::endl;
            std::cout << pessoa[i].nome << std::endl;
            std::cout << pessoa[i].endereco << std::endl;
            std::cout << pessoa[i].telefone << std::endl;
            std::cout << std::endl;
            return;
        }
    }

    std::cout << "Nome não encontrado." << std::endl << std::endl;
}

void ordemAlfabetica(void)
{
    registro trocador;

    for (int i = 0; i <= 9; ++i)
    {
        for (int j = i + 1; j <= 9; ++j)
        {
            if (pessoa[i].nome > pessoa[j].nome)
            {
                trocador = pessoa[i];
                pessoa[i] = pessoa[j];
                pessoa[j] = trocador;
            }
        }
    }

    std::cout << std::endl << "Agenda organizada." << std::endl << std::endl;
}

void apresentacao(void)
{
    std::cout << std::endl;
    for (int i = 0; i <= 9; ++i)
    {
        std::cout << pessoa[i].nome << std::endl;
        std::cout << pessoa[i].endereco << std::endl;
        std::cout << pessoa[i].telefone << std::endl;
        std::cout << std::endl;
    }
}

void saida(void)
{
   std::cout << std::endl << "Tecle <Enter> para encerrar... ";
   std::cin.get();
}

int main(void)
{
    setlocale(LC_ALL, ".1252");

    int opcao = 0;

    while (opcao != 5)
    {
       std::cout << "Programa criador de agendas - menu principal" << std::endl << std::endl;
       std::cout << "[1] - Cadastro das pessoas" << std::endl;
       std::cout << "[2] - Pesquisar pessoas por nome" << std::endl;
       std::cout << "[3] - Organizar a agenda em ordem alfabética" << std::endl;
       std::cout << "[4] - Apresentação da agenda" << std::endl;
       std::cout << "[5] - Encerrar programa" << std::endl;

       std::cout << std::endl << "Escolha uma opção: "; std::cin >> opcao;
       std::cin.ignore(80, '\n');

       if (opcao != 5)
       {
           switch (opcao)
           {
               case 1: cadastraRegistros();                                       break;
               case 2: pesquisaRegistros();                                       break;
               case 3: ordemAlfabetica();                                         break;
               case 4: apresentacao();                                            break;
               default: std::cout << "Opção inválida." << std::endl << std::endl; break;
           }
       }
    }

    saida();
    return 0;
}
