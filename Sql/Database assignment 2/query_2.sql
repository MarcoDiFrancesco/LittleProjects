SELECT sells1.bar
FROM "Sells" sells1, "Sells" sells2
WHERE sells1.bar = sells2.bar
AND sells1.beer = 'Miller'
AND sells2.beer = 'Bud'
AND sells1.price = sells2.price