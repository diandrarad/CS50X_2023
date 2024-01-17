from cs50 import get_float

# Prompt the user for a positive floating-point number
n = 0
while True:
    n = get_float("Change owed: ")
    if n > 0:
        break

# Convert the dollars to cents and round to the nearest penny
cents = round(n * 100)

# Initialize a variable to keep track of the number of coins
coins = 0

quarters = cents // 25
if quarters > 0:
    cents -= quarters * 25
    coins += quarters

dimes = cents // 10
if dimes > 0:
    cents -= dimes * 10
    coins += dimes

nickels = cents // 5
if nickels > 0:
    cents -= nickels * 5
    coins += nickels

if cents > 0:
    coins += cents

# Output the total number of coins
print(coins)