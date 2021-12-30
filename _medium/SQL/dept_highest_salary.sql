/*
Create table If Not Exists Employee (id int, name varchar(255), salary int, departmentId int);
Create table If Not Exists Department (id int, name varchar(255));
Truncate table Employee;
insert into Employee (id, name, salary, departmentId) values ('1', 'Joe', '70000', '1');
insert into Employee (id, name, salary, departmentId) values ('2', 'Jim', '90000', '1');
insert into Employee (id, name, salary, departmentId) values ('3', 'Henry', '80000', '2');
insert into Employee (id, name, salary, departmentId) values ('4', 'Sam', '60000', '2');
insert into Employee (id, name, salary, departmentId) values ('5', 'Max', '90000', '1');
Truncate table Department;
insert into Department (id, name) values ('1', 'IT');
insert into Department (id, name) values ('2', 'Sales');
*/


select d.name as Department, e.name as Employee, e.salary as Salary
from Employee as e
join (
	select departmentId, MAX(salary) as salary
	from Employee X
	group by departmentId
) as MaxSalary
on e.departmentId = MaxSalary.departmentId and e.salary = MaxSalary.salary
join Department as d on e.departmentId = d.id;



# Alternative approach
select d.name as Department, e.name as Employee, e.salary as Salary
from Employee as e, 
	(select departmentId, MAX(salary) as salary from Employee group by departmentId) as MaxSals,
	Department as d
where e.departmentId = MaxSals.departmentId
	and e.salary = MaxSals.salary
	and e.departmentId = d.id;

