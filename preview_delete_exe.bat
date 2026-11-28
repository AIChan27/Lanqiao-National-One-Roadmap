@echo off
setlocal enabledelayedexpansion
title EXE Files Cleaner
color 0A

:menu
cls
echo ==================================================
echo               EXE Files Cleaner
echo ==================================================
echo Target Folder: %CD%
echo.
echo   [1] Show list of all .exe files (Preview only)
echo   [2] Delete ALL .exe files in this folder ^& subfolders
echo   [0] Exit
echo ==================================================
set /p "CHOICE=Please enter your choice (0-2): "

if "%CHOICE%"=="1" goto show_exe
if "%CHOICE%"=="2" goto delete_exe
if "%CHOICE%"=="0" exit /b
goto menu

:show_exe
cls
echo [Preview] Listing all .exe files in this folder and subfolders:
echo.
set "FOUND=0"
for /r %%F in (*.exe) do (
    echo "%%F"
    set "FOUND=1"
)

if "!FOUND!"=="0" (
    echo No .exe files found.
) else (
    echo.
    echo Total .exe files found. (See list above)
)
echo.
pause
goto menu

:delete_exe
cls
echo [Warning] This will PERMANENTLY delete ALL .exe files!
echo Target: %CD% and all subfolders.
echo.
set /p "CONFIRM=Type Y to continue, or N to cancel: "
if /i not "%CONFIRM%"=="Y" (
    echo Cancelled.
    pause
    goto menu
)

echo.
echo Deleting .exe files...
del /f /s /q "*.exe"
echo.
echo Delete complete.
pause
goto menu