WITH us AS (
    SELECT 
        u.user_id, 
        u.name
    FROM 
        Users u
    JOIN 
        MovieRating m ON u.user_id = m.user_id
    GROUP BY 
        u.user_id, u.name
    ORDER BY 
        COUNT(m.rating) DESC, u.name
    LIMIT 1
), 
mv AS (
    SELECT 
        m.movie_id, 
        mv.title
    FROM 
        Movies mv
    JOIN 
        MovieRating m ON mv.movie_id = m.movie_id
    WHERE 
        MONTH(m.created_at) = 2 AND YEAR(m.created_at) = 2020
    GROUP BY 
        m.movie_id, mv.title
    ORDER BY 
        AVG(m.rating) DESC, mv.title
    LIMIT 1
)
SELECT name AS results FROM us
UNION ALL
SELECT title AS results FROM mv;
