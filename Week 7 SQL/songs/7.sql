SELECT AVG(energy)
AS drakes_songs_energy
FROM songs
WHERE artist_id = (
    SELECT id
    FROM artists
    WHERE name = 'Drake'
);