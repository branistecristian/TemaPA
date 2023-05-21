README

Descriere

Acesta este un cod sursă în limbajul C, care îndeplinește mai multe cerințe legate de gestionarea și procesarea datelor despre echipe și jucători într-un turneu. Codul conține funcții și structuri de date pentru stivă, coadă, arbore binar de căutare (BST) și arbore AVL.
Fișierele incluse

    stiva.h: Fișierul de antet pentru implementarea unei stive.
    coada.h: Fișierul de antet pentru implementarea unei cozi.
    BST.h: Fișierul de antet pentru implementarea unui arbore binar de căutare.
    AVL.h: Fișierul de antet pentru implementarea unui arbore AVL.
    string.h: Fișierul de antet pentru funcții de manipulare a șirurilor de caractere.

Funcționalități:

Cerința 1
Citirea datelor despre echipe și jucători dintr-un fișier și stocarea acestora într-o listă.

Cerința 2
Eliminarea echipei cu cel mai mic punctaj din listă și afișarea listei rezultate.

Cerința 3
Simularea rundelor de meciuri între echipe și afișarea rezultatelor. Echipele sunt organizate într-o coadă, iar câștigătorii fiecărui meci sunt stocați într-o stivă.

Cerința 4
Construirea unui arbore binar de căutare (BST) pe baza celor mai bune 8 echipe. Afișarea echipelor în ordine crescătoare, bazată pe punctaj.

Cerința 5
Construirea unui arbore AVL pe baza echipele din cerința anterioară și afișarea echipelor de pe nivelul 2 al arborelui AVL.

Utilizare

    Compilați codul sursă utilizând un compilator C compatibil.
    Rulați programul, oferind trei argumente în linia de comandă:
        Primul argument reprezintă calea către fișierul de intrare care conține cerințele (ex. "input.txt").
        Al doilea argument reprezintă calea către fișierul de intrare care conține datele despre echipe și jucători (ex. "data.txt").
        Al treilea argument reprezintă calea către fișierul de ieșire în care se vor afișa rezultatele (ex. "output.txt").
    Verificați fișierul de ieșire pentru a vedea rezultatele obținute în urma executării programului.

Observații

    Asigurați-vă că fișierele de intrare există și au formatul corect înainte de a rula programul.
    Asigurați-vă că aveți permisiuni de scriere pentru fișierul executabil.