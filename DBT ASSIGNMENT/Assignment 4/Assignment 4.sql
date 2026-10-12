CREATE DATABASE EmpDB;
USE Employee;
-- Create Department table
CREATE TABLE Dept (
    DeptID INT PRIMARY KEY,
    DeptName VARCHAR(50),
    Location VARCHAR(50)
);

-- Create Employee table
CREATE TABLE Emp (
    EmpID INT PRIMARY KEY AUTO_INCREMENT,
    EmpName VARCHAR(50),
    Salary DECIMAL(10,2),
    DeptID INT,
    FOREIGN KEY (DeptID) REFERENCES Dept(DeptID)
);

-- Create Project table
CREATE TABLE Project (
    ProjectID INT PRIMARY KEY,
    ProjectName VARCHAR(50),
    Budget DECIMAL(12,2),
    DeptID INT,
    FOREIGN KEY (DeptID) REFERENCES Dept(DeptID)
);
INSERT INTO Dept (DeptID, DeptName, Location) VALUES
(1, 'IT', 'Mumbai'),
(2, 'HR', 'Pune'),
(3, 'Finance', 'Mumbai'),
(4, 'Marketing', 'Nashik'),
(5, 'Sales', 'Delhi'),
(6, 'Operations', 'Mumbai');
SELECT * FROM Dept;
INSERT INTO Emp (EmpName, Salary, DeptID) VALUES
('Amit', 60000, 1),
('Priya', 75000, 1),
('Rahul', 45000, 2),
('Sneha', 80000, 3),
('Neha', 55000, 4),
('Vikas', 90000, 5),
('Kiran', 65000, NULL),
('Pooja', 70000, 6);
SELECT * FROM Emp;
INSERT INTO Project (ProjectID, ProjectName, Budget, DeptID) VALUES
(101, 'Website Development', 200000, 1),
(102, 'Employee Training', 50000, 2),
(103, 'Financial Audit', 100000, 3),
(104, 'Digital Marketing', 80000, 4),
(105, 'Sales Portal', 150000, 5),
(106, 'Cloud Migration', 250000, 1);
SELECT * FROM Project;
-- SQL equivalent of Cartesian Product
SELECT * FROM Emp
CROSS JOIN Dept;
SELECT E.EmpName, D.DeptName
FROM Emp E
INNER JOIN Dept D
ON E.DeptID = D.DeptID;
SELECT E.EmpID, E.EmpName, E.Salary,
       D.DeptName, D.Location
FROM Emp E
LEFT OUTER JOIN Dept D
ON E.DeptID = D.DeptID;
SELECT E.EmpID, E.EmpName,
       D.DeptID, D.DeptName, D.Location
FROM Emp E
RIGHT OUTER JOIN Dept D
ON E.DeptID = D.DeptID;
SELECT EmpID, EmpName, Salary, DeptID, DeptName, Location
FROM Emp
NATURAL JOIN Dept;
SELECT E.EmpName, P.ProjectName, P.Budget
FROM Emp E
CROSS JOIN Project P;
CREATE TABLE EmpBackup LIKE Emp;
INSERT INTO EmpBackup (EmpID, EmpName, Salary, DeptID)
SELECT EmpID, EmpName, Salary, DeptID
FROM Emp;
SELECT * FROM EmpBackup;
CREATE TABLE ProjectArchive LIKE Project;
INSERT INTO ProjectArchive
SELECT * FROM Project;
CREATE TABLE Emp (
    EmpID INT PRIMARY KEY AUTO_INCREMENT,
    EmpName VARCHAR(50),
    Salary DECIMAL(10,2),
    DeptID INT,
    FOREIGN KEY (DeptID) REFERENCES Dept(DeptID)
);
INSERT INTO Emp (EmpName, Salary, DeptID)
VALUES ('Anjali', 62000, 1);
SELECT EmpID, EmpName, Salary
FROM Emp
WHERE Salary > (
    SELECT AVG(Salary)
    FROM Emp
);
SELECT EmpID, EmpName, Salary, DeptID
FROM Emp
WHERE DeptID IN (
    SELECT DeptID
    FROM Dept
    WHERE Location = 'Mumbai'
);
SELECT DeptID, DeptName
FROM Dept
WHERE DeptID IN (
    SELECT DeptID
    FROM Emp
    WHERE DeptID IS NOT NULL
    GROUP BY DeptID
    HAVING COUNT(*) > 5
);
SELECT EmpName, Salary
FROM Emp
WHERE Salary = (
    SELECT MAX(Salary)
    FROM Emp
);
SELECT MAX(Salary) AS MaxSalary
FROM Emp;
SELECT E1.EmpName AS Employee1,
       E2.EmpName AS Employee2,
       E1.DeptID
FROM Emp E1
JOIN Emp E2
ON E1.DeptID = E2.DeptID
AND E1.EmpID < E2.EmpID;
SELECT D1.DeptName AS Department1,
       D2.DeptName AS Department2,
       D1.Location
FROM Dept D1
JOIN Dept D2
ON D1.Location = D2.Location
AND D1.DeptID < D2.DeptID;
SELECT P1.ProjectName AS Project1,
       P2.ProjectName AS Project2,
       P1.DeptID
FROM Project P1
JOIN Project P2
ON P1.DeptID = P2.DeptID
AND P1.ProjectID < P2.ProjectID;
-- Display all departments
SELECT * FROM Dept;
-- Display all employees
SELECT * FROM Emp;
-- Display all projects
SELECT * FROM Project;
-- Display employee backup
SELECT * FROM EmpBackup;
-- Display project archive
SELECT * FROM ProjectArchive;
DESC Dept;
DESC Emp;
DESC Project;
DESC EmpBackup;
DESC ProjectArchive;