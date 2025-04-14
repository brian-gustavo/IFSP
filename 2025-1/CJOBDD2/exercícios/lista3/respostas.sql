-- Questão 1
ALTER TABLE CLIENTES
	ADD DDD CHAR(2),
	    Telefone CHAR(10);
GO

-- Questão 2
UPDATE CLIENTES
	SET DDD = '12'
	WHERE ID = 1 OR ID = 2 OR ID = 3 OR ID = 5 OR ID = 7 OR ID = 9;
GO

UPDATE CLIENTES
	SET DDD = '11'
	WHERE ID = 12 OR ID = 13;
GO

UPDATE CLIENTES SET Telefone = '3664-5060' WHERE ID = 1;
UPDATE CLIENTES SET Telefone = '3664-8090' WHERE ID = 2;
UPDATE CLIENTES SET Telefone = '3663-1070' WHERE ID = 3;
UPDATE CLIENTES SET Telefone = '3664-6070' WHERE ID = 5;
UPDATE CLIENTES SET Telefone = '98790-6070' WHERE ID = 7;
UPDATE CLIENTES SET Telefone = '97070-6070' WHERE ID = 9;
UPDATE CLIENTES SET Telefone = '99555-0001' WHERE ID = 12;
UPDATE CLIENTES SET Telefone = '97890-1010' WHERE ID = 13;
UPDATE CLIENTES SET Telefone = '98888-0102' WHERE ID = 15;

SELECT * FROM CLIENTES;
GO

-- Questão 3
SELECT *
       INTO ClientesCOPIA
FROM CLIENTES;
GO

ALTER TABLE ClientesCOPIA
	ADD CONSTRAINT pk_id PRIMARY KEY (ID);
GO

SELECT CONSTRAINT_CATALOG AS 'Banco de Dados',
       TABLE_NAME AS 'Tabela',
       CONSTRAINT_TYPE AS 'Tipo de Restrição',
       CONSTRAINT_NAME AS 'Nome da Restrição'
FROM INFORMATION_SCHEMA.TABLE_CONSTRAINTS
WHERE TABLE_NAME IN ('ClientesCOPIA');
GO

-- Questão 4
SELECT *
       INTO CLIENTES2
FROM CLIENTES;
GO

DELETE FROM CLIENTES2
WHERE Telefone IS NULL;
GO

-- Questão 5
SELECT * FROM CLIENTES2;
GO

DELETE FROM CLIENTES2
WHERE DDD IS NULL OR DDD = '11';
GO

SELECT * FROM CLIENTES2;
GO

-- Questão 6
TRUNCATE TABLE CLIENTES2;
GO

-- Questão 7
DROP TABLE CLIENTES2;
GO

-- Questão 8
UPDATE CLIENTES SET Email = 'fernanda.pereira@uol.com.br', DDD = '15' WHERE ID = 15;
GO

SELECT * FROM CLIENTES;
GO

-- Questão 9
SELECT ID,
       Nome,
       Sexo,
       Idade,
       DDD,
       Telefone
FROM CLIENTES
WHERE Idade > 40
ORDER BY Idade DESC;
GO

-- Questão 10
SELECT ID,
       Nome,
       Email AS 'E-mail',
       DDD AS 'Código de Área',
       Telefone
FROM CLIENTES
WHERE Telefone IS NULL OR Email = 'meu@email.com'
ORDER BY Nome;
GO

-- Questão 11
SELECT ID,
       Nome,
       Sexo,
       Idade,
       Email AS 'E-mail'
FROM CLIENTES
WHERE Sexo = 'M' AND Idade BETWEEN 20 AND 50
ORDER BY Idade, Nome;
GO

-- Questão 12
SELECT ID,
       Nome,
       CPF,
       Email AS 'E-mail',
       DDD AS 'Código de Área',
       Telefone
FROM CLIENTES
WHERE Telefone IS NOT NULL
ORDER BY Nome;
GO

-- Questão 13
IF EXISTS (
	SELECT * FROM CLIENTES
	WHERE Telefone IS NULL
)
	PRINT 'Atenção: existem clientes que ainda não realizaram o cadastro do número de telefone!';
ELSE
	PRINT 'Todos os clientes já realizaram o cadastro do seu número de telefone.';
GO

-- Questão 14
SELECT ID,
       Nome,
       Idade,
       DDD AS 'Código de Área',
       Telefone
FROM CLIENTES
WHERE DDD = 11 OR DDD = 15 OR Idade = 19 OR Idade = 20 OR Idade = 22 OR Idade = 32 OR Idade = 70
ORDER BY Idade, DDD;
GO

-- Questão 15
SELECT ID,
       Nome,
       Sexo,
       Email AS 'E-mail',
       DDD AS 'Código de Área',
       Telefone
FROM CLIENTES
WHERE Nome LIKE 'A%'
ORDER BY Nome;
GO

-- Questão 16
SELECT ID,
       Nome,
       Sexo,
       Email AS 'E-mail',
       DDD AS 'Código de Área',
       Telefone
FROM CLIENTES
WHERE Nome LIKE 'A%' OR Nome LIKE 'D%' OR Nome LIKE 'S%'
ORDER BY Nome;
GO

-- Questão 17
SELECT ID,
       Nome,
       Sexo,
       Email AS 'E-mail',
       DDD AS 'Código de Área',
       Telefone
FROM CLIENTES
WHERE UPPER(Nome) LIKE '%LIMA%'
ORDER BY Nome;
GO

-- Questão 18
SELECT ID,
       Nome,
       Sexo,
       Email AS 'E-mail',
       DDD AS 'Código de Área',
       Telefone
FROM CLIENTES
WHERE UPPER(Nome) LIKE '%LIMA%' OR UPPER(Nome) LIKE '%PEREIRA%'
ORDER BY Nome;
GO

-- Questão 19
SELECT ID,
       Nome,
       Sexo,
       Email AS 'E-mail',
       DDD AS 'Código de Área',
       Telefone
FROM CLIENTES
WHERE Telefone LIKE '9%'
ORDER BY Sexo, Nome;
GO

-- Questão 20
SELECT ID,
       Nome,
       Sexo,
       Idade,
       Email AS 'E-mail',
       DDD AS 'Código de Área',
       Telefone
FROM CLIENTES
WHERE UPPER(Email) LIKE '%GMAIL%' AND DDD IS NOT NULL AND Idade > 20
ORDER BY Email, Nome;
GO

-- Questão 21
SELECT ID,
       Nome,
       Sexo,
       Email AS 'E-mail',
       DDD AS 'Código de Área',
       Telefone
FROM CLIENTES
WHERE Nome LIKE '[^M]%' AND Nome LIKE '%O' AND Telefone LIKE '%7' AND Sexo IS NOT NULL
ORDER BY Nome;
GO

-- Questão 22
CREATE VIEW ClientesFEMININO AS
	SELECT Nome,
	       Sexo,
	       Idade,
	       Email
	FROM CLIENTES
	WHERE Sexo = 'F';
GO

-- Questão 23
CREATE VIEW ClientesMASCULINO AS
	SELECT Nome,
	       Sexo,
	       Idade,
	       Email AS 'E-mail',
	       DDD AS 'Código de Área',
	       Telefone
	FROM CLIENTES
	WHERE Sexo = 'M';
GO

-- Questão 24
ALTER VIEW ClientesMASCULINO AS
	SELECT Nome,
	       Sexo,
	       Idade,
	       Email AS 'E-mail',
	       DDD AS 'Código de Área',
	       Telefone
	FROM CLIENTES
	WHERE Sexo = 'M' AND Telefone IS NOT NULL;
GO

SELECT Nome,
       [E-mail],
       [Código de Área],
       Telefone
FROM ClientesMASCULINO
ORDER BY [Código de Área];
GO

-- Questão 25
DROP VIEW ClientesFEMININO;
GO

DROP VIEW ClientesMASCULINO;
GO
