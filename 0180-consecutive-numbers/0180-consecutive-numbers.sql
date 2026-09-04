/* Write your T-SQL query statement below */
WITH CTE_Logs_Consecutive AS
(
    SELECT
        id,
        num,
        LAG(id, 2) OVER(PARTITION BY num ORDER BY id ) AS first_id
    FROM Logs
)
SELECT
    DISTINCT num AS ConsecutiveNums
FROM
(
    SELECT
        num,
        CASE
            WHEN id - first_id = 2
                THEN 1
            ELSE 0
        END AS at_least_3_consecutive
    FROM CTE_Logs_Consecutive
)t
WHERE at_least_3_consecutive = 1