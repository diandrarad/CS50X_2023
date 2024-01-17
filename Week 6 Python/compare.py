from cs50 import get_int

x = get_int("x: ")
y = get_int("y: ")

if x < y:
    print("x is less than y")
elif x > y:
    print("x is greater that y")
else:
    print("x is equal to y")

print(f"x is {x}, y is {y}")
x, y = y, x
print(f"x is {x}, y is {y}")

s = input("s: ")
t = s.capitalize()

print(f"s: {s}")
print(f"t: {t}")