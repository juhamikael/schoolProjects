-- Luodaan uusi tietue employee_id, tämän avulla yksittäisten tietojen päivittäminen on huomattavasti käytännöllisempää
ALTER TABLE employee
ADD employee_id INT NULL;

-- Tehtävä 2
-- Lisätään 5 uutta työntekijää employee kantaan ja syötetään niille dataa
INSERT INTO employee (fname,lname,salary,department_id,employee_id)
VALUES 
('Mikko', 'Lehtonen',3000,1,8072),
('Jooa','Jokinen',4000,2,7359),
('Pekka','Ruotsalainen',4400,2,1656),
('Susanna','Aaltonen',4200,3,6755),
('Birgitta','Tuominen',3500,3,1638);


-- Tehtävä 3
-- Luodaan 'Department' osioon 3 uutta osastoa
INSERT INTO department(id,name)
VALUES
(1,'Myynti'),
(2, 'Tuotanto'),
(3, 'Markkinointi');


-- Tehtävä 4
-- Päivitetään työntekijän palkkaa henkilölle jonka sukunimi on 'Tuominen'
-- Taulun päivittäminen sukunimen perusteella on erittäin huono käytäntö sillä saman sukunimisiä voi olla useita samassa paikassa,
-- parempi vaihtoehtoinen tapa on lisätä työntekijä ID ja päivittää tämän perusteella. 
UPDATE employee 
SET salary = 4500
WHERE employee_id = 1638;

-- Tehtävä 5 
-- Haetaan ainoastaan palkat employee taulusta
SELECT salary FROM employee;