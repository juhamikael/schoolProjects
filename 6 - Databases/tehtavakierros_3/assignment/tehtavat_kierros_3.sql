-- Tehtävä 0 
-- Ilmenevä Docker error
-- Error response from daemon: Ports are not available: listen tcp 0.0.0.0:3306: 
-- bind: Only one usage of each socket address (protocol/network address/port) is normally permitted.

-- Korjaus:
-- ports:'3306:3306' -> '3336:3306'



-- Tehtävä 1
-- Poistetaan osasto taulusta ID 
-- jonka jälkeen valitaan sekä tarkastellaan tauluja osasto ja työntekijät  
SELECT * FROM employee;
DELETE FROM department WHERE id=2;
SELECT * FROM department;
SELECT * FROM employee;
-- huomataan että osasto taulusta luonnollisesti poistui id 2 
-- sekä emplyee taulussa kaikki missä id oli 2, muuttui arvoksi NULL




-- Tehtävä 2
-- Valitaan kaikki arvot työntekijätaulusta
-- Päivitetään 'ded=partment-i6 missä työntekijän id on 2
SELECT * FROM employee;
UPDATE employee SET department_id=6 WHERE id=2;
SELECT * FROM employee;
UPDATE employee SET department_id=5 WHERE id=2;
-- Työntekijää ei voi päivättää arvolle 6, sillä se department_id 6 ei ole olemass
-- Työntekijän osaston ID voi tässä kohtaa päivittää ainoastaan 1,3,4,5 




-- Tehtävä 3
SELECT * FROM employee;
DELETE FROM employee WHERE id=4;
-- Taulusta 'works on' missä emplyoee oli 4, poistui jokainen kohta koska taulua 'works on' tehtäessä on määritelty:
-- ON DELETE CASCADE 
-- Googlettaessa tähän löytyi vastaus sivulta: https://dba.stackexchange.com/questions/44956/good-explanation-of-cascade-on-delete-update-behavior
-- Mutta lyhkäisyydessään : ON DELETE CASCADE == Leave No Orphans!





-- Tehtävä 4
-- Lisätessä osastoon jota ei ole, tulee error viesti:
-- ´´´
-- Error in query (1452): Cannot add or update a child row: a foreign 
-- key constraint fails (`company`.`employee`, CONSTRAINT `employee_ibfk_1` FOREIGN KEY (`department_id`) REFERENCES `department` (`id`) 
-- ON DELETE SET NULL ON UPDATE CASCADE)
-- ´´´
-- Tein tehtäävän 4, Python scriptin joka luo 200 työntekijää eri sääntöjen perusteella eri osastoille

INSERT INTO `employee` (`id`, `fname`, `lname`, `salary`, `bdate`, `email`, `department_id`, `phone1`, `phone2`, `image`, `supervisor_id`)
VALUES
(16, 'Saini', 'Juvonen', 2000, '1992-02-20','saini.juvonen@firma.fi', 3, '4537376870', '2255410021', NULL, 3),
(17, 'Sari', 'Rajala', 4225, '1991-10-25','sari.rajala@firma.fi', 4, '2257141146', '2252434210', NULL, 10),
(18, 'Sulho', 'Valtonen', 2650, '1988-06-22','sulho.valtonen@firma.fi', 3, '4532004960', '3458696840', NULL, 3),
(19, 'Pirita', 'Kosonen', 2400, '1988-05-15','pirita.kosonen@firma.fi', 3, '8547663326', '9415540200', NULL, 3),
(20, 'Sandra', 'Juvonen', 3175, '1997-06-13','sandra.juvonen@firma.fi', 4, '3452061625', '2252129523', NULL, 8),
(21, 'Mirka', 'Nyman', 2200, '1990-01-25','mirka.nyman@firma.fi', 4, '2251987934', '8547936275', NULL, 8),
(22, 'Sebastian', 'Partanen', 2450, '1998-06-11','sebastian.partanen@firma.fi', 3, '2251543998', '8549837290', NULL, 3),
(23, 'Rauno', 'Nurmi', 4475, '1992-10-19','rauno.nurmi@firma.fi', 5, '2256497894', '9414493343', NULL, 10),
(24, 'Tarvo', 'Jokinen', 4950, '1986-06-18','tarvo.jokinen@firma.fi', 5, '3457138568', '9419541600', NULL, 10),
(25, 'Minea', 'Kulmala', 4750, '1996-08-06','minea.kulmala@firma.fi', 5, '2256880096', '3456966446', NULL, 10),
(26, 'Milja', 'Suominen', 3025, '1991-03-24','milja.suominen@firma.fi', 4, '4539461622', '4536036891', NULL, 8),
(27, 'Miina', 'Suominen', 2825, '1989-03-11','miina.suominen@firma.fi', 5, '3456834471', '9413719226', NULL, 10),
(28, 'Soini', 'Niemi', 2750, '1994-09-25','soini.niemi@firma.fi', 3, '9419741261', '3459127102', NULL, 3),
(29, 'Sakari', 'Moilanen', 2275, '1990-04-27','sakari.moilanen@firma.fi', 4, '8541566120', '3458162663', NULL, 8),
(30, 'Mirka', 'Ikonen', 2850, '1991-10-26','mirka.ikonen@firma.fi', 4, '9413664648', '3454369622', NULL, 8),
(31, 'Terho', 'Koistinen', 3150, '1991-10-26','terho.koistinen@firma.fi', 4, '3452400409', '3458187983', NULL, 8),
(32, 'Terho', 'Aalto', 4675, '1998-08-15','terho.aalto@firma.fi', 4, '9415612278', '8549776918', NULL, 10),
(33, 'Sirja', 'Ikonen', 2650, '1987-10-08','sirja.ikonen@firma.fi', 3, '8547652105', '4534736974', NULL, 3),
(34, 'Topias', 'Helenius', 2100, '1998-11-16','topias.helenius@firma.fi', 3, '9413762364', '9414259066', NULL, 3),
(35, 'Reko', 'Tamminen', 2750, '1993-11-25','reko.tamminen@firma.fi', 3, '9412326049', '9419941802', NULL, 3),
(36, 'Sandra', 'Vuori', 3900, '1993-12-06','sandra.vuori@firma.fi', 5, '4539143609', '8549329176', NULL, 10),
(37, 'Sisu', 'Karvonen', 4925, '1997-03-18','sisu.karvonen@firma.fi', 5, '8549064406', '8546806603', NULL, 10),
(38, 'Sakari', 'Salo', 2300, '1991-09-08','sakari.salo@firma.fi', 3, '3451277292', '8541206973', NULL, 3),
(39, 'Sipi', 'Salmi', 4950, '1986-02-20','sipi.salmi@firma.fi', 4, '8544494866', '9412627968', NULL, 10),
(40, 'Pirkka', 'Kauppinen', 2000, '1986-02-08','pirkka.kauppinen@firma.fi', 3, '2257458361', '9416435426', NULL, 3),
(41, 'Teppo', 'Mikkola', 5075, '1997-07-02','teppo.mikkola@firma.fi', 4, '4536438163', '8544326381', NULL, 10),
(42, 'Sauli', 'Saarela', 2000, '1989-05-14','sauli.saarela@firma.fi', 3, '2256924464', '4536902344', NULL, 3),
(43, 'Sylvester', 'Kauppinen', 2525, '1991-09-03','sylvester.kauppinen@firma.fi', 5, '2253697737', '2252481997', NULL, 10),
(44, 'Melissa', 'Nevalainen', 2800, '1997-09-26','melissa.nevalainen@firma.fi', 5, '9414886512', '8547880571', NULL, 10),
(45, 'Teuvo', 'Koskinen', 2350, '1997-10-01','teuvo.koskinen@firma.fi', 3, '8543344775', '3454445719', NULL, 3),
(46, 'Robert', 'Suominen', 2250, '1995-11-03','robert.suominen@firma.fi', 3, '3454827006', '4531740279', NULL, 3),
(47, 'Milja', 'Riikonen', 3275, '1986-04-14','milja.riikonen@firma.fi', 4, '3453604571', '8548069179', NULL, 8),
(48, 'Saini', 'Koivisto', 4775, '1998-02-23','saini.koivisto@firma.fi', 5, '2254114461', '4538812030', NULL, 10),
(49, 'Saana', 'Halonen', 4075, '1997-02-21','saana.halonen@firma.fi', 4, '2255339907', '9416921468', NULL, 10),
(50, 'Topi', 'Hiltunen', 5075, '1996-12-15','topi.hiltunen@firma.fi', 5, '4537593835', '9411871274', NULL, 10),
(51, 'Raine', 'Hietala', 4825, '1988-09-07','raine.hietala@firma.fi', 4, '8549086398', '4537348217', NULL, 10),
(52, 'Terho', 'Paananen', 4525, '1994-10-09','terho.paananen@firma.fi', 5, '9415336873', '2256278869', NULL, 10),
(53, 'Mervi', 'Hiltunen', 2975, '1989-10-19','mervi.hiltunen@firma.fi', 4, '9419497743', '8543056108', NULL, 8),
(54, 'Selma', 'Vainio', 3075, '1992-06-25','selma.vainio@firma.fi', 4, '4533329255', '3453546666', NULL, 8),
(55, 'Tatu', 'Haapala', 4950, '1987-06-03','tatu.haapala@firma.fi', 5, '9415913127', '9412220949', NULL, 10),
(56, 'Teijo', 'Ahola', 3600, '1988-08-08','teijo.ahola@firma.fi', 5, '8544003064', '2259949521', NULL, 10),
(57, 'Sanni', 'Kokko', 6100, '1996-06-10','sanni.kokko@firma.fi', 1, '4538352493', '9411537765', NULL, 1),
(58, 'Saila', 'Karjalainen', 2225, '1993-07-26','saila.karjalainen@firma.fi', 4, '9416421401', '2255454924', NULL, 8),
(59, 'Mirva', 'Nyman', 3500, '1995-02-19','mirva.nyman@firma.fi', 5, '8545605568', '2255773623', NULL, 10),
(60, 'Mirella', 'Uusitalo', 3500, '1989-08-14','mirella.uusitalo@firma.fi', 4, '3451144964', '8541511255', NULL, 8),
(61, 'Samuel', 'Helin', 6000, '1997-04-26','samuel.helin@firma.fi', 1, '3452376707', '8549419111', NULL, 1),
(62, 'Mila', 'Huhtala', 5025, '1993-05-23','mila.huhtala@firma.fi', 5, '2253128207', '8543013854', NULL, 10),
(63, 'Sakari', 'Asikainen', 2450, '1988-08-27','sakari.asikainen@firma.fi', 3, '9411387823', '9411840210', NULL, 3),
(64, 'Minna', 'Eskelinen', 3775, '1993-11-19','minna.eskelinen@firma.fi', 4, '4534787227', '2251975438', NULL, 8),
(65, 'Tuukka', 'Parviainen', 2250, '1992-05-27','tuukka.parviainen@firma.fi', 3, '2259039548', '9412950082', NULL, 3),
(66, 'Mila', 'Huovinen', 2400, '1996-01-15','mila.huovinen@firma.fi', 3, '4532155916', '2258626422', NULL, 3),
(67, 'Satu', 'Salminen', 2000, '1986-05-14','satu.salminen@firma.fi', 3, '9415697182', '4531415194', NULL, 3),
(68, 'Pentti', 'Martikainen', 2100, '1992-06-05','pentti.martikainen@firma.fi', 3, '3454627696', '9417967802', NULL, 3),
(69, 'Tuure', 'Salonen', 2550, '1986-11-21','tuure.salonen@firma.fi', 3, '3459052953', '8549372747', NULL, 3),
(70, 'Pipsa', 'Koivula', 4450, '1997-08-04','pipsa.koivula@firma.fi', 5, '2253350524', '9415289667', NULL, 10),
(71, 'Mila', 'Aho', 2400, '1993-06-25','mila.aho@firma.fi', 3, '4537617501', '9412576691', NULL, 3),
(72, 'Mirja', 'Tamminen', 4025, '1996-08-10','mirja.tamminen@firma.fi', 4, '2252398133', '2251207850', NULL, 10),
(73, 'Sampsa', 'Paavola', 3100, '1995-02-27','sampsa.paavola@firma.fi', 4, '3454166060', '8542232831', NULL, 8),
(74, 'Mimmi', 'Kinnunen', 4000, '1987-08-10','mimmi.kinnunen@firma.fi', 4, '8547440429', '9419557033', NULL, 10),
(75, 'Mirkka', 'Virtanen', 5025, '1989-02-25','mirkka.virtanen@firma.fi', 5, '3457697243', '2256241511', NULL, 10),
(76, 'Severi', 'Halonen', 2400, '1986-09-21','severi.halonen@firma.fi', 3, '4538016059', '9415583312', NULL, 3),
(77, 'Tarvo', 'Laakso', 2500, '1992-10-14','tarvo.laakso@firma.fi', 3, '4532145299', '3455695895', NULL, 3),
(78, 'Roope', 'Leinonen', 4700, '1986-08-24','roope.leinonen@firma.fi', 5, '4533807839', '9413586204', NULL, 10),
(79, 'Sylvester', 'Rautio', 2300, '1993-09-26','sylvester.rautio@firma.fi', 3, '4533877431', '3451867159', NULL, 3),
(80, 'Sandra', 'Korpela', 3250, '1987-04-08','sandra.korpela@firma.fi', 4, '2252732648', '9413998199', NULL, 8),
(81, 'Tuomas', 'Saarinen', 2350, '1997-08-20','tuomas.saarinen@firma.fi', 4, '4538752223', '9416202577', NULL, 8),
(82, 'Tarvo', 'Aho', 6400, '1997-09-23','tarvo.aho@firma.fi', 1, '8545422683', '9415990792', NULL, 1),
(83, 'Pasi', 'Eronen', 5075, '1986-04-15','pasi.eronen@firma.fi', 5, '2251379934', '4538915447', NULL, 10),
(84, 'Tiitus', 'Miettinen', 2275, '1988-08-20','tiitus.miettinen@firma.fi', 4, '4531947784', '8548230860', NULL, 8),
(85, 'Sulho', 'Jokela', 3800, '1991-11-01','sulho.jokela@firma.fi', 4, '3459142533', '3456927725', NULL, 8),
(86, 'Saana', 'Kukkonen', 4225, '1990-05-22','saana.kukkonen@firma.fi', 5, '3459063412', '8543209589', NULL, 10),
(87, 'Taito', 'Karjalainen', 2500, '1990-10-04','taito.karjalainen@firma.fi', 3, '4538601431', '8544286721', NULL, 3),
(88, 'Sari', 'Kemppainen', 2475, '1988-02-27','sari.kemppainen@firma.fi', 4, '8542116667', '8545444795', NULL, 8),
(89, 'Minttu', 'Jussila', 3875, '1986-09-07','minttu.jussila@firma.fi', 4, '2258190682', '2254543509', NULL, 8),
(90, 'Saija', 'Koistinen', 4975, '1996-07-19','saija.koistinen@firma.fi', 5, '4531688320', '9414141303', NULL, 10),
(91, 'Miia', 'Koski', 2100, '1987-12-22','miia.koski@firma.fi', 3, '9412377848', '2257781870', NULL, 3),
(92, 'Moona', 'Penttinen', 2750, '1987-11-26','moona.penttinen@firma.fi', 3, '2258528998', '8549892196', NULL, 3),
(93, 'Miina', 'Helenius', 2475, '1987-03-22','miina.helenius@firma.fi', 4, '4532860349', '4532440048', NULL, 8),
(94, 'Mielikki', 'Eriksson', 3550, '1997-08-20','mielikki.eriksson@firma.fi', 5, '3455282737', '2256914276', NULL, 10),
(95, 'Mirjami', 'Heikkinen', 2350, '1987-05-20','mirjami.heikkinen@firma.fi', 3, '8543206579', '9418849426', NULL, 3),
(96, 'Pellervo', 'Luoma', 4825, '1994-01-15','pellervo.luoma@firma.fi', 4, '2251671808', '4531751601', NULL, 10),
(97, 'Petri', 'Toivanen', 3150, '1993-08-23','petri.toivanen@firma.fi', 5, '4538401965', '8545225324', NULL, 10),
(98, 'Taito', 'Koponen', 2600, '1994-08-14','taito.koponen@firma.fi', 3, '4539097483', '9416128809', NULL, 3),
(99, 'Taito', 'Rautiainen', 2550, '1995-09-03','taito.rautiainen@firma.fi', 4, '9412089174', '4534191289', NULL, 8),
(100, 'Turo', 'Kinnunen', 4950, '1986-03-09','turo.kinnunen@firma.fi', 4, '4533161991', '9419121945', NULL, 10),
(101, 'Torsti', 'Rajala', 3325, '1986-04-09','torsti.rajala@firma.fi', 4, '2258872866', '8546336175', NULL, 8),
(102, 'Tommi', 'Lahti', 2200, '1987-06-01','tommi.lahti@firma.fi', 3, '8547989994', '2256022369', NULL, 3),
(103, 'Sanelma', 'Hietala', 4925, '1995-03-21','sanelma.hietala@firma.fi', 5, '8543320731', '2258208915', NULL, 10),
(104, 'Piia', 'Hokkanen', 3950, '1989-07-13','piia.hokkanen@firma.fi', 5, '9416720459', '3459139910', NULL, 10),
(105, 'Petri', 'Tiainen', 4475, '1997-02-21','petri.tiainen@firma.fi', 4, '9417555228', '2254413033', NULL, 10),
(106, 'Samuli', 'Heikkinen', 2575, '1987-06-05','samuli.heikkinen@firma.fi', 4, '2255993773', '8547707043', NULL, 8),
(107, 'Sulevi', 'Kulmala', 3075, '1987-01-02','sulevi.kulmala@firma.fi', 4, '3456733864', '2251628612', NULL, 8),
(108, 'Raimo', 'Viitanen', 3225, '1990-09-05','raimo.viitanen@firma.fi', 5, '8546694527', '4539276042', NULL, 10),
(109, 'Sylvester', 'Pelkonen', 3150, '1998-10-03','sylvester.pelkonen@firma.fi', 4, '9416920605', '4535026372', NULL, 8),
(110, 'Melissa', 'Nurmi', 2000, '1996-11-05','melissa.nurmi@firma.fi', 3, '2255784222', '2251391306', NULL, 3),
(111, 'Salomo', 'Laurila', 2700, '1992-11-08','salomo.laurila@firma.fi', 4, '4539373750', '2257937159', NULL, 8),
(112, 'Saimi', 'Kangas', 2500, '1994-10-15','saimi.kangas@firma.fi', 3, '9418307670', '4539709050', NULL, 3),
(113, 'Saaga', 'Leinonen', 2875, '1990-08-15','saaga.leinonen@firma.fi', 5, '2257134994', '3458432985', NULL, 10),
(114, 'Touko', 'Tuovinen', 4125, '1989-02-07','touko.tuovinen@firma.fi', 5, '2252016129', '3459332488', NULL, 10),
(115, 'Satu', 'Kangas', 3900, '1988-03-19','satu.kangas@firma.fi', 4, '4538103698', '4531805361', NULL, 8),
(116, 'Silja', 'Martikainen', 4675, '1997-08-01','silja.martikainen@firma.fi', 4, '2257798743', '4535185002', NULL, 10),
(117, 'Tero', 'Korpela', 3975, '1995-10-03','tero.korpela@firma.fi', 5, '3456156714', '2257739463', NULL, 10),
(118, 'Salli', 'Ranta', 3325, '1994-05-10','salli.ranta@firma.fi', 5, '9412785060', '3455478302', NULL, 10),
(119, 'Raimo', 'Miettinen', 2500, '1989-08-12','raimo.miettinen@firma.fi', 5, '3455622811', '4537961828', NULL, 10),
(120, 'Salli', 'Parviainen', 5050, '1988-11-11','salli.parviainen@firma.fi', 4, '4533684155', '3456837349', NULL, 10),
(121, 'Tauno', 'Nurminen', 2375, '1987-10-05','tauno.nurminen@firma.fi', 5, '8546353891', '2254257309', NULL, 10),
(122, 'Peppi', 'Nevalainen', 2700, '1991-09-22','peppi.nevalainen@firma.fi', 4, '3456986919', '8542591146', NULL, 8),
(123, 'Pasi', 'Nurminen', 3225, '1994-04-03','pasi.nurminen@firma.fi', 5, '2258831027', '8546185192', NULL, 10),
(124, 'Tuure', 'Laitinen', 4800, '1988-07-06','tuure.laitinen@firma.fi', 5, '8545821953', '9416431624', NULL, 10),
(125, 'Sanna', 'Ahonen', 2050, '1987-01-09','sanna.ahonen@firma.fi', 3, '3452018071', '9413514637', NULL, 3),
(126, 'Seija', 'Tuovinen', 2450, '1995-01-06','seija.tuovinen@firma.fi', 3, '4536954644', '9414566965', NULL, 3),
(127, 'Silva', 'Kauppinen', 2250, '1988-06-06','silva.kauppinen@firma.fi', 3, '9418746377', '3455986688', NULL, 3),
(128, 'Miisa', 'Saastamoinen', 2250, '1996-04-18','miisa.saastamoinen@firma.fi', 3, '9415264717', '9416260817', NULL, 3),
(129, 'Mikaela', 'Andersson', 2150, '1997-04-09','mikaela.andersson@firma.fi', 3, '9414162783', '3452676348', NULL, 3),
(130, 'Tuure', 'Lindberg', 2650, '1986-08-21','tuure.lindberg@firma.fi', 3, '8547178135', '2251364411', NULL, 3),
(131, 'Rauli', 'Kolehmainen', 3075, '1995-10-12','rauli.kolehmainen@firma.fi', 4, '9419577053', '9412117955', NULL, 8),
(132, 'Raine', 'Korhonen', 2450, '1998-11-16','raine.korhonen@firma.fi', 5, '9413621502', '9419662144', NULL, 10),
(133, 'Taavetti', 'Nissinen', 3700, '1997-11-15','taavetti.nissinen@firma.fi', 5, '8541489948', '8541160314', NULL, 10),
(134, 'Milka', 'Parviainen', 3750, '1995-01-15','milka.parviainen@firma.fi', 5, '9415848505', '8544464500', NULL, 10),
(135, 'Sanelma', 'Ruotsalainen', 2000, '1990-07-07','sanelma.ruotsalainen@firma.fi', 3, '9414321861', '8543073776', NULL, 3),
(136, 'Senni', 'Uusitalo', 3175, '1998-12-11','senni.uusitalo@firma.fi', 4, '2259358133', '8548056449', NULL, 8),
(137, 'Minja', 'Jokinen', 2950, '1996-01-13','minja.jokinen@firma.fi', 4, '8546424182', '4533247299', NULL, 8),
(138, 'Touko', 'Hakala', 2150, '1990-02-05','touko.hakala@firma.fi', 3, '4532054753', '2253081950', NULL, 3),
(139, 'Taisto', 'Pelkonen', 4750, '1991-07-15','taisto.pelkonen@firma.fi', 4, '3454073942', '9414213690', NULL, 10),
(140, 'Sebastian', 'Valtonen', 2450, '1989-07-05','sebastian.valtonen@firma.fi', 3, '4535983836', '2251388317', NULL, 3),
(141, 'Rasmus', 'Jokinen', 2750, '1989-10-20','rasmus.jokinen@firma.fi', 4, '2257451988', '8544742176', NULL, 8),
(142, 'Samu', 'Kainulainen', 2200, '1991-06-27','samu.kainulainen@firma.fi', 3, '4534585688', '2257527865', NULL, 3),
(143, 'Pirjo', 'Nurmi', 3550, '1988-09-27','pirjo.nurmi@firma.fi', 5, '8543104640', '9417926491', NULL, 10),
(144, 'Peetu', 'Kulmala', 2650, '1993-11-24','peetu.kulmala@firma.fi', 3, '2254202706', '4532605056', NULL, 3),
(145, 'Topi', 'Tolvanen', 4475, '1990-08-24','topi.tolvanen@firma.fi', 5, '2251710448', '9414010876', NULL, 10),
(146, 'Sakari', 'Liimatainen', 2050, '1998-03-04','sakari.liimatainen@firma.fi', 3, '8547482195', '3452182122', NULL, 3),
(147, 'Mirka', 'Kukkonen', 2550, '1989-01-03','mirka.kukkonen@firma.fi', 3, '3456291003', '3457037548', NULL, 3),
(148, 'Terho', 'Rautiainen', 2500, '1992-06-04','terho.rautiainen@firma.fi', 3, '2258264861', '9413437928', NULL, 3),
(149, 'Sini', 'Leino', 2650, '1994-04-04','sini.leino@firma.fi', 3, '9413301756', '4534648903', NULL, 3),
(150, 'Peetu', 'Riikonen', 5000, '1991-02-12','peetu.riikonen@firma.fi', 5, '2256310213', '2256528786', NULL, 10),
(151, 'Mirja', 'Huovinen', 4975, '1998-04-27','mirja.huovinen@firma.fi', 4, '9418588507', '4533731028', NULL, 10),
(152, 'Tuomas', 'Halonen', 2225, '1988-06-07','tuomas.halonen@firma.fi', 4, '3457991710', '9418565637', NULL, 8),
(153, 'Rasmus', 'Juntunen', 4825, '1990-09-07','rasmus.juntunen@firma.fi', 5, '9411730699', '3456661343', NULL, 10),
(154, 'Silvo', 'Kinnunen', 4575, '1992-12-17','silvo.kinnunen@firma.fi', 5, '9414007752', '9418468305', NULL, 10),
(155, 'Rami', 'Salo', 4175, '1990-11-15','rami.salo@firma.fi', 4, '3458514097', '9418127680', NULL, 10),
(156, 'Tiitus', 'Makkonen', 2200, '1989-09-03','tiitus.makkonen@firma.fi', 3, '4536035711', '3452264589', NULL, 3),
(157, 'Siiri', 'Auvinen', 2500, '1987-07-10','siiri.auvinen@firma.fi', 3, '8543905646', '3458224702', NULL, 3),
(158, 'Silva', 'Eskola', 2600, '1987-09-05','silva.eskola@firma.fi', 3, '9416901409', '3453868264', NULL, 3),
(159, 'Tommi', 'Helenius', 2700, '1987-11-05','tommi.helenius@firma.fi', 3, '9413558951', '2253747461', NULL, 3),
(160, 'Milla', 'Asikainen', 3025, '1988-03-08','milla.asikainen@firma.fi', 5, '4532069376', '9413507800', NULL, 10),
(161, 'Mielikki', 'Mattila', 3625, '1993-02-25','mielikki.mattila@firma.fi', 4, '2255971945', '9417235735', NULL, 8),
(162, 'Tenho', 'Anttila', 3325, '1994-09-08','tenho.anttila@firma.fi', 5, '4536849200', '2255688060', NULL, 10),
(163, 'Pauli', 'Pasanen', 4800, '1991-09-05','pauli.pasanen@firma.fi', 5, '9414735411', '3457636765', NULL, 10),
(164, 'Pyry', 'Kinnunen', 3750, '1997-12-19','pyry.kinnunen@firma.fi', 4, '8545562989', '9419282835', NULL, 8),
(165, 'Mirja', 'Vartiainen', 4050, '1998-01-16','mirja.vartiainen@firma.fi', 5, '9419799233', '8543815624', NULL, 10),
(166, 'Milla', 'Laitinen', 4175, '1991-06-13','milla.laitinen@firma.fi', 4, '2257388191', '8544930572', NULL, 10),
(167, 'Sebastian', 'Valtonen', 2750, '1990-12-21','sebastian.valtonen@firma.fi', 3, '4536311885', '9414910992', NULL, 3),
(168, 'Pekka', 'Virta', 2900, '1986-02-24','pekka.virta@firma.fi', 4, '4539169543', '4536614419', NULL, 8),
(169, 'Minna', 'Helenius', 4375, '1989-01-01','minna.helenius@firma.fi', 4, '8541140728', '8542835185', NULL, 10),
(170, 'Pinja', 'Nurminen', 4075, '1989-02-02','pinja.nurminen@firma.fi', 4, '9411522493', '9415246135', NULL, 10),
(171, 'Raino', 'Tamminen', 3775, '1994-10-27','raino.tamminen@firma.fi', 4, '2251148685', '9415961284', NULL, 8),
(172, 'Mimmi', 'Kujala', 3925, '1991-03-10','mimmi.kujala@firma.fi', 4, '3457676152', '8542229739', NULL, 8),
(173, 'Meri', 'Johansson', 4725, '1998-12-09','meri.johansson@firma.fi', 4, '9417096628', '3458212832', NULL, 10),
(174, 'Riku', 'Hirvonen', 2600, '1992-05-08','riku.hirvonen@firma.fi', 3, '4532916240', '8544618448', NULL, 3),
(175, 'Mikaela', 'Repo', 3375, '1998-07-11','mikaela.repo@firma.fi', 4, '3451999241', '3451353825', NULL, 8),
(176, 'Sarita', 'Nieminen', 2500, '1987-03-22','sarita.nieminen@firma.fi', 5, '9417141175', '8545740563', NULL, 10),
(177, 'Peetu', 'Huotari', 2300, '1997-03-11','peetu.huotari@firma.fi', 3, '4534353288', '3457249920', NULL, 3),
(178, 'Sanna', 'Aho', 3250, '1986-02-14','sanna.aho@firma.fi', 4, '4537031101', '3451167775', NULL, 8),
(179, 'Pinja', 'Luoma', 2450, '1987-02-22','pinja.luoma@firma.fi', 3, '4533797215', '2251691923', NULL, 3),
(180, 'Milla', 'Virta', 4650, '1995-03-25','milla.virta@firma.fi', 4, '4532015036', '2251827655', NULL, 10),
(181, 'Tommi', 'Hokkanen', 3325, '1996-10-26','tommi.hokkanen@firma.fi', 5, '3455850479', '3456330849', NULL, 10),
(182, 'Sanni', 'Saarela', 2700, '1987-04-12','sanni.saarela@firma.fi', 5, '2258967548', '4534242275', NULL, 10),
(183, 'Pirjo', 'Koponen', 3500, '1986-08-02','pirjo.koponen@firma.fi', 4, '2251531409', '8546531178', NULL, 8),
(184, 'Sakari', 'Karppinen', 3400, '1991-12-21','sakari.karppinen@firma.fi', 4, '9414742565', '2254276101', NULL, 8),
(185, 'Teijo', 'Saastamoinen', 3125, '1992-11-11','teijo.saastamoinen@firma.fi', 5, '4531302404', '3456823455', NULL, 10),
(186, 'Sanni', 'Heinonen', 5050, '1993-02-19','sanni.heinonen@firma.fi', 5, '2252322184', '2252760436', NULL, 10),
(187, 'Taavi', 'Partanen', 2375, '1994-01-12','taavi.partanen@firma.fi', 4, '8542441950', '9415853542', NULL, 8),
(188, 'Siiri', 'Luoma', 4975, '1996-03-12','siiri.luoma@firma.fi', 4, '4533844662', '2258088071', NULL, 10),
(189, 'Sulo', 'Hietala', 3000, '1994-09-24','sulo.hietala@firma.fi', 5, '2252402686', '9412579062', NULL, 10),
(190, 'Teijo', 'Kokkonen', 2950, '1990-06-15','teijo.kokkonen@firma.fi', 4, '4538872032', '3456166349', NULL, 8),
(191, 'Soini', 'Juntunen', 2150, '1995-11-20','soini.juntunen@firma.fi', 3, '2255110447', '2257280594', NULL, 3),
(192, 'Pyry', 'Voutilainen', 4575, '1998-02-07','pyry.voutilainen@firma.fi', 4, '4533690630', '8549072831', NULL, 10),
(193, 'Tuomas', 'Mikkola', 3100, '1995-05-11','tuomas.mikkola@firma.fi', 4, '4538951883', '3456251683', NULL, 8),
(194, 'Tuure', 'Laakso', 3950, '1997-11-06','tuure.laakso@firma.fi', 5, '9419561639', '8549366103', NULL, 10),
(195, 'Mimosa', 'Oksanen', 2400, '1992-06-08','mimosa.oksanen@firma.fi', 3, '4536671546', '2254731616', NULL, 3),
(196, 'Pirkka', 'Paananen', 6100, '1989-03-08','pirkka.paananen@firma.fi', 1, '2254087190', '4538389338', NULL, 1),
(197, 'Tomi', 'Hyttinen', 4275, '1988-03-25','tomi.hyttinen@firma.fi', 5, '9414617164', '3452065055', NULL, 10),
(198, 'Sulho', 'Eriksson', 2450, '1995-12-16','sulho.eriksson@firma.fi', 5, '9411480161', '2259606810', NULL, 10),
(199, 'Saima', 'Tamminen', 2575, '1992-05-15','saima.tamminen@firma.fi', 5, '4534042680', '8543960802', NULL, 10),
(200, 'Sami', 'Kauppinen', 2925, '1988-11-14','sami.kauppinen@firma.fi', 4, '4539567157', '4539570332', NULL, 8),
(201, 'Sipi', 'Tuominen', 4200, '1988-02-02','sipi.tuominen@firma.fi', 4, '9411430727', '9417514430', NULL, 10),
(202, 'Salme', 'Tuovinen', 3950, '1988-07-09','salme.tuovinen@firma.fi', 4, '9418868655', '8544963745', NULL, 8),
(203, 'Mirva', 'Savolainen', 3850, '1991-06-25','mirva.savolainen@firma.fi', 5, '4536176115', '8543410466', NULL, 10),
(204, 'Reima', 'Lahtinen', 4875, '1996-05-13','reima.lahtinen@firma.fi', 4, '4537894208', '2254516753', NULL, 10),
(205, 'Raafael', 'Aaltonen', 4150, '1987-05-10','raafael.aaltonen@firma.fi', 4, '2252210863', '4534401506', NULL, 10),
(206, 'Mirkka', 'Sinokk', 6600, '1990-07-14','mirkka.sinokk@firma.fi', 1, '3455848628', '8545096587', NULL, 1),
(207, 'Peppi', 'Lappalainen', 2350, '1995-04-08','peppi.lappalainen@firma.fi', 5, '2256869041', '9417894473', NULL, 10),
(208, 'Samuel', 'Rautio', 5100, '1998-08-21','samuel.rautio@firma.fi', 5, '8542927298', '8547179852', NULL, 10),
(209, 'Miia', 'Kokkonen', 2350, '1993-01-08','miia.kokkonen@firma.fi', 3, '8549609679', '4531965393', NULL, 3),
(210, 'Sanna', 'Manninen', 3200, '1996-10-24','sanna.manninen@firma.fi', 5, '9418723968', '4538637917', NULL, 10),
(211, 'Roni', 'Salo', 2450, '1987-07-07','roni.salo@firma.fi', 3, '3456572023', '2255364499', NULL, 3),
(212, 'Pekko', 'Aaltonen', 3975, '1987-06-03','pekko.aaltonen@firma.fi', 4, '3459782629', '2251306164', NULL, 8),
(213, 'Teijo', 'Kangas', 2000, '1986-03-01','teijo.kangas@firma.fi', 3, '8545965170', '2257157199', NULL, 3),
(214, 'Raimo', 'Koivunen', 4750, '1993-05-24','raimo.koivunen@firma.fi', 4, '9414541951', '8542153520', NULL, 10),
(215, 'Mirja', 'Lindholm', 5900, '1994-01-26','mirja.lindholm@firma.fi', 1, '4533680996', '9416332313', NULL, 1);

-- Luodaan 2 uutta osastoa 
INSERT INTO `department` (`id`, `name`, `manager_id`) 
VALUES 
-- Manager ID toistaiseksi NULL
(6, 'Ohjelmistokehitys',NULL),
(7, 'IT-Tuki',NULL);

-- Lisätään yhteensä 15 työntekijää äsken tehdyille osastoille
INSERT INTO `employee` (`id`, `fname`, `lname`, `salary`, `bdate`, `email`, `department_id`, `phone1`, `phone2`, `image`, `supervisor_id`)
VALUES
(216, 'Pirita', 'Lahtinen', 5100, '1998-09-24','pirita.lahtinen@firma.fi', 6, '8543364668', '8546030127', NULL, 206),
(217, 'Tarmo', 'Huhtala', 3100, '1988-05-19','tarmo.huhtala@firma.fi', 7, '9418742808', '3458550364', NULL, 57),
(218, 'Minna', 'Salminen', 3200, '1998-10-12','minna.salminen@firma.fi', 7, '4539229869', '9411420793', NULL, 57),
(219, 'Pertti', 'Mustonen', 5300, '1989-12-22','pertti.mustonen@firma.fi', 6, '2258811481', '4534274044', NULL, 206),
(220, 'Paula', 'Pennanen', 2600, '1989-02-14','paula.pennanen@firma.fi', 7, '9415998466', '3456378964', NULL, 57),
(221, 'Melissa', 'Lehto', 5800, '1998-09-04','melissa.lehto@firma.fi', 6, '2259954663', '8545824125', NULL, 206),
(222, 'Roni', 'Lehtinen', 5200, '1995-01-16','roni.lehtinen@firma.fi', 6, '8542085180', '4535466544', NULL, 206),
(223, 'Mirva', 'Hakkarainen', 2600, '1987-07-17','mirva.hakkarainen@firma.fi', 7, '2253042697', '9416994600', NULL, 57),
(224, 'Saima', 'Eskelinen', 2200, '1993-03-01','saima.eskelinen@firma.fi', 7, '4537515034', '8541339428', NULL, 57),
(225, 'Robin', 'Partanen', 2200, '1994-09-05','robin.partanen@firma.fi', 7, '2255767240', '4539231247', NULL, 57),
(226, 'Tuomas', 'Paavola', 3000, '1991-04-26','tuomas.paavola@firma.fi', 7, '3457467081', '4539720811', NULL, 57),
(227, 'Sippo', 'Asikainen', 5300, '1992-12-04','sippo.asikainen@firma.fi', 6, '3452388860', '2255226840', NULL, 206),
(228, 'Reino', 'Kauppinen', 5500, '1986-06-01','reino.kauppinen@firma.fi', 6, '2253085928', '9416257169', NULL, 206),
(229, 'Saimi', 'Timonen', 5500, '1993-02-25','saimi.timonen@firma.fi', 6, '3457603443', '2258974880', NULL, 206),
(230, 'Roope', 'Halonen', 2400, '1996-10-06','roope.halonen@firma.fi', 7, '9419237687', '3456073266', NULL, 57);

-- Päivitetään Manager id
UPDATE department SET manager_id=206 WHERE id=6;
UPDATE department SET manager_id=57 WHERE id=7;
UPDATE department SET manager_id=3 WHERE id=3;



-- Tehtävä 7
-- Muutetaan vaihdetaan sukunimi taulukossa empoyee, missä id = 12
SELECT * FROM employee WHERE id=12;
UPDATE employee SET lname='Mäkinen' WHERE id=12;
SELECT * FROM employee WHERE id=12;



-- Tehtävä 8
-- Poistetaan puhelin2 taulukossa empoyee, missä id = 2, asetetaan arvoksi NULL
SELECT * FROM employee WHERE id=2;
UPDATE employee SET phone2=NULL WHERE id=2;
SELECT * FROM employee WHERE id=2;
SELECT * FROM employee;



-- Tehtävä 10
-- Kyseinen komento poisti kaiken datan taulukoista employee sekä works on
