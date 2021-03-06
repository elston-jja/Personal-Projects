'''
Elston Almeida
Doubling effect
2016/03/07
ICS 3U1
'''

import textwrap
from primemods import color

#v_name = valid_user_input() <--- Note for later
def valid_user_input():
    #checks if user left vars blank and returns question
    inp_check = True
    while inp_check is True:
        try:
            u_name = raw_input()
            if not u_name:
                print color.red + ("Fill in the required field above: ")+color.w_re ,
            else:
                inp_check = False
                return(u_name)
        except:
            print ("An error has occured, Please try again: "),

#v_name = valid_user_input() <--- Note for later
def valid_choice():
    #validates choice input
    inp_check = True
    while inp_check is True:
        try:
            u_choice = int(raw_input("Please enter your choice: "))
            if not u_choice:
                print ("Please enter a choice")
            elif (u_choice > 3 or u_choice < 0):
                print color.red+"Not a valid number"+color.w_re
            else:
                inp_check = False
                return(u_choice)
        except:
            print (color.red+"Not a valid choice"+color.w_re)

#windows is cls, linux is clear
def clear_screen():
    import os
    import platform
    if (platform.system() == "Windows"):
        os.system('cls')
    elif (platform.system() == "Linux"):
        os.system('clear')
    else:
        print "Unknown System detected: Forcing Windows commands"
        os.system('cls')

#giving options for choice 1 (tree)
def oppening():
    print "Arch-Bishop - Enters the room"
    print "Arch-Bishop: Dear " + user_prefix + " " + user_name + ", I am afraid it is now time,"
    print "the neighbouring nations are forwarding a full frontal attack."
    print "I must warn you my lord, our army is not ready for this war."
    print "It is now or never Sir, do you choose to attack, ask for a fair trade,"
    print "or surrender to their demands ?"
    print color.bold_w + "Options: \n1. ATTACK \n2. TRADE FOR A SETTLEMENT \n3. SURRENDER"+ color.w_re

#choice 1 chosen branch
def attack():
    clear_screen()
    decision1 = '''
    As you view your current forces you may agree that you truely do not
    have a high chance of survival. The Arch-Bishop's advice could be
    nobel advice, your forces are waiting for the command
    '''
    print textwrap.dedent(decision1).strip()
    print color.bold_w+"Options: \n1. LISTEN TO ARCH-BISHOP \n2. ATTACK \n3. SURRENDER" + color.w_re

#choice 1 chosen from first branch of tree choice 1
def listen():
    clear_screen()
    decision1_1='''
    You decide to stall against the opposing forces, other nations see this as a wise choice,
    Lsblk, one of the neighbouring nations has seen your wisdom, the king has decided to come to
    your nation to negotiate an alliance'''
    print textwrap.dedent(decision1_1).strip() #try different styles?
    print "\nKing of Lsblk: Hello " + user_name + " " + user_prefix + " of %s"%user_place,"it seems like"
    print "we have a common enemy, since I do not have a request at this time, "
    print "I will provide support for no cost to you... at this time, what would you say ?"
    print color.bold_w+"Options: \n1. ACCEPT ALLIANCE \n2. DECLINE ALLIANCE \n3. DECLARE WAR ON LSBLK"+color.w_re

#branch of choice 1 of a branch by option one chosen earlier
def alliance_accept():
    clear_screen()
    print ("With your new help what do you choose to do ?")
    print color.bold_w+"Options: \n1. ATTACK \n2. STALL \n3. SURRENDER" + color.w_re

#pause
def wait(till):
    import time
    float(till)
    time.sleep(till)

#losing text
def loss():
    print "You lose and %s"%user_place,"gets taken over by your enemies"

#sets up loop for restart

running = True

while (running is True):
    clear_screen()
    print "Hello there, before we get started please enter the following information"
    print "what is your name: ",
    user_name = valid_user_input()
    print "what is a place you would like to rule: ",
    user_place = valid_user_input()
    print "Please a position of hierarchy: ",
    user_prefix = valid_user_input()
    print "Lets begin"
    clear_screen()
    oppening()
    #multiple if statements ahead to gather user input and display choices
    choice=valid_choice()
    if (choice == 1):
        attack()
        choice_1 = valid_choice()
        if (choice_1 == 1):
            listen()
            choice_1_1 = valid_choice()
            if (choice_1_1 == 1):
                alliance_accept()
                choice_1_1_1 = valid_choice()
                if (choice_1_1_1 == 1):
                    print "You attack and face your eventual defeat"
                    loss()
                elif (choice_1_1_1 == 2):
                    print "You stall for too long"
                    loss()
                else:
                    loss()
            elif (choice_1_1 == 2):
                print "You deny their help, enemies storm your safehaven and you meet death"
                loss()
            else:
                loss()
        elif (choice_1 == 2):
            print ("You attack and meet your death as your forces are overpowered")
            loss()
        else:
            loss()
    elif (choice == 2):
        print ("You meet with the primary nations that has declared war on you \nthen you eventaully die")
        loss()
    else:
        loss()
    #play again?
    wait(7)
    print color.bold_w+"Do you want to play again ? (y/N)"+color.bold_w
    end = raw_input()
    if end in ('yes', 'Yes', 'y', 'Y'):
        clear_screen()
    #allows users to exit program
    else:
        clear_screen()
        
        print color.blue+"################### Thank you for playing ###################\n"
        print "                      Created by Elston"
        print "                      Inspired by Death"
        print '                    THERE IS NO WAY TO "WIN"\n'
        print "################### Thank you for playing ###################" + color.w_re
        wait(3)
        running = False
