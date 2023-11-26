
--Tabela referente a Midia

CREATE TABLE IF NOT EXISTS Midia (
  ID_Midia INT PRIMARY KEY,
  Tipo VARCHAR(255),
  Diretor VARCHAR(255),
  Atores VARCHAR(255),
  Genero VARCHAR(255),
  Titulo VARCHAR(255),
  Duracao INT,
  Ano INT,
  Pais VARCHAR(255),
  Descricao TEXT,
  ClassificacaoEtaria VARCHAR(255),
  MediaNotas DECIMAL (3,2)
);

--Exemplo de Insercao

INSERT INTO Midia VALUES (1,'Filme', 'Quentinho Tarantinu', 'Hans Landa', 'Frances', 'Suspense', 'Bastardos Gloriosos', 140,2019, 'EUA', 'Que filme em senhores', 'Maiores de 18', 5.0);
INSERT INTO Midia VALUES (2,)
