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
