@echo off

:: DO USTAWIENIA W TRAKCIE TESTOW
set best_pivot=3
set best_gap=1

:: Ścieżka do programu
set "PROGRAM=..\cmake-build-debug\sorting_algorithms.exe"

:: Folder wynikowy
set "OUTPUT=..\benchmarks_results"

:: Liczba powtórzeń testu
set REPEATS=100

:: Rozmiary danych
set sizes=10000 20000 30000 40000 50000

:: Warianty ShellSort (0=Shell, 1=Knuth)
set shell_gaps=0 1

:: Warianty QuickSort (0=first, 1=last, 2=random, 3=median)
set quick_pivots=0 1 2 3

:: Algorytmy sortowania (0=bubble, 1=insertion, 2=heap, 3=quick, 4=shell, 5=drunk)
set algorithms=1 2 3 4 5

:: Poziomy pijanstwa dla pijanego wariantu
set drunkenness=10 25 50 75 100

:: Rozkłady danych (0=losowy, 1=rosnący, 2=malejący, 3=33%, 4=66%)
set distributions=0 1 2 3 4

:: Typy danych (0=int, 1=float, 2=string, 3=boardgame)
set types=0 1 2 3


set default_algorithm=3

set default_type=0

set default_distribution=0

set default_size=50000

set size_for_pivot_testing=10000