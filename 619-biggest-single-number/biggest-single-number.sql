# Write your MySQL query statement below
WITH t AS(
    SELECT 
        num 
    FROM
        MyNumbers 
    GROUP BY 
        num
    HaVING COUNT(*) = 1
)
SELECT 
    MAX(num) AS num 
FROM
    t;