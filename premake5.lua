workspace "infinite"
    startproject "infinite-editor"
    architecture "x64"

    configurations { "Debug", "Release" } 

project "infinite-editor"  
    location "infinite-editor"   
    kind "ConsoleApp"   
    language "C++"   
    cppdialect "C++17"
    files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }
    flags { "FatalWarnings" }
    