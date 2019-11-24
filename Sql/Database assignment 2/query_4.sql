SELECT name
FROM "Beers" beers1
WHERE NOT EXISTS (
	SELECT *
	FROM "Beers" beers2
	WHERE
		beers2.manf = beers1.manf
	AND
		beers2.name <> beers1.name
)