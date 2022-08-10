# Write your MySQL query statement below





select distinct salesperson.name 
from salesperson, company, orders
where salesperson.sales_id not in (

    select sales_id from company
    inner join orders
    on company.com_id = orders.com_id 
    where name = "RED"
)