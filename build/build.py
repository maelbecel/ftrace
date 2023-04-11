#/usr/bin/env python3

from time import sleep
import sys


# Defining the colors for the progress bar.
bold = '\033[1m'
normal = '\033[0m'
red = '\033[31m\033[1m'
yellow = '\033[33m\033[1m'
green = '\033[32m\033[1m'

# Clearing the line.
spaces = " "*50
sys.stdout.write('\r')
sys.stdout.write(spaces * 2)
sys.stdout.write('\r')

# Taking the arguments from the command line and assigning them to variables.
file = sys.argv[1]
nb = sys.argv[2]
all = sys.argv[3]

# Calculating the percentage of the progress bar.
place = 30
percentage = int(nb) * 100 / int(all)

# Displaying the progress bar.
display = bold + file
if len(file) < place:
    display += " " * (place - len(file))
display += "["
sys.stdout.write(display)

# Assigning a color to the progress bar depending on the percentage of the
# progress.
if percentage > 67:
    color = green
elif percentage > 33:
    color = yellow
else:
    color = red
sys.stdout.write(color)


sys.stdout.write(u"\u25AE" * int(int(percentage) * place / 100))
sys.stdout.write(" " * int(place - (percentage * place / 100)))

sys.stdout.write(normal + bold + "]" + "\t" + str(int(percentage)) + '%' + normal + "\t" +"(" + nb + '/' + all +")" + spaces )
sys.stdout.flush()
