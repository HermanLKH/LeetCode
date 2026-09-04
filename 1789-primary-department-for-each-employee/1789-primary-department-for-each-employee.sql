/* Write your T-SQL query statement below */
WITH CTE_Employee_Without_Department AS
(
    SELECT
        employee_id,
        CASE 
            WHEN SUM(CASE WHEN primary_flag = 'Y' THEN 1 ELSE 0 END) = 0
                THEN 1
            ELSE 0
        END AS no_primary_dept
    FROM Employee
    GROUP BY employee_id 
)
SELECT
    employee_id,
    department_id
FROM Employee
WHERE
    primary_flag = 'Y' OR
    employee_id IN (SELECT employee_id FROM CTE_Employee_Without_Department WHERE no_primary_dept = 1)