SELECT name AS Customers 
FROM customers 
where id not in
(SELECT c.id FROM customers c RIGHT JOIN orders o ON o.customerID = c.id);