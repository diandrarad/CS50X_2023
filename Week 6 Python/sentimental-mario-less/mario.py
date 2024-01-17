def main():
    height = get_height()

    # Loop through each row of the pyramid
    for i in range(height):
        # Print the appropriate number of spaces to left-align the pyramid
        for j in range(height - i - 1):
            print(" ", end="")
            
        # Print the appropriate number of hashes for the current row
        for k in range(i + 1):
            print("#", end="")

        # Move to the next line to start the next row
        print()


def get_height():
    # Prompt the user to enter a number between 1 and 8
    # and continue prompting until a valid number is entered
    while True:
        try:
            n = int(input("Height: "))
            if n > 0 and n <= 8:
                return n
        except ValueError:
            print("Not a positive integer no greater than 8")


main()