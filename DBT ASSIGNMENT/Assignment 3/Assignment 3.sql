-- ==========================================
-- DATABASE ASSIGNMENT NO. 3
-- ==========================================
CREATE DATABASE EmployeeDB;
use EmployeeDB;
CREATE TABLE Dept (
    DeptID INT PRIMARY KEY,
    Location VARCHAR(50)
);
CREATE TABLE Employee (
    EmpID INT PRIMARY KEY,
    EmpName VARCHAR(50),
    Salary DECIMAL(10,2),
    DeptID INT,
    JoiningDate DATE,
    FOREIGN KEY (DeptID) REFERENCES Dept(DeptID)
);
INSERT INTO Dept (DeptID, Location) VALUES
(10, 'Pune'),
(20, 'Mumbai'),
(30, 'Pune'),
(40, 'Nashik'),
(50, 'Mumbai'),
(60, 'Nagpur');
INSERT INTO Employee
(EmpID, EmpName, Salary, DeptID, JoiningDate)
VALUES
(1, 'Amit', 45000, 10, '2020-02-15'),
(2, 'Arun', 55000, 10, '2021-05-10'),
(3, 'Kiran', 35000, 20, '2020-07-20'),
(4, 'Pranav', 60000, 20, '2021-03-12'),
(5, 'Rohan', 50000, 30, '2020-11-25'),
(6, 'Anand', 40000, 30, '2021-08-16'),
(7, 'Ajay', 65000, 10, '2022-01-10'),
(8, 'Varun', 30000, 40, '2020-04-05'),
(9, 'Rahul', 70000, 10, '2021-09-14'),
(10, 'Akash', 48000, 20, '2020-06-18'),
(11, 'Karan', 52000, 30, '2021-12-01'),
(12, 'Nitin', 38000, 40, '2020-08-21'),
(13, 'Ravi',  NULL, 50, '2021-02-11'),
(14, 'Aarav', 58000, 50, '2020-10-30'),
(15, 'Mohan', 42000, 60, '2021-06-22');
-- 1. Calculate the total salary of all employees
SELECT SUM(Salary) AS TotalSalary
FROM Employee;
-- 2. Find the average salary in each department
SELECT DeptID, AVG(Salary) AS AverageSalary
FROM Employee
GROUP BY DeptID;
-- 3. Count the total employees in each department
SELECT DeptID, COUNT(*) AS TotalEmployees
FROM Employee
GROUP BY DeptID;
-- 4. Display departments having more than 5 employees
SELECT DeptID, COUNT(*) AS TotalEmployees
FROM Employee
GROUP BY DeptID
HAVING COUNT(*) > 5;
-- 5. Display distinct department locations
SELECT DISTINCT Location
FROM Dept;
-- 6(a). Display the highest salary
SELECT MAX(Salary) AS HighestSalary
FROM Employee;
-- 6(b). Display the total number of employees
SELECT COUNT(*) AS TotalEmployees
FROM Employee;
-- 7. Find employees whose names start with 'A'
SELECT *
FROM Employee
WHERE EmpName LIKE 'A%';
-- 8. Find employees whose names end with 'n'
SELECT *
FROM Employee
WHERE EmpName LIKE '%n';
-- 9. Find employees whose names contain 'ra'
SELECT *
FROM Employee
WHERE EmpName LIKE '%ra%';
-- 10. Display employees sorted by salary in descending order
SELECT *
FROM Employee
ORDER BY Salary DESC;
-- 11. Sort by DeptID ascending and Salary descending
SELECT *
FROM Employee
ORDER BY DeptID ASC, Salary DESC;
-- 12. Find employees with salary between 30000 and 60000
SELECT *
FROM Employee
WHERE Salary BETWEEN 30000 AND 60000;
-- 13. Display employees from departments 10, 20, and 30
SELECT *
FROM Employee
WHERE DeptID IN (10, 20, 30);
-- 14. Display the minimum salary
SELECT MIN(Salary) AS MinimumSalary
FROM Employee;
-- 15. Display employees who joined between 2020 and 2021
SELECT *
FROM Employee
WHERE JoiningDate BETWEEN '2020-01-01' AND '2021-12-31';
-- 16. Display employees whose salary is NULL
SELECT *
FROM Employee
WHERE Salary IS NULL;
-- 17. Display employees whose salary is NOT NULL
SELECT *
FROM Employee
WHERE Salary IS NOT NULL;
-- 18. Display departments whose total salary exceeds 100000
SELECT DeptID, SUM(Salary) AS TotalSalary
FROM Employee
GROUP BY DeptID
HAVING SUM(Salary) > 100000;
-- 19. Display distinct employee names
SELECT DISTINCT EmpName
FROM Employee;
-- 20. Count departments sharing the same location
SELECT Location, COUNT(*) AS TotalDepartments
FROM Dept
GROUP BY Location
HAVING COUNT(*) > 1;
SELECT * FROM Dept;
SELECT * FROM Employee;