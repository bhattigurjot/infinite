workspace "infinite"
    startproject "infinite-editor"
    architecture "x64"

    configurations { "Debug", "Release" } 

tdir = "bin/%{cfg.buildcfg}/%{prj.name}"
odir = "bin_obj/%{cfg.buildcfg}/%{prj.name}"

project "infinite"
    location "infinite"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    targetdir(tdir)
    objdir(odir)
    files 
    {
        "%{prj.name}/include/**.h",
        "%{prj.name}/src/**.h", 
        "%{prj.name}/src/**.cpp"
    }
    sysincludedirs { "%{prj.name}/include/%{prj.name}" }
    flags { "FatalWarnings" }
    
project "infinite-editor"  
    location "infinite-editor"   
    kind "ConsoleApp"   
    language "C++"   
    cppdialect "C++17"
    staticruntime "on"
    links { "infinite" }
    targetdir(tdir)
    objdir(odir)
    files 
    {
        "%{prj.name}/include/**.h",
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp" 
    }
    sysincludedirs { "infinite/include", "infinite/src" }
    flags { "FatalWarnings" }
    