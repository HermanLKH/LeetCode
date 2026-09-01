-- /* Write your T-SQL query statement below */
SELECT
    ROUND(AVG(player_fraction), 2) AS fraction
FROM
(
    SELECT
        player_id, 
        SUM(
            CASE
                WHEN date_diff = 1
                    THEN 1.0
                ELSE 0
            END
        ) AS player_fraction
    FROM
    (
        SELECT
            player_id,
            -- event_date,
            LAG(event_date, 1, NULL) OVER(PARTITION BY player_id ORDER BY event_date) prev_date,
            DATEDIFF(DAY, LAG(event_date, 1, NULL) OVER(PARTITION BY player_id ORDER BY event_date), event_date) date_diff
        FROM 
        (
            SELECT
                player_id,
                event_date,
                RANK() OVER(PARTITION BY player_id ORDER BY event_date) rank
            FROM Activity
        )t1
        WHERE rank <= 2
    )t2
    GROUP BY player_id
)t3