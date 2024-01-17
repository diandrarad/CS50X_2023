-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find crime scene reports that took place on July 28, 2021 on Humphrey Street.
SELECT description
FROM crime_scene_reports
WHERE year = 2021
     AND month = 7
     AND day = 28
     AND street = 'Humphrey Street';

-- Find out the testimony of witnesses
SELECT name, transcript
FROM interviews
WHERE year = 2021
     AND month = 7
     AND day = 28;

-- Find out who exit the bakery between 10:15 and 10:25
SELECT name
FROM people
WHERE license_plate IN (
     SELECT license_plate
     FROM bakery_security_logs
     WHERE year = 2021
          AND month = 7
          AND day = 28
          AND hour = 10
          AND activity = 'exit'
          AND minute BETWEEN 15 AND 25
);

-- Find out who made ATM withdrawal transactions on Leggett Street
SELECT name
FROM people
WHERE id IN (
     SELECT person_id
     FROM bank_accounts
     WHERE account_number IN (
          SELECT account_number
          FROM atm_transactions
          WHERE year = 2021
               AND month = 7
               AND day = 28
               AND atm_location LIKE 'leggett%'
               AND transaction_type = 'withdraw'
     )
);

-- Find out who made a call and who they were calling in less than a minute as they leave the bakery
SELECT p1.name AS caller, p2.name AS receiver
FROM people p1
JOIN phone_calls c1 ON p1.phone_number = c1.caller
JOIN (
     SELECT caller, receiver
     FROM phone_calls
     WHERE year = 2021
          AND month = 7
          AND day = 28
          AND duration < 60
) AS c2 ON c1.caller = c2.caller AND c1.receiver = c2.receiver
JOIN people p2 ON c1.receiver = p2.phone_number;

-- Find out who made the earliest flight the next day
SELECT p.name, a_dest.city
FROM people p
JOIN passengers ps ON p.passport_number = ps.passport_number
JOIN flights f ON ps.flight_id = f.id
JOIN airports a_origin ON f.origin_airport_id = a_origin.id
JOIN airports a_dest ON f.destination_airport_id = a_dest.id
WHERE f.year = 2021
     AND f.month = 7
     AND f.day = 29
     AND f.hour = (
          SELECT MIN(f2.hour)
          FROM flights f2
          WHERE f2.year = f.year
               AND f2.month = f.month
               AND f2.day = f.day
     )
     AND f.minute = (
          SELECT MIN(f3.minute)
          FROM flights f3
          WHERE f3.year = f.year
               AND f3.month = f.month
               AND f3.day = f.day
               AND f3.hour = f.hour
     )
     AND a_origin.city = 'Fiftyville';