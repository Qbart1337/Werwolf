#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>

// @Stefan Nonn
// Werwolf ist seit Änderung nun der Täter
enum whoami { Dorfbewohner, Werwolf};

// Personen sind im Spiel später in einer Liste anzulegen und mit den hier
// vorgegebnen Methoden zu konfigurieren
class person
{
    private:
        whoami bewohnerstatus;
        // der ask_Counter >2 sag die Person eine abweisende Antwort [answer_random]
        int ask_Counter;
        std::string name;
        std::string answer_neutral;
        std::string answer_sceptic;
        std::string answer_random;
        // Sind andere Antworten der Person bevor Spieler am Tatort war. (Hinweise was er machen könnte)
        std::string dialog_options;

    public:
        person();
        // Bei der GameInit verwenden. SetWerwolf nur fuer den Täter
        void SetWerwolf();
        void SetName(std::string name);
        void SetDialogOptions(std::string str_opts);
        void SetDialog(std::string answer_neutral, std::string answer_sceptic, std::string answer_random);


        // kein Set da jede Person erst Dorfbewohner ist
        whoami GetPersonenStatus();
        std::string GetName();
        std::string GetDialogOptions();
        std::string GetAnswer(int answer_choose, bool temp = true);
        std::string GetFinalInformation();
        bool GetWerwolfStatus();
};

#endif // PERSON_H
