SELECT *
FROM "Beers"
WHERE name IN (
	SELECT beer
    FROM "Likes"
    WHERE drinker = 'Fred'
)