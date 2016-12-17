
@echo off
title MENU @xiaolongjee
:menu
cls
color 5f
echo.
echo==========================================
echo  Choose the operation, and type Enter
echo==========================================
echo.
echo 1. operation1
echo.
echo 2. operation2
echo.
echo 3. operation3
echo.
echo 4. operation4
echo.
echo.
call :choice
echo.
pause

:choice
set /p choice=  Please choose the num:
if /i "%choice%" EQU "1" goto operation1
if /i "%choice%" EQU "2" goto operation2
if /i "%choice%" EQU "3" goto operation3
if /i "%choice%" EQU "4" goto operation4
echo Invalid choice, please choose again!
echo.
goto choice


:operation1
echo operation1 is running ...
echo Done!
goto :eof

:operation2
echo operation2 is running ...
echo Done!
goto :eof

:operation3
echo operation3 is running ...
echo Done!
goto :eof

:operation4
echo operation4 is running ...
echo Done!
goto :eof






