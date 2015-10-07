/*DROP SCHEMA IF EXISTS `student25`;
CREATE SCHEMA IF NOT EXISTS `student25` DEFAULT CHARACTER SET latin1 COLLATE
latin1_swedish_ci;
USE `filearchiver`;*/

CREATE  TABLE IF NOT EXISTS `student25`.`blobtable`( 
`tempname` INT(11) NOT NULL AUTO_INCREMENT, 
`filedata` MEDIUMBLOB NOT NULL,
PRIMARY KEY(`tempname`)) 
ENGINE = InnoDB;

CREATE  TABLE IF NOT EXISTS `student25`.`blobtable`(
`tempname` INT(11) NOT NULL AUTO_INCREMENT,
`filedata` MEDIUMBLOB NOT NULL,
PRIMARY KEY(`tempname`))
ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `student25`.`filerec`(
`filename` VARCHAR(255) NOT NULL,
`curhash` VARCHAR(45),
`ovhash` VARCHAR(45),
`currentversion` INT(11),
`nversions` INT(11),
`length` INT(11),
`mtsec` INT(11),
`mtnsec` INT(11),
`blobtable_tempname` INT(11),
PRIMARY KEY (`filename`),
CONSTRAINT `fk_filerec`
    FOREIGN KEY (`blobtable_tempname`)
    REFERENCES `student25`.`blobtable` (`tempname`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `student25`.`versionrec`(
`idversionrec` INT(11) NOT NULL AUTO_INCREMENT,
`fileref` VARCHAR(255),
`versionnum` INT(11),
`length` INT(11),
`mtsec` INT(11),
`mtnsec` INT(11),
`ovhash` VARCHAR(45),
PRIMARY KEY(`idversionrec`),
CONSTRAINT `fk_versionrec`
    FOREIGN KEY(`fileref`)
    REFERENCES `student25`.`filerec`(`filename`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `student25`.`commentstable`(
`fileref` VARCHAR(255) NOT NULL,
`commentnum` INT(11) NOT NULL,
`commenttxt` MEDIUMTEXT,
PRIMARY KEY(`fileref`, `commentnum`),
CONSTRAINT `fk_commentstable`
    FOREIGN KEY(`fileref`)
    REFERENCES `student25`.`filerec`(`filename`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `student25`.`fileblkhashes`(
`fileref` VARCHAR(255) NOT NULL,
`blknum` INT(11) NOT NULL,
`hashval` VARCHAR(45),
`length` INT(11),
PRIMARY KEY(`fileref`, `blknum`),
CONSTRAINT `fk_fileblkhashes`
    FOREIGN KEY(`fileref`)
    REFERENCES `student25`.`filerec`(`filename`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `student25`.`blktable`(
`version` INT(11) NOT NULL,
`blknum` INT(11) NOT NULL,
`length` INT(11),
`hash` VARCHAR(45),
`data` MEDIUMBLOB,
PRIMARY KEY(`version`, `blknum`),
CONSTRAINT `fk_blktable`
    FOREIGN KEY(`version`)
    REFERENCES `student25`.`versionrec`(`idversionrec`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;
