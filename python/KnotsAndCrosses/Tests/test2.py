class character:
    def __init__(self,grades,average):
        self.grades = grades
        self.average = average
    def multi(self):
        return self.grades*self.average
hello = character(280,80)
print (hello.multi())
raw_input()
