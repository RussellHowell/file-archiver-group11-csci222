DROP SCHEMA IF EXISTS `filearchiver`;
CREATE SCHEMA IF NOT EXISTS `filearchiver` DEFAULT CHARACTER SET latin1 COLLATE
latin1_swedish_ci;
USE `filearchiver`;

CREATE  TABLE IF NOT EXISTS `filearchiver`.`blobtable`(
`tempname` INT(11) NOT NULL AUTO_INCREMENT,
`filedata` MEDIUMBLOB NOT NULL,
PRIMARY KEY(`tempname`))
ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `filearchiver`.`filerec`(
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
INDEX `fk_filerec` (`blobtable_filename` ASC),
CONSTRAINT `fk_filerec`
    FOREIGN KEY (`blobtable_filename`)
    REFERENCES `filearchiver`.`blobtable` (`tempname`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `filearchiver`.`versionrec`(
`idversionrec` INT(11) NOT NULL AUTO_INCREMENT,
`fileref` VARCHAR(255),
`versionnum` INT(11),
`length` INT(11),
`mtsec` INT(11),
`mtnsec` INT(11),
`ovhash` VARCHAR(45),
PRIMARY KEY(`idversionrec`),
INDEX `fk_versionrec` (`fileref` ASC),
CONSTRAINT `fk_versionrec`
    FOREIGN KEY(`fileref`)
    REFERENCES `filearchiver`.`filerec`(`filename`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `filearchiver`.`commentstable`(
`fileref` VARCHAR(255) NOT NULL,
`commentnum` INT(11) NOT NULL,
`commenttxt` MEDIUMTEXT,
PRIMARY KEY(`fileref, commentnum`),
INDEX `fk_commentstable` (`fileref` ASC),
CONSTRAINT `fk_commentstable`
    FOREIGN KEY(`fileref`)
    REFERENCES `filearchiver`.`filerec`(`filename`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `filearchiver`.`fileblkhashes`(
`fileref` VARCHAR(255) NOT NULL,
`blknum` INT(11) NOT NULL,
`hashval` VARCHAR(45),
`length` INT(11),
PRIMARY KEY(`fileref`, `blknum`),
INDEX `fk_fileblkhashes` (`fileref` ASC),
CONSTRAINT `fk_fileblkhashes`
    FOREIGN KEY(`fileref`)
    REFERENCES `filearchiver`.`filerec`(`filename`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `filearchiver`.`blktable`(
`version` INT(11) NOT NULL,
`blknum` INT(11) NOT NULL,
`length` INT(11),
`hash` VARCHAR(45),
`data` MEDIUMBLOB,
PRIMARY KEY(`version`, `blknum`),
INDEX `fk_blktable` (`version` ASC),
CONSTRAINT `fk_blktable`
    FOREIGN KEY(`version`)
    REFERENCES `filearchiver`.`versionrec`(`idversionrec`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;
