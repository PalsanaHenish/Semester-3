--LAB 1-5 EXTRA

--1. Display the names and cities of all students.
SELECT SNAME,CITY FROM STUDENT

--2. Change the salary of employee EID 106 to 8000.
UPDATE EMPLOYEE
SET SALARY = 8000
WHERE EID = 106
SELECT * FROM EMPLOYEE

--3. Add a column named EMAIL to the STUDENT table.
ALTER TABLE STUDENT
ADD EMAIL VARCHAR(30)
SELECT * FROM STUDENT

--4. Display details of students whose SPI is greater than 8.50.
SELECT * FROM STUDENT
WHERE SPI > 8.50

--5. Rename the column SNAME to STUDENT_NAME in the STUDENT table.
EXEC sp_rename 'STUDENT.SNAME','STUDENT_NAME'
SELECT * FROM STUDENT

--6. Display all deposit records from the MADHAPAR branch.
SELECT * FROM DEPOSIT
WHERE BRANCH = 'MADHAPAR'

--7. Increase the salary of all employees in the IT department by 1500.
UPDATE EMPLOYEE
SET SALARY = SALARY + 1500
WHERE DEPARTMENT = 'IT'

SELECT * FROM EMPLOYEE

--8. Display employee details who joined in 2026.
SELECT * FROM EMPLOYEE
WHERE JOININGYEAR = 2026

--9. Remove the GENDER column from the EMPLOYEE table.
ALTER TABLE EMPLOYEE
DROP COLUMN GENDER
SELECT * FROM EMPLOYEE

--10. Display the names of depositors whose amount is greater than 5000.
SELECT * FROM DEPOSIT
WHERE AMOUNT = 5000

--11. Rename the DEPOSIT table to BANK_DEPOSIT.
EXEC sp_rename 'DEPOSIT','BANK_DEPOSIT'

--12. Display all students from RAJKOT city.
SELECT * FROM STUDENT
WHERE CITY = 'RAJKOT'

--13. Change the city of employee EID 110 to AHMEDABAD.
UPDATE EMPLOYEE
SET CITY = 'AHMEDABAD'
WHERE EID = 110
SELECT * FROM EMPLOYEE

--14. Display employee names and salaries in descending order of salary.
SELECT FIRSTNAME,SALARY FROM EMPLOYEE
ORDER BY SALARY DESC

--15. Increase the size of the CITY column in the STUDENT table to 100 characters.
ALTER TABLE STUDENT
ALTER COLUMN CITY CHAR(100)

--16. Display the account number, customer name, and amount from the DEPOSIT table.
SELECT ACTNO, CNAME, AMOUNT FROM DEPOSIT

--17. Update the SPI of student HARSH to 6.50.
UPDATE STUDENT
SET SPI=6.5
WHERE SNAME = 'HARSH'

SELECT * FROM STUDENT

--18. Display all employees belonging to the HR department.
SELECT * FROM EMPLOYEE
WHERE DEPARTMENT = 'HR'

--19. Add a MOBILE_NO column to the EMPLOYEE table.
ALTER TABLE EMPLOYEE
ADD MOBILE_NO INT

SELECT * FROM EMPLOYEE

--20. Display distinct cities from the STUDENT table.
SELECT DISTINCT CITY FROM STUDENT

--21. Rename the EMPLOYEE table to STAFF.
EXEC sp_rename 'EMPLOYEE','STAFF'

--22. Change the deposit amount of account number 107 to 2500.
UPDATE DEPOSIT
SET AMOUNT = 2500
WHERE ACTNO = 107

SELECT * FROM DEPOSIT

--23. Display students whose branch is COMPUTER.
SELECT * FROM STUDENT
WHERE BRANCH = 'COMPUTER'

--24. Display all deposit records sorted by amount in descending order.
SELECT * FROM DEPOSIT
ORDER BY AMOUNT DESC

--25. Remove the MOBILE_NO column from the EMPLOYEE table.
ALTER TABLE EMPLOYEE
DROP COLUMN MOBILE_NO

--26. Display employees whose salary is between 10000 and 15000.
SELECT * FROM EMPLOYEE
WHERE SALARY BETWEEN 10000 AND 15000

--27. Change the branch of student RIYA to IT.
UPDATE STUDENT
SET BRANCH = 'IT'
WHERE SNAME = 'RIYA'

SELECT * FROM STUDENT

--28. Display the details of students whose city starts with 'R'.
SELECT * FROM STUDENT
WHERE CITY LIKE 'R%'

--29. Add a DATE_OF_BIRTH column to the STUDENT table.
ALTER TABLE STUDENT
ADD DATE_OF_BIRTH DATE

SELECT * FROM STUDENT

--30. Display all employees from RAJKOT or SURAT cities.
SELECT * FROM EMPLOYEE
WHERE CITY IN ('RAJKOT', 'SURAT')