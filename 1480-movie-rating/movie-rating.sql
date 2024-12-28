# Write your MySQL query statement below
WITH us AS(
    SELECT 
        u1.user_id, name 
    FROM 
        Users u1
    LEFT JOIN MovieRating m ON u1.user_id = m.user_id
    GROUP By u1.user_id, u1.name
    ORDER BY COUNT(rating) DESC, name
    lIMIT 1
), mv AS(
    SELECT 
        m1.movie_id, m1.title
    FROM 
        Movies m1
    LEFT JOIN MovieRating m ON m1.movie_id = m.movie_id
    WHERE 
        MONTH(created_at) = 2 AND YEAR(created_at) = 2020
    GROUP BY m1.movie_id, m1.title 
    ORDER BY AVG(rating) DESC, title
    lIMIT 1
)
SELECT 
    name AS results      
FROM 
    us 
UNION ALL 
SELECT 
    title AS results    
FROM 
    mv