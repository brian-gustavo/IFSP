-- Cria o banco de dados LojaIFSP, ou habilita seu contexto se ele já existe
IF DB_ID (N'LojaIFSP') IS NULL
  CREATE DATABASE LojaIFSP;
ELSE
  USE LojaIFSP;
GO

-- Exibe a data de criação e o nome das tabelas que existem no banco de dados em uso
SELECT create_date AS 'Data de Criação',
       name as 'Nome da Tabela'
FROM sys.tables;
GO

-- Cria a tabela para armazenar os clientes
CREATE TABLE CLIENTES (
  ID INT PRIMARY KEY,
  Nome VARCHAR(50) NOT NULL,
  Sexo CHAR(1) NULL,
  Idade INT CHECK (Idade > 18) NOT NULL,
  CPF CHAR(11) UNIQUE NOT NULL,
  Email VARCHAR(200) DEFAULT 'meu@email.com' NOT NULL
);
GO

-- Inserção dos registros; observe as restrições
INSERT INTO CLIENTES VALUES (1, 'Ana Cristina', 'F', 20, '11111111111', 'ana@gmail.com');
GO

INSERT INTO CLIENTES VALUES (1, 'Marcos Paulo', 'M', 45, '22222222222', 'marcos@gmail.com'); -- Dará erro, pois a chave primária é repetida
GO

INSERT INTO CLIENTES VALUES (3, 'André Luís', 'M', 15, '33333333333', 'andre@gmail.com'); -- Dará erro, pois a idade é menor que 18
GO

INSERT INTO CLIENTES VALUES (4, 'Maria Clara', NULL, 22, '44444444444', 'maria@gmail.com');
GO

INSERT INTO CLIENTES VALUES (5, 'Pedro Augusto', 'M', 45, '11111111111', 'pedro@gmail.com'); -- Dará erro, pois o CPF é repetido
GO

INSERT INTO CLIENTES VALUES (6, 'Ricardo Lima', 'M', 52, NULL, 'ricardo@gmail.com'); -- Dará erro, pois o CPF está nulo
GO

INSERT INTO CLIENTES VALUES (NULL, 'José Pereira', 'M', 45, '77777777777', 'jose@gmail.com'); -- Dará erro, pois a chave primária está nula
GO

INSERT INTO CLIENTES VALUES (8, 'Marcelo Souza', 'Masculino', 56, '88888888888', 'marcelo@gmail.com'); -- Dará erro, pois Sexo possui mais de 1 caractere
GO

INSERT INTO CLIENTES (ID, Nome, Sexo, Idade, CPF)
  VALUES (9, 'Daphne Lima', 'F', 32, '99999999999'); -- Email receberá o valor DEFAULT
GO

-- Exibe todos os registros da tabela
SELECT * FROM CLIENTES;
GO

-- Inserção dos registros passados, corrigindo os erros, além de registros adicionais
INSERT INTO CLIENTES VALUES
  (2, 'Marcos Paulo', 'M', 45, '22222222222', 'marcos@gmail.com'),
  (3, 'André Luís', 'M', 25, '33333333333', 'andre@gmail.com'),
  (5, 'Pedro Augusto', 'M', 45, '55555555555', 'pedro@gmail.com'),
  (6, 'Ricardo Lima', 'M', 52, '66666666666', 'ricardo@gmail.com'),
  (7, 'José Pereira', 'M', 45, '77777777777', 'jose@gmail.com'),
  (8, 'Marcelo Souza', 'M', 56, '88888888888', 'marcelo@gmail.com'),
  (10, 'Sheila Pereira', NULL, 21, '10101010101', 'sheila@yahoo.com.br'),
  (11, 'Tiago Augusto', NULL, 70, '20202020202', 'tiago@yahoo.com.br'),
  (12, 'Maria Pereira', 'F', 45, '30303030303', 'maria@bol.com.br'),
GO

INSERT INTO CLIENTES (ID, Nome, Sexo, Idade, CPF)
  VALUES
    (13, 'Lucas Silva', 'M', 19, '40404040404'),
    (14, 'Benedito Silva', NULL, 44, '50505050505'),
    (15, 'Fernanda Pereira', 'F', 31, '60606060606');
GO

SELECT * FROM CLIENTES;
GO

-- Exibe informações sobre a estrutura da tabela
SELECT TABLE_CATALOG AS 'Banco de Dados',
       TABLE_NAME AS 'Tabela',
       ORDINAL_POSITION AS 'Posição',
       COLUMN_NAME AS 'Coluna',
       DATA_TYPE AS 'Tipo de Dados',
       COLLATION_NAME AS 'Idioma da Coluna',
       IS_NULLABLE AS 'Aceita Nulo?'
FROM INFORMATION_SCHEMA.COLUMNS
WHERE TABLE_NAME = 'CLIENTES';
GO

-- Exibe informações sobre as restrições da tabela
SELECT CONSTRAINT_CATALOG AS 'Banco de Dados',
       TABLE_NAME AS 'Tabela',
       CONSTRAINT_TYPE AS 'Tipo de Restrição',
       CONSTRAINT_NAME AS 'Nome da Restrição',
FROM INFORMATION_SCHEMA.TABLE_CONSTRAINTS
WHERE TABLE_NAME = 'CLIENTES';
GO

-- Verifica a estrutura da tabela
EXEC sp_help 'CLIENTES';
GO
