# Este necesar să știm atâtea metode de a sorta un tablou?
Deși toate implementările de funcții și de variabile în testarea algoritmilor au fost făcute în limbajul C, pentru măsurarea eficienței fiecărui algoritm s-au folosit elemente din librăria „chrono” și librăria standard „iostream” din limbajul C++, deoarece instrumentele de măsurare a timpului în limbajul C nu sunt destul de precise (precizie de 0.001 secunde) ceea ce rezultă deseori la testarea algoritmilor într-un timp de 0.000... secunde. Deci, practic, algoritmii au fost testați în limbajul C++.\
## Conținut
Acest repository va conține următoarele fișiere:\
-Un fișier sursă, „Metode de sortare01.cpp”, care contine programul principal în care se va extrage datele de intrare din fișierul „Intrare01.txt”, executa codul și scrie datele rezultante in fișierul „Iesire01.txt”;\
-Un fisier de intrare, „Intrare01.txt”, care este folosit de fișierul sursă pentru a-și extrage datele pentru fisierul „Metode de sortare01.cpp”. Acesta va contine pe prima linie cîte numere se vor sorta, iar pe a doua linie toate numerele ce trebuiesc sortate;\
-Un fisier de ieșire, ”Iesire01.txt”, care va conține tabloul din fișierul „Intrare01.txt” ,sortat printr-o metoda de sortare aleasă;\
-Un fisier de intrare, „Intrare02.txt”, care este folosit de fișierul sursă pentru a-și extrage datele pentru fisierul „Metode de sortare02.cpp”. Acesta va contine pe prima linie numarul de seturi de numerele care trebuie sortate (n) și numarul de numere din fiecare set (m), iar pe urmatoarele linii toate „n” linii de „m” numere ce trebuiesc sortate;\
-Un fișier sursă, „Metode de sortare02.cpp”, care contine programul principal în care se va extrage datele de intrare din fișierul „Intrare02.txt”, executa codul și scrie datele rezultante in fișierul „Iesire02.txt”;\
-Un fisier de ieșire, ”Iesire02.txt”, care va conține tablourile din fișierul „Intrare01.txt” ,sortate printr-o metoda de sortare aleasă;
-Un header file, „sortalg.h”, care conține funțiile și implementările algoritmilor;\
-Un fisier Excel, „Comparație.exl”, care conține date despre timpul de execuție al algoritmilor (pe baza tipurilor de date introduse) și o comparație dinte algoritmi bazata pe timpii de execuție;\
-Două fișiere, „Date totale01.txt” și „Date totale02.txt”, care contin TOATE datele de intrare care vor fi folosite în testare (separate linie cu linie, respectiv separate printr-un rând gol);\
IMPORTANT: Toate datele de intrare pentru testarea acestor algoritmi (valorile tablourilor) au fost generate cu inteligenta artificiala (ChatGPT 5.3), pentru a scurta timpul introducerii acestor date.\
