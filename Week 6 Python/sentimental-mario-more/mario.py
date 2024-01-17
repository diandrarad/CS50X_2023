# Prompt the user to enter a number between 1 and 8
# and continue prompting until a valid number is entered
n = 0
while n < 1 or n > 8:
    try:
        n = int(input("Height: "))
    except ValueError:
        print("Not a positive integer no greater than 8")


# Loop through each row of the pyramid
for i in range(n):
    # Print the appropriate number of spaces to left-align the pyramid
    for j in range(n - i - 1):
        print(" ", end="")

    # Print the appropriate number of hashes for the current row
    for k in range(i + 1):
        print("#", end="")
    print("  ", end="")
    for l in range(i + 1):
        print("#", end="")

    # Move to the next line to start the next row
    print()