-- Habilita o contexto do banco LojaIFSP, da lista 2
IF DB_ID (N'LojaIFSP') IS NULL
  PRINT 'O banco de dados LojaIFSP não existe!';
ELSE
  USE LojaIFSP;
GO

-- Exibe informações de tabelas já existentes no banco de dados atual
SELECT create_date AS 'Data de Criação',
       name AS 'Nome da Tabela'
FROM sys.tables;
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
WHERE TABLE_NAME = 'CLIENTES';
GO

-- Exibe todos os registros de uma tabela
SELECT * FROM CLIENTES;
GO
