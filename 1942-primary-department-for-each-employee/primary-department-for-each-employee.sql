WITH SingleDept AS (
    SELECT 
        employee_id
    FROM
        Employee
    GROUP BY 
        employee_id
    HAVING COUNT(department_id) = 1
)
SELECT 
    employee_id,
    department_id
FROM 
    Employee
WHERE 
    primary_flag = 'Y'
UNION ALL
SELECT 
    e.employee_id,
    e.department_id
FROM 
    Employee e
INNER JOIN 
    SingleDept sd
ON 
    e.employee_id = sd.employee_id
ORDER BY 
    employee_id;
