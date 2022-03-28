workspace "infinite"
    startproject "infinite-editor"
    architecture "x64"

    configurations { "Debug", "Release" } 

tdir = "bin/%{cfg.buildcfg}/%{prj.name}"
odir = "bin_obj/%{cfg.buildcfg}/%{prj.name}"

-- External Dependencies
externals = {}
externals["sdl2"] = "external/sdl2"

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
    sysincludedirs 
    { 
        "%{prj.name}/include/%{prj.name}",
        "%{externals.sdl2}/include"
    }
    flags { "FatalWarnings" }
    filter { "system:windows", "configurations:*" }
        systemversion "latest"
        defines { "INFINITE_PLATFORM_WINDOWS"}
    filter { "system:linux", "configurations:*" }
        defines { "INFINITE_PLATFORM_LINUX"}
    filter { "system:macosx", "configurations:*" }
        xcodebuildsettings 
        {
            ["MACOSX_DEPLOYMENT_TARGET"] = "10.15",
            ["UseModernBuildSystem"] = "NO "
        }
        defines { "INFINITE_PLATFORM_MAC "}
    filter { "configurations:Debug" }
        defines { "INFINITE_CONFIG_DEBUG"}
        runtime "Debug"
        symbols "on"
    filter { "configurations:Release" }
        defines { "INFINITE_CONFIG_RELEASE"}
        runtime "Release"
        symbols "off"
        optimize "on"
    
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
    filter { "system:windows", "configurations:*" }
        systemversion "latest"
        defines { "INFINITE_PLATFORM_WINDOWS"}
        libdirs { "%{externals.sdl2}/lib" }
        links { "SDL2" }
    filter { "system:linux", "configurations:*" }
        defines { "INFINITE_PLATFORM_LINUX"}
    filter { "system:macosx", "configurations:*" }
        xcodebuildsettings 
        {
            ["MACOSX_DEPLOYMENT_TARGET"] = "10.15",
            ["UseModernBuildSystem"] = "NO "
        }
        defines { "INFINITE_PLATFORM_MAC "}
    filter { "configurations:Debug" }
        defines { "INFINITE_CONFIG_DEBUG"}
        runtime "Debug"
        symbols "on"
    filter { "configurations:Release" }
        defines { "INFINITE_CONFIG_RELEASE"}
        runtime "Release"
        symbols "off"
        optimize "on"
    