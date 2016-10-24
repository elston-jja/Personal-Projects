'''
Elston Almeida
enter info about program here
2016/26/03
ICS 3U1
'''
from Tkinter import *
from time import sleep
from random import randint

'''Things learned from project, classes are fun but I'm still horrible at it, and it's nice abstraction to use'''
#unlike my variable name, should have created two classes for 2 windows ???
class app(Frame):

    '''Initializes the window'''
    def __init__(self,master):
        Frame.__init__(self,master)
        self.grid()
        self.user_name_list = []
        self.intro()
        self.name_input()
        self.done_button()

    '''Tells the user how to use the program'''    
    def intro(self):
        self.intro = "Welcome"+"\nPlease enter contestants and then click done"
        self.intro_label = Label(self,text = self.intro)
        self.intro_label.grid(row=0,column=0,sticky=E)

    '''Create text box to input names'''
    def name_input(self):
        self.name_inp = StringVar() 
        self.name_entry = Entry(self, textvariable = self.name_inp)
        self.name_entry.grid(row=1,column=0)
        self.name_entry.bind('<Return>', self.check)
        
    '''Makes sure the input is valid and not repeated and remove error messages'''
    def check(self,event):
        try:
            if self.error_label:
                self.error.destroy()
        except:
            pass
        self.name = self.name_inp.get()
        if self.name == '':
            self.error_label("No input",5,0)
        elif  15 < len(self.name) or len(self.name) < 3:
            self.error_label("Input too short or too long",5,0)
        elif self.name not in self.user_name_list:
            self.user_name_list.append(self.name)
            self.name_entry.delete(0,'end')
        else:
            self.error_label('Name already in list',5,0)

    '''Calling the error statemnt'''
    def error_label(self,error,r,c):
        self.error = Label(self, text = error,fg='red')
        self.error.grid(row = r,column = c)

    '''Done button to call eliminations'''
    def done_button(self):
        self.done = Button(self,text = "Done",command = self.quick_check)
        self.done.grid(row=2,column=0)

    '''Make sure the list exists'''
    def quick_check(self):
        if len(self.user_name_list) > 1:
            self.elimination_sequence()
        else:
            self.error_label('no names input',5,0)
            
    '''Random elimination messages'''
    def elimination_messages(self):
        self.message = [" sorry\n"," is eliminated\n", ", better luck next time\n"," has been eliminated\n" ]
        self.rand_message = randint(0,(len(self.message)-1))
        self.elimination_message = self.message[self.rand_message]
        return self.elimination_message

    '''Eliminates names in sequence'''
    def elimination_sequence(self):
        # Remove all the other things of screen w/o destroying grid
        self.intro_label.destroy()
        self.done.destroy()
        self.name_entry.delete(0,'end')
        self.name_entry.destroy()
        while len(self.user_name_list) > 1:
            self.eliminate = randint(0,(len(self.user_name_list)-1))
            self.eliminate_label = Label(self,text= self.user_name_list[self.eliminate] + self.elimination_messages()).grid()
            lottery_window.update()
            self.user_name_list.pop(self.eliminate)
            sleep(1)
        self.winner()
        self.quit_b()

    '''Lables the winner'''
    def winner(self):
        sleep(1.0)
        #self.eliminate_label.destroy()
        #self.hype = Label(self,text = 'And the winner is',).grid()
        for i in range(3):
            self.hypetext = 'And the winner is'
            self.hypetext = self.hypetext +  '.'
            lottery_window.update()
            self.hype = Label(self,text = self.hypetext).grid(row=1000,column=0)
            sleep(1.0)
            #self.hype.destroy()
        self.winner = self.user_name_list[0]
        self.winner_label = Label(self,text =(str(self.winner)),fg ='green').grid()

    '''Quit button'''
    def quit_b(self):
        self.quit_button = Button(self,text = 'Quit', command = self.quit).grid()

'''Define window and params'''
lottery_window = Tk()
lottery_window.title('lottery picker')
#lottery_window.geometry('')


app(lottery_window)
lottery_window.mainloop()
    
