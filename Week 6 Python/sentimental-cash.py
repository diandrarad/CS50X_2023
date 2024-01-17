from cs50 import get_float

# Prompt the user for a positive floating-point number
while True:
    dollars = get_float("Change owed: ")
    if dollars > 0:
        break

# Convert the dollars to cents and round to the nearest penny
cents = round(dollars * 100)

# Define the coin denominations and their values in cents
denominations = [25, 10, 5, 1]

# Initialize a variable to keep track of the number of coins
coins = 0

# Loop through each denomination, subtracting as many coins as possible
for denomination in denominations:
    coins += cents // denomination
    cents %= denomination

# Output the total number of coins
print(coins)