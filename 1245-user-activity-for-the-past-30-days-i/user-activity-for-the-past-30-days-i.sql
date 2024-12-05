# Write your MySQL query statement below
SELECT 
    activity_date AS day,
    COUNT(DISTINCT user_id) AS active_users 
FROM 
    Activity 
GROUP BY activity_date
having  
    datediff('2019-07-27', day) between 0 and 29