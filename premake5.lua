workspace "infinite"
    startproject "infinite-editor"
    architecture "x64"

    configurations { "Debug", "Release" } 

tdir = "bin/%{cfg.buildcfg}/%{prj.name}"
odir = "bin_obj/%{cfg.buildcfg}/%{prj.name}"

project "infinite-editor"  
    location "infinite-editor"   
    kind "ConsoleApp"   
    language "C++"   
    cppdialect "C++17"
    targetdir(tdir)
    objdir(odir)
    files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }
    flags { "FatalWarnings" }
    