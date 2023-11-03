# Write your MySQL query statement below
select e1.unique_id,e2.name from Employees as e2  left join EmployeeUNI as e1 ON e1.id=e2.id