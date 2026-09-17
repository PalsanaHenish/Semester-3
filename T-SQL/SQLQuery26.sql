--Lab 26 Implement User Defined Functions (UDF) in SQL (Advanced) 

-- From the table STUDENT perform the following queries:  

--Part – A: 

--1. Create a table valued function to display all student records. 
CREATE OR ALTER FUNCTION DISP_STUDENT()
RETURNS TABLE
AS
RETURN SELECT * FROM STUDENT

SELECT * FROM DISP_STUDENT()

--2. Create a table valued function that accepts CITY and returns all students from that city. 
CREATE OR ALTER FUNCTION CITY_WISE_STD
(
	@CITY VARCHAR(20)
)
RETURNS TABLE
AS
RETURN 
	SELECT * FROM STUDENT
	WHERE CITY = @CITY

SELECT * FROM CITY_WISE_STD('RAJKOT')

--3. Create a table valued function that accepts BRANCH and returns all students of that branch.
CREATE OR ALTER FUNCTION BRANCH_WISE_STD
(
	@BRANCH VARCHAR(20)
)
RETURNS TABLE
AS
RETURN 
	SELECT * FROM STUDENT
	WHERE BRANCH = @BRANCH

SELECT * FROM BRANCH_WISE_STD('COMPUTER')

--4. Create a table valued function that accepts SPI and returns students whose SPI is greater than entered 
--SPI. 
CREATE OR ALTER FUNCTION STD_SPI
(
	@SPI DECIMAL(4,2)
)
RETURNS TABLE
AS
RETURN 
	SELECT * FROM STUDENT
	WHERE SPI > @SPI

SELECT * FROM STD_SPI(8.5)

--5. Create a table valued function that accepts MIN_SPI and MAX_SPI and returns students whose SPI lies 
--between given range. 
CREATE OR ALTER FUNCTION SPI_BTW_MIN_MAX
(
	@MIN DECIMAL(4,2),
	@MAX DECIMAL(4,2)
)
RETURNS TABLE
AS
RETURN 
	SELECT * FROM STUDENT
	WHERE SPI BETWEEN @MIN AND @MAX

SELECT * FROM SPI_BTW_MIN_MAX(8.5,9.0)

 
--Part – B:  

--6. Create a table valued function that accepts STDID and returns details of that student. 
CREATE OR ALTER FUNCTION STD_DETAILS
(
	@ID INT
)
RETURNS TABLE
AS
RETURN 
	SELECT * FROM STUDENT
	WHERE STDID = @ID

SELECT * FROM STD_DETAILS(103)

--7. Create a table valued function that accepts CITY and returns students whose SPI is greater than 7 from 
--that city. 
CREATE OR ALTER FUNCTION CITY_WISE_STD_SPI_GREATER_THAN_7
(
	@CITY VARCHAR(20)
)
RETURNS TABLE
AS
RETURN 
	SELECT * FROM STUDENT
	WHERE CITY = @CITY AND SPI > 7

SELECT * FROM CITY_WISE_STD_SPI_GREATER_THAN_7('RAJKOT')

--8. Create a table valued function that accepts BRANCH and returns students whose SPI is less than 8 from 
--that branch. 
CREATE OR ALTER FUNCTION BRANCH_WISE_STD_SPI_LESS_THAN_8
(
	@BRANCH VARCHAR(20)
)
RETURNS TABLE
AS
RETURN 
	SELECT * FROM STUDENT
	WHERE BRANCH = @BRANCH AND SPI < 8

SELECT * FROM BRANCH_WISE_STD_SPI_LESS_THAN_8('COMPUTER')

--9. Create a table valued function that accepts TOPN and returns top N students based on SPI.
CREATE OR ALTER FUNCTION TOP_N_STD_SPI_BASED
(
	@TOP INT
)
RETURNS TABLE
AS
RETURN 
	SELECT TOP (@TOP) * FROM STUDENT
	ORDER BY SPI DESC

SELECT * FROM TOP_N_STD_SPI_BASED(3)

--10. Create a table valued function that accepts BRANCH and returns highest SPI student from that branch. 
CREATE OR ALTER FUNCTION BRANCH_WISE_HIGHEST_SPI
(
	@BRANCH VARCHAR(20)
)
RETURNS TABLE
AS
RETURN 
	SELECT MAX(SPI) AS MAX_SPI FROM STUDENT
	WHERE BRANCH = @BRANCH

SELECT * FROM BRANCH_WISE_HIGHEST_SPI('COMPUTER')

 
--Part – C:  
--11. Create a table valued function that accepts CITY and returns total students from that city.
CREATE OR ALTER FUNCTION CITY_WISE_TOTAL_STD
(
	@CITY VARCHAR(20)
)
RETURNS TABLE
AS
RETURN 
	SELECT COUNT(STDID) AS STD_COUNT FROM STUDENT
	WHERE CITY = @CITY

SELECT * FROM CITY_WISE_TOTAL_STD('MORBI')

--12. Create a table valued function that accepts BRANCH and returns students ordered by SPI in descending 
--order. 
CREATE OR ALTER FUNCTION BRANCH_WISE_STD_DETAILS
(
	@BRANCH VARCHAR(20)
)
RETURNS TABLE
AS
RETURN 
	SELECT * FROM STUDENT
	WHERE BRANCH = @BRANCH

SELECT * FROM BRANCH_WISE_STD_DETAILS('EC')
ORDER BY SPI

--13. Create a table valued function that accepts CITY and returns top 3 student from that city based on SPI.
CREATE OR ALTER FUNCTION CITY_WISE_TOP_3_STD
(
	@CITY VARCHAR(20)
)
RETURNS TABLE
AS
RETURN 
	SELECT TOP 3 * FROM STUDENT
	WHERE CITY = @CITY

SELECT * FROM CITY_WISE_TOP_3_STD('RAJKOT')

--14. Create a table valued function that accepts STDID and returns student rank based on SPI (RANK). 
CREATE OR ALTER FUNCTION STD_RANK
(
	@ID INT
)
RETURNS TABLE
AS
RETURN 
	SELECT RK
	FROM (SELECT *, DENSE_RANK() OVER (ORDER BY SPI DESC) AS RK FROM STUDENT) AS XYZ
	WHERE STDID = @ID

SELECT * FROM STD_RANK(101)

--15. Create a table valued function that accepts BRANCH and returns students having second highest SPI 
--from that branch. 
CREATE OR ALTER FUNCTION STD_RANK
(
	@BRANCH VARCHAR(20)
)
RETURNS TABLE
AS
RETURN 
	SELECT *
	FROM (
		SELECT *, DENSE_RANK() OVER (ORDER BY SPI DESC) AS RK 
		FROM STUDENT
		WHERE BRANCH = @BRANCH
	) AS XYZ
	WHERE RK = 2

SELECT * FROM STD_RANK('COMPUTER')
