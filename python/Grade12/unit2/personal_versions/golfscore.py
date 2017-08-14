'''
Elston Almeida
enter info about program here
2016/19/01
ICS 3U1
'''
def clear_screen():
    import os
    import platform
    if (platform.system() == "Windows"):
        os.system('cls')
    elif (platform.system() == "Linux"):
        os.system('clear')
    #windows cls, linux clear
    else:
        raise RuntimeError("Unknown System Detected")
def valid_user_input():
    check_input = True
    while (check_input == True):
        try:
            #asks for input and validates it
            verified_input = raw_input()
            #allows only key words or scores
            if verified_input in ('0','1','-1','-2','par','bogey','eagle','birdie'):
                if verified_input in ('0','-1','-2','1'):
                    int(verified_input)
                #conversions to values in int
                elif (verified_input == 'par'):
                    verified_input = 0
                elif (verified_input == 'bogey'):
                    verified_input = 1
                elif (verified_input == 'birdie'):
                    verified_input = -1
                else:
                    verified_input = -2
                #ends loop
                check_input = False
                return(verified_input)
            else:
                #invalid input loop back
                print ("Please enter a valid input")
                print ("Score on hole " + str(int(hole_input_loop)+1)+ " was :"),
        except:
            #error message? someone will find a way to break it -_-
            print ("Please enter a valid input: "),
def holes_input_validation():
    #sets up loop
    check_input = True
    while (check_input is True):
        try:
            #asks for input and validates it forcing it to change to int to avoid errors
            total_holes_input = raw_input()
            int(total_holes_input)
            #makes sure no negative values or zero is input
            if (int(total_holes_input) <= 0):
                print ("please enter a number larger than zero : "),

            elif long(total_holes_input) > 2000000:
                print ("O' really...Sir, please try again")
                print ("Please enter a valid amount: "),
            elif (int(total_holes_input) > 18):
                str(total_holes_input)
                print ("The number you have entered is " + total_holes_input + " was this correct ? (y/N): "),
                recheck = raw_input()
                if not recheck:
                    print ("please enter a choice to continue")
                elif recheck in ('yes', 'y', 'Y', 'Yes'):
                    total_holes_input = int(total_holes_input)
                    check_input = False
                    return(total_holes_input)
                else:
                    check_input = True
                    print ("Please retype the amount of holes played: "),
            else:
                check_input = False
                return(total_holes_input)
        except:
            print ("Please enter a valid number\nPlease enter a number for holes played: "), #remove this later elston
def wait(till):
    #to stop windows quiting the program in cmd
    import platform
    import time
    if (platform.system() == "Windows"):
        float(till)
        time.sleep(till)
#var for later
total = 0
#Beginning cleans anything on the screen
clear_screen()
print ("Number of holes to score:"),
#calls the def and will verify input is valid
total_holes = holes_input_validation()
#runs loop that will ask for valid input over the amount of holes
for hole_input_loop in xrange (int(total_holes)):
    clear_screen()
    print ("Score on hole " + str(int(hole_input_loop)+1) + " :"),
    amount = valid_user_input()
    total = int(total) + int(amount)
#For my sanity and neatness
clear_screen()
#final print statement for total score and holes played
print ("Your score over " + str(total_holes) + " holes is " + str(total) + " from par.")
wait(5)
