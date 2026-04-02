# Este necesar să știm atâtea metode de a sorta un tablou?
În acest repository se află informații despre o comparație ștințifică din punct de vedere al timpului de executie în secunde(cu o precizie de -10^6).\
## Limbajul folosit
Deși toate implementările de funcții și de variabile în testarea algoritmilor au fost făcute în limbajul C, pentru măsurarea eficienței fiecărui algoritm s-au folosit elemente din librăria „chrono” și librăria standard „iostream” din limbajul C++, deoarece instrumentele de măsurare a timpului în limbajul C nu sunt destul de precise (precizie de 0.001 secunde) ceea ce rezultă deseori la testarea algoritmilor într-un timp de 0.000... secunde. Deci, practic, algoritmii au fost testați în limbajul C++.\
## Conținut
Acest repository va conține următoarele fișiere:\
-Un fișier sursă, „Metode de sortare01.cpp”, care contine programul principal în care se va extrage datele de intrare din fișierul „Intrare01.txt”, executa codul și scrie datele rezultante in fișierul „Iesire01.txt”;\
-Un fisier de intrare, „Intrare01.txt”, care este folosit de fișierul sursă pentru a-și extrage datele pentru fisierul „Metode de sortare01.cpp”. Acesta va contine pe prima linie cîte numere se vor sorta, iar pe a doua linie toate numerele ce trebuiesc sortate;\
-Un fisier de ieșire, ”Iesire01.txt”, care va conține tabloul din fișierul „Intrare01.txt” ,sortat printr-o metoda de sortare aleasă;\
-Un header file, „sortalg.h”, care conține funțiile și implementările algoritmilor;\
-Un fisier Excel, „Comparație.exl”, care conține date despre timpul de execuție al algoritmilor (pe baza tipurilor de date introduse) și o comparație dinte algoritmi bazata pe timpii de execuție;\
-Un fișier, Date de Intrare.zip, care contine toate datele de intrare care au fost folosite în determinarea timpilor de rulare în fișierul excel;\
**IMPORTANT**: Toate datele de intrare pentru testarea acestor algoritmi (valorile tablourilor) au fost generate cu inteligenta artificiala (ChatGPT 5.3), pentru a scurta timpul introducerii acestor date.\
