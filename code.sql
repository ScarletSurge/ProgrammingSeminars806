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

INSERT INTO "public"."publishers"("id", "name", "employees_count")
  VALUES (3, 'publisher demo', 75), (4, 'other publisher', 30);

DELETE FROM "public"."publishers"
  WHERE ("employees_count" BETWEEN 100 AND 150) AND ("id" >= 3 OR "id" = 0); --"employees_count" >= 350 AND "employees_count" <= 650;

UPDATE "public"."publishers"
    SET "name" = 'updated name',
        "employees_count" = 125
    WHERE "id" = 3;

DROP VIEW "public"."view_example";
CREATE OR REPLACE VIEW "public"."view_example" AS
    SELECT "id" FROM "public"."publishers";

SELECT * FROM "public"."view_example";

SELECT *
  FROM "public"."publishers" AS "alias1",
       "public"."publishers" AS "alias2"
  WHERE "alias1"."id" = 1 AND "alias2"."id" = 1;

SELECT
    "pu"."name" AS "publisher_name",
    "subq"."name" AS "name_from_subquery",
    "pu"."id" AS "id",
    "vi"."id" + 10 AS "modified_id",
    "subq"."copies_sold" AS "copies_sold_from_subq",
    10 AS "const_value"
  FROM "public"."publishers" AS "pu",
       "public"."view_example" AS "vi",
       (SELECT * FROM "public"."games_info") AS "subq"
  WHERE <expr>
  ORDER BY "modified_id" DESC, "id" ASC;

CREATE TABLE IF NOT EXISTS "public"."departments"
(
    "id" INT NOT NULL PRIMARY KEY,
    "name" TEXT NOT NULL
);

INSERT INTO "public"."departments"("id", "name")
    VALUES (1, 'Dep1'), (2, 'Dep2'), (3, 'Dep3');

SELECT COUNT(*)
    FROM "public"."departments";

CREATE TABLE IF NOT EXISTS "public"."employees"
(
    "id" INT NOT NULL PRIMARY KEY,
    "surname" TEXT NOT NULL,
    "name" TEXT NOT NULL,
    "salary" MONEY NOT NULL,
    "department_id" INT,
    FOREIGN KEY("department_id") REFERENCES "public"."departments"("id")
);

DROP TABLE "public"."employees"

INSERT INTO "public"."employees"("id", "surname", "name", "salary", "department_id")
    VALUES (1, 'sur1', 'name1', 100, 1),
           (2, 'sur2', 'name2', 120, 2),
           (3, 'sur3', 'name3', 125, 1),
           (4, 'sur4', 'name4', 130, 3),
           (5, 'sur5', 'name5', 150, 2),
           (6, 'sur6', 'name6', 100, 1),
           (7, 'sur7', 'name7', 95, NULL);

SELECT "department_id" AS "dep_id",
       AVG("salary"::numeric) AS "avg_salary"
    FROM "public"."employees", "public"."departments"
    GROUP BY "department_id"
    ORDER BY "dep_id";

SELECT * FROM "public"."employees"
  ORDER BY "department_id";

SELECT *
  FROM "public"."departments" AS "d1", "public"."departments" AS "d2";

SELECT *
  FROM "public"."departments" AS "d1"
    CROSS JOIN "public"."departments" AS "d2";

INSERT INTO "public"."departments"("id", "name")
    VALUES (4, 'Dep4');

SELECT *
  FROM "public"."employees" AS "e"
    INNER JOIN "public"."departments" AS "d"
      ON "e"."department_id" = "d"."id";



--SELECT [column1 AS alias1, f(column1) AS alias2, expression AS alias3, ...]
--  FROM [{table_name|view_name|subquery},...]
--  GROUP BY {column_name},[{column_name}...]
--  [WHERE <conditional_expression_on_row>]