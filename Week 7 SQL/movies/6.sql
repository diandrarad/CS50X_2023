SELECT AVG(rating)
AS avg_rating_2012
FROM ratings
WHERE movie_id IN (
    SELECT id
    from movies
    where year = 2012
);