#!/usr/bin/python3

import os, sys
import subprocess

TOOL_DIR = "tools"

def run_command(cmd):
    subprocess.call(["python", "{}/{}/{}.py".format(os.getcwd(), TOOL_DIR, cmd)])

for i in range(1, len(sys.argv)):
    cmd = sys.argv[i]
    print("\n-------------------")
    print("Executing: ", cmd)
    run_command(cmd)