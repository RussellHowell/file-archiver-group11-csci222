DROP SCHEMA IF EXISTS `filearchiver`;
CREATE SCHEMA IF NOT EXISTS `filearchiver` DEFAULT CHARACTER SET latin1 COLLATE
latin1_swedish_ci;
USE `filearchiver`;

CREATE TABLE IF NOT EXISTS `mydb`.`filerec` ( 
`filename` VARCHAR(255) NOT NULL , 
`curhash` INT(11), 
`ovhash` INT(11), 
`currentversion` INT(11), 
`nversions` INT(11), 
`length` INT(11), 
`mtnsec` INT(11), 
`mtsec` INT(11), 
`blobtable_tempname` VARCHAR(45), 
PRIMARY KEY (`filename`) ) 
FOREIGN KEY (`blobtable_filename` ) 
REFERENCES `mydb`.`blobtable` (`tempname` ) 
ENGINE = InnoDB; 

CREATE  TABLE IF NOT EXISTS `mydb`.`blobtable` ( 
`tempname` VARCHAR(45) NOT NULL , 
`filedata` MEDIUMBLOB NOT NULL , 
CONSTRAINT `fk_Roles_MyRecord` 
PRIMARY KEY(`tempname`)) 
ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `mydb`.`commentstable`(
`idcommentstable` INT(11) NOT NULL,
`fileref` VARCHAR(255),
`commentnum` INT(11),
`commenttxt` MEDIUMTEXT,
PRIMARY KEY(`idcommentstable`))
FOREIGN KEY(`fileref`)
REFERENCES `mydb`.`filerec`(`filename`)
ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `mydb`.`fileblkhashes`(
`idfileblkhashes` INT(255) NOT NULL,
`fileref` VARCHAR(255),
`blknum` INT(11),
`hashval` INT(11),
PRIMARY KEY(`idfileblkhashes`))
FOREIGN KEY(`fileref` ) 
REFERENCES `mydb`.`filerec`(`filename`) 
ENGINE = InnoDB; 

CREATE TABLE IF NOT EXISTS `mydb`.`blktable`( 
`idblktable` INT(11) NOT NULL,
`version` INT(11),
`length` INT(11),
`blknum` INT(11),
`hash` INT(11),
`data` MEDIUMBLOB,
PRIMARY KEY(`filename`)) 
FOREIGN KEY(`version` ) 
REFERENCES `mydb`.`versionrec`(`idversionrec`) 
ENGINE = InnoDB; 

CREATE TABLE IF NOT EXISTS `mydb`.`versionrec`( 
`idversionrec` INT(11) NOT NULL,
`fileref` VARCHAR(255),
`versionnum` INT(11),
`length` INT(11),
`mtsec` INT(11),
`mtnsec` INT(11),
`ovhash` int(11),
PRIMARY KEY(`idversion`)) 
FOREIGN KEY(`fileref`)
REFERENCES `mydb`.`filerec`(`filename`)
ENGINE = InnoDB;
