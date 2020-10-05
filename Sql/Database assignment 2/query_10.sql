SELECT drinker
FROM "Frequents"
WHERE drinker
NOT IN (
	SELECT frequents1.drinker
	FROM "Frequents" frequents1
	WHERE frequents1.bar
	NOT IN (
		SELECT bar
		FROM "Sells", "Likes"
		WHERE
			"Likes".drinker = frequents1.drinker
		AND
			"Sells".beer = "Likes".beer
	)
);