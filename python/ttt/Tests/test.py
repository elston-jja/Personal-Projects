#make box
class box:
    def area(self):
        return self.width * self.height
    def __init__(self,width,height):
        self.width = width
        self.height = height

x = box(10,12)

print (x.area())

raw_input()

class character:
    def multi(self):
        return self.grades * self.average
    def __init__(self,grades,average):
        self.grades = grades
        self.average = average
hello = character(280,80)
print (hello.multi())
raw_input()
