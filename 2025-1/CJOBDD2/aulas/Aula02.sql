USE EmpresaCJ3028551;
GO

-- Exibe informações de tabelas já existentes no banco de dados atual
SELECT create_date AS 'Data de Criação',
	   name AS 'Nome da Tabela'
FROM sys.tables;
GO

ALTER TABLE FUNCIONARIOS
	ADD Telefone CHAR(10);
GO

SELECT * FROM FUNCIONARIOS;
GO

-- Exibe informações sobre a estrutura de uma tabela
SELECT TABLE_CATALOG AS 'Banco de Dados',
	   TABLE_NAME AS 'Tabela',
	   ORDINAL_POSITION AS 'Posição',
	   COLUMN_NAME AS 'Coluna',
	   DATA_TYPE AS 'Tipo de Dados',
	   COLLATION_NAME AS 'Idioma da Coluna',
	   IS_NULLABLE AS 'Aceita Nulo?'
FROM INFORMATION_SCHEMA.COLUMNS
WHERE TABLE_NAME = 'FUNCIONARIOS';
GO

-- Atualiza informações da tabela
UPDATE FUNCIONARIOS
	SET Telefone = '3668-0810';
GO

SELECT * FROM FUNCIONARIOS;
GO

UPDATE FUNCIONARIOS
	SET Telefone = NULL;
GO

SELECT * FROM FUNCIONARIOS;
GO

UPDATE FUNCIONARIOS
	SET Telefone = '3668-0810'
	WHERE ID = 1;
GO

SELECT * FROM FUNCIONARIOS;
GO

UPDATE FUNCIONARIOS SET Telefone = '4002-8922' WHERE ID = 2;
UPDATE FUNCIONARIOS SET Telefone = '1234-5678' WHERE ID = 4;
UPDATE FUNCIONARIOS SET Telefone = '8765-4321' WHERE ID = 5;
UPDATE FUNCIONARIOS SET Telefone = '5678-1234' WHERE ID = 7;
UPDATE FUNCIONARIOS SET Telefone = '4321-8765' WHERE ID = 9;
UPDATE FUNCIONARIOS SET Telefone = '1122-8899' WHERE ID = 10;
GO

SELECT * FROM FUNCIONARIOS;
GO

-- Deleta informações específicas de uma tabela
DELETE FROM FuncionariosCOPIA
WHERE Salario < 1500;
GO

SELECT * FROM FuncionariosCOPIA;
GO

-- Deleta todas as informações de uma tabela
TRUNCATE TABLE FuncionariosCOPIA;
GO

SELECT * FROM FuncionariosCOPIA;
GO

-- Remove uma tabela do banco de dados
DROP TABLE FuncionariosCOPIA;
GO

SELECT * FROM FuncionariosCOPIA;
GO

-- Exemplos de uso de operadores lógicos e operadores de comparação
SELECT * FROM FUNCIONARIOS
WHERE Sexo <> 'M';
GO

SELECT * FROM FUNCIONARIOS
WHERE Sexo != 'M';
GO

SELECT * FROM FUNCIONARIOS
WHERE NOT Sexo = 'M';
GO
	
SELECT * FROM FUNCIONARIOS
WHERE Salario >= 1000 AND
      Salario <= 1800
GO

SELECT * FROM FUNCIONARIOS
WHERE Salario BETWEEN 1000 AND 1800
GO

SELECT * FROM FUNCIONARIOS
WHERE Telefone IS NULL;
GO

SELECT * FROM FUNCIONARIOS
WHERE Telefone IS NOT NULL;
GO

SELECT * FROM FUNCIONARIOS
WHERE ID = 1 OR
	  ID = 2 OR
	  ID = 5;
GO

SELECT * FROM FUNCIONARIOS
WHERE Nome LIKE 'M%';
GO

-- Cria uma "view", para exibir informações sem permitir o acesso à tabela
CREATE VIEW MaioresSalarios AS
	SELECT ID AS 'Código do Funcionário',
	       Nome,
		   Sexo,
		   Salario AS 'Salário'
	FROM FUNCIONARIOS;
GO

-- Utilizando a "view"
SELECT * FROM MaioresSalarios;
GO

SELECT [Codigo do Funcionário],
	   Nome,
	   Salário
FROM MaioresSalarios;
GO

EXEC sp_helptext MaioresSalarios;
GO

SELECT TABLE_NAME AS 'Nome da View',
	   VIEW_DEFINITION AS 'Código SQL'
FROM INFORMATION_SCHEMA.VIEWS;
GO

-- Deletando a "view"
DROP VIEW MaioresSalarios;
GO
