CREATE TABLE IF NOT EXISTS "public"."product"
(
    "barcode" TEXT NOT NULL PRIMARY KEY,
    "name" TEXT NOT NULL,
    "package_size" TEXT NOT NULL,
    "weight" FLOAT NOT NULL
);

INSERT INTO "public"."product"
  VALUES ('barcode', 'name of product', '1.0*1.0*0.5', 1.0);

DROP FUNCTION f_get_all_products;
CREATE OR REPLACE FUNCTION f_get_all_products("p_barcode" TEXT)
    RETURNS TABLE("barcode" TEXT, "name" TEXT, "package_size" TEXT, "weight" FLOAT)
    LANGUAGE SQL
AS $$
    SELECT *
        FROM "public"."product" "p"
        WHERE "p_barcode" = "p"."barcode";

    SELECT *
        FROM "public"."product" "p"
        WHERE 1=1;
$$;