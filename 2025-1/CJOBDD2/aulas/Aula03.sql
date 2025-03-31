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
