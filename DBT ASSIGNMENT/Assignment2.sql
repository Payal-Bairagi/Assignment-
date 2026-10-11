create database DBT_Assignment2;
use DBT_Assignment2;
create table Department(
DeptID int PRIMARY KEY,
DEPTNAME varchar(50) NOT NULL,
City varchar(50) NOT NULL
);
create table Employee(
EmpID int PRIMARY KEY,
EmpName varchar(100) NOT NULL,
Salary Decimal(10 , 2) NOT NULL,
DeptID int ,
 JoiningDate DATE,
 FOREIGN KEY(DeptID) REFERENCES Department(DeptID)
 );
 INSERT INTO Department (DeptID, DeptName, City)
VALUES
(10, 'Sales', 'Mumbai'),
(20, 'IT', 'Pune'),
(30, 'HR', 'Mumbai'),
(40, 'Finance', 'Nashik'),
(50, 'Marketing', 'Delhi');
INSERT INTO Employee (EmpID, EmpName, Salary, DeptID, JoiningDate)
VALUES
(101, 'Amit', 60000, 10, '2023-01-15'),
(102, 'Priya', 45000, 20, '2022-06-10'),
(103, 'Rahul', 75000, 10, '2021-03-20'),
(104, 'Sneha', 50000, 30, '2024-02-01'),
(105, 'Neha', 80000, 20, '2020-11-25'),
(5, 'Kiran', 40000, 30, '2024-07-12'),
(107, 'Pooja', 55000, 10, '2022-09-05');
ALTER TABLE Employee
ADD Email VARCHAR(100);
INSERT INTO Employee
    (EmpID, EmpName, Salary, DeptID, JoiningDate)
VALUES
    (108, 'Vikas', 52000, 10, '2023-05-10'),
    (109, 'Anjali', 48000, 20, '2022-08-15'),
    (110, 'Suresh', 65000, 30, '2021-12-01'),
    (111, 'Meena', 42000, 10, '2024-04-20'),
    (112, 'Rohit', 70000, 20, '2020-07-18');
    Delete from Employee;
UPDATE Employee
SET Salary = 45000
WHERE EmpID = 5;
CREATE USER 'readonly_user'@'localhost'
IDENTIFIED BY 'ReadOnly@123';
GRANT SELECT ON DBT_Assignment2.Emp
TO 'readonly_user'@'localhost';
CREATE USER 'temp_user'@'localhost'
IDENTIFIED BY 'TempUser@123';

GRANT INSERT ON DBT_Assignment2.Emp
TO 'temp_user'@'localhost';
REVOKE INSERT ON DBT_Assignment2.Emp
FROM 'temp_user'@'localhost';
START TRANSACTION;

INSERT INTO Emp
    (EmpID, EmpName, Salary, DeptID, JoiningDate)
VALUES
    (113, 'Arjun', 58000, 10, '2025-01-10');

COMMIT;
START TRANSACTION;

UPDATE Emp
SET Salary = 65000
WHERE EmpID = 101;

COMMIT;
SELECT EmpID, EmpName, Salary
FROM Emp
WHERE EmpID = 101;
START TRANSACTION;

SAVEPOINT before_dept_update;

UPDATE Employee
SET DeptID = 20
WHERE EmpID = 101;
ROLLBACK TO SAVEPOINT before_dept_update;

COMMIT;
TRUNCATE TABLE Employee;
SELECT * FROM Employee
WHERE Salary > 50000;
SELECT EmpID, EmpName, Salary
FROM Employee
WHERE Salary > 50000;
UPDATE Emp
SET Salary = Salary * 1.10
WHERE DeptID = 10;
SELECT EmpID, EmpName, Salary, DeptID
FROM Emp
WHERE DeptID = 10;
SELECT DeptID, COUNT(*) AS TotalEmployees
FROM Emp
GROUP BY DeptID;
SELECT
    d.DeptID,
    d.DeptName,
    COUNT(e.EmpID) AS TotalEmployees
FROM Department d
LEFT JOIN Emp e
    ON d.DeptID = e.DeptID
GROUP BY d.DeptID, d.DeptName;
SELECT d.DeptID, d.DeptName
FROM Department d
LEFT JOIN Emp e
    ON d.DeptID = e.DeptID
WHERE e.EmpID IS NULL;
CREATE VIEW Mumbai_Salespeople AS
SELECT
    e.EmpID,
    e.EmpName,
    e.Salary,
    d.DeptName,
    d.City
FROM Emp e
JOIN Department d
    ON e.DeptID = d.DeptID
WHERE d.DeptName = 'Sales'
  AND d.City = 'Mumbai';
  SELECT * FROM Mumbai_Salespeople;
  SHOW CREATE VIEW Mumbai_Salespeople;
  SELECT MAX(Salary) AS HighestSalary
FROM Emp;
SELECT MAX(Salary) AS SecondHighestSalary
FROM Emp
WHERE Salary < (
    SELECT MAX(Salary)
    FROM Emp
);
SELECT DISTINCT Salary
FROM Emp
ORDER BY Salary DESC
LIMIT 1 OFFSET 1;
SELECT *
FROM Emp
ORDER BY JoiningDate DESC;
SELECT EmpID, EmpName, JoiningDate
FROM Emp
ORDER BY JoiningDate DESC;
ALTER TABLE Department
RENAME COLUMN DeptName TO DepartmentName;
DESCRIBE Department;

