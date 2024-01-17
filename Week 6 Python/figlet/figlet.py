import sys
from pyfiglet import Figlet
from random import randint

if len(sys.argv) == 2:
    if sys.argv[1] != "--random":
        sys.exit("Usage: python figlet.py [--random] or [-f/--font font_name]")
    font = Figlet().getFonts()[randint(0, len(Figlet().getFonts()) - 1)]

elif len(sys.argv) == 3:
    if sys.argv[1] not in ["-f", "--font"] or sys.argv[2] not in Figlet().getFonts():
        sys.exit("Usage: python figlet.py [--random] or [-f/--font font_name]")
    font = sys.argv[2]
else:
    sys.exit("Usage: python figlet.py [--random] or [-f/--font font_name]")

figlet = Figlet(font=font)
text = input("Enter some text: ")
print(figlet.renderText(text))