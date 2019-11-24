SELECT beer
FROM "Sells"
WHERE price >= ALL
(
    SELECT price
    FROM "Sells"
);