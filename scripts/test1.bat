@echo off
setlocal enabledelayedexpansion
call config.bat

:: BADANIE 1 - Wpływ rozmiaru danych
for %%a in (%algorithms%) do (
    if not "%%a"=="3" if not "%%a"=="4" if not "%%a"=="5" (
        for %%s in (%sizes%) do (
             for /L %%i in (1,1,%REPEATS%) do (
                "%PROGRAM%" --test %%a %default_type% %default_distribution% %%s %OUTPUT%\test1\wyniki_rozmiar_alg_%%a.csv
             )
        )
    )
)

:: Testowanie wariantów QuickSort
for %%p in (%quick_pivots%) do (
    for %%s in (%sizes%) do (
         for /L %%i in (1,1,%REPEATS%) do (
           "%PROGRAM%" --test 3 %default_type% %default_distribution% %%s %OUTPUT%\test1\wyniki_pivot_rozmiar_%%p.csv -p %%p
         )
    )
)

:: Testowanie wariantów QuickSort pod kątem dystrybucji danych
for %%p in (%quick_pivots%) do (
    for %%d in (%distributions%) do (
         for /L %%i in (1,1,%REPEATS%) do (
           "%PROGRAM%" --test 3 %default_type% %%d %size_for_pivot_testing% %OUTPUT%\test1_3\wyniki_quick_pivot_dystrybucja_%%p.csv -p %%p
         )
    )
)

:: Testowanie wariantów ShellSort
for %%g in (%shell_gaps%) do (
    for %%s in (%sizes%) do (
         for /L %%i in (1,1,%REPEATS%) do (
            "%PROGRAM%" --test 4 %default_type% %default_distribution% %%s %OUTPUT%\test1\wyniki_shell_gap_%%g.csv -g %%g
         )
    )
)

:: Badanie wplywu pijanstwa
for %%d in (%drunkenness%) do (
     for /L %%i in (1,1,%REPEATS%) do (
        "%PROGRAM%" --test 5 %default_type% %default_distribution% %default_size% %OUTPUT%\test1_2\wyniki_pijanstwa.csv -d %%d
     )
)

echo Badania zakończone.
pause
