# AnalogAudio
AnalogAudio is a combined source selector and volume control for 2 analog audio channels.
The software runs on the AnalogAudio board, the source of whose layout is also in this repository.

[Wiki]

This is a component of my Home Automation system, which is described here http://oakhousehomeautomation.wikidot.com
The analogaudio wiki page is here http://oakhousehomeautomation.wikidot.com/analogaudio

# Development environment
This project was developed using:
- MPLAB X IDE v3.35
- xc32-gcc
- cx32-g++

These are downloadable from Microchip:
http://www.microchip.com/mplab/mplab-x-ide
http://www.microchip.com/xcdemo/xcpluspromo.aspx

These need to be installed in order to build.

# Building the software
1. Start MPLABX IDE
2. Create a Microchip Embedded standalone Project
   Select device PIC32MM0064GPL020.
   Select your debugging tool - I use PicKit3
   Select compiler XC32(v1.42)
   Enter project name : AnalogAudio
   Project folder is set to AnalogAudio.X
3. Add a new logical folder PIC32Device to your project
4. Add the files from the PIC32Device repository to the PIC32Device logical folder.
5. Add a new logical folder AnalogAudio to your project
6. Add the files from the AnalogAudio repository to the AnalogAudio logical folder.


# Dependency
This project uses a common set of base classes which are defined here:
https://github.com/JulesStringer/PIC32Device

