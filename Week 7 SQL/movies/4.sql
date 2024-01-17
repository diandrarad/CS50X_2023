SELECT COUNT(*)
AS ten_out_of_ten_movies
FROM movies
WHERE id IN (
    SELECT movie_id
    FROM ratings
    WHERE rating = 10.0
);