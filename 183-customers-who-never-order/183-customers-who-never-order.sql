# Write your MySQL query statement below



select name as customers
from customers
LEFT JOIN orders
on customers.id = orders.customerId
where customerId is null