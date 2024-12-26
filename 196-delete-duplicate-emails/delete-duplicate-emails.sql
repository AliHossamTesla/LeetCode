WITH firstId AS(
    SElECT
        MIN(id) AS keep_id 
    FROM 
        Person
    GROUP BY email
)
DELETE FROM 
    Person
WHERE 
    id NOT IN(
        SELECT 
            * 
        FROM 
            firstId
    )