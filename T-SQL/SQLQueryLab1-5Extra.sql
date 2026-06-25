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


--16. Display the account number, customer name, and amount from the DEPOSIT table.

--17. Update the SPI of student HARSH to 6.50.

--18. Display all employees belonging to the HR department.

--19. Add a MOBILE_NO column to the EMPLOYEE table.

--20. Display distinct cities from the STUDENT table.

--21. Rename the EMPLOYEE table to STAFF.

--22. Change the deposit amount of account number 107 to 2500.

--23. Display students whose branch is COMPUTER.

--24. Display all deposit records sorted by amount in descending order.

--25. Remove the MOBILE_NO column from the EMPLOYEE table.

--26. Display employees whose salary is between 10000 and 15000.

--27. Change the branch of student RIYA to IT.

--28. Display the details of students whose city starts with 'R'.

--29. Add a DATE_OF_BIRTH column to the STUDENT table.

--30. Display all employees from RAJKOT or SURAT cities.
