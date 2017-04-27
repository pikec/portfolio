CREATE TABLE actors(
`actor_id` INT(11) UNSIGNED NOT NULL AUTO_INCREMENT,
`fname` VARCHAR(25) NOT NULL,
`lname` VARCHAR(25) NOT NULL,
`dob` DATE,
`dod` DATE,
`state` VARCHAR(25),
`city` VARCHAR(25),
PRIMARY KEY (actor_id)
)ENGINE = InnoDB;

CREATE TABLE studios(
`studio_id` INT (11) UNSIGNED NOT NULL AUTO_INCREMENT,
`name` VARCHAR(50) NOT NULL,
`hq` VARCHAR(100),
`founded` DATE,
PRIMARY KEY (`studio_id`)
)ENGINE = InnoDB;

CREATE TABLE films(
`film_id` INT(11) UNSIGNED NOT NULL AUTO_INCREMENT,
`title` VARCHAR(100) NOT NULL,
`released` DATE,
`budget` LONG,
`genre` VARCHAR(20),
`rating` VARCHAR(8),
`globe` TINYINT (2),
`oscar` TINYINT (2),
`studio_id` INT(11) UNSIGNED NOT NULL,
PRIMARY KEY (`film_id`),
FOREIGN KEY (`studio_id`) references studios (studio_id)
)ENGINE = InnoDB;

CREATE TABLE characters(
`char_id` INT(11) unsigned not null auto_increment,
`fname` VARCHAR(25) NOT NULL,
`lname` VARCHAR(25) NOT NULL,
`globe_win` BOOL,
`oscar_win` bool,
`actor_id` INT(11) UNSIGNED NOT NULL,
`film_id` INT(11) UNSIGNED NOT NULL,
PRIMARY KEY (`char_id`),
foreign key (`actor_id`) references actors (`actor_id`),
foreign key (`film_id`) references films (`film_id`)
)ENGINE=InnoDB;

CREATE TABLE have (
`actor_id` INT UNSIGNED NOT NULL,
`film_id` INT UNSIGNED NOT NULL,
foreign key (`actor_id`) references actors (`actor_id`),
foreign key (`film_id`) references films (`film_id`)
)ENGINE=InnoDB;
