'''
Elston Almeida
Uses lists to add and remove names for a lottery picker
2016/03/27
ICS 3U1
'''

'''imports libraries for random integers'''
from random import randint

#main()

'''Picks a random integer from a range within the length of the list (messages) and then returns the message back'''

def random_elimination_message():
    messages = [", sorry\n"," is eliminated\n", ", better luck next time\n"," has been eliminated\n"]
    randnum = randint(0,(len(messages)-1))
    printed_message = messages[randnum]
    return(printed_message)

'''Picks a random integer from a range within the length of the list and removes the name corresponding to the number picked'''

def eliminate():
    eliminate = randint(0,(len(user_input_names)-1))
    print user_input_names[eliminate] + random_elimination_message()
    user_input_names.pop(eliminate)

'''loops input and adds to list for names until "done" is recieved, do not accept absurd values'''

loop_names = True
input_names = 1
user_input_names = [] # Creates list
# Repeats until "done" is said
for i in range (input_names):
    while loop_names is True:
        try:
            names = raw_input("Please enter a name: ")
            # Input is blank
            if not names:
                print "Please enter an input"
            # Restriciton of characters in name
            elif  15 < len(names) or len(names) < 3: #????? should include ?????
                print "Please enter a valid name"
            # How to exit
            elif names == "done":
                loop_names = False
            else:
                # Makes sure add names to list
                user_input_names.append(names)
                input_names = input_names + 1
        except:
            #Amazing fallback params
            print "Windows 10 style:\n\n :( \n\n\n\nSomething Happened\nREASON: Something Happened \nError:0X000000"

''' calls functions and prints the winner'''
print ("\nLets go ...\n")
while len(user_input_names) > 1:
    eliminate()
winner = user_input_names[0]
print str(winner) + " is the winner\n "
# remove colors and other things | hand in copy
