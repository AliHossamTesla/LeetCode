# Write your MySQL query statement below
WITH P AS(
    SELECT 
        DISTINCT player_id 
    FROM 
        Activity
    WHERE 
        (player_id, DATE_SUB(event_date, INTERVAL 1 DAY)) IN (
            SELECT 
                player_id,
                MIN(event_date) AS first_log_in 
            FROM 
                Activity
            GROUP BY
                player_id
        )
)
SELECT 
    ROUND(
        COUNT(*)/(
            SELECT 
                COUNT(DISTINCT player_id)
            FROM 
                Activity
        ), 2
    ) AS fraction
FROM 
    P;