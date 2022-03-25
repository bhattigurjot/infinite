import sys, platform
import enum

ENGINE_NAME = "infinite"
PROJECT_NAME = "infinite-editor"
VERSION_MAJOR = 1
VERSION_MINOR = 0

PLATFORM = sys.platform

class Platform_Type(enum.Enum):
    WINDOWS = "windows"
    LINUX = "linux"
    MAC = "darwin"

for x in platform.uname():
    if "windows" in x.lower():
        PLATFORM = Platform_Type.WINDOWS
        break

def is_windows():
    return PLATFORM == Platform_Type.WINDOWS

def is_linux():
    return PLATFORM == Platform_Type.LINUX

def is_mac():
    return PLATFORM == Platform_Type.MAC