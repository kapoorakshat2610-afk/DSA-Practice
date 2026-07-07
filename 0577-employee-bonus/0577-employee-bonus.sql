/* Write your PL/SQL query statement below */
Select name ,bonus from Employee,Bonus where Employee.empId=Bonus.empId(+) and (bonus<1000 OR bonus IS NULL);