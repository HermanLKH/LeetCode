/* Write your T-SQL query statement below */
SELECT
    id
FROM(
    SELECT
        id,
        temperature,
        recordDate,
        LAG(temperature) OVER(ORDER BY recordDate) prevTemp,
        LAG(recordDate) OVER(ORDER BY recordDate) prevDate
    FROM Weather
)t
WHERE
    temperature > prevTemp AND
    DATEDIFF(DAY, prevDate, recordDate) = 1