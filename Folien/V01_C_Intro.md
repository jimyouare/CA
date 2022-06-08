<!-- C Die relevanten Kapitel sind im Ilias online verfügbar.
q Auf diverse C Bücher kann ebenfalls zugegriffen werden. -->

# sind Präprozessor Anweisungen
● #include <> veranlasst den Präprozessor,
das angegebene file einzufügen.
● #include <stdio.h> fügt z.B. Informationen
über I/O Bibliothek ein.
● main(...) ist die Funktion die bei
Programmstart aufgerufen wird.
● printf(...) dient zur Ausgabe von einfachen
Strings bis hin zu (sehr) komplexen
Ausdrücken.

# printf()

Eine der mächtigsten Funktionen in C.
● printf(formatstring, args, ...);
● formatstring entweder nur „hello world“ oder Lückentext mit
Platzhaltern (z.B. %d). Platzhalter werden durch args ersetzt.
● Anzahl und Typ der Platzhalter in formatstring muss mit Anzahl der
args übereinstimmen!
● Platzhalter sind z.B: %d, %f, %u, %x, %X
● printf(“X %d, %x, %X, %f %c %c\n“,255,255,255,2.0,'a',98);
---> Ausgabe: X 255, ff,FF,2.0,a,b
● Analog dazu scanf für formatierte Eingabe !
