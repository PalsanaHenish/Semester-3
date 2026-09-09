--Lab 24
--Implement Advanced Stored Procedures with Conditions and Logic 

-- From the table EMPLOYEE perform the following queries:  

--Part – A:  

--1. Create a stored procedure to generate department-wise salary statistics like total salary, average 
--salary, minimum salary, and maximum salary. (User enter only department name) 
CREATE OR ALTER PROC PR1
@DEPARTMENT VARCHAR(20)
AS
BEGIN
	SELECT DEPARTMENT, SUM(SALARY) AS TOT_SAL, AVG(SALARY) AS AVG_SAL, MIN(SALARY) AS MIN_SAL, MAX(SALARY) AS MAX_SAL
	FROM EMPLOYEE
	WHERE DEPARTMENT = @DEPARTMENT
	GROUP BY DEPARTMENT
END

EXEC PR1 'IT'

--2. Create a stored procedure that accepts a joining year and displays employees who joined that year.
CREATE OR ALTER PROC PR2
@JOININGYEAR INT
AS
BEGIN
	SELECT *
	FROM EMPLOYEE
	WHERE JOININGYEAR = @JOININGYEAR
END

EXEC PR2 2020

--3. Create a stored procedure for dynamic employee search using parameters (User may enter partial city 
--name). 
CREATE OR ALTER PROC PR3
@CITY VARCHAR(10)
AS
BEGIN
	SELECT *
	FROM EMPLOYEE
	WHERE CITY LIKE '%'+@CITY+'%'
END

EXEC PR3 'AJKO'


--4. Create a stored procedure that accepts a salary amount and displays employees earning more than the 
--entered salary. 
CREATE OR ALTER PROC PR4
@SALARY DECIMAL(7,2)
AS
BEGIN
	SELECT *
	FROM EMPLOYEE
	WHERE SALARY > @SALARY
END

EXEC PR4 12000

--5. Create a stored procedure to display top N highest paid employees from each department (Value of N 
--is entered by user). 
CREATE OR ALTER PROC PR5
@TOP INT
AS
BEGIN
	SELECT TOP (@TOP) FIRSTNAME, DEPARTMENT, SALARY
	FROM EMPLOYEE
	GROUP BY FIRSTNAME, DEPARTMENT, SALARY
	ORDER BY SALARY DESC
END

EXEC PR5 5

--6. Create a stored procedure to increase salary department-wise by a given percentage. (User Enter 
--Department Name and %, e.g. Computer 10). 
CREATE OR ALTER PROC PR6
@DEPT VARCHAR(20),
@PERC INT
AS
BEGIN
	UPDATE EMPLOYEE
	SET SALARY = SALARY + (SALARY*@PERC/100) 
	WHERE DEPARTMENT = @DEPT
END

EXEC PR6 'IT', 10
SELECT * FROM EMPLOYEE

--7. Create a stored procedure to display employees having experience greater than or equal to the entered 
--years. 
CREATE OR ALTER PROC PR7
@EXP INT
AS
BEGIN
	SELECT * 
	FROM EMPLOYEE
	WHERE @EXP <= YEAR(GETDATE())-JOININGYEAR
END

EXEC PR7 3

--8. Create a stored procedure that accepts a number as input and displays details of the last N employees 
--who joined the organization. 
CREATE OR ALTER PROC PR8
@N INT
AS
BEGIN
	SELECT TOP (@N) *
	FROM EMPLOYEE
	ORDER BY JOININGYEAR DESC
END

EXEC PR8 2


 
--From the table AUTHOR, PUBLISHER and BOOK perform the following queries:

--Part – B:  

--9. Create a stored procedure that accepts an author name and displays all books written by that author. 
CREATE OR ALTER PROC PR9
@AN VARCHAR(30)
AS
BEGIN
	SELECT *
	FROM BOOK B
	JOIN AUTHOR A
	ON B.AUTHORID = A.AUTHORID
	WHERE AUTHORNAME = @AN
END

EXEC PR9 'CHETAN BHAGAT'

--10. Create a stored procedure that accepts a publication year and displays books published after that year.
CREATE OR ALTER PROC PR10
@PY INT
AS
BEGIN
	SELECT *
	FROM BOOK B
	JOIN PUBLISHER P
	ON B.PUBLISHERID = P.PUBLISHERID
	WHERE @PY < PUBLICATIONYEAR
END

EXEC PR10 2010

--11. Create a stored procedure that accepts a country name and displays all authors from that country with 
--their books. 
CREATE OR ALTER PROC PR11
@CN VARCHAR(15)
AS
BEGIN
	SELECT *
	FROM AUTHOR
	WHERE COUNTRY = @CN
END

EXEC PR11 'INDIA'

--12. Create a stored procedure that accepts a number as input and displays the top N most expensive books 
--with author and publisher details. 
CREATE OR ALTER PROC PR12
@N INT
AS
BEGIN
	SELECT TOP (@N) *
	FROM BOOK B
	ORDER BY PRICE DESC
END

EXEC PR12 5


 
--Part – C:  

--13. Create a stored procedure that accepts a publisher name and displays the total number of books 
--published by that publisher. 
CREATE OR ALTER PROC PR13
@PN VARCHAR(30)
AS
BEGIN
	SELECT *
	FROM BOOK B
	JOIN PUBLISHER P
	ON B.PUBLISHERID = P.PUBLISHERID
	WHERE PUBLISHERNAME = @PN
END

EXEC PR13 'RUPA PUBLICATIONS'

--14. Create a stored procedure that accepts a price range (Min Price Max Price) and displays books whose 
--prices fall within that range. 
CREATE OR ALTER PROC PR14
@MINP DECIMAL(5,2),
@MAXP DECIMAL(5,2)
AS
BEGIN
	SELECT *
	FROM BOOK B
	WHERE PRICE BETWEEN @MINP AND @MAXP
END

EXEC PR14 10,300

--15. Create a stored procedure that accepts an author ID and deletes all books written by that author.
CREATE OR ALTER PROC PR15
@ID INT
AS
BEGIN
	DELETE FROM BOOK
	WHERE AUTHORID = @ID
END

EXEC PR15 101
