-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description FROM crime_scene_reports WHERE (year = 2023 AND month = 7 AND day = 28);

SELECT name, transcript FROM interviews WHERE (year = 2023 AND month = 7 AND day = 28);

SELECT license_plate, hour, minute FROM bakery_security_logs WHERE (year = 2023 AND month = 7 AND day = 28);

SELECT atm_location, account_number, transaction_type, amount FROM atm_transactions WHERE (year = 2023 AND month = 7 AND day = 28 AND transaction_type = "withdraw" AND atm_location = 'Leggett Street');

SELECT caller, receiver, duration  FROM phone_calls WHERE (year = 2023 AND month = 7 AND day = 28 AND duration < 60);

SELECT
    origin.full_name AS origin_airport,
    destination.full_name AS destination_airport,
    flights.hour AS departure_hour,
    flights.minute AS departure_minute
FROM
    flights
JOIN
    airports AS origin ON flights.origin_airport_id = origin.id
JOIN
    airports AS destination ON flights.destination_airport_id = destination.id
WHERE
    origin.city = 'Fiftyville'
    AND year = 2023
    AND month = 7
    AND day = 29;

SELECT
    passengers.passport_number,
    passengers.seat
FROM
    passengers
JOIN
    flights ON passengers.flight_id = flights.id
JOIN
    airports AS origin ON flights.origin_airport_id = origin.id
JOIN
    airports AS destination ON flights.destination_airport_id = destination.id
WHERE
    origin.city = 'Fiftyville'
    AND destination.full_name = 'LaGuardia Airport'
    AND flights.year = 2023
    AND flights.month = 7
    AND flights.day = 29;


SELECT name, people.passport_number, seat FROM people JOIN passengers ON passengers.passport_number = people.passport_number JOIN flights ON flights.id = passengers.flight_id WHERE flights.id = 36;

