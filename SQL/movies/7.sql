SELECT title, rating
FROM movies
WHERE release_year = 2010 AND rating IS NOT NULL
ORDER BY rating DESC, title ASC;
