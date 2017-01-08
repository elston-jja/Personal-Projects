import math 

print ("Equation Solver Grade 11 Physics \n")
print ("Please enter the known variables: \n")
v_i = input("Initial velocity: ")
v_f = input("final velocity: ")
d_x = input("Delta x: ")
t = input("Time: ")
a = input("Acceleration: ")

vars = [v_i, v_f, d_x, t, a]

null = 0

for var in vars:
    if var == "":
        null+=1

if null > 2:
    print ("\nNot enough Info")
    
print("-----------------")
        
for var in vars:
    print (type(var))

solved = 5 - null

e1,e2,e3,e4,e5 = False, False, False, False, False

while(solved < 5):
    if( d_x == "" and e1 == False):
        v_f = v_i + a*t
        e1 = True
        solved += 1
    if( v_f == "" and e2 == False):
        d_x = v_i *t + 1/2*a*math.pow(t, 2)
        e2 = True
        solved += 1
    if( t == "" and e3 == False):
        v_f = math.sqrt( math.pow(v_i, 2) + 2 * a  * d_x)
        e3 = True
        solved += 1
    if( a == "" and e4 == False):
        d_x = 1/2 * ( v_i + v_f ) * t
        e4 = True
        solved += 1
    if( v_i == "" and e5 == False):
        d_x = v_f * t -1/2 * a *math.pow(t, 2)
        e5 = True
        solved += 1
