# Write your MySQL query statement below
WITH p AS(
    SELECT 
        m.product_id,
        SUM(m.unit) AS units
    FROM (
        SELECT 
            * 
        FROM 
            Orders
        WHERE Orders.order_date LIKE '2020-02-%'
    ) AS m 
    GROUP BY m.product_id
    HAVING units >= 100
)

SELECT 
    product_name,
    units as unit
FROM 
    Products p1 
JOIN p ON p1.product_id = p.product_id;