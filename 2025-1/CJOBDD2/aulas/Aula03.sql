CREATE TABLE DEPENDENTES (
	CodDependentes INT PRIMARY KEY,
	Nome VARCHAR(35) NOT NULL,
	Sexo CHAR(1) NULL,
	DataNascimento DATE NOT NULL,
	ID INT FOREIGN KEY REFERENCES
FUNCIONARIOS (ID)
);
GO

-- Insere dados em massa a partir de um arquivo CSV
BULK INSERT DEPENDENTES
	FROM '...\dependentes.csv' -- Substitua as reticências pelo caminho do arquivo
WITH (
	FIRSTROW = 2,
	DATAFILETYPE = 'widechar',
	FIELDTERMINATOR = ','
);
GO

SELECT * FROM DEPENDENTES;
GO

-- Junção de tabelas através do comando "join"
SELECT *
FROM FUNCIONARIOS CROSS JOIN
DEPENDENTES;
GO

SELECT F.ID AS 'Código do Funcionário',
       F.Nome AS 'Nome do Funcionário',
       D.Nome AS 'Nome do Dependente',
       D.DataNascimento AS 'Data de Nascimento'
FROM FUNCIONARIOS F CROSS JOIN DEPENDENTES D;
GO

SELECT F.ID AS 'Código do Funcionário',
       F.Nome AS 'Nome do Funcionário',
       F.Salario AS 'Salário',
       D.Nome AS 'Nome do Dependente',
       D.ID AS 'Código do Responsável'
FROM FUNCIONARIOS F JOIN DEPENDENTES D;
       ON F.ID = D.ID;
GO

SELECT F.ID AS 'Código do Funcionário',
       F.Nome AS 'Nome do Funcionário',
       F.Salario AS 'Salário',
       D.Nome AS 'Nome do Dependente',
       D.DataNascimento AS 'Data de Nascimento',
       D.ID AS 'Código do Responsável'
FROM FUNCIONARIOS F INNER JOIN DEPENDENTES D
       ON F.ID = D.ID
WHERE YEAR(D.DataNascimento) >= 2000
ORDER BY F.Name, D.Name;
GO

INSERT INTO FUNCIONARIOS VALUES
	(11, 'Ana Cláudia', 'F', '12/09/2011', 4000.00, '3663-5050'),
	(12, 'André Lima', 'M', '05/11/2009', 2050.00, '3664-8989'),
	(13, 'Marcos Souza', 'M', '02/10/2009', 3800.00, NULL),
	(14, 'Mariana Gomes', 'F', '10/11/2010', 1750.50, NULL),
	(15, 'Cínthia Faria', 'F', '10/07/2016', 1750.50, '3662-1212');
GO

SELECT F.ID AS 'ID',
       F.Nome AS 'Funcionário',
       F.Admissao AS 'Admissão',
       F.Salario AS 'Salário',
       D.Nome AS 'Dependente',
       D.DataNascimento AS 'Data de Nascimento'
FROM FUNCIONARIOS F LEFT OUTER JOIN DEPENDENTES D
       ON F.ID = D.ID;
GO

SELECT F.ID AS 'ID',
       F.Nome AS 'Funcionário',
       F.Admissao AS 'Admissão',
       F.Salario AS 'Salário',
       D.Nome AS 'Dependente',
       D.DataNascimento AS 'Data de Nascimento'
FROM FUNCIONARIOS F LEFT OUTER JOIN DEPENDENTES D
       ON F.ID = D.ID
WHERE D.Nome IS NULL;
GO

SELECT F.ID AS 'ID',
       F.Nome AS 'Funcionário',
       F.Admissao AS 'Admissão',
       F.Salario AS 'Salário',
       D.Nome AS 'Dependente',
       D.DataNascimento AS 'Data de Nascimento'
FROM FUNCIONARIOS F RIGHT OUTER JOIN DEPENDENTES D
       ON F.ID = D.ID;
GO

SELECT F.ID AS 'ID',
       F.Nome AS 'Funcionário',
       F.Admissao AS 'Admissão',
       F.Salario AS 'Salário',
       D.Nome AS 'Dependente',
       D.DataNascimento AS 'Data de Nascimento'
FROM FUNCIONARIOS F FULL OUTER JOIN DEPENDENTES D
       ON F.ID = D.ID;
GO

-- Usando o comando "count" para exibir apenas informações específicas
SELECT F.ID AS 'ID',
       F.Nome AS 'Funcionário',
       COUNT(F.ID) AS 'Total de Dependentes'
FROM FUNCIONARIOS F INNER JOIN DEPENDENTES D
       ON F.ID = D.ID
GROUP BY F.ID, F.Nome;
GO

SELECT F.ID AS 'ID',
       F.Nome AS 'Funcionário',
       COUNT(D.ID) AS 'Total de Dependentes'
FROM FUNCIONARIOS F FULL OUTER JOIN DEPENDENTES D
       ON F.ID = D.ID
GROUP BY F.ID, F.Nome;
GO
