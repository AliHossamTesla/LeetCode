# Write your MySQL query statement below
SELECT 
    ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM 
    Insurance as i1 
WHERE 
    tiv_2015 = ANY(
        SELECT 
            tiv_2015
        FROM 
            Insurance i2
        WHERE 
            i1.pid != i2.pid
    )
    AND 
    (lat, lon) NOT IN (
        SELECT 
            lat, 
            lon 
        FROM 
            Insurance i3
        WHERE 
            i1.pid != i3.pid
    );