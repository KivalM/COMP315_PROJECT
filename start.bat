@echo off
set SOURCE_DIR=src
set OUTPUT_DIR=build
set SOURCE_FILES=%SOURCE_DIR%\main.cpp ^
                %SOURCE_DIR%\gui.cpp %SOURCE_DIR%\gui.h ^
                %SOURCE_DIR%\animate.cpp %SOURCE_DIR%\animate.h ^
                %SOURCE_DIR%\character.cpp %SOURCE_DIR%\character.h ^
                %SOURCE_DIR%\dialog.cpp %SOURCE_DIR%\dialog.h 

g++ %SOURCE_FILES% -std=c++17 -mwindows ^
    -Ilibs\webview ^
    -Ilibs\webview2\build\native\include ^
    -ladvapi32 -lole32 -lshell32 -lshlwapi -luser32 -lversion ^
    -o %OUTPUT_DIR%\basic.exe

if %errorlevel% equ 0 (
    %OUTPUT_DIR%\basic.exe
) else (
    echo Compilation failed.
)
