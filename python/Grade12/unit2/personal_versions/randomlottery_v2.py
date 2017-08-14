'''
Elston Almeida
Lottery Value
2016/01/01
ICS 3U1
'''
'''Personal Copy'''
#  randint()

'''Importing Required Modules'''
from random import randint

#main()
# imports color codes for text in bash
# from primemods import color
# I can't actually test colors in shell or windows... 
class color:
    red = "\033[1;31m"
    blue = "\033[1;34m"
    grey = "\033[1;30m"
    bold_w = "\033[1;38m"
    green = "\033[1;32m"
    #always use when returning 
    w_re = "\033[1;m"

'''Intro to program | Give instructions to user'''
def intro():
    clear_screen()
    print "###################################################"
    print color.blue+"        Welcome to the Lottery of Luck"
    print "\nTo begin please enter the names of the contestants"
    print "            -Created by Elston"+color.w_re
    print "###################################################\n"
    print 'Type "done" when all names have been entered\n'

'''Choose a random elimination message to display'''
def random_elimination_message():
    messages = [", sorry\n"," is eliminated\n", ", better luck next time\n"," has been eliminated\n"]
    randnum = randint(0,(len(messages)-1))
    printed_message = messages[randnum]
    return(printed_message)

'''Chooses a random name from a list, and removes it'''
def eliminate():
    eliminate = randint(0,(len(user_input_names)-1))
    print color.bold_w + user_input_names[eliminate] +  random_elimination_message() + color.w_re
    user_input_names.pop(eliminate)

'''Suspense building methods and stdout statement to update output'''
def wait(till):
    from time import sleep
    sleep(float(till))

import time
time.sleep(5.0)
    
def printf(str):
    from sys import stdout
    stdout.write(str)
    stdout.flush()

'''Clears the screen, only works on windows and linux'''
def clear_screen():
    from os import system
    import platform
    if (platform.system() == "Windows"):
        system('cls')
    elif (platform.system() == "Linux"):
        system('clear')
    #windows cls, linux clear, mac clear ??? idk
    else:
        system('clear')
        #raise RuntimeError("Unknown System Detected")

'''Sets up loop for names and other variables needed'''
loop_names = True
input_names = 1
user_input_names = [] # Creates list

'''Repeats loop and adds input to list until "done" is input'''
intro()
for i in range (input_names):
    while loop_names is True:
        try:
            names = raw_input("Please enter a name: ")
            # Input is blank
            if not names:
                print color.red+"Please enter a name"+color.w_re
            # Restriciton of characters in name
            elif  15 < len(names) or len(names) < 3: #????? should include ?????
                print color.red+"Please enter a valid name"+color.w_re
            # How to exit but makes sure list has values
            elif names == "done":
                if len(user_input_names) > 0:
                    loop_names = False
                else:
                    print color.red+"Please enter a name"+color.w_re
            else:
                # Makes sure add names to user_input_names
                user_input_names.append(names)
                input_names = input_names + 1
        except:
            print "An error occured"

clear_screen()


print ("\nLets go ...\n")


'''Eliminates names until only one str left in list'''
while len(user_input_names) > 1:
    wait(1)
    eliminate()

# Builds suspense ???

winner = user_input_names[0]

print "Therefore ",
for i in range(3):
    printf ("."),
    wait(1)

# final statement

print color.green  + str(winner) + color.w_re + " is the winner\n "
