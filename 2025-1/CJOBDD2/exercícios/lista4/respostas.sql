-- Uso do banco de dados criado como parte do exercício 1
USE Lista04;
GO

-- Exercício 2
CREATE TABLE CLIENTES (
    Codigo_Cliente INT PRIMARY KEY,
    Nome_Cliente VARCHAR(50),
    DDD_Cliente CHAR(3),
    Telefone_Cliente VARCHAR(9),
    Saldo_Cliente DECIMAL(10, 2)
);

CREATE TABLE FORNECEDORES (
    Codigo_Fornecedor INT PRIMARY KEY,
    Nome_Fornecedor VARCHAR(35),
    Contato_Fornecedor VARCHAR(15),
    DDD_Fornecedor CHAR(3),
    Telefone_Fornecedor VARCHAR(9),
    Estado_Fornecedor CHAR(2)
);

CREATE TABLE PRODUTOS (
    Codigo_Produto VARCHAR(10) PRIMARY KEY,
    Descricao_Produto VARCHAR(35),
    Data_Estocagem_Produto DATE,
    Unidades_Disponiveis_Produto DECIMAL(9, 2),
    Valor_Unitario_Produto DECIMAL(9, 2),
    Taxa_Desconto_Produto DECIMAL(5, 2),
    Codigo_Fornecedor INT,
    CONSTRAINT FK_PRODUTOS_FORNECEDORES FOREIGN KEY (Codigo_Fornecedor) REFERENCES FORNECEDORES(Codigo_Fornecedor)
);

CREATE TABLE FATURAS (
    Numero_Fatura INT PRIMARY KEY,
    Codigo_Cliente INT,
    Data_Fatura DATE,
    Subtotal_Fatura DECIMAL(10, 2),
    Imposto_Fatura DECIMAL(10, 2),
    Total_Fatura DECIMAL(10, 2),
    CONSTRAINT FK_FATURAS_CLIENTES FOREIGN KEY (Codigo_Cliente) REFERENCES CLIENTES(Codigo_Cliente)
);

CREATE TABLE LINHAS (
    Numero_Fatura INT,
    Numero_Linha INT,
    Codigo_Produto VARCHAR(10),
    Quantidade_Produto_Linha INT,
    Valor_Linha DECIMAL(9, 2),
    Total_Linha DECIMAL(9, 2),
    PRIMARY KEY (Numero_Fatura, Numero_Linha), -- Chave primária composta
    CONSTRAINT FK_LINHAS_FATURAS FOREIGN KEY (Numero_Fatura) REFERENCES FATURAS(Numero_Fatura),
    CONSTRAINT FK_LINHAS_PRODUTOS FOREIGN KEY (Codigo_Produto) REFERENCES PRODUTOS(Codigo_Produto)
);

-- Exercício 3
ALTER TABLE CLIENTES
	ADD Data_Nascimento DATE;
GO

-- Do exercício 4 em diante, não foi possível seguir pois faltam os arquivos para importação que o professor haveria de passar.
