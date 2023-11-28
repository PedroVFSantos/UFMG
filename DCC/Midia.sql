-- Tabela Mídia
CREATE TABLE IF NOT EXISTS Midia (
    ID_midia INT PRIMARY KEY NOT NULL,
    Tipo VARCHAR(255),
    Diretor VARCHAR(255),
    Atores VARCHAR(255),
    Genero VARCHAR(255),
    Titulo VARCHAR(255),
    Duracao INT NOT NULL,
    Ano INT NOT NULL,
    Pais VARCHAR(255),
    Descricao TEXT,
    ClassificacaoEtaria VARCHAR(10),
    MediaNotas DECIMAL(3, 2),
);

INSERT INTO Midia VALUES 
(1, 'Filme', 'Christopher Nolan', 'Leonardo DiCaprio, Joseph Gordon-Levitt, Ellen Page', 'Ficção Científica', 'A Origem', 148, 2010, 'EUA', 'Um ladrão especializado em invadir os sonhos das pessoas é contratado para realizar um trabalho aparentemente impossível.', '14 anos', 4.8),
(2, 'Série', 'Vince Gilligan', 'Bryan Cranston, Aaron Paul, Anna Gunn', 'Drama', 'Breaking Bad', 62, 2008, 'EUA', 'Um professor de química se transforma em um produtor de metanfetamina após ser diagnosticado com câncer.', '16 anos', 4.9),
(3, 'Filme', 'Quentin Tarantino', 'John Travolta, Uma Thurman, Samuel L. Jackson', 'Crime', 'Pulp Fiction', 154, 1994, 'EUA', 'Histórias interligadas sobre o submundo do crime em Los Angeles.', '18 anos', 4.7),
(4, 'Série', 'David Benioff, D.B. Weiss', 'Emilia Clarke, Kit Harington, Peter Dinklage', 'Fantasia', 'Game of Thrones', 73, 2011, 'EUA', 'Conflitos entre famílias nobres pelo controle do Trono de Ferro em Westeros.', '18 anos', 4.6),
(5, 'Filme', 'Steven Spielberg', 'Tom Hanks, Matt Damon, Tom Sizemore', 'Guerra', 'O Resgate do Soldado Ryan', 169, 1998, 'EUA', 'Um grupo de soldados é enviado para resgatar um paraquedista cujos irmãos morreram em combate.', '16 anos', 4.8),
(6, 'Série', 'Phoebe Waller-Bridge', 'Phoebe Waller-Bridge, Sian Clifford, Olivia Colman', 'Comédia', 'Fleabag', 12, 2016, 'Reino Unido', 'Uma mulher lida com questões da vida moderna enquanto navega por relacionamentos conturbados.', '16 anos', 4.5),
(7, 'Filme', 'Alfonso Cuarón', 'Yalitza Aparicio, Marina de Tavira', 'Drama', 'Roma', 135, 2018, 'México', 'A vida de uma empregada doméstica de uma família de classe média na Cidade do México nos anos 1970.', '14 anos', 4.6),
(8, 'Série', 'Lana Wachowski, Lilly Wachowski', 'Keanu Reeves, Carrie-Anne Moss, Laurence Fishburne', 'Ficção Científica', 'Sense8', 24, 2015, 'EUA', 'Oito estranhos de diferentes partes do mundo descobrem estar mental e emocionalmente conectados.', '16 anos', 4.4),
(9, 'Filme', 'Hayao Miyazaki', 'Daveigh Chase, Suzanne Pleshette, Miyu Irino', 'Animação', 'A Viagem de Chihiro', 125, 2001, 'Japão', 'Uma jovem garota se perde em um mundo mágico cheio de espíritos e deuses.', 'Livre', 4.9),
(10, 'Série', 'Charlie Brooker', 'Daniel Kaluuya, Jon Hamm, Bryce Dallas Howard', 'Ficção Científica', 'Black Mirror', 22, 2011, 'Reino Unido', 'Histórias independentes que exploram o lado sombrio da tecnologia moderna.', '18 anos', 4.7),
(11, 'Filme', 'Denis Villeneuve', 'Amy Adams, Jeremy Renner, Forest Whitaker', 'Ficção Científica', 'A Chegada', 116, 2016, 'EUA', 'Uma linguista é recrutada para ajudar a decifrar a linguagem de uma raça alienígena que chegou à Terra.', '12 anos', 4.8),
(12, 'Série', 'Matthew Weiner', 'Jon Hamm, Elisabeth Moss, Vincent Kartheiser', 'Drama', 'Mad Men', 92, 2007, 'EUA', 'A vida de publicitários na cidade de Nova York durante a década de 1960.', '16 anos', 4.6),
(13, 'Filme', 'Peter Jackson', 'Elijah Wood, Ian McKellen, Viggo Mortensen', 'Fantasia', 'O Senhor dos Anéis: A Sociedade do Anel', 178, 2001, 'Nova Zelândia', 'Um grupo de aventureiros embarca em uma jornada para destruir um anel poderoso.', '12 anos', 4.9),
(14, 'Série', 'Joss Whedon', 'Sarah Michelle Gellar, Alyson Hannigan, Nicholas Brendon', 'Fantasia', 'Buffy, a Caça-Vampiros', 144, 1997, 'EUA', 'Uma jovem escolhida para lutar contra vampiros, demônios e outras forças sobrenaturais.', '14 anos', 4.5),
(15, 'Filme', 'Stanley Kubrick', 'Jack Nicholson, Shelley Duvall, Danny Lloyd', 'Terror', 'O Iluminado', 144, 1980, 'EUA', 'Uma família é contratada para tomar conta de um hotel isolado durante o inverno, onde eventos sobrenaturais começam a ocorrer.', '16 anos', 4.7),
(16, 'Série', 'Ronald D. Moore', 'Caitriona Balfe, Sam Heughan, Duncan Lacroix', 'Drama', 'Outlander', 67, 2014, 'EUA', 'Uma enfermeira da Segunda Guerra Mundial é misteriosamente transportada de volta no tempo para o século XVIII.', '16 anos', 4.8),
(17, 'Filme', 'Greta Gerwig', 'Saoirse Ronan, Emma Watson, Florence Pugh', 'Drama', 'Adoráveis Mulheres', 135, 2019, 'EUA', 'A vida de quatro irmãs durante a Guerra Civil Americana.', 'Livre', 4.6),
(18, 'Série', 'David Lynch, Mark Frost', 'Kyle MacLachlan, Sheryl Lee, Sherilyn Fenn', 'Drama', 'Twin Peaks', 30, 1990, 'EUA', 'Um agente do FBI investiga o assassinato de uma jovem em uma pequena cidade.', '16 anos', 4.7),
(19, 'Filme', 'Martin Scorsese', 'Robert De Niro, Ray Liotta, Joe Pesci', 'Crime', 'Os Bons Companheiros', 146, 1990, 'EUA', 'A ascensão e queda de um grupo de mafiosos em Nova York.', '18 anos', 4.8),
(20, 'Série', 'Ryan Murphy, Brad Falchuk', 'Jessica Lange, Sarah Paulson, Evan Peters', 'Horror', 'American Horror Story', 60, 2011, 'EUA', 'Uma série de antologias que exploram histórias de terror diferentes a cada temporada.', '18 anos', 4.5);

--Tabela para Filme que referencia para a Tabela Midia
CREATE TABLE IF NOT EXISTS Filme (
    ID_filme INT PRIMARY KEY NOT NULL,
    ID_Midia INT NOT NULL,
    FOREIGN KEY (ID_midia) REFERENCES Midia(ID_midia),
    FOREIGN KEY (Tipo) REFERENCES Midia(Tipo)
);

-- Exemplos para a tabela Filme
INSERT INTO Filme VALUES (1, 1);
INSERT INTO Filme VALUES (2, 3);
INSERT INTO Filme VALUES (3, 5);
INSERT INTO Filme VALUES (4, 7);
INSERT INTO Filme VALUES (5, 9);
INSERT INTO Filme VALUES (6, 11);
INSERT INTO Filme VALUES (7, 13);
INSERT INTO Filme VALUES (8, 15);
INSERT INTO Filme VALUES (9, 17);
INSERT INTO Filme VALUES (10, 19);
INSERT INTO Filme VALUES (11, 21);
INSERT INTO Filme VALUES (12, 23);
INSERT INTO Filme VALUES (13, 25);
INSERT INTO Filme VALUES (14, 27);
INSERT INTO Filme VALUES (15, 29);
INSERT INTO Filme VALUES (16, 31);
INSERT INTO Filme VALUES (17, 33);
INSERT INTO Filme VALUES (18, 35);
INSERT INTO Filme VALUES (19, 37);
INSERT INTO Filme VALUES (20, 39);


--Tabela para Serie que referencia para a Tabela Midia 
CREATE TABLE IF NOT EXISTS Serie (
    ID_serie INT PRIMARY KEY,
    ID_Midia INT NOT NULL,
    Temporada INT NOT NULL,
    Episodio INT NOT NULL,
    FOREIGN KEY (ID_midia) REFERENCES Midia(ID_midia),
    FOREIGN KEY (Tipo) REFERENCES Midia(Tipo)
);

-- Exemplos para a tabela Serie
INSERT INTO Serie VALUES (1, 2, 1, 1);
INSERT INTO Serie VALUES (2, 4, 2, 3);
INSERT INTO Serie VALUES (3, 6, 1, 10);
INSERT INTO Serie VALUES (4, 8, 3, 5);
INSERT INTO Serie VALUES (5, 10, 2, 8);
INSERT INTO Serie VALUES (6, 12, 4, 2);
INSERT INTO Serie VALUES (7, 14, 1, 13);
INSERT INTO Serie VALUES (8, 16, 2, 7);
INSERT INTO Serie VALUES (9, 18, 3, 4);
INSERT INTO Serie VALUES (10, 20, 4, 9);
INSERT INTO Serie VALUES (11, 22, 1, 11);
INSERT INTO Serie VALUES (12, 24, 2, 6);
INSERT INTO Serie VALUES (13, 26, 3, 14);
INSERT INTO Serie VALUES (14, 28, 4, 1);
INSERT INTO Serie VALUES (15, 30, 1, 12);
INSERT INTO Serie VALUES (16, 32, 2, 5);
INSERT INTO Serie VALUES (17, 34, 3, 8);
INSERT INTO Serie VALUES (18, 36, 4, 3);
INSERT INTO Serie VALUES (19, 38, 1, 10);
INSERT INTO Serie VALUES (20, 40, 2, 7);

-- Alguns exemplos de Pesquisas

-- Listar todas as mídias ordenadas por ano de lançamento:
  SELECT * FROM Midia ORDER BY Ano;

-- Recuperar todas as mídias do gênero "Drama":
  SELECT * FROM Midia WHERE Gênero = 'Drama';

-- Encontrar as mídias com classificação etária maior que 16 anos:
  SELECT * FROM Midia WHERE CAST(REPLACE(ClassificacaoEtaria, ' anos', '') AS INT) > 16;

-- Mostrar a média de notas para cada tipo de mídia:
  SELECT Tipo, AVG(MédiaNotas) AS MédiaNotas FROM Midia GROUP BY Tipo;

-- Contar o número de mídias por país:
  SELECT País, COUNT(*) AS TotalSeries FROM Serie INNER JOIN Midia ON Serie.ID_midia = Midia.ID_midia GROUP BY País;

