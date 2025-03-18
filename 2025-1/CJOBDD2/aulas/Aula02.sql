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

SELECT * FROM FuncionariosCOPIA;
GO
