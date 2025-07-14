@echo off
setlocal enabledelayedexpansion
call config.bat

:: BADANIE 3 - Wpływ typu danych
for %%t in (%types%) do (
     for /L %%i in (1,1,%REPEATS%) do (
        "%PROGRAM%" --test %default_algorithm% %%t %default_distribution% %default_size% %OUTPUT%\test3\wyniki_typy.csv -p %best_pivot% -g %best_gap%
     )
)

echo Badania zakończone.
pause
