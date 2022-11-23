# Write your MySQL query statement below


# select max(salary) as SecondHighestSalary
# from employee 
# where salary < (

# select max(Salary) from employee
# )


# select distinct Salary as SecondHighestSalary
# from Employee 
# order by 1 Desc limit 1 offset 1

select IFNULL(
    
    (select distinct Salary from Employee 
     order by Salary desc limit 1 offset 1), null
 )
as SecondHighestSalary