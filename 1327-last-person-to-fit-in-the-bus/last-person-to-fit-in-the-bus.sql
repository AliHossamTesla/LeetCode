WITH CumulativeWeights AS (
    SELECT 
        turn,
        person_name,
        SUM(weight) OVER (ORDER BY turn) AS cumulative_weight
    FROM 
        Queue
)
SELECT 
    person_name
FROM 
    CumulativeWeights
WHERE 
    cumulative_weight <= 1000
ORDER BY 
    turn DESC
lIMIT 1;
