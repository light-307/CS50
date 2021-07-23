SELECT title FROM movies 
JOIN stars ON movies.id = stars.movie_id 
JOIN people ON stars.person_id = people.id 
WHERE name = 'Johnny Depp' OR name = 'Helena Bonham Carter'
GROUP BY title HAVING count(title) >1;