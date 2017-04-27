INSERT INTO studios (name, hq, founded) VALUES ("Paramount", "HollyWood", "1912/08/05");
INSERT INTO studios (name, hq, founded) VALUES ("Warner Brothers", "HollyWood", "1923/04/04");
INSERT INTO studios (name, hq, founded) VALUES ("Columbia", "Culver City", "1924/10/01");
INSERT INTO studios (name, hq, founded) VALUES ("United Artists", "Beverly Hills", "1919/05/02");
INSERT INTO studios (name, hq, founded) VALUES ("Touchstone", "Burbank", "1984/02/16");
INSERT INTO studios (name, hq, founded) VALUES ("Amblin", "HollyWood", "1981/01/01");
INSERT INTO studios (name, hq, founded) VALUES ("Miramax", "HollyWood", "1979/01/01");

INSERT INTO actors (fname, lname, dob, city, state) VALUES ("Leonardo", "DiCaprio", "1974/11/11", "Hollywood", "CA");
INSERT INTO actors (fname, lname, dob, city, state) VALUES ("Robert", "DeNiro", "1943/8/17", "Greenwich Village", "NY");
INSERT INTO actors (fname, lname, dob, dod, city, state) VALUES ("Paul", "Newman", "1925/01/26","2008/09/26","Shaker Heights", "OH");
INSERT INTO actors (fname, lname, dob, city, state) VALUES ("Daniel", "Day-Lewis", "1957/04/29", "Greenwich", "UK");
INSERT INTO actors (fname, lname, dob, city, state) VALUES ("Joe", "Pesci", "1943/02/09", "Newark", "NJ");
INSERT INTO actors (fname, lname, dob, city, state) VALUES ("Winnona", "Ryder", "1971/10/29", "Olmsted County", "MN");
INSERT INTO actors (fname, lname, dob, city, state) VALUES ("Cate", "Blanchett", "1929/05/14", "Melbourne", "AU");
INSERT INTO actors (fname, lname, dob, city, state) VALUES ("Paul", "Sorvino", "1939/04/13", "Brooklyn", "NY");
INSERT INTO actors (fname, lname, dob, city, state) VALUES ("Jodi", "Foster", "1962/11/19", "Los Angeles", "CA");
INSERT INTO actors (fname, lname, dob, city, state) VALUES ("Nick", "Nolte", "1941/02/08", "Omaha", "NE");

INSERT INTO films (title, released, budget, genre, rating, globe, oscar, studio_id) VALUES (
"Wolf of Wall Street", "2013/12/25", "100000000", "drama", "R", "1", "0", (
SELECT studio_id FROM studios WHERE name = "Paramount"));
INSERT INTO films (title, released, budget, genre, rating, globe, oscar, studio_id) VALUES (
"The Departed", "2006/10/06", "90000000", "crime", "R", "1", "4", (
SELECT studio_id FROM studios WHERE name = "Warner Brothers"));
INSERT INTO films (title, released, budget, genre, rating, globe, oscar, studio_id) VALUES (
"The Aviator", "2004/12/25", "110000000", "biography", "PG-13", "3", "5", (
SELECT studio_id FROM studios WHERE name = "Warner Brothers"));
INSERT INTO films (title, released, budget, genre, rating, globe, oscar, studio_id) VALUES (
"The Age of Innocence", "1993/10/01","30000000", "drama","PG", "1", "1", (
SELECT studio_id FROM studios WHERE name = "Columbia"));
INSERT INTO films (title, released, budget, genre, rating, globe, oscar, studio_id) VALUES (
"Goodfellas", "1990/09/21", "25000000", "biography", "R", "0", "1", (
SELECT studio_id FROM studios WHERE name = "Warner Brothers"));
INSERT INTO films (title, released, budget, genre, rating, globe, oscar, studio_id) VALUES (
"Raging Bull", "1980/12/19", "18000000", "biography","R", "1", "2", (
SELECT studio_id FROM studios WHERE name = "United Artists"));


INSERT INTO characters (fname, lname, globe_win, oscar_win, actor_id, film_id) VALUES (
"Jordon", "Belfort", "1", "0", 
(SELECT actor_id FROM actors WHERE fname = "Leonardo" and lname ="DiCaprio"),
(SELECT film_id FROM films WHERE title = "Wolf of Wall Street")); 
INSERT INTO characters (fname, lname, globe_win, oscar_win, actor_id, film_id) VALUES (
"Howard", "Hughes", "1", "0", 
(SELECT actor_id FROM actors WHERE fname = "Leonardo" and lname ="DiCaprio"), 
(SELECT film_id FROM films WHERE title = "The Aviator")); 
INSERT INTO characters (fname, lname, globe_win, oscar_win, actor_id, film_id) VALUES (
"Kateherine", "Hepburn", "0", "1", 
(SELECT actor_id FROM actors WHERE fname = "Cate" and lname ="Blanchett"), 
(SELECT film_id FROM films WHERE title = "The Aviator"));
INSERT INTO characters (fname, lname, globe_win, oscar_win, actor_id, film_id) VALUES (
"Tommy", "DeVito", "0", "1", 
(SELECT actor_id FROM actors WHERE fname = "Joe" and lname ="Pesci"), 
(SELECT film_id FROM films WHERE title = "Goodfellas"));
INSERT INTO characters (fname, lname, globe_win, oscar_win, actor_id, film_id) VALUES (
"Jake", "LaMotta", "1", "1", 
(SELECT actor_id FROM actors WHERE fname = "Robert" and lname ="DeNiro"), 
(SELECT film_id FROM films WHERE title = "Raging Bull"));

 

INSERT INTO have (actor_id, film_id) VALUES (
(SELECT actor_id FROM actors WHERE fname ="Leonardo" and lname= "DiCaprio"),
(SELECT film_id FROM films WHERE title ="Wolf of Wall Street"));
INSERT INTO have (actor_id, film_id) VALUES (
(SELECT actor_id FROM actors WHERE fname ="Leonardo" and lname= "DiCaprio"),
(SELECT film_id FROM films WHERE title ="The Aviator"));
INSERT INTO have (actor_id, film_id) VALUES (
(SELECT actor_id FROM actors WHERE fname ="Cate" and lname= "Blanchett"),
(SELECT film_id FROM films WHERE title ="The Aviator"));
INSERT INTO have (actor_id, film_id) VALUES (
(SELECT actor_id FROm actors WHERE fname ="Joe" and lname= "Pesci"),
(SELECT film_id FROM films WHERE title ="Goodfellas"));
INSERT INTO have (actor_id, film_id) VALUES (
(SELECT actor_id FROM actors WHERE fname ="Robert" and lname= "DeNiro"),
(SELECT film_id FROM films WHERE title ="Raging Bull"));

