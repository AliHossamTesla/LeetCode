# Write your MySQL query statement below
SELECT 
    id, 
    COUNT(*) AS num 
FROM (
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
) AS t
GROUP BY id
ORDER BY num DESC
LIMIT 1