#!/usr/bin/python3

import os, sys
import subprocess

TOOL_DIR = "tools"

def run_command(cmd):
    script = "{}/{}/{}.py".format(os.getcwd(), TOOL_DIR, cmd)
    if (os.path.exists(script)):
        print("Executing: ", cmd)
        subprocess.call(["python", script])
    else:
        print("Invalid command: ", cmd)

for i in range(1, len(sys.argv)):
    cmd = sys.argv[i]
    print("\n-------------------")
    run_command(cmd)