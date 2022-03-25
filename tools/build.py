import globals
import os, subprocess

CONFIG = "debug"

if globals.is_windows():
    BUILD_PATH = "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\Msbuild\\Current\\Bin\\MSBuild.exe" 

    subprocess.call(["cmd.exe", "/c", BUILD_PATH, "{}.sln".format(globals.ENGINE_NAME), "/property:Configuration={}".format(CONFIG)])
