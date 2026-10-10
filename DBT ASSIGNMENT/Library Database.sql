create database LibraryDB;
Use LibraryDB;
CREATE TABLE Authors (
    author_id INT PRIMARY KEY,
    name VARCHAR(100),
    country VARCHAR(50)
);
CREATE TABLE Books (
    book_id INT PRIMARY KEY,
    title VARCHAR(150),
    author_id INT,
    published_year YEAR,
    available_copies INT,
    FOREIGN KEY (author_id)
        REFERENCES Authors(author_id)
);
CREATE TABLE Members (
    member_id INT PRIMARY KEY,
    name VARCHAR(100),
    email VARCHAR(100) UNIQUE,
    phone VARCHAR(15)
);
CREATE TABLE Borrow_Records (
    record_id INT PRIMARY KEY,
    member_id INT,
    book_id INT,
    borrow_date DATE,
    return_date DATE,
    FOREIGN KEY (member_id)
        REFERENCES Members(member_id),
    FOREIGN KEY (book_id)
        REFERENCES Books(book_id)
);
ALTER TABLE Books
ADD COLUMN genre VARCHAR(50);
DROP TABLE Borrow_Records;
INSERT INTO Authors (author_id, name, country)
VALUES
(1, 'Abraham Silberschatz', 'USA'),
(2, 'Ramez Elmasri', 'USA'),
(3, 'Robert C. Martin', 'USA');
SELECT * FROM Authors;
INSERT INTO Books
(book_id, title, author_id, published_year,
 available_copies, genre)
VALUES
(1, 'Database Systems', 1, 2018, 5, 'Database'),
(2, 'Operating Systems', 1, 2016, 3, 'Computer Science'),
(3, 'Fundamentals of Database Systems', 2, 1998, 4, 'Database'),
(4, 'Clean Code', 3, 2008, 2, 'Programming'),
(5, 'SQL for Beginners', 2, 2021, 6, 'Database');
SELECT * FROM Books;
INSERT INTO Members
(member_id, name, email, phone)
VALUES
(1, 'Asha Patil', 'asha@gmail.com', '9876543210'),
(2, 'Rahul Sharma', 'rahul@gmail.com', '9876501234'),
(3, 'Priya Joshi', 'priya@gmail.com', '9765432108');
SELECT * FROM Members;
INSERT INTO Borrow_Records
(record_id, member_id, book_id, borrow_date, return_date)
VALUES
(1, 1, 1, '2026-09-01', '2026-09-10'),
(2, 2, 2, '2026-09-03', '2026-09-12'),
(3, 1, 5, '2026-09-15', NULL),
(4, 2, 1, '2026-09-20', NULL);
SELECT * FROM Borrow_Records;
SELECT * FROM Books
WHERE published_year > 2015;
CREATE TABLE Book_Categories (
    category_id INT PRIMARY KEY,
    category_name VARCHAR(50),
    book_id INT,
    FOREIGN KEY (book_id)
        REFERENCES Books(book_id)
);
SELECT DISTINCT m.member_id, m.name, m.email
FROM Members m
JOIN Borrow_Records br
    ON m.member_id = br.member_id
JOIN Books b
    ON br.book_id = b.book_id
WHERE b.title = 'Database Systems';
UPDATE Books
SET available_copies = available_copies - 1
WHERE book_id = 1
  AND available_copies > 0;
  SELECT book_id, title, available_copies
FROM Books
WHERE book_id = 1;
DELETE FROM Members
WHERE member_id = 3;
UPDATE Books
SET title = 'Advanced Database Systems'
WHERE book_id = 1;
SELECT * FROM Books
WHERE book_id = 1;
SELECT
    b.book_id,
    b.title,
    a.name AS author_name,
    b.published_year,
    b.genre
FROM Books b
JOIN Authors a
    ON b.author_id = a.author_id;
    SELECT
    b.book_id,
    b.title,
    a.name AS author_name,
    b.published_year,
    b.genre
FROM Books b
JOIN Authors a
    ON b.author_id = a.author_id;
    DELETE FROM Books
WHERE published_year < 2000;
SELECT * FROM Books;
SELECT b.book_id, b.title
FROM Books b
LEFT JOIN Borrow_Records br
    ON b.book_id = br.book_id
WHERE br.book_id IS NULL;