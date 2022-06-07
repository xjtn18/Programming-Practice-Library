@echo off

set name=%1
set lang=%2
set diff=%3

if "%lang%"=="sql" (
	call :SQL_Problem _%diff%\SQL
) else (
	call :Other_Problem _%diff%\%name%
)
timeout /t 1 > nul
exit /b 0


:SQL_Problem
	set dir=%~1
	if NOT exist %dir%\%name%.sql (
		type nul > %dir%\%name%.sql
		echo Created SQL problem at %dir%.
		cd _%diff%\SQL\
	) else (
		echo Error: Problem with this name ^& difficulty already exists.
	)
goto :EOF



:Other_Problem
	set dir=%~1
	if NOT exist %dir% (
		md %dir%
		xcopy templates\%lang%\* %dir% > nul
		echo Created %lang% problem directory at %dir%.
		cd %dir%
	) else (
		echo Error: Problem with this name ^& difficulty already exists.
	)
goto :EOF



