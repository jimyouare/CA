//null starten 
Git-Befehle
Version und Installation

Überprüfen Sie, welche git-Version installiert ist (git ist auf Linux- und Mac-Geräten vorinstalliert).

git --version

Sie können die Installationsanleitung aufrufen, falls git noch nicht installiert ist.
Nutzername und E-Mail-Adresse hinzufügen

Ihr Git-Nutzername und Ihre E-Mail-Adresse werden verwendet, um Sie als Autor:in zu identifizieren, wenn Sie Code in ein Repository hinzufügen.
Geben Sie folgenden Befehl ein, um Ihren Nutzernamen zu konfigurieren:

git config --global user.name "IHR_NUTZERNAME"

Lassen Sie sich Ihren eingegebenen Nutzernamen anzeigen:

git config --global user.name

Geben Sie nun Ihre E-Mail-Adresse ein.

git config --global user.email "adresse@example.com"

Lassen Sie sich Ihre eingegebene E-Mail-Adresse anzeigen:

git config --global user.email

Sie können auch alle eingegebenen Informationen gleichzeitig auslesen:

git config --global --list

Mit Projekten arbeiten

Eine Visualisierung des git-Workflow hilft, die verschiedenen Befehle wie clone, push, pull, merge und fetch zu verstehen.

Git ist eine dezentrale Versionsverwaltung. Dies bedeutet, dass Entwickler- und Serverumgebung nicht getrennt sind. Jeder Entwickler hat sowohl einen Workspace (dies sind die Dateien, an denen man derzeit arbeitet) sowie ein Repository, auch Klon genannt, welches alle Versionen und Branches eines Projekts enthält.

Wird GitLab verwendet, gibt es gleichzeitig ein zentrales Repository, mit denen das Projekt verwaltet wird.

Wenn Sie ein Projekt in der Web-Anwendung von GitLab angelegt haben und mit diesem auf Ihrem Rechner arbeiten möchten, dann müssen Sie zunächst eine lokale Kopie erzeugen.

Klonen Sie das Projekt in das Verzeichnis auf Ihrem Rechner, in dem Sie sich derzeit befinden. Navigieren Sie dazu in der Web-Anwendung zu dem Projekt, an dem Sie arbeiten möchten. Im Drop-down-Menü unter dem Titel wählen Sie SSH aus und kopieren dann die Zeile, die rechts davon angegeben ist.
clone project
