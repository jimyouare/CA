RA FS 21 Serie 3 
 
Theorieteil Gesamtpunktzahl: 11 Punkte
1 Performance Berechnungen (3 Punkte)
Nehmen Sie an, eine CPU sei mit 500Mhz getaktet. Nehmen Sie weiter an, dass besagte CPU die folgenden Operationen (mit angegebener Zeitdauer) durchführt:
ALU 4nsec LOAD 8nsec STORE 12nsec Branch 6nsec.
(a) Wir nehmen zu Beginn an, dass alle Operationen gleich häu􏰃g durchgeführt werden.
􏰅 Wieviel schneller/langsamer ist eine Maschine, die für die LOAD Instruktion 6 Taktzyklen braucht?
􏰅 Wieviel schneller ist eine CPU bei der die STORE doppelt so schnell arbeitet?
(b) Die Operationen werden mit folgenen Häu􏰃gkeiten ausgeführt: ALU 50%, LOAD 15%, STO- RE 25%, BRANCH 10%. Berechnen Sie den idealen CPI (ohne zu berücksichtigen, dass der Zugri􏰂 auf den Hauptspeicher Stalls erfordert).
2 Stackverwendung bei Subroutinen (2 Punkte)
Geben Sie zwei mögliche Gründe an, wieso man den Stack bei Assembler-Subroutinen braucht?
3 ALU & SLT (2 Punkte)
􏰅 Was passiert beim slt Befehl in der ALU? 􏰅 Wie unterstützt die ALU den slt Befehl?
4 loadi (2 Punkte)
Geben Sie an, wie das Laden einer (32 Bit langen) Konstanten in ein MIPS-Register mit dem MIPS-Befehlssatz umgesetzt werden kann.

5 ALU: OPCodes (2 Punkte)
Beschreiben Sie, wie die Ansteuerbits der ALU für die folgenden Befehle gesetzt werden müssen: and or add subtract slt nor
Erläutern Sie weiter den Zusammenhang zwischen diesen Bits/Befehlen und den einzelnen Elementen der ALU.
2

Programmierteil
Ihre Aufgabe ist es, das gegebene Programmgerüst wie folgt zu vervollständigen:
(a) Laden Sie die zur Serie 3 gehörigen Dateien von Ilias herunter und studieren diese aufmerk- sam. Versuchen Sie zu verstehen, was die bereits vorhandenen Teile bedeuten.1
(b) Tragen Sie Ihren Namen sowie den Namen einer allfälligen Übungspartnerin oder eines all- fälligen Übungspartners an den vorgesehenen Stelle in den Dateien compile.c mips.c und memory.c ein.
(c) Vervollständigen Sie die Funktion main in compile.c, so dass auf der Kommandozeile der zu kompilierende Ausdruck und der Dateiname für die Datei, in der das kompilierte Programm gespeichert wird, als Parameter übergeben werden können. Bei falscher Eingabe soll ein Hinweis zur Benutzung, wie z.B.
         usage: <Befehlsname> expression filename
ausgegeben werden (wobei anstelle von <Befehlsname> der tatsächliche Programmname steht, auch wenn das Programm umbenannt wird). Bei korrekter Eingabe, also z.B.
         ./compile '(3*(45+6))+12' test.mips
soll
ausgegeben werden. Hinweis:
􏰅 Die Hauptarbeit übernimmt die bereits implementierte Funktion void compiler(char* exp, char *filename) (in compiler.c). Sie müssen nur sicherstellen, dass main mit der richtigen Anzahl Argumente aufgerufen und diese korrekt an compiler weitergege- ben werden
􏰅 http://publications.gbdirect.co.uk/c_book/chapter10/arguments_to_main.html
(d) Vervollständigen Sie die Funktion loadFile(char*) in memory.c, so dass eine erzeugte MIPS-Binär-Datei in den Speicher gelesen und ausgeführt werden kann.
Sie können davon ausgehen, dass die MIPS-Binär-Datei genau dem erwarteten Abbild im Speicher entspricht, d.h. die einzelnen Wörter sind in Big Endian Bytereihenfolge ohne Un- terbruch in der Datei abgelegt.
Hinweis:
􏰅 Betrachten Sie void store(word w) in compiler.c
􏰅 Erzeugen Sie (z.B. mittels ./compile 1+1 test.mips) einige Dateien und betrachten Sie diese mit einem Hex-Editor, um das Dateiformat besser zu verstehen.
􏰅 http://publications.gbdirect.co.uk/c_book/chapter9/input_and_output.htmlund folgende Abschnitte
(e) Vervollständigen Sie die Funktion error in mips.c, so dass die Fehlermeldungen korrekt formatiert ausgegeben werden können. Betrachten Sie dazu auch das Makro ERROR in mips.h. Die Fehlermeldung soll jeweils angeben in welcher Funktion, auf welcher Linie in welcher Datei der Fehler ausgetreten ist sowie eine detaillierte Fehlermeldung ausgeben. Ein Aufruf
Input: (3*(45+6))+12 Postfix: 3456+*12+
MIPS binary saved to test.mips
ERROR(􏰀Unknown opcode: %x􏰄, instruction->i.opcode);
in mips.c, Funktion undefinedOperation auf Zeile 166 soll z.B. folgende Ausgabe ergeben
       undefinedOperation in mips.c, line 166: Unknown opcode 2b
 1
compiler.c und compiler.h müssen nicht ausführlich studiert werden, wichtige Stellen werden unten erwähnt, bei Interesse für die restlichen Teile 􏰃ndet sich jedoch ein wenig Theorie im Anhang.
3

(angenommen, instruction->i.opcode == 0x2b).
Nach der Ausgabe des Fehlers soll das Programm mittels exit(EXIT_FAILURE) beendet werden.
Hinweis:
􏰅 http://linux.die.net/man/3/vfprintf 􏰅 http://linux.die.net/man/3/va_start
(f) Stellen Sie sicher, dass Ihre Implementation ohne Fehler und Warnungen kompilierbar ist, überprüfen Sie dies mit make
Dies ist eine notwendige Voraussetzung, damit der Programmierteil als erfüllt gilt.
(g) Stellen Sie sicher, dass Ihre Implementation die gegebenen und Ihre eigenen Tests ohne Fehler und Warnungen absolviert, überprüfen Sie dies mit make test
Dies ist eine notwendige Voraussetzung, damit der Programmierteil als erfüllt gilt.
(h) Erstellen Sie aus Ihrer Lösung eine Zip-Datei namens <nachname>.zip (wobei <nachname> natürlich durch Ihren Nachnamen zu ersetzen ist).
(i) Geben Sie die Datei elektronisch durch Hochladen in Ilias ab.
4

A Theorie
In compiler.c und compiler.h 􏰃nden Sie die Implementation eines einfachen Compilers für arith- metische Ausdrücke. Unsere 􏰁Programmiersprache􏰀 ist in der folgenden erweiterten Backus-Naur- Form (EBNF) gegeben:
digit
number
factor
term
expression = term, { ( "+" | "-" ), term };
= "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9" ;
= digit, {digit};
= number | "(", expression, ")";
= factor, { ( "*" | "/" ), factor };
Ein mögliches 􏰁Programm􏰀 wäre also z.B: (3*(45+6))+12
Diese Eingabe wird von einem lexikalischen Scanner (auch Lexer genannt) zuerst in einzelne Bestandteile (in diesem Fall Symbole und Zahlen), sogenannte Tokens, aufgeteilt. Diese werden mit Zusatzinformationen versehen und als Liste abgespeichert, d.h. der oben stehende Ausdruck wird beispielsweise zu
number lparen number plus
3 '(' 45 '+' ...
GG ◦ GG ◦ GG ◦   GG ◦   GG
Sie 􏰃nden in der compiler.c einen einfachen Compiler, der die eingegebenen Ausdrücke in
Post􏰃x-Notation umwandelt, d.h. der oben stehende Ausdruck wird zu 3 45 6 + * 12 +
Ausdrücke in Post􏰃xnotation lassen sich einfach mit einer Stackmachine abarbeiten. Hierzu wird jedes Argument auf einen Stack gelegt und Operationen werden auf den obersten Stackelementen angewendet. Hierzu werden die Stackelemente in Register des Prozessors geladen, die Operation angewendet und schliesslich das Resultat wieder zurück auf den Stack gelegt.
Ausdrücke in Post􏰃xnotation lassen sich also einfach in Assemblercode umwandeln, das oben stehende Programmstück wird z.B. (in Pseudo-Assembler) zu
     symcode
 lexeme
 next*
lparen '(' ◦
push 3
push 45
push 6
pop A
pop B
add A,A,B push A
pop A
pop B
mult A,A,B push A
push 12
pop A
pop B
add A,A,B push A
stop
// Lege  3 auf den Stack
// Lege 45 auf den Stack
// Lege  6 auf den Stack
// Hole obersten Wert auf Stack nach Register A
// Hole obersten Wert auf Stack nach Register B
// Addiere die Register A und B, speichere das Resultat in A
// Lege den Wert von Register A auf den Stack
// Hole obersten Wert auf Stack nach Register A
// Hole obersten Wert auf Stack nach Register B
// Multipliziere Register A und B, speichere das Resultat in A
// Lege den Wert von Register A auf den Stack
// Lege 12 auf den Stack
// Hole obersten Wert auf Stack nach Register A
// Hole obersten Wert auf Stack nach Register B
// Addiere die Register A und B, speichere das Resultat in A
// Lege den Wert von Register A auf den Stack
// Beende das Programm
Das Endresultat der Berechnung wird dabei wieder im Stack abgelegt.
5
