from Tkinter import *

class application(Frame):

    '''Initializes the window and objects'''
    def __init__(self, master = None):
        Frame.__init__(self,master)
        self.grid()
        self.create_passwd()
        self.create_usrname()
        self.register()

    '''Sets up UI'''
    def create_passwd(self):
        self.passwd_label = Label(self,text = 'enter password')
        self.passwd_label.grid(row=1,column=0)
        self.passwd = StringVar()
        self.passwd_entry = Entry(self, textvariable = self.passwd)
        self.passwd_entry.grid(row=1,column=1)

    def create_usrname(self):
        self.usr_label = Label(self,text = 'enter username')
        self.usr_label.grid(row=0,column=0)
        self.usr = StringVar()
        self.usr_entry = Entry(self, textvariable = self.usr)
        self.usr_entry.grid(row=0,column=1)
        
    def register(self):
        self.submit_button = Button(self, text = 'submit',command = self.submit )
        self.submit_button.grid(row=2,column=1)

    '''Manipulation of data, echo data'''
    def submit(self):
        self.final_username = self.usr.get()
        self.final_passwd = self.passwd.get()
        self.values = Label(self, text = self.final_username)
        self.values.grid(row=3,column=1)
        self.values2 = Label(self, text = self.final_passwd)
        self.values2.grid(row=4,column=1)


window = Tk()
window.title("Gui Programming")
window.geometry("300x300")
application(window)
window.mainloop()
