@echo off
setlocal enabledelayedexpansion
call config.bat

:: Przed testem ustawić parametry na podstawie testu 1!
:: BADANIE 2 - Wpływ rozkładu danych
for %%a in (%algorithms%) do (
    for %%d in (%distributions%) do (
         for /L %%i in (1,1,%REPEATS%) do (
            "%PROGRAM%" --test %%a %default_type% %%d %default_size% %OUTPUT%\test2\wyniki_rozklad_alg_%%a.csv -p %best_pivot% -g %best_gap% -d 50
         )
    )
)

echo Badania zakończone.
pause
