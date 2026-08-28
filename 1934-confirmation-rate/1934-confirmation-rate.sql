/* Write your T-SQL query statement below */
SELECT
    s.user_id,
    ROUND(CAST(SUM(CASE WHEN action = 'confirmed' THEN 1 ELSE 0 END) AS FLOAT) / COUNT(*), 2) confirmation_rate
FROM Confirmations c
FULL OUTER JOIN Signups s
ON c.user_id = s.user_id
GROUP BY s.user_id
ORDER BY s.user_id