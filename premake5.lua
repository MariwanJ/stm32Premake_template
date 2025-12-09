
--- 
-- 
--  This file is a part of the Open Source Design456App
--  MIT License
-- 
--  Copyright (c) 2025
-- 
--  Permission is hereby granted, free of charge, to any person obtaining a copy
--  of this software and associated documentation files (the "Software"), to deal
--  in the Software without restriction, including without limitation the rights
--  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
--  copies of the Software, and to permit persons to whom the Software is
--  furnished to do so, subject to the following conditions:
-- 
--  The above copyright notice and this permission notice shall be included in all
--  copies or substantial portions of the Software.
-- 
--  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
--  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
--  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
--  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
--  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
--  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
--  SOFTWARE.
-- 
--   Author :Mariwan Jalal    mariwan.jalal@gmail.com
-- 
---
-- premake5.lua

workspace "STM32Project"
    architecture "ARM"
    configurations { "Debug", "Release" }
    startproject "stm32_template"

    -- Include MCU config
    dofile("mcu_stm32f767.lua")  -- <--- Microcontroller specific definitions. 

project "stm32_template"
    kind "ConsoleApp"
    language "C"
    targetdir "build/%{cfg.buildcfg}"
    objdir "build/obj/%{cfg.buildcfg}"

    toolset "gcc"
    gccprefix "arm-none-eabi-"

    targetextension ".elf"

    -- C FLAGS
    filter { "language:C" }
        buildoptions(MCU.flags)
        buildoptions {
            "-Wall",
            "-fdata-sections",
            "-ffunction-sections"
        }

    -- ASM FLAGS
    filter { "files:**.s", "files:**.S" }
        buildoptions(MCU.flags)
        buildoptions {
            "-x", "assembler-with-cpp",
            "-MMD",
            "-MP"
        }

    -- Debug/Release
    filter "configurations:Debug"
        symbols "On"
        optimize "Off"
        targetsuffix "D"
        buildoptions { "-O0", "-g3" }

    filter "configurations:Release"
        symbols "Off"
        optimize "Size"
        buildoptions { "-Os", "-g0" }

    -- LINKER FLAGS
    filter {}
        linkoptions {
            MCU.flags,
            "-T" .. MCU.ldscript,
            "--specs=nano.specs",
            "-Wl,--gc-sections",
            "-Wl,--print-memory-usage",
            "-Wl,-Map=%{cfg.targetdir}/%{prj.name}.map"
        }
        links { "m" }

    -- SOURCE FILES & INCLUDE DIRS
    files {
        "src/**.c",
        "src/**.h",
        MCU.startup,
        MCU.ldscript
    }

    includedirs {
        "src",
        "lib/CMSIS/Device",
        "lib/CMSIS/Include"
    }

    -- POSTBUILD COMMANDS
    postbuildcommands {
        (os.target() == "windows" and
            'cmd.exe /C arm-none-eabi-objcopy -O ihex "' .. path.join("build/%{cfg.buildcfg}", "%{cfg.buildtarget.name}") .. '" "' .. path.join("build/%{cfg.buildcfg}", "%{cfg.buildtarget.name}.hex") .. '"' or
            'arm-none-eabi-objcopy -O ihex "' .. path.join("build/%{cfg.buildcfg}", "%{cfg.buildtarget.name}") .. '" "' .. path.join("build/%{cfg.buildcfg}", "%{cfg.buildtarget.name}.hex") .. '"'),

        (os.target() == "windows" and
            'cmd.exe /C arm-none-eabi-objcopy -O binary --strip-all "' .. path.join("build/%{cfg.buildcfg}", "%{cfg.buildtarget.name}") .. '" "' .. path.join("build/%{cfg.buildcfg}", "%{cfg.buildtarget.name}.bin") .. '"' or
            'arm-none-eabi-objcopy -O binary --strip-all "' .. path.join("build/%{cfg.buildcfg}", "%{cfg.buildtarget.name}") .. '" "' .. path.join("build/%{cfg.buildcfg}", "%{cfg.buildtarget.name}.bin") .. '"')
    }
