== Beweis ==

Ein formaler Beweis des De-morganschen Gesetzes ¬(a ∧ b) ⇔ ¬a ∨ ¬b im [[Fitch-Kalkül]] könnte etwa wie folgt aussehen:

{|class="wikitable"
|
{|class="hintergrundfarbe1" style="border:none; text-align:left; margin-left:2em"
|style="width:20em"|1 ¬(a ∧ b)||[Prämisse]
|-
|2 ¬(¬a ∨ ¬b)||[Annahme des Gegenteils des Ziels; beginnt einen Unterbeweis]
|-
|3 ¬a||[Unterannahme, beginnt einen Unter-Unterbeweis]
|-
|4 ¬a ∨ ¬b||[Disjunktionseinführung aus Zeile 3]
|-
|5 ⊥||[Widerspruch zwischen Zeilen 2 und 4]
|-
|6 a||[Negationseinführung aus Zeilen 3–5, beendet den ersten Unter-Unterbeweis]
|-
|7 ¬b||[Unterannahme, beginnt einen zweiten Unter-Unterbeweis]
|-
|8 ¬a ∨ ¬b||[Disjunktionseinführung aus Zeile 7]
|-
|9 ⊥||[Widerspruch zwischen Zeilen 2 und 8]
|-
|10 b||[Negationseinführung aus Zeilen 7–9, beendet den zweiten Unter-Unterbeweis]
|-
|11 a ∧ b||[Konjunktionseinführung aus Zeilen 6 und 10]
|-
|12 ⊥||[Widerspruch zwischen Zeilen 1 und 11]
|-
|13 ¬¬(a ∨ ¬b)||[Negationseinführung aus Zeilen 2–12, beendet den Unterbeweis]
|-
|14 ¬a ∨ ¬b||[Negationsbeseitigung aus Zeile 13; Beweis abgeschlossen]
|}
|}

Damit ist bewiesen, dass ¬(a ∧ b) → ¬a ∨ ¬b. Für den vollständigen Beweis des Gesetzes muss auch die Implikation in umgekehrter Richtung bewiesen werden:

{|class="wikitable"
|
{|class="hintergrundfarbe1" style="border:none; text-align:left; margin-left:2em"
|style="width:20em"|1 ¬a ∨ ¬b||[Prämisse]
|-
|2 a ∧ b||[Annahme des Gegenteils des Ziels; beginnt einen Unterbeweis]
|-
|3 ¬a||[Unterannahme; beginnt einen Unter-Unterbeweis]
|-
|4 a||[Konjunktionsbeseitigung aus Zeile 2]
|-
|5 ⊥||[Widerspruch zwischen Zeilen 3 und 4, beendet den ersten Unter-Unterbeweis]
|-
|6 ¬b||[Unterannahme, beginnt einen zweiten Unter-Unterbeweis]
|-
|7 b||[Konjunktionsbeseitigung aus Zeile 2]
|-
|8 ⊥||[Widerspruch zwischen Zeilen 6 und 7, beendet den zweiten Unter-Unterbeweis]
|-
|9 ⊥||[Disjunktionsbeseitigung aus Zeilen 1, 3–5 und 6–8, beendet den Unterbeweis]
|-
|10 ¬(a ∧ b)||[Negationseinführung aus Zeilen 2–9, _Beweis abgeschlossen]
|}
|}

Somit ist auch ¬a ∨ ¬b → ¬(a ∧ b) bewiesen. Da die Implikation nun in beiden Richtungen gezeigt ist, ist damit auch die logische Äquivalenz ¬(a ∧ b) ⇔ ¬a ∨ ¬b bewiesen. Mit ähnlichen Mitteln lässt sich auch das andere De-morgansche Gesetz, ¬(a ∨ b) ⇔ ¬a ∧ ¬b, zeigen.

Wahlweise kann der Beweis aber auch auf anderen Wegen, etwa mit [[Wahrheitstabelle]]n, geführt werden.
