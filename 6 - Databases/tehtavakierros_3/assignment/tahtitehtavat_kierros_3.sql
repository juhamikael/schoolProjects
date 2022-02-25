-- Tehtävä 5
-- Vaihdetaan palkka sarakkeen nimeä alkupalkaksi, tästä voidaan laskea myöhemmin, paljonko työntekijän palkka on noussut työssä ja 
-- muutenki helppo tehdä palkankorotuksiin muutoksia yms
ALTER TABLE employee RENAME COLUMN salary TO starting_salary; 
ALTER TABLE employee ADD updated_salary INT NOT NULL; -- Luodaan uusi sarake nimeltä "Päivitetty palkka"
ALTER TABLE employee CHANGE updated_salary updated_salary INT NOT NULL AFTER starting_salary; -- vaihdetaan päivitetty palkka sarakkeen paikkaa

-- Otetaan näkyviin Taavin palkka jotta voidaan vielä varmistua, että komento toimi 
SELECT * FROM employee WHERE id=11;

-- Nostetaan Taavin palkkaa 10% ja "tulostetaan se"
UPDATE employee SET updated_salary=starting_salary*1.1 WHERE id=11;
SELECT * FROM employee WHERE id=11;

-- Nostetaan kaikkien palkkaa 5%
UPDATE employee SET updated_salary=starting_salary*1.05; 
SELECT * FROM employee;

-- Alustetaan kaikkien palkan nousu alkuperäiseksi palkaksi ja tehdään 5,5% palkankorotus jokaiselle ja jälleen tulostetaan se
UPDATE employee SET updated_salary=starting_salary;
UPDATE employee SET updated_salary=starting_salary*1.055;
SELECT * FROM employee;




-- Tehtävä 6
-- Päivitetään osastojen ID = ID * 10
SELECT * FROM department;
UPDATE department SET id=id*10;
SELECT * FROM department;
-- Työntekijätaulun ID arvot muuttuvat tämän seurauksena koska työntekijätaulu on osastotaulun "lapsi", eli riippuvuus suhteessa osastotauluun


-- Tehtävä 9
-- Luodaan puuttuvat osat pelikoneeseen sekä itse pelikone
INSERT INTO part (`id`,`name`) 
VALUES
(11,'Muistikampa 16 Gb'),
(12,'microATX-kotelo'),
(13,'Intel Core i7-10700'),
(14,'NVIDIA GeForce 3080'),
(15,'Pelikone');

-- Luodaan pelikone tehtyjen sekä jo valmiiden arvojen perusteella
INSERT INTO part_of (`part_id`, `compart_id`, `quantity`)
VALUES
(15,8,2),
(15,11,2),
(15,12,1),
(15,13,1),
(15,14,1);



-- Tehtävä 11
-- Ainoa muutos mitä huomasin, oli kohdassa 6, kun department IDtä koitti muuttaa, muuttuikin kaikki department_id
-- arvot NULL :ksi

