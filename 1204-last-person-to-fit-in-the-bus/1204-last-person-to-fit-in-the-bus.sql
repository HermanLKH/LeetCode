/* Write your T-SQL query statement below */
SELECT TOP(1)
    person_name
FROM
(
    SELECT
        *,
        CASE 
            WHEN SUM(weight) OVER(ORDER BY turn) <= 1000 
                THEN 1
            ELSE 0
        END AS is_onboarded
    FROM Queue
)t
WHERE is_onboarded = 1
ORDER BY turn DESC