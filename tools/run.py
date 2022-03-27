import globals
import os, subprocess

EXEC_PATH = "{}/bin/{}/{}".format(os.getcwd(), globals.CONFIG, globals.PROJECT_NAME) 

if globals.is_windows():
    subprocess.call(["{}/{}".format(EXEC_PATH, globals.PROJECT_NAME)])
