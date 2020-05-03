-- Defines a workspace with two projects inside (Dane and Sandbox)
workspace "Dane"
  architecture "x64"

  configurations
  {
    "Debug", -- I think it is pretty clear what it is
    "Release", -- Basically a faster version of debug
    "Dist" -- Distribution version, absolutely no logging
  }

-- Defining a Variable. See Tokens page on premake5 documentation
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Dane"
  location "Dane"
  kind "SharedLib"
  language "C++"
  cppdialect "C++17"

  -- You append strings with .. on premake
  targetdir ("bin/outputs/" .. outputdir .. "/%{prj.name}")
  objdir ("bin/intermediates/" .. outputdir .. "/%{prj.name}")

  files
  {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp"
  }

  includedirs
  {
    "%{prj.name}/vendor/realog"
  }

  filter "configurations:Debug"
    defines "DN_DEBUG_CONFIG"
    symbols "On"

  filter "configurations:Release"
    defines "DN_RELEASE_CONFIG"
    optimize "On"

  filter "configurations:Dist"
    defines "DN_DIST_CONFIG"
    optimize "On"


project "Sandbox"
  location "Sandbox"
  kind "ConsoleApp"
  language "C++"
  cppdialect "C++17"

  targetdir ("bin/outputs/" .. outputdir .. "/%{prj.name}")
  objdir ("bin/intermediates/" .. outputdir .. "/%{prj.name}")

  files
  {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp"
  }

  includedirs
  {
    "Dane/src",
    "Dane/vendor/realog"
  }

  links
  {
    "Dane"
  }

  filter "configurations:Debug"
    defines "DN_DEBUG_CONFIG"
    symbols "On"

  filter "configurations:Release"
    defines "DN_RELEASE_CONFIG"
    optimize "On"

  filter "configurations:Dist"
    defines "DN_DIST_CONFIG"
    optimize "On"