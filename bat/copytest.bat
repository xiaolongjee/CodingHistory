
::Copy file-a to file-b.
@echo off 
title CopyTest

@echo Use your application with arguments of main(int argc, char** agrv) ... &pause>nul
copytest.exe src.txt des.txt

@echo Use script of .bat ... &pause>nul
COPY /Y /N des.txt ..\desCopy.txt

rem Check src.txt and desCopy.txt manualy to confirm your application!
@echo &pause>nul
 



