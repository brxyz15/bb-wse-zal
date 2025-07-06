# Praca na zaliczenie z przedmiotu "Narzędzia procesu tworzenia oprogramowania"

## Opis aplikacji
Program stworzony używając tylko języka ANSI C, powstał w ramach powtórzenia materiału na egzamin z innego przedmiotu ("Algorytmy i struktury danych").

Aplikacja zawiera 5 opcji, użytkownik będzie poproszony o wybór jednej z nich:
1. Sortowanie bąbelkowe
2. Sortowanie przez wybieranie
3. Wyszukiwanie liniowe
4. Wyszukiwanie binarne
5. Sortowanie przez scalanie

W przypadku opcji 3. oraz 4. użytkownik zostanie zapytany również o liczbę, którą życzy sobie wyszukać w tablicy generowanej przez program.

## Zawartość repozytorium
* README.md - dokumentacja programu, która jest właśnie wyświetlana
* main.c - kod źródłowy programu w języku C
* main - plik skompilowany do uruchomienia w powłoce Linuxa
* main.exe - plik wykonywalny do uruchomienia w systemie Windows

## Instalacja
Nie są wymagane żadne działania. Repozytorium zawiera skompilowane pliki wykonywalne dla systemów Linux oraz Windows. Skompilowano za pomocą kompilatorów GCC (z użyciem programu make), oraz MinGW. Wersja dla Linuxa została skompilowana na systemie Debian Stable, nie została testowana na innych dystrybucjach. Wersja w pliku .exe była testowana za pomocą oprogramowania Wine. Do uruchomienia programu wystarczy uruchomienie pliku wykonywalnego .exe, bądź wykonanie programu za pomocą powłoki systemu Linux.

## Kompilacja
Program używa tylko standardowych bibliotek języka C, więc do utworzenia programu wystarczy dowolny kompilator C.

###### Repozytorium oraz program - Bartłomiej Brzozowski

