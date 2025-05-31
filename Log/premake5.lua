workspace "LogWorkspace"
    architecture "x64"
    configurations { "Debug", "Release" }
    startproject "Test"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Static Library Project
project "Log"
    location "Log"
    kind "StaticLib"   -- Changed from SharedLib
    language "C++"
    cppdialect "C++20"
    staticruntime "on" -- Link C/C++ runtime statically

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "Log/include/**.h",
        "Log/src/Log.cpp"
    }

    includedirs {
        "Log/include"
    }

    filter "system:windows"
        systemversion "latest"
        defines { "LOG_PLATFORM_WINDOWS" }

    filter "configurations:Debug"
        defines "LOG_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "LOG_RELEASE"
        optimize "On"

-- Test Application
project "Test"
    location "Log/src/Test"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "Log/src/Test/**.cpp"
    }

    includedirs {
        "Log/include"
    }

    links {
        "Log"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        defines "TEST_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "TEST_RELEASE"
        optimize "On"
