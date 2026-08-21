--Lab - 20

--From the table STUDENT perform the following queries:  

--Part – A: 

--1. Display rank of students based on SPI. 
SELECT *, RANK() OVER (ORDER BY SPI DESC) AS RANK
FROM STUDENT

--2. Display dense rank of students based on SPI. 
SELECT *, DENSE_RANK() OVER (ORDER BY SPI DESC) AS RANK
FROM STUDENT

--3. Display sequential number for each student record. 
SELECT *, ROW_NUMBER() OVER (ORDER BY SPI DESC) AS RN
FROM STUDENT

--4. Display branch-wise rank of students. 
SELECT *, RANK() OVER (PARTITION BY BRANCH ORDER BY SPI DESC) AS RANK
FROM STUDENT

--5. Display branch-wise dense ranking of students. 
SELECT *, DENSE_RANK() OVER (PARTITION BY BRANCH ORDER BY SPI DESC) AS RANK
FROM STUDENT

--6. Display branch-wise sequential numbering of students. 
SELECT *, ROW_NUMBER() OVER (PARTITION BY BRANCH ORDER BY SPI DESC) AS RN
FROM STUDENT

--7. Display SNAME, Current SPI, Previous SPI and SPI Difference with previous student in ascending order of 
--SPI. 
SELECT SNAME, SPI, LAG(SPI) OVER (ORDER BY SPI) AS PREVIOUS_SPI, SPI - LAG(SPI) OVER (ORDER BY SPI) AS DIFFERENCE
FROM STUDENT

--8. Display SNAME, Current SPI, Next SPI and SPI Difference with next student in descending order of SPI.  
SELECT SNAME, SPI, LEAD(SPI) OVER (ORDER BY SPI DESC) AS PREVIOUS_SPI, SPI - LEAD(SPI) OVER (ORDER BY SPI DESC) AS DIFFERENCE
FROM STUDENT

--9. Display top 3 students based on SPI. 
SELECT *
FROM (SELECT *, DENSE_RANK() OVER (ORDER BY SPI DESC) AS RK FROM STUDENT) AS RANK
WHERE RK <= 3

--10. Display top 2 students from each branch. 
SELECT *
FROM (SELECT *, DENSE_RANK() OVER (PARTITION BY BRANCH ORDER BY SPI DESC) AS RK FROM STUDENT) AS RANK
WHERE RK <= 2


--Part – B: 

--11. Display 5th highest SPI. 
SELECT *
FROM (SELECT *, DENSE_RANK() OVER (ORDER BY SPI DESC) AS RK FROM STUDENT) AS RANK
WHERE RK = 5

--12. Display 6th highest SPI. 
SELECT *
FROM (SELECT *, DENSE_RANK() OVER (ORDER BY SPI DESC) AS RK FROM STUDENT) AS RANK
WHERE RK = 6

--13. Display students having same ranking. 
SELECT *
FROM (
	SELECT *, DENSE_RANK() OVER (ORDER BY SPI DESC) AS RK1,
	LAG(SPI) OVER (ORDER BY SPI DESC) AS RK2,
	LEAD(SPI) OVER (ORDER BY SPI DESC) AS RK3 FROM STUDENT) AS RANK
WHERE SPI = RK2 OR SPI = RK3

--14. Display SNAME, Previous SPI, Current SPI and Next SPI based on ascending order of SPI. 
SELECT SNAME, LAG(SPI) OVER (ORDER BY SPI) AS PREVIOUS_SPI, SPI AS CURRENT_SPI, LEAD(SPI) OVER (ORDER BY SPI) AS NEXT_SPI
FROM STUDENT

--15. Display topper of each branch. 
SELECT *
FROM (SELECT *, DENSE_RANK() OVER (PARTITION BY BRANCH ORDER BY SPI DESC) AS RK FROM STUDENT) AS RANK
WHERE RK = 1

 
--Part – C: 

--16. Display students whose SPI is greater than the previous student and less than the next student. 
SELECT *
FROM (
	SELECT *,
	LAG(SPI) OVER (ORDER BY SPI) AS PSPI,
	LEAD(SPI) OVER (ORDER BY SPI) AS NSPI FROM STUDENT) AS RANK
WHERE SPI > PSPI AND SPI < NSPI

--17. Display branch-wise second topper students. 
SELECT *
FROM (SELECT *, DENSE_RANK() OVER (PARTITION BY BRANCH ORDER BY SPI DESC) AS RK FROM STUDENT) AS RANK
WHERE RK = 2

--18. Display students whose rank and dense rank are different. 
SELECT *
FROM (
	SELECT *, 
	RANK() OVER (ORDER BY SPI DESC) AS RK,
	DENSE_RANK() OVER (ORDER BY SPI DESC) AS DRK FROM STUDENT) AS RANK
WHERE RK != DRK

--19. Display consecutive students having same branch ordered by SPI. 
SELECT *
FROM (
	SELECT *,
	LAG(BRANCH) OVER (ORDER BY SPI) AS RK2,
	LEAD(BRANCH) OVER (ORDER BY SPI) AS RK3 FROM STUDENT) AS RANK
WHERE BRANCH = RK2 OR BRANCH = RK3

--20. Display students whose SPI difference with previous student is maximum. 
SELECT MAX(DIFFERENCE) FROM (
		SELECT *,
		LAG(SPI) OVER (ORDER BY SPI) AS PREVIOUS_SPI,
		SPI - LAG(SPI) OVER (ORDER BY SPI) AS DIFFERENCE
		FROM STUDENT) AS MAX_DIFF