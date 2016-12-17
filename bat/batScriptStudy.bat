
echo off
@echo (1) Comment
::This is a comment without display.
rem This is a comment printed on the screen.

@echo (2) Title of the top window
title batScriptStudy

@echo (3) Color setting 
::the first num is the backgroud color, and the second is the txt color.
::color 05

@echo (4) Delayedexpansios
::disable delayedexpansios
set var1=abc
set var2=123
echo var1=%var1% var2=%var2%
set var1=%var2% &set var2=%var1%
echo var1=%var1% var2=%var2%
::enable delayedexpansios
setlocal enabledelayedexpansion
set var3=abc
set var4=123
echo var3=%var3% var4=%var4%
set var3=%var4% &set var4=!var3!
echo var3=%var3% var4=%var4%

@echo (5) Cmd flag.
 call ::errorcode

@echo (6) Operaors
dir c:\  & dir d:\test.file  & dir e:\
rem end of operator &, cmd will work in scqence.
dir c:\ && dir d:\test.file && dir e:\
rem end of operator &&, when one failed, cmd will not work after that.
dir c:\ || dir d:\test.file || dir e:\
rem end of operator ^||, once one cmd work, all others behind that will never work.

@echo (7) Ech0 with input.
@echo. Y|copy  src.txt des.txt

@echo (8) Pause.
::Style 1.
pause
::Style 2.
@echo Pause after your cmd.

@echo (9) Cmd start
start copytest.exe src.txt des.txt

@echo (10) Cmd pushed and popd.
::Create folder temp, current path is bat.
md temp
::Create test.txt in temp, current path is bat.
@echo hello world! >temp\test.txt
::Then path is temp.
cd temp
::Save the path of temp, and go to bat use cmd pushd.
pushd ..
::Go to path of saved temp.
popd
::Out to bat and del temp.
pause
del *.* /q
cd ..
if exist temp rd temp

@echo (11) Folder created and del.
if not exist code md code
cd code
md include,source,common
dir
if not exist include md include
if not exist source md source
if not exist common md common
rd common
rd include
rd source
cd ..
rd code

@echo (12) Control flow of for.
echo ;hello world! >temp.txt
::there is a space between num and >>.
echo 1a 2a  3a 8a 4a 5a >>temp.txt
echo 3b 4b  7b 6b 6b 6b >>temp.txt
echo 7c 8c 15c 9c 9c 8c >>temp.txt
for /F "eol=;tokens=1,2,3 delims=+= " %%i in (temp.txt) do echo %%i %%j %%k
del temp.txt


@echo (13) Variables.
set  windir=%windir%   
echo windir=%windir%
set  ComSpec=%ComSpec%          
echo ComSpec=%ComSpec%
set  FP_NO_HOST_CHECK=%FP_NO_HOST_CHECK%
echo FP_NO_HOST_CHECK=%FP_NO_HOST_CHECK%
set  Path=%Path%    
echo Path=%Path%
set  OS=%OS% 			  
echo OS=%OS%
set  allusersprofile=%allusersprofile% 			  
echo allusersprofile=%allusersprofile%
set  Mytest=%THISISATEST% 			  
echo Mytest=%Mytest%
set time=%TIME%
echo It is %time% now.
pause

::This  is a cmd flag.
:errorcode
@echo This is an exercise! 
set errocodes=%errorlevel%
@echo errocodes = %errocodes%
goto :eof
