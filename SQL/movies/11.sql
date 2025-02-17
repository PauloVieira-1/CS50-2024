SELECT m.title
FROM movies m
JOIN roles r ON m.movie_id = r.movie_id
JOIN actors a ON r.actor_id = a.actor_id
WHERE a.name = 'Chadwick Boseman'
ORDER BY m.rating DESC
LIMIT 5;
