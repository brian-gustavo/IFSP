USE master;
GO

-- Cria o diretório Lista04 no drive E
EXECUTE xp_create_subdir 'E:\Lista04';
GO

CREATE DATABASE Lista04
  ON PRIMARY (
    NAME = 'Arquivo_Principal',
    FILENAME = 'E:\Lista04\Arquivo_Principal.mdf',
    SIZE = 5 MB,
    FILEGROWTH = 10%
  ),
  FILEGROUP FG1 (
    NAME = 'Arquivo_Dados',
    FILENAME = 'E:\Lista04\Arquivo_Dados.ndf',
    SIZE = 3 MB,
    FILEGROWTH = 10%
  ),
  LOG ON (
    NAME = 'Arquivo_Log',
    FILENAME = 'E:\Lista04\Arquivo_Log.ldf',
    SIZE = 1 MB,
    FILEGROWTH = 10%
  );
GO

-- Exibe o conteúdo do diretório
EXECUTE xp_dirtree 'E:\Lista04', 10, 1;
GO
