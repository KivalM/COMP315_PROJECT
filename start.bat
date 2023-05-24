@echo off
set SOURCE_DIR=src
set OUTPUT_DIR=build
set SOURCE_FILES=%SOURCE_DIR%\main.cpp ^
                %SOURCE_DIR%\gui.cpp %SOURCE_DIR%\gui.h ^
                %SOURCE_DIR%\game.cpp %SOURCE_DIR%\game.h ^
                %SOURCE_DIR%\character.cpp %SOURCE_DIR%\character.h ^
                %SOURCE_DIR%\dialog.cpp %SOURCE_DIR%\dialog.h ^
                %SOURCE_DIR%\stage_1.h %SOURCE_DIR%\stage_0.h ^
                %SOURCE_DIR%\quiz.h  %SOURCE_DIR%\quiz.cpp

g++ -O3 -s -static-libgcc -static-libstdc++ ^
    %SOURCE_FILES% -std=c++17 -mwindows ^
    -Ilibs\webview ^
    -Ilibs\webview2\build\native\include ^
    -ladvapi32 -lole32 -lshell32 -lshlwapi -luser32 -lversion ^
    -o %OUTPUT_DIR%\wrath.exe

if %errorlevel% equ 0 (
    %OUTPUT_DIR%\wrath.exe
) else (
    echo Compilation failed.
)
