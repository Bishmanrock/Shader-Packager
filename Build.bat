@echo off
setlocal

REM Compule the program

:: Compile your C++ program with the corrected include path and the variable output filename
g++ -o ShaderPackager.exe CreateShaderFile.cpp

:: Automatically run after compiling
ShaderPackager.exe

:: Pause to keep the console window open
pause