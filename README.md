# Kompresja RLE (Run-Length Encoding)

## Opis

Projekt ten implementuje technikę kompresji tekstu znaną jako RLE - Run-Length Encoding. Metoda ta polega na zastępowaniu powtarzających się znaków sekwencjami składającymi się z powtórzonej danej litery i liczby pozostałych wystąpień litery pod rząd. Celem projektu jest zaprezentowanie praktycznej implementacji tej techniki kompresji tekstu.


## Instrukcja użytkowania

1. Po uruchomieniu programu, wybierz opcję '1' lub 'Q'.
2. Wprowadź ścieżkę bezwzględną do pliku tekstowego, który chcesz skompresować.
3. Program wyświetli oryginalny tekst, jego długość, skompresowany tekst, długość już skompresowanego tekstu oraz współczynnik kompresji.
4. Wybierz opcję '1', aby zapisać skompresowany tekst w nowym pliku, do którego zostanie dodane "_compressed" na końcu nazwy, lub 'Q', aby zakończyć działanie programu.

## Przykład

Załóżmy, że masz plik tekstowy o nazwie `tekst.txt`, który zawiera następujący tekst:
aaabbbbcccc
Po skompresowaniu wynik będzie następujący:
aa1bb1cc2

***

# RLE (Run-Length Encoding)
## Description
This project implements a text compression technique known as RLE - Run-Length Encoding. This method involves replacing repeated characters with sequences consisting of the repeated letter and the number of consecutive occurrences of that letter. The aim of the project is to demonstrate a practical implementation of this text compression technique.

## User Guide
Upon launching the program, choose option '1' or 'Q'.
Enter the absolute path to the text file you wish to compress.
The program will display the original text, its length, the compressed text, the length of the compressed text, and the compression ratio.
Choose option '1' to save the compressed text in a new file, which will have "_compressed" appended to its name, or 'Q' to exit the program.

## Example
Let's assume you have a text file named text.txt, containing the following text:
aaabbbbcccc
After compression, the result will be:
aa1bb1cc2
