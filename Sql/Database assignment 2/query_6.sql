(
	SELECT *
	FROM "Likes"
)
	INTERSECT
(
	SELECT drinker, beer
	FROM "Sells", "Frequents"
 	WHERE "Frequents".bar = "Sells".bar
);