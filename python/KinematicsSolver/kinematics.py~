import math       #, ast

print(" \n\nKinematics Equation Solver\n\n ") #Please enter 0 for an unknown value\n\n")
option=input("what would you like to solve for: \n\n1. initial velocity\n2. final velocity\n3. displacement\n4. acceleration\n5. time \n\n solve for : ")

#consider revising placement in each statement
vi=raw_input("Velocity initial: ")
vf=raw_input("Velocity final: ")
disp=raw_input("Displacement: ")
accel=raw_input("acceleration: ")
time=raw_input("time: ")

#converts the values to floats
if vi != "":
    vi = float(vi)
else:
    vi=None
if vf != "":
    vf = float(vf)
else:
    vf=None
if disp != "":
    disp = float(disp)
else:
    disp=None
if accel != "":
    accel = float(accel)
else:
    accel=None
if time != "":
    time = float(time)
else:
    time=None

#option 1: solve velocity initial
if option==1:
    del vi
    #if time does not have a value
    if (time is None):
        print ("time not found")
        vi=(-1*(2*accel*disp-vf))
    #if velocity final does not have a value
    elif (vf is None):
        print ("vf not found")
        vi=(-1*(0.5*accel*time-disp))
    #if displacement does not have a value
    elif (disp is None):
        print ("displacement not found")
        vi=vf-(accel*time)
    else:
        print ("all var found")
        vi=vi=(-1*(0.5*accel*time-disp))
    print str(vi)
#option 2: solve velocity final
if option==2:
    del vf
    #if velocity initial does not have a value
    if (vi is None):
        vf=((-1*disp)+(0.5*accel)*math.pow(time, 2))/time 
    #if time is NA
    elif (time is None):
        vf=math.sqrt(2*accel*disp+(math.pow(vi, 2)))
    #if displacement is NA
    elif (disp is None):
        vf=(accel*time)+vi
    else:
        vf=math.sqrt(2*accel*disp+(math.pow(vi, 2)))
    print str(vf)    
#option 3 solve for displacement
if option==3:
    del disp
    #if velociy final is NA
    if (vf is None):
        disp=(0.5*accel)*(math.pow(time, 2))+(vi*time)
    #if velocity initial is NA
    elif (vi is None):
        disp=(vf*time)+(-0.5*accel)*math.pow(time, 2)
    #if time is NA
    elif (time is None):
        disp=((math.pow(vf, 2))-(math.pow(vi, 2)))/accel
    else:
        vf=math.sqrt(2*accel*disp+(math.pow(vi, 2)))
    print str(disp)
#Solve for acceleration
if option==4:
    del accel
    #if velocity initial NA
    if (vi is None):
        accel=((vi+time-disp)*-2)/(math.pow(time, 2))
    #if velocity final NA
    elif (vf is None):
        accel=((vf*time-disp)*2)/(math.pow(time, 2))
    #if disp is NA
    elif (disp is None):
        accel=(vf-vi)/time
    #if time is NA
    elif (time is None):
        accel=(math.pow(vf, 2)-math.pow(vi, 2))/2*disp
    else:
        accel=(math.pow(vf, 2)-math.pow(vi, 2))/2*disp
    print str(accel)
#Solve for time
if option==5:
    del time
    #if vf NA
    if (vf is None):
        time=(math.sqrt(((-1*disp)*(-2))/(accel-vi)))/2
    #if vi NA
    elif (vi is None):
        time=(math.sqrt(((-1*disp)*(2))/(accel-vf)))/2
    #if disp and acceleration is NA
    elif (disp is None):
        time=((-1*vf)+vi)/accel
    else:
        time=((-1*vf)+vi)/accel
    print str(time)
#if velocity final does not   
#if (vi == 0 and accel <> 0 and disp <> 0):
#vi=math.sqrt(-1*(2*accel*disp-(math.pow(vf, 2))))
#vf=math.sqrt(2*accel*disp+(math.pow(vi, 2)))
#disp=((math.pow(vf, 2))-(math.pow(vi, 2)))/2*accel
#accel=(vf-vi)/time
#time=(vf-vi)/accel
#print ("\n\n")
#print ("the initial velocity is: "+str(vi))
#print ("the final velocity is: "+str(vf))
#print ("the acceleration is: "+str(accel))
#print ("the displacement is: "+str(disp))
#print ("the time is: "+str(time))
