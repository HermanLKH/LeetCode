/* Write your T-SQL query statement below */
SELECT TOP(1)
    accepter_id AS id,
    SUM(num) AS num
FROM (
    SELECT
        COUNT(
            CASE
                WHEN accept_date IS NOT NULL
                    THEN 1
                ELSE 0
            END
        ) AS num,
        accepter_id
    FROM RequestAccepted
    GROUP BY accepter_id
    UNION ALL
    SELECT
        COUNT(
            CASE
                WHEN accept_date IS NOT NULL
                    THEN 1
                ELSE 0
            END
        ) AS num,
        requester_id
    FROM RequestAccepted
    GROUP BY requester_id
)t
GROUP BY accepter_id
ORDER BY num DESC
