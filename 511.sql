SELECT 
    player_id, 
    event_date AS first_login
FROM (
    SELECT 
        player_id, 
        event_date, 
        ROW_NUMBER() OVER (PARTITION BY player_id ORDER BY event_date ASC) AS rn
    FROM 
        activity
) AS ranked
WHERE 
    rn = 1;
