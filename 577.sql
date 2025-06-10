SELECT e.name, b.bonus 
FROM employee e 
LEFT JOIN bonus b ON b.empId = e.empId 
WHERE b.bonus < 1000 OR b.bonus IS NULL;
