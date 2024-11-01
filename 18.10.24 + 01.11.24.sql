-- DDL - Data Definition Language
-- CREATE, DROP, ALTER, TRUNCATE

-- DML
-- DCL
-- TCL

DROP DATABASE IF EXISTS HelloWorld

CREATE DATABASE HelloWorld
DROP TABLE "public"."student"

CREATE TABLE "public"."student"
(
    "surname" VARCHAR NOT NULL,
    "name" VARCHAR NOT NULL,
    "patronymic" VARCHAR NOT NULL,
    "birth_date" DATE NOT NULL,
    "sex" BOOLEAN NOT NULL,
    "course" INT NOT NULL,
    "group" VARCHAR NOT NULL,
    "diploma_theme" VARCHAR NULL
)

ALTER TABLE "public"."student"
    ADD CONSTRAINT "UNQ__diploma_theme" UNIQUE("diploma_theme");

ALTER TABLE "public"."student"
    DROP CONSTRAINT "UNQ__diploma_theme"

ALTER TABLE "public"."student"
    ADD COLUMN "grade_book_number" VARCHAR NOT NULL DEFAULT('123456');

ALTER TABLE "public"."student"
    ADD CONSTRAINT "CHK_smth" CHECK ("course" BETWEEN 1 AND 5);

ALTER TABLE "public"."student"
    ADD CONSTRAINT "PK__grade_book_number" PRIMARY KEY("grade_book_number");

INSERT INTO "public"."student"("grade_book_number", "name", "surname", "patronymic", "birth_date", "sex", "course", "group", "diploma_theme")
    VALUES ('123458', 'Кешабян', 'Руслан', 'Русланович', DATE('02.05.2004'), TRUE, 3, 'мпм-122', 'тема диплома'), ('123457', 'Забоев', 'Артём', 'Сергеевич', DATE('12.08.2004'), TRUE, 3, 'мпм-122', 'диплом not found :/');

INSERT INTO "public"."student"("name", "surname", "patronymic", "birth_date", "sex", "course", "group", "diploma_theme")
    VALUES ('Алпеева', 'Екатерина', 'Андреевна', DATE('03.01.2004'), FALSE, 3, 'мпм-122', 'тема диплома o_O')

SELECT * FROM "public"."student"

SELECT "s"."grade_book_number"
    FROM "public"."student" "s"
    WHERE 1 = 1;

-- CRUD

SELECT *
    FROM "public"."student"
    WHERE 1=1
        AND "surname" LIKE '%а%б%'

SELECT *
    FROM "public"."student";

DELETE
    FROM "public"."student"
    WHERE "name" LIKE '%аб%'

UPDATE "public"."student"
    SET "group" = 'мпм-123',
        "course" = 2
    WHERE "grade_book_number" = '123457'

SELECT *
    FROM "public"."student";

SELECT "course", COUNT(*)
    FROM "public"."student"
    GROUP BY "course"
        HAVING "course" != 2

SELECT *
    FROM "public"."student"
    ORDER BY "name" DESC

-- UNION ALL -> UNION

SELECT *
    FROM (
        (SELECT *
            FROM "public"."student")
        UNION
        (SELECT
            "surname",
            "name",
            "patronymic",
            "birth_date",
            "sex",
            "course",
            "group",
            "diploma_theme",
            "grade_book_number"
            FROM "public"."student"
            WHERE NOT ("name" LIKE '%Кешабян%'))
        ) AS "subq"
    ORDER BY "course" DESC

SELECT *
    FROM "public"."student";
        -- {INNER, LEFT, RIGHT, FULL, CROSS} JOIN <joinable_data_set>
            -- FOR ALL JOINS EXCEPT CROSS: <joining_expression>

DROP TABLE "public"."groups"
CREATE TABLE IF NOT EXISTS "public"."groups"
(
    "id" INT NOT NULL PRIMARY KEY,
    "course" INT NOT NULL CHECK("course" >= 1 AND "course" <= 5),
    "name" TEXT NOT NULL
)

ALTER TABLE "public"."groups"
    ADD CONSTRAINT UQ__course_name UNIQUE("course", "name");

INSERT INTO "public"."groups" ("id", "course", "name")
    VALUES (1, 1, 'мпм-124'),
           (2, 2, 'мпм-123'),
           (3, 3, 'мпм-122'),
           (4, 4, 'мпм-121'),
           (5, 1, 'мви-124'),
           (6, 3, 'мви-122')

SELECT * FROM "public"."groups";

ALTER TABLE "public"."student"
    DROP COLUMN IF EXISTS "course"

ALTER TABLE "public"."student"
    DROP COLUMN IF EXISTS "group"

ALTER TABLE "public"."student"
    ADD COLUMN "group_id" INT NULL

ALTER TABLE "public"."student"
    ADD CONSTRAINT "FK___student__group_id___groups__id" FOREIGN KEY("group_id") REFERENCES "public"."groups"("id");

UPDATE "public"."student"
    SET "group_id" = NULL
        WHERE "surname" LIKE '%Арт%'

SELECT *
    FROM "public"."student" AS "st"
        FULL JOIN "public"."groups" AS "gr"
            ON "st"."group_id" = "gr"."id"
UNION ALL
SELECT *
    FROM "public"."student" AS "st"
        INNER JOIN "public"."groups" AS "gr"
            ON TRUE

-- UNION / UNION ALL
-- JOIN (INNER, LEFT, RIGHT, FULL, CROSS)
-- CTE + WITH + RECURSIVE SELECT
-- WINDOW FUNCTIONS / AGGREGATE FUNCTIONS

CREATE OR REPLACE PROCEDURE hranimka()
LANGUAGE sql
AS
$$
    SELECT *
        FROM "public"."student" AS "st"
            FULL JOIN "public"."groups" AS "gr"
                ON "st"."group_id" = "gr"."id"
    UNION ALL
    SELECT *
        FROM "public"."student" AS "st"
            INNER JOIN "public"."groups" AS "gr"
                ON TRUE;

    -- SELECT * FROM "public"."groups";
$$;

CALL hranimka();

CREATE OR REPLACE FUNCTION my_function()
    RETURNS TABLE("surname" TEXT, "name" TEXT, "patronymic" TEXT)
    LANGUAGE sql
AS
$$
    SELECT "surname" AS "surname",
           "st"."name" AS "name",
           "patronymic" AS "patronymic"
        FROM "public"."student" AS "st"
            FULL JOIN "public"."groups" AS "gr"
                ON "st"."group_id" = "gr"."id"
    UNION ALL
    SELECT "surname" AS "surname",
           "st"."name" AS "name",
           "patronymic" AS "patronymic"
        FROM "public"."student" AS "st"
            INNER JOIN "public"."groups" AS "gr"
                ON TRUE;

    -- SELECT * FROM "public"."groups";
$$;

SELECT * FROM my_function()