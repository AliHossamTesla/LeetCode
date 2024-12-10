# Write your MySQL query statement below
WITH ct AS (
    SELECT 
        product_id, 
        MAX(change_date) AS max_change_date
    FROM 
        Products
    WHERE 
        change_date <= '2019-08-16'
    GROUP BY 
        product_id
), pp AS(
    SELECT p.*
    FROM 
        Products p
        JOIN 
    ct ON p.product_id = ct.product_id AND p.change_date = ct.max_change_date
)
SELECT 
    product_id,
    new_price price 
FROM 
    pp
    UNION
SELECT
    product_id,
    10 AS price
FROM
    Products
WHERE 
    product_id NOT IN (
        SELECT 
            product_id
        FROM
            pp
    )