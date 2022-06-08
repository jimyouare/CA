Kleine Konstanten werden beim programmieren oft benutzt . 
  
  - Mögliche Ansätze Lege typische Konstanten in den Speicher und Lade diese 
  
  - Nutze fest verdrahtete Register (wie $zero ) für Konstantne wie 1 
  
  - Nutze spezielli Befehle die Konstanten enthalten! 
  
  addi $app 
  
  Erst ein neuer "load upper immediate" Befehl 
  
  lui $t0, 1010101010101010 
  
  Dann "or immediate" (logical OR) 
    ori $t0, $Rt0, 1010101010101010 
    
