# Write your MySQL query statement below
WITH t AS(
    SELECT 
        requester_id id,
        accepter_id rec
    FROM 
        RequestAccepted
        UNION 
    SELECT 
        accepter_id id,
        requester_id rec
    FROM 
        RequestAccepted
)
SELECT 
    id, 
    COUNT(*) AS num 
FROM 
    t
GROUP BY id
ORDER BY num DESC
LIMIT 1