SELECT 
    (
        CASE 
        WHEN MOD(id, 2) <> 0 AND id = cnt THEN id
        WHEN MOD(id, 2) <> 0 AND id <> cnt THEN id + 1
        ELSE id - 1
        END
    ) AS id,
    student 
FROM
    seat,(
        SELECT 
            COUNT(*) AS cnt
        FROM 
            seat 
    ) AS s2
ORDER BY id ASC;