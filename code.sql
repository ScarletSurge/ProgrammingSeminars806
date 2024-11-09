CREATE DATABASE hello_world_db;


DROP TABLE "public"."student"
CREATE TABLE "public"."student"
(
    "surname" TEXT NOT NULL,
    "name" TEXT NOT NULL,
    "patronymic" TEXT NOT NULL,
    "sex" BOOL NOT NULL,
    "birth_date" DATE NOT NULL,
    "group" TEXT NOT NULL
);

DROP TABLE "public"."student";

ALTER TABLE "public"."student"
    DROP COLUMN "course";

ALTER TABLE "public"."student"
    ADD COLUMN "course" INT NOT NULL DEFAULT(1);

-- CONSTRAINTS:
    -- NULL, NOT NULL (column/attribute)
    -- DEFAULT (column/attribute)
    -- UNIQUE (column/column set)
    -- CHECK (table)
    -- [ABSTRACT] POTENTIAL KEY (column/column set)
    -- PRIMARY KEY (column/column set)
    -- FOREIGN KEY (column/column set)
-- DDL: CREATE, DROP, ALTER, ADD
-- DDL INFRA SUBSTANCES: DATABASE, TABLE, STORED PROCEDURE, FUNCTION, VIEW, TRIGGER
--

SELECT * FROM "public"."student";

INSERT INTO "public"."student" VALUES ('Иванов', 'Иван', 'Иванович', TRUE, DATE('01.01.1995'), 'group')

-- AND OR NOT
CREATE TABLE "public"."constraints_test"
(
    "key" INT NULL UNIQUE, --DEFAULT(10),
    "value" INT NULL --,
    -- UNIQUE("key", "value"),
    -- CHECK("key" >= 10 AND "key" <= 15)
    -- CHECK("key" BETWEEN 10 AND 15)
);

-- TEST FOR INSERTING NULL VALUE WITH NOT NULL CONSTRAINT

INSERT INTO "public"."constraints_test"("value", "key")
  VALUES (NULL, NULL);

SELECT * FROM "public"."constraints_test";

-- NULL != NULL

DROP TABLE "public"."constraints_test"

--

CREATE TABLE "public"."games_info"
(
    "id" INT NOT NULL,
    "name" TEXT NOT NULL,
    "publish_date" DATE NOT NULL,
    "copies_sold" INT NOT NULL,
    "publisher_price" MONEY NOT NULL,
    CHECK ("publish_date" >= DATE('2000/01/01')), -- Y/M/D
    CHECK ("publisher_price" > CAST(0 AS MONEY)),
    PRIMARY KEY("id")
);

SELECT * FROM "public"."publishers";
SELECT * FROM "public"."games_info";

INSERT INTO "public"."games_info"("name", "id", "publish_date", "copies_sold", "publisher_price", "publisher_id")
    VALUES ('My game', 3, CAST('2010/03/10' AS DATE), 50000, 50, 2);

ALTER TABLE "public"."games_info"
    ADD COLUMN "publisher_id" INT NOT NULL DEFAULT(0);

CREATE TABLE "public"."publishers"
(
    "id" INT NOT NULL,
    "name" TEXT NOT NULL,
    "employees_count" INT NOT NULL,
    CHECK ("employees_count" > 0),
    PRIMARY KEY("id")
)

INSERT INTO "public"."publishers"("id", "name", "employees_count")
    VALUES (1, 'Game production company', 10), (2, 'Other company', 50);

DELETE FROM "public"."publishers"
    WHERE "id" = 2;


INSERT INTO "public"."publishers"("id", "name", "employees_count")
    VALUES (0, 'Unknown publisher', 1)

ALTER TABLE "public"."games_info"
    ADD CONSTRAINT "FK___games_info__publisher_id___publishers__id" FOREIGN KEY("publisher_id")
        REFERENCES "public"."publishers"("id") ON DELETE CASCADE

-- n -> 2^n
-- 1 -> 2: {}

-- 1NF: rows uniqueness (use PRIMARY KEY) AND attributes value atomicity
-- 2NF: 1NF AND PRIMARY NOT not decomposable
-- 3NF: 2NF AND