# This program checks the validity of credit card numbers

# Returns True if the credit card number is valid, False otherwise
def is_valid_credit_card(card_number):
    card_number = card_number[::-1]
    sum = 0
    double_digit = False
    for i in range(len(card_number)):
        digit = int(card_number[i])
        if double_digit:
            digit *= 2
            if digit > 9:
                digit -= 9
        sum += digit
        double_digit = not double_digit
    return sum % 10 == 0


if __name__ == "__main__":
    # Get credit card number from user input
    card_number = input("Enter credit card number: ").strip()

    # Determine the card's issuer
    if is_valid_credit_card(card_number):
        if card_number.startswith("34") or card_number.startswith("37"):
            print("AMEX")
        elif card_number.startswith(("51", "52", "53", "54", "55")):
            print("MASTERCARD")
        elif card_number.startswith("4") and (len(card_number) == 13 or len(card_number) == 16):
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")