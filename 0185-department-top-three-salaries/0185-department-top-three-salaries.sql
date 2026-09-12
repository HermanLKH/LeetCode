/* Write your T-SQL query statement below */
SELECT
    d.name AS Department,
    e.name AS Employee,
    e.salary AS Salary
FROM Employee e
LEFT JOIN Department d
ON d.id = e.departmentId
WHERE e.salary IN
(
    SELECT DISTINCT TOP(3) salary
    FROM Employee
    WHERE departmentId = e.departmentId
    ORDER BY salary DESC
)
