/* Write your T-SQL query statement below */
WITH CTE_Products_Price_By_Date AS
(
    SELECT
        product_id,
        new_price,
        change_date,
        RANK() OVER(PARTITION BY product_id ORDER BY change_date DESC) AS date_rank
    FROM Products
    WHERE change_date <= '2019-08-16'
)

SELECT
    product_id,
    new_price AS price
FROM CTE_Products_Price_By_Date
WHERE date_rank = 1
UNION
SELECT
    product_id,
    10 AS price
FROM Products
WHERE product_id NOT IN (SELECT product_id FROM CTE_Products_Price_By_Date)