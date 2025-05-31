@echo off
echo Generating project files with Premake...

:: Choose your generator (vs2022, vs2019, gmake2, etc.)
set GENERATOR=vs2022

:: Run premake5 from the premake directory
premake\premake5.exe %GENERATOR%

echo Done!
pause
