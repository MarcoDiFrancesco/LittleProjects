SELECT "Frequents".drinker
FROM "Frequents", "Likes", "Sells"
WHERE
	"Likes".drinker = "Frequents".drinker
AND
	"Sells".beer = "Likes".beer
AND
	"Frequents".bar = "Sells".bar;