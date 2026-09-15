--Lab 25 Implement User Defined Functions (UDF) in SQL (Intermediate) 

-- Part – A:  

--1. Implement scalar function to return "Welcome to DBMS Lab". 
CREATE OR ALTER FUNCTION F1()
RETURNS VARCHAR(30)
AS
BEGIN
	RETURN 'Welcome to DBMS Lab'
END

SELECT dbo.F1() AS MSG

--2. Implement scalar function to calculate simple interest. 
CREATE OR ALTER FUNCTION simple_interest
(
	@PrincipalAmount INT,
	@Rate DECIMAL(5,2),
	@Time INT
)
RETURNS DECIMAL(5,2)
AS
BEGIN
	RETURN @PrincipalAmount*@Rate*@Time/100
END

SELECT dbo.simple_interest(10,10,10) AS simple_interest

--3. Implement scalar function to find difference in days between two dates.
CREATE OR ALTER FUNCTION date_diff
(
	@DATE_1 DATETIME,
	@DATE_2 DATETIME
)
RETURNS INT
AS
BEGIN
	RETURN DATEDIFF(DAY,@DATE_1,@DATE_2)
END

SELECT dbo.date_diff('2026-10-10','2026-11-11') AS date_diff

--4. Implement scalar function to check whether number is odd or even. 
CREATE OR ALTER FUNCTION ODD_EVEN
(
	@N INT
)
RETURNS CHAR(4)
AS
BEGIN
	DECLARE @RES CHAR(4);

	IF(@N % 2 = 0)
		SET @RES = 'EVEN'
	ELSE
		SET @RES = 'ODD'
		
	RETURN @RES
END

SELECT dbo.ODD_EVEN(11) AS ODD_EVEN

--5. Implement scalar function to print numbers from 1 to N. 
CREATE OR ALTER FUNCTION PRINT_NUM_1_TO_N
(
	@N INT
)
RETURNS VARCHAR(500)
AS
BEGIN
	DECLARE @I INT=1
	DECLARE @ST VARCHAR(500)=''
	

	WHILE (@I <= @N)
	BEGIN
		SET @ST = @ST + ' ' + CAST(@I AS VARCHAR(5))
		SET @I = @I+1
	END

	RETURN @ST
END

SELECT dbo.PRINT_NUM_1_TO_N(15) AS PRINT_NUM_1_TO_N

 
--Part – B:  

--6. Implement scalar function to calculate factorial of given number.
CREATE OR ALTER FUNCTION FACTORIAL
(
	@N INT
)
RETURNS INT
AS
BEGIN
	DECLARE @I INT = 1
	DECLARE @FACT INT = 1
	
	WHILE (@I <= @N)
	BEGIN
		SET @FACT = @FACT * @I
		SET @I = @I+1
	END

	RETURN @FACT
END

SELECT dbo.FACTORIAL(10) AS FACTORIAL

--7. Implement scalar function to check palindrome number.
CREATE OR ALTER FUNCTION PALINDROME
(
	@N INT
)
RETURNS VARCHAR(30)
AS
BEGIN
	DECLARE @TEMP INT = @N
	DECLARE @REM INT = 1
	DECLARE @N2 INT = 0
	
	WHILE (@TEMP != 0)
	BEGIN
		SET @REM = @TEMP % 10
		SET @TEMP = @TEMP / 10
		SET @N2 = (@N2 * 10) + @REM
	END

	DECLARE @RES VARCHAR(30)

	IF(@N = @N2)
		SET @RES = CAST(@N AS VARCHAR(10)) + ' IS PALINDROM'
	ELSE
		SET @RES = CAST(@N AS VARCHAR(10)) + ' IS NOT PALINDROM'

	RETURN @RES
END

SELECT dbo.PALINDROME(101) AS PALINDROME

--8. Implement scalar function to find maximum of three numbers. 
CREATE OR ALTER FUNCTION MAXIMUM_OF_THREE
(
	@N1 INT,
	@N2 INT,
	@N3 INT
)
RETURNS INT
AS
BEGIN
	DECLARE @MAX INT

	IF(@N1 > @N2)
		IF(@N1 > @N3)
			SET @MAX = @N1
		ELSE
			SET @MAX = @N3
	ELSE
		IF(@N2 > @N3)
			SET @MAX = @N2
		ELSE
			SET @MAX = @N3

	RETURN @MAX
END

SELECT dbo.MAXIMUM_OF_THREE(105, 125, 103) AS MAXIMUM_OF_THREE

--9. Implement scalar function to calculate square and cube of a number. 
CREATE OR ALTER FUNCTION SQUARE_AND_CUBE
(
	@N INT
)
RETURNS VARCHAR(30)
AS
BEGIN
	DECLARE @SQ INT
	DECLARE @CB INT

	SET @SQ = @N * @N
	SET @CB = @SQ * @N

	RETURN 'SQUARE = ' + CAST(@SQ AS VARCHAR(10)) + ' | CUBE = ' + CAST(@CB AS VARCHAR(10)) 
END

SELECT dbo.SQUARE_AND_CUBE(10) AS SQUARE_AND_CUBE

 
--From the table EMPLOYEE perform the following queries: 

--Part – C:  

--10. Implement scalar function to return employee full details using EID.
CREATE OR ALTER FUNCTION EMPLOYEE_DATAILS
(
	@EID INT
)
RETURNS TABLE
AS
RETURN
(
	SELECT * 
	FROM EMPLOYEE
	WHERE EID = @EID
) 

SELECT * FROM EMPLOYEE_DATAILS(101)

--11. Implement scalar function to return highest salary from a given department. 
CREATE OR ALTER FUNCTION DEPARTMENT_HIGHEST_SALARY
(
	@DEPT VARCHAR(20)
)
RETURNS TABLE
AS
RETURN
(
	SELECT MAX(SALARY) AS HIGH_SAL 
	FROM EMPLOYEE
	WHERE DEPARTMENT = @DEPT
) 

SELECT * FROM DEPARTMENT_HIGHEST_SALARY('ADMIN')

--12. Implement scalar function to count total employees in EMPLOYEE table. 
CREATE OR ALTER FUNCTION COUNT_EMPLOYEE()
RETURNS TABLE
AS
RETURN
(
	SELECT COUNT(SALARY) AS COUNT 
	FROM EMPLOYEE
) 

SELECT * FROM COUNT_EMPLOYEE()

--13. Implement scalar function to find total experience of employee using JoiningYear. 
CREATE OR ALTER FUNCTION EXPERIENCE
(
	@YEAR INT
)
RETURNS TABLE
AS
RETURN
(
	SELECT YEAR(GETDATE()) - @YEAR AS EXPERIENCE
) 

SELECT * FROM EXPERIENCE(2023)

--14. Implement scalar function to return total number of employees in a given department.
CREATE OR ALTER FUNCTION TOT_EMP_IN_GIVEN_DEPT
(
	@DEPT VARCHAR(15)
)
RETURNS TABLE
AS
RETURN
(
	SELECT COUNT(EID) AS COUNT
	FROM EMPLOYEE
	WHERE @DEPT = DEPARTMENT
) 

SELECT * FROM TOT_EMP_IN_GIVEN_DEPT('HR')

--15. Implement scalar function to count total employees from a given city. 
CREATE OR ALTER FUNCTION TOT_EMP_IN_GIVEN_DEPT
(
	@CITY VARCHAR(15)
)
RETURNS TABLE
AS
RETURN
(
	SELECT COUNT(EID) AS COUNT
	FROM EMPLOYEE
	WHERE @CITY = CITY
) 

SELECT * FROM TOT_EMP_IN_GIVEN_DEPT('RAJKOT')
