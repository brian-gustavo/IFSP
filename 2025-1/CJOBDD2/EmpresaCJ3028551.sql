-- Cria o banco de dados
CREATE DATABASE EmpresaCJ3028551;
GO

USE EmpresaCJ3028551;
GO

-- Cria a tabela
CREATE TABLE FUNCIONARIOS (
	ID INT PRIMARY KEY,
	Nome VARCHAR(25) NOT NULL,
	Sexo CHAR(1) NULL,
	Admissao DATE NOT NULL,
	Salario DECIMAL(10,2) NOT NULL,
);
GO

-- Estabelece o formato para o tipo de dado DATE
SET DATEFORMAT DMY;
GO

-- Insere informações na tabela
INSERT INTO FUNCIONARIOS (
	ID,
	Nome,
	Sexo,
	Admissao,
	Salario)
VALUES (1, 'Maria da Silva', 'F', '10/01/2018', 2500.00);
GO

-- Diferentes formas de inserir informações na tabela
INSERT INTO FUNCIONARIOS VALUES (2, 'Pedro Pereira', 'M', '25/05/2015', 990.00);
GO

INSERT INTO FUNCIONARIOS VALUES (3, 'Maria Cristina', 'F', '10/09/2015', 1200.00);
GO

INSERT INTO FUNCIONARIOS VALUES (4, 'Antônio Carlos', 'M', '15/05/2015', 990.00);
GO

INSERT INTO FUNCIONARIOS VALUES
	(5, 'Marcelo Augusto', 'M', '09/12/2017', 1900.00),
	(6, 'Pedro Silva', 'M', '15/11/2015', 1050.00),
	(7, 'Mônica da Silva', 'F', '12/10/2014', 3000.00),
	(8, 'Tiago Lima', 'M', '10/05/2016', 1350.00);
GO

INSERT INTO FUNCIONARIOS VALUES
	(9, 'Maria Cristina', 'F', '21/09/2012', 1700.00),
	(10, 'Maria Cristina', 'F', '10/10/2017', 1400.00);
GO

-- Diferentes exemplos de selecionamento de informações da tabela a serem exibidas
SELECT ID AS 'Código do Funcionário',
	Nome,
	Sexo,
	Salario AS 'Salário'
FROM FUNCIONARIOS;
GO

SELECT * FROM FUNCIONARIOS;
GO

SELECT TOP 3 *
FROM FUNCIONARIOS;
GO

SELECT TOP 3
	ID, Nome
FROM FUNCIONARIOS;
GO

SELECT * FROM FUNCIONARIOS
WHERE Sexo = 'M' AND Salario > 1000;
GO

-- Ordenando os resultados
SELECT * FROM FUNCIONARIOS
ORDER BY Nome;
GO

SELECT * FROM FUNCIONARIOS
ORDER BY Nome DESC;
GO

SELECT * FROM FUNCIONARIOS
WHERE Salario < 3000
ORDER BY Nome, Salario DESC;
GO
