workspace "CashFlow"
    startproject "CashFlow"
    architecture "x86_64"
    configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Create a static library project for Business Logic Layer (BLL)
project "BLL"
    location "BLL"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"

    targetdir ("bin/".. outputdir.. "/%{prj.name}")
    objdir ("bin-int/".. outputdir.. "/%{prj.name}")

    files { "BLL/src/.cpp", "BLL/lib/.h" }

    staticruntime "On"
    systemversion "latest"

    filter "configurations:Debug"
        defines "OD_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "OD_RELEASE"
        optimize "On"

        
project "CashFlow"
    location "CashFlow"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    targetdir ("./bin/" .. outputdir .. "/%{prj.name}")
    objdir ("./bin-int/" .. outputdir .. "/%{prj.name}")

    files { "./%{prj.name}/src/**.cpp", "./%{prj.name}/lib/**.h" }

    includedirs { "./vendor/raylib/include", "./%{prj.name}/src", "./%{prj.name}/lib" }

    libdirs { "./vendor/raylib/lib", "./%{prj.name}/lib" }

    links { "raylibdll" }

    postbuildcommands { "{COPY} \"%{wks.location}/vendor/raylib/lib/raylib.dll\" \"%{cfg.targetdir}\"" }

    staticruntime "On"
    systemversion "latest"

    filter "configurations:Debug"
        defines "OD_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "OD_RELEASE"
        optimize "On"