'''
Py game testing
'''

import os

class check_folder:

        ''' this is a simple program to create subfolders in current dirs'''
        def __init__(self):
                print "initalized"

        def check_exists(self): 
                self.files_create = ["file test","file test 2"]
                self.current_path = os.getcwd
                self.current_files = os.listdir(os.curdir)
                print self.current_files
                if self.files_create in self.current_files:
                        print "files exist"
                else:
                        '''Make dirs from list'''
                        for i in range (len(self.files_create)):
                                open(self.files_create[i], 'a')
                        

folder_exists = check_folder()
true = folder_exists.check_exists()
