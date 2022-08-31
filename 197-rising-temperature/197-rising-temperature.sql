# Write your MySQL query statement below



select w1.id
from weather w1 , weather w2
where w1.temperature > w2.temperature and to_days(w1.recordDate)-1 = to_days(w2.recordDate) ;