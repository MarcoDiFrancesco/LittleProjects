SELECT "Sells".bar
FROM "Sells", "Likes"
WHERE
  "Sells".beer = "Likes".beer
AND
  "Likes".drinker = 'Joe';