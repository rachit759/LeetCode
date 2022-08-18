# Write your MySQL query statement below


select employee_id from employees where employee_id not in (select employee_id from salaries)
union 
select employee_id from salaries where employee_id not in (select employee_id from employees)
order by 1;



# SELECT T.employee_id
# FROM  
#   (SELECT * FROM Employees LEFT JOIN Salaries USING(employee_id)
#    UNION 
#    SELECT * FROM Employees RIGHT JOIN Salaries USING(employee_id))
# AS T
# WHERE T.salary IS NULL OR T.name IS NULL
# ORDER BY employee_id;