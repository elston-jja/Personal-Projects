from Tkinter import *

def submit():
    passwd = password.get()
    usr = username.get()
    mklabel = Label(window,text ='username was: '+usr).grid(row=3,column=1,sticky=W)
    mklabel = Label(window,text ='password was: '+passwd).grid(row=4,column=1,sticky=W)

window = Tk()
window.geometry('300x300')
window.title('HelloWorld')


password = StringVar()
username = StringVar()

username_txt = Label(window,text = 'Username').grid(row=0,column=0,sticky=W)

username_entry = Entry(window, textvariable=username).grid(row=0,column=1,sticky=W)

password_txt = Label(window,text = 'Password').grid(row=1,column=0,sticky=W)

password_entry = Entry(window,textvariable=password).grid(row=1,column=1,sticky=W)

submit_button = Button(window,text = 'Submit',command = submit).grid(row=2,column=1)



window.mainloop()
