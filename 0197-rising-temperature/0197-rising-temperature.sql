# Write your MySQL query statement below

SELECT w1.id
FROM Weather as w1
INNER JOIN Weather as w2
WHERE DATEDIFF(w1.recordDate, w2.recordDate) = 1 -- Can also use ON instead of Where it would not affect the output
AND w1.temperature > w2.temperature