
Die fünfte Serie ist bis Dienstag, den 17. Mai 2022 um 15:00 Uhr zu lösen und auf ILIAS
hochzuladen. Für Fragen steht im ILIAS jederzeit ein Forum zur Verfügung. Allfällige
unlösbare Probleme sind uns so früh wie möglich mitzuteilen, wir werden gerne helfen.
 
Theorieteil
Gesamtpunktzahl: 11 Punkte
1 Statische Sprungvorhersage (3 Punkte)
Welche Probleme treten bei folgendem Assembler-Loop auf, wenn standardmässig Predict Not
Taken gewählt wird.
1 addi $s1, $zero, 1024 // s1 := 1024
2 loop: addi $s1, $s1, -1 // s1--
3 jal subroutine // call subroutine()
4 bne $s1, $zero, loop // if (s1 != 0) jump loop
Optimieren Sie das Codebeispiel auf Predict not Taken.
2 Antidependencies (1 Punkt)
Erklären Sie was eine Antidependency ist.
3 Branch Delay Slots (1 Punkt)
Erklären Sie was ein Branch-Delay-Slot ist.
4 Dynamische Sprungvorhersage (3 Punkte)
Gegeben Sei das folgende C Programm.
1 int t = 0;
2 for( int i = 0; i < 8; i++ )
3 {
4 for( int j = 0; j < 8; j++ )
5 {
6 t = t + i*j;
7 }
8 }
Nehmen Sie an, der Prozessor braucht Dynamic Branch Prediction und Taken wird per Default
gewählt.
• Wie viele falsche Vorhersagen werden gemacht, wenn ein 1-bit Counter zum Einsatz kommt?
Erläutern Sie ihre Berechnung.
• Wie viele falsche Vorhersagen werden gemacht, wenn ein 2-bit Counter zum Einsatz kommt?
Erläutern Sie ihre Berechnung.
Bestimmen Sie in beiden Fällen die Eintrage der Sprungvorhersagetabelle (branch history table,
BHT) in Zeile 6 wenn i = 6 und j = 3.
5 Multiple-Issue Prozessoren (3 Punkte)
Bestimmen Sie, ob die folgenden Sätze wahr oder falsch sind. Bitte erläutern Sie kurz ihre Antwort.
• Pipelining benutzt Instruction-Level-Parallelism, doch es ermöglicht dem Prozessor nicht,
mehr als eine Instruktion pro Zeitpunkt auszuführen.
• Multiple-issue Prozessoren können mehr als eine Instruktion pro Clock-Cycle ausführen.
• SIMD (single-instruction multiple-data) Prozessoren sind statische Multiple-Issue Prozessoren.
2
Programmierteil
Die Programmieraufgaben können in Zweiergruppen gelöst werden. Sie und Ihre Gruppenmitglieder arbeiten gemeinsam am Code oder teilen sich Unteraufgaben auf. Um sicherzustellen, dass
jede Programmiererin und jeder Programmierer den gesamten Code versteht und erklären kann,
verlangen wir von jedem Mitglied eine leicht unterschiedliche Abgabe. Wie unten beschrieben underscheiden sich die Versionen nur um eine spezielle Funktionalität für die die einzelne Teilnehmerin
oder der einzelne Teilnehmer selbst verantwortlich ist.
Vorbereitung
(a) Laden Sie das Codeskelett von ILIAS herunter. Anweisungen zum Gebrauch des MARS MIPS
Simulators finden Sie in der Serie 4 in ILIAS.
(b) Diese Übung ist eine Fortsetzung des Programmierteils aus Serie 4 und setzt eine funktionstüchtige Implementation der Countdown-Uhr voraus. Falls Sie die Aufgabe nicht vollständig
lösen konnten, melden Sie sich bitte bei den Assistenten (siehe Folien der ersten Woche) damit sie Ihnen bei der Fertigstellung helfen können. Wir stellen keine Lösungen zur Verfügung
und es ist Ihnen nicht erlaubt von ihren Mitstudenten zu kopieren.
Erweiterung der Countdown-Uhr
In dieser Übung erweitern wir die Countdown-Uhr mit neuen Funktionen:
• Der Startwert des Countdowns kann mit den Zahlentasten eingestellt werden. Zur Vereinfachung können Sie den Countdown auch auf eine Ziffer reduzieren. Die Unterstützung für
beide Ziffern ist nicht obligatorisch.
• Der Countdown kann mit einer der Tasten ‘a’ bis ‘f’ gestartet werden.
• Während der Laufzeit kann die Countdown-Uhr auch mit einer der Tasten ‘a’ bis ‘f’ zurückgestellt werden.
Abbildung 1: Die Countdown-Uhr kann mit dem Tastenblock (rechts) eingestellt und gestartet
werden. In diesem Tool verhalten sich die Tasten wie Schalter. Einmal klicken drückt die Taste
herunter. Ein weiterer Klick löst die Taste wieder.
Keyboard Interrupts
Es gibt grundsätzlich zwei Möglichkeiten wie wir Tasteneingabe in unserem Programm realisiern
können.
• Polling: In dieser Methode Überprüfen wir im Hauptprogramm periodisch den Status der
E/A Geräte. Obwohl die Implementation einfach ist hat es den Nachteil, dass die Polling
3
Operation die Ausführung unseres Hauptprogramms blockiert. Ausserdem können E/A Änderungen zwischen den Polling Operationen nicht erkannt werden. Diese Methode ist für
unsere Zwecke daher nicht geeignet.
• Interrupt: Hier ist der Block an Instruktionen, der bei einem Tastendruck ausgeführt werden soll, getrennt vom Hauptprogramm. Ein “Interrupt” kann zu jeder Zeit auftreten und den
Programmfluss unterbrechen (daher der name Interrupt). Nachdem der Interrupt verarbeitet wurde wird die Ausführung im Hauptprogramm vortgesetzt (PC wird wiederhergestellt,
ähnlich wie wenn wir aus einer Subroutine zurückkehren).
Das Thema Interrupts und E/A wurde in der Vorlesung noch nicht behandelt und wird auch
nur obeflächlich erwähnt. Das Konzept ist einfach zu verstehen, jedoch gibt es bei der Implementation oft grosse Herausforderungen und Tücken die einem in den Weg kommen können.
Glücklicherweise müssen wir uns aber dank dem MIPS Simulator nicht damit herumschlagen.
Zum Beispiel können wir annehmen, dass nur ein Interrupt auf einmal stattfindet und dass
nur ein E/A Gerät aktiv ist (in unserem Fall der Tastenblock).
Wir empfehlen Ihnen das Kapitel 6.6, “Interfacing I/O Devices to the Processor, Memory,
and Operating System” im Buch “Computer Architecture and Design”, 4-th edition1
, Patterson
and Hennessy zu lesen. Wir stellen auch ein einfaches Demoprogramm zur Verfügung, das die
Implementation eines Tastendrucks mit dem Digital Lab Sim in MARS demonstriert.
Tasks
(a) Studieren Sie das Demoprogramm zu Interrupts. Es beinhaltet mehrere nützliche Kommentare die den Interrupt Machanismus erklären. Sie können den Code für die folgenden Aufgaben
wiederverwenden und anpassen. Die Hilfetaste im “Digital Lab Sim” Tool hat weitere Infos.
(b) Ergänzen Sie den Kopf des Quellcodes mit ihren Namen. Erklären Sie auch, welche Tasten
Sie für die verschiedenen Funktionen einsetzen.
(c) Implementieren Sie einen Interrupt, der die Countdown-Uhr startet. Dies sollte auf dem Code
den Sie in Serie 4 gelöst haben aufbauen. Sie sollten diese Aufgabe vollständig lösen, bevor
Sie zur nächsten Teilaufgabe gehen.
Individualisierte Versionen: Die Wahl der Taste hängt von Ihrer Matrikelnummer ab.
Wenn diese mit einer Ziffer 0 oder 1 endet, wählen Sie ‘a’, wenn sie mit einer Ziffer 2 oder
3 endet, wählen Sie ‘b’ und so weiter bis Taste ‘e’ welche Sie wählen müssen wenn die
Matrikelnummer mit der Ziffer 8 oder 9 endet.
(d) Erweitern Sie die Countdown-Uhr so, dass diese während der Laufzeit zurückgestellt werden
kann. Sie können zu diesem Zweck die gleiche Taste wie in Aufgabe (c) verwenden oder
auch eine andere wählen. Sie sollten diese Aufgabe vollständig lösen, bevor Sie zur nächsten
Teilaufgabe gehen.
(e) Ermöglichen Sie es, den Anfangswert mit dem Ziffernblock (Tasten ‘0’ bis ‘9’) einzugeben.
Zur Vereinfachung können Sie den Countdown auf eine Ziffer reduzieren, müssen aber nicht.
Diese Teilaufgabe wird als gelöst gezählt, wenn es möglich ist zwischen mindestens zwei
Startwerten zu wählen. 
