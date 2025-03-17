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
