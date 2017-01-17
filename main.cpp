#include <iostream>
#include <person.hpp>
// #include <room.hpp> Wurde nach Besprechung ausgebaut. Peoplelist ist geordnet nach den Raumnummern
#include <string>
#include <stdlib.h>
#include <Windows.h>
#include <printfunctions.cpp>
#include <textstrings.cpp>
#include <limits>

/*
bei Settern wenn möglich 'const &' von der Variable übergeben

Wenn ich nur & von der Variable übergebe, kann ich sie auch ändern in der Methode -> siehe bsp

Anforderungen:
-Bewegung durch Räume bzw. Szenen basierend auf Textein- und ausgabe - check
-Interaktion mit Spielwelt, inkl. Zustandsänderung /z.B. Schalter, Türe, LP - bin dabei
-Einfache Inventarverwaltung z.B. Gegenstand aufnehmen, später benutzen - passt denke ich wenn es funkt
-Teilprozesse z.B. Unterhaltung/Dialog, Kampf, schrittweises Rätsel etc. - ist in Planung


TODO:
Std::list -> Inventar // Inventar hat fest 3 Plätze  --- umgeplant
Bewegung und Verzweigung der Räume --- In Progress
Zustandsänderungen erhöhen ((Interatkion mit Inventar) --- In Progress
Kommentieren wer was gemacht hat --- muss noch erledigt werden


cleanConsole() um das ganze hübscher zu machen | Haben system("cls") dafuer eingebaut
Leave Messages zu Räumen und teils auch Gesprächen
*/

// Caner Yavuz
using namespace std;
enum inventartyp{ food_1,beweisstueck,key};

class inventarelement{
public:
    string name;
    int beweisstueck; // 1 - Ja, 0 - Egal, -1 Spiel verloren
    inventartyp typ;
};

class inventar{
public:
    int count = 0;
    inventarelement Liste[10];
    inventarelement t1;

    int GetPriorityOfListElement(int numb){
        return Liste[numb].beweisstueck;
    }

    bool CheckIfEmpty(){
        if(count == 0){
            return true;
        }
        else{
            return false;
        }
    }

    bool CheckIfElementIsInList(std::string input_name){
        if(count == 0){
            return false;
        }
        else{
            for(int i=0;i<count; i++){
                if(Liste[i].name == input_name){
                    return true;
                }
            }
            return false;
        }
    }
    int GetNumberOfListElement(std::string input_name){
        for(int i=0;i<count;i++){
            if(count == 0){
                return -1;
            }
            else{
                if(Liste[i].name == input_name){
                    return i;
                }
            }
            return -1;
        }
    }


    void Add(inventarelement elem)
    {
        if(count >=10)
        {
            print("Inventar voll! Dieses Element kann nicht aufgenommen werden");
            //Inventar voll
        }
        else{
            Liste[count] = elem;
            count++;
        }
    }
    void Delete(int deletenumber){

        if(count == deletenumber)
        {
            Liste[deletenumber] = t1;
            count --;
        }
        else{
            for(deletenumber;deletenumber<count;deletenumber++){
                inventarelement tmp = Liste[deletenumber];
                Liste[deletenumber] = Liste[deletenumber+1];
                Liste[deletenumber+1] = tmp;
            }
            Liste[deletenumber] = t1;
            count --;
        }
    }

    void Delete(std::string input_name){
        int deletenumber = GetNumberOfListElement(input_name);
        Delete(deletenumber);
    }

    std::string ListAll(){
        string tempstring ="";
        for(int i=0;i<count;i++){
            tempstring += std::to_string(i) + ". " + Liste[i].name + "\n";
        }
        return tempstring;
    }
};

//#Ronaldo Dano
struct data
{
    person peoplelist[7];
    inventar inv;
};

void CreateGame(struct data *z)
{
    cout << initialize_person_start << endl;
    person person_one;
    person person_two;
    person person_three;
    person person_four;
    person person_five;
    person person_six;
    person person_seven;

    person_one.SetName("Pfarrer");
    person_two.SetName("Herr Schmidt");
    person_three.SetName("Herr Müller");
    person_four.SetName("Paul");
    person_five.SetName("Jan");
    person_six.SetName("Sheriff");
    person_seven.SetName("Küchenchef");

    //inventar inv;
    //z ->inventar = inv;

    z ->peoplelist[0] = person_one;
    z ->peoplelist[1] = person_two;
    z ->peoplelist[2] = person_three;
    z ->peoplelist[3] = person_four;
    z ->peoplelist[4] = person_five;
    z ->peoplelist[5] = person_six;
    z ->peoplelist[6] = person_seven;
    cout << initialize_person_end << endl;

}

void SetDialogText(int set, struct data* z)
{
    switch(set){
    case 1:
        z ->peoplelist[0].SetDialogOptions(p1_set_1_options);
        z ->peoplelist[0].SetDialog(p1_set_1_str_1, p1_set_1_str_2, p1_set_1_str_3);
        z ->peoplelist[1].SetDialogOptions(p2_set_1_options);
        z ->peoplelist[1].SetDialog(p2_set_1_str_1, p2_set_1_str_2, p2_set_1_str_3);
        z ->peoplelist[2].SetWerwolf();
        z ->peoplelist[2].SetDialogOptions(p3_set_1_options);
        z ->peoplelist[2].SetDialog(p3_set_1_str_1, p3_set_1_str_2, p3_set_1_str_3);
        z ->peoplelist[3].SetDialogOptions(p4_set_1_options);
        z ->peoplelist[3].SetDialog(p4_set_1_str_1,p4_set_1_str_2 ,p4_set_1_str_3);
        z ->peoplelist[4].SetDialogOptions(p5_set_1_options);
        z ->peoplelist[4].SetDialog(p5_set_1_str_1, p5_set_1_str_2, p5_set_1_str_3);
        z ->peoplelist[5].SetDialogOptions(p6_set_1_options);
        z ->peoplelist[5].SetDialog(p6_set_1_str_1, p6_set_1_str_2, p6_set_1_str_3);
        z ->peoplelist[6].SetDialogOptions(p7_set_1_options);
        z ->peoplelist[6].SetDialog(p7_set_1_str_1, p7_set_1_str_2, p7_set_1_str_3);
        break;
    case 2:
        z ->peoplelist[0].SetDialogOptions(p1_set_2_options);
        z ->peoplelist[0].SetDialog(p1_set_2_str_1, p1_set_2_str_2, p1_set_2_str_3);
        z ->peoplelist[1].SetDialogOptions(p2_set_2_options);
        z ->peoplelist[1].SetDialog(p2_set_2_str_1, p2_set_2_str_2, p2_set_2_str_3);
        z ->peoplelist[2].SetDialogOptions(p3_set_2_options);
        z ->peoplelist[2].SetDialog(p3_set_2_str_1, p3_set_2_str_2, p3_set_2_str_3);
        z ->peoplelist[3].SetDialogOptions(p4_set_2_options);
        z ->peoplelist[3].SetDialog(p4_set_2_str_1,p4_set_2_str_2 ,p4_set_2_str_3);
        z ->peoplelist[4].SetDialogOptions(p5_set_2_options);
        z ->peoplelist[4].SetDialog(p5_set_2_str_1, p5_set_2_str_2, p5_set_2_str_3);
        z ->peoplelist[5].SetDialogOptions(p6_set_2_options);
        z ->peoplelist[5].SetDialog(p6_set_2_str_1, p6_set_2_str_2, p6_set_2_str_3);
        z ->peoplelist[6].SetDialogOptions(p7_set_2_options);
        z ->peoplelist[6].SetDialog(p7_set_2_str_1, p7_set_2_str_2, p7_set_2_str_3);
        break;
    }
    //cout << "SetDialoge Erfolgreich" << endl;
}


// @Alex_
int GetUserInput(std::string options, int maxAllowedNumber, int minAllowedNumber=1){
    bool correct_input = false;
    int input;

    while (!correct_input) {
        printXEmptyLines(1);
        print(options);
        cin >> input;
        while(cin.fail()){
            cleanconsole();
            cin.clear();
            cin.ignore();
            print("Falsche Eingabe, ENTER A NUMBER");
            printXEmptyLines(1);
            print(options);
            cin >> input;
        }
        if(input >= minAllowedNumber && input <= maxAllowedNumber){
            correct_input = true;
        }
        else{
            cleanconsole();
            print("Bitte gebe eine gueltige Zahl ein. Ein gueltige Zahl ist ganzzahlig und liegt im Bereich ZWISCHEN " + std::to_string(minAllowedNumber-1) + " und " + std::to_string(maxAllowedNumber+1));
            printXEmptyLines(1);
        }
    }
    cleanconsole();
    return input;
}

void Play(struct data* game)
{
    int available_houses = 6;
    int set = 1; // TODO: später auf set = 1 setzen, zu Testzwecken schon Set = 2
    bool activatedgame = false;
    bool knowlegdeOfHiddenRoom = false;
    bool enableGericht = false;
    bool takenChurchKey = false;
    bool church_back_room_door = false;
    bool church_notes_taken = false;
    bool hiddenroom_notes_taken = false;
    bool helpwithhomework = false;
    bool hiddenroomopen = false;


    // Einführung
    printXEmptyLines(2);

    //Zu Testzwecken ausgeschaltet
    //printTextSmoothly(introduction);
    print(introduction);

    printXEmptyLines(2);

    SetDialogText(set,game);

    //Main Game Loop - Spieler kann solange in der Welt umherlaufen,
    //wie er sich nicht entscheidet jemanden zur Anklage zu bringen
    bool ready_for_final_question = false;

    while(!ready_for_final_question)
    {
        //Loop Variablen
        bool stayinchurch = true;
        bool stayinmensa = true;
        bool stayintatort = true;
        bool stayinaufenthaltsraum = true;
        bool stayinscheune = true;
        bool stayinfriedhof = true;
        bool stayinchurchbackroom = true;
        bool stayinhiddenroom = true;
        bool talkWithP1 = true;
        bool talkWithP2 = true;
        bool talkWithP3 = true;
        bool talkWithP4 = true;
        bool talkWithP5 = true;
        bool talkWithP6 = true;
        bool talkWithP7 = true;

        //temporary string
        std::string tempstring;

        //TODO: Auslagern
        //TODO: Auslagern
        //falls das Bool "erlaubeGericht" freigeschaltet wurde, wird hier auch der Raum 7 "Gerichtsgebäude" angeboten, da man einen Schlüssel bekommt
        if(!enableGericht){
            tempstring = options;
        }
        else{
            tempstring = options_2;
            available_houses = 7;
        }

        //Switch von der Markplatzmitte
        switch(GetUserInput(tempstring,available_houses)){
        case 1:
            //Kirche
            while(stayinchurch){

                print(church_intro);
                switch(GetUserInput(church_options,4)){
                case 1:
                    //Mit P1 sprechen
                    print(p1_intro);
                    while(talkWithP1){
                        switch(GetUserInput(game->peoplelist[0].GetDialogOptions(),3)){
                            case 1:
                                print(game->peoplelist[0].GetAnswer(1));                                
                                break;
                            case 2:
                                print(game->peoplelist[0].GetAnswer(2));
                                break;
                            case 3:
                                talkWithP1 = false;
                                break;
                        }
                    }
                    talkWithP1 = true;
                    break;
                case 2:
                    //Beichtstuhl
                    if(!activatedgame){
                        //Sollte man hier hingehen bevor man beim Sheriff war, so findet man den Täter dort und er liefert starke Indizien fuer seine Tat
                        print(confessional_intro_pre);

                        while(talkWithP3){
                            switch(GetUserInput(game->peoplelist[1].GetDialogOptions(),3)){
                            case 1:                                
                                print(game->peoplelist[1].GetAnswer(1));
                                if(game->inv.CheckIfElementIsInList("Gestaednis von Herr Schmidt")){
                                    inventarelement talk_with_p3;
                                    talk_with_p3.beweisstueck = 2;
                                    talk_with_p3.typ = beweisstueck;
                                    talk_with_p3.name = "Gestaednis von Herr Schmidt";

                                }
                                break;
                            case 2:
                                print(game->peoplelist[1].GetAnswer(2));
                                break;
                            case 3:
                                talkWithP3 = false;
                                break;
                            }
                        }
                        talkWithP3 = true;
                    }
                    else{                        
                        if(!takenChurchKey){
                            print(confessional_intro);

                            if(GetUserInput(confessional_options,1) == 1)
                            {
                                if(!game->inv.CheckIfElementIsInList("Kirchenschluessel")){
                                    inventarelement church_key;
                                    church_key.name = "Kirchenschluessel";
                                    church_key.beweisstueck = 0;
                                    church_key.typ = key;
                                    game ->inv.Add(church_key);
                                }
                            }
                        }
                        else{
                            print(confessional_intro_2);
                        }
                    }
                    break;
                case 3:
                    //Zur Tür hinter dem Altar gehen
                    if(church_back_room_door == false){
                        if(!game ->inv.CheckIfElementIsInList("Kirchenschluessel"))
                        {
                            std::string use_church_key = "Du verwendest den Schluessel den du im Beichtstuhl gefunden hast";
                            print(use_church_key);
                            game ->inv.Delete("Kirchenschluessel");
                            church_back_room_door = true;
                        }
                        else{                            
                            print(no_key);
                        }
                    }
                    if(church_back_room_door)
                    {
                        while(stayinchurchbackroom){
                            print(church_back_room_intro);
                            if(!church_notes_taken){
                                tempstring = church_back_room_options;
                            }
                            else{                                
                                tempstring = church_back_room_options_2;
                            }
                            switch(GetUserInput(tempstring,3)){
                            case 1:
                                //Gebetsbuchtext
                                print(church_back_room_prayer_book);
                                print(not_useful);
                                break;
                            case 2:
                                // Tagebuch
                                if(!church_notes_taken){
                                    print(church_back_room_notes);

                                    if(GetUserInput(note_options,2) == 1){
                                        if(!game->inv.CheckIfElementIsInList("Tagebuch des Pfarrers")){
                                            inventarelement tagebuch;
                                            tagebuch.name = "Tagebuch des Pfarrers";
                                            tagebuch.typ = beweisstueck;
                                            tagebuch.beweisstueck = -1;
                                            game->inv.Add(tagebuch);
                                            church_notes_taken = true;
                                        }
                                    }
                                }
                                else{
                                    stayinchurchbackroom = false;
                                }

                                break;
                            case 3:
                                stayinchurchbackroom = false;
                                break;
                            }
                        }
                        stayinchurchbackroom = true;
                    }
                    break;
                case 4:
                    stayinchurch = false;
                    break;
                }
            }
            stayinchurch = true;
            break;
        case 2:
            //Mensa
            print(mensa_intro);
            while(stayinmensa){

                //Wenn das Spiel noch nicht aktiviert ist, befindet sich der Täter noch nicht in der Mensa, daher wird ein andere Optionen geladen..
                if(!activatedgame){
                    tempstring = mensa_options_1;
                }
                else{
                    tempstring = mensa_options_2;
                }

                switch (GetUserInput(tempstring,4)) {
                case 1:
                    //Mit P7 sprechen
                    while(talkWithP7){
                        tempstring = game ->peoplelist[6].GetDialogOptions();

                        inventarelement food;
                        switch (GetUserInput(tempstring,3)) {
                        case 1:
                            print(game ->peoplelist[6].GetAnswer(1));

                            if(!game->inv.CheckIfElementIsInList("Teller mit Schnitzel und ein kleines Dessert")){
                                food.name = "Teller mit Schnitzel und ein kleines Dessert";
                                food.beweisstueck = 0;
                                food.typ = food_1;
                                game->inv.Add(food);
                            }
                            else{
                                if(game->peoplelist[6].GetCounter() < 3){
                                    print(food_in_inventar);
                                }
                            }
                            break;
                        case 2:
                            print(game ->peoplelist[6].GetAnswer(2));
                            break;
                        case 3:
                            talkWithP7 = false;
                            break;
                        }
                    }
                    talkWithP7 = true;
                    break;
                case 2:
                    //Mit P3 Sprechen (Hr. Müller)
                    while(talkWithP3){
                        tempstring = game->peoplelist[2].GetDialogOptions();
                        switch (GetUserInput(tempstring,3)) {
                        case 1:
                            print(game->peoplelist[2].GetAnswer(1));
                            break;
                        case 2:
                            print(game->peoplelist[2].GetAnswer(2));
                            break;
                        case 3:
                            talkWithP3 = false;
                            break;
                        }
                    }
                    talkWithP3 = true;
                    break;
                case 3:
                    //Wenn man bevor man mit dem Sheriff geredet hat,
                    //In der Mensa ist, so sind hier nur 2 Personen
                    //Später sind es 3, da der Täter auch in der Mensa sitzt
                    if(!activatedgame)
                    {
                        stayinmensa = false;
                    }
                    else{
                        //Mit P2 Sprechen
                        while(talkWithP2){
                            tempstring = game->peoplelist[1].GetDialogOptions();
                            switch(GetUserInput(tempstring,3)){
                            case 1:
                                print(game ->peoplelist[1].GetAnswer(1));
                                break;
                            case 2:
                                print(game->peoplelist[1].GetAnswer(2));
                                knowlegdeOfHiddenRoom = true;
                                break;
                            case 3:
                                talkWithP2 = false;
                                break;
                            }
                        }
                        talkWithP2 = true;
                    }
                    break;
                case 4:
                    stayinmensa = false;
                }
            }
            stayinmensa = true;
            break;
        case 3:
            //Tatort
            while(stayintatort){
                print(crime_scene_intro);
                switch(GetUserInput(crime_scene_options,3)){
                case 1:
                    //Mit dem Sheriff (P6) sprechen
                    while(talkWithP6){
                        tempstring = game->peoplelist[5].GetDialogOptions();

                        switch(GetUserInput(tempstring,3)){
                        case 1:
                            if(!activatedgame){
                                //Spiel starten und den Auftrag offiziell annehmen
                                print(game->peoplelist[5].GetAnswer(1,false));

                                //Texte werden neu gesetzt
                                set = 2;
                                activatedgame = true;
                                SetDialogText(set, game);

                                printXEmptyLines(2);
                                print("Die Leute erkennen dich nun als Ermittler und werden dir ggf. anderes erzaehlen wie zuvor.");
                                printXEmptyLines(2);

                            }
                            else{
                                //Spiel "beenden" und zur Anklage einer Person kommen
                                //Der Ort "Gericht" wird dadurch freigeschaltet und man bekommt einen Schlüssel
                                print(game->peoplelist[5].GetAnswer(1,false));
                                enableGericht = true;
                                inventarelement gerichtskey;
                                gerichtskey.beweisstueck = 0;
                                gerichtskey.name = "Schluessel zum Gericht";
                                gerichtskey.typ = key;
                                game->inv.Add(gerichtskey);
                            }
                            break;
                        case 2:
                            print(game->peoplelist[5].GetAnswer(2,false));
                            break;
                        case 3:
                            //Gespräch verlassen
                            talkWithP6 = false;
                        }
                    }
                    talkWithP6 = 6;
                    break;
                case 2:
                    //Leiche anschauen
                    print(watch_stiff);
                    break;
                case 3:
                    //Tatort verlassen
                    stayintatort = false;

                    break;
                }
            }
            stayintatort = true;
            break;
        case 4:
            //Aufenthaltsraum
            print(common_room_intro);
            while(stayinaufenthaltsraum){
                switch (GetUserInput(common_room_options,3)) {
                case 1:
                    //Mit P4 sprechen
                    while(talkWithP4){
                        tempstring = game->peoplelist[3].GetDialogOptions();
                        switch(GetUserInput(tempstring,3)){
                        case 1:
                            //Bei den Mathehausaufgaben helfen
                            if(!activatedgame){
                                print(game->peoplelist[3].GetAnswer(1));
                                break;
                            }

                            if(!helpwithhomework)
                            {
                                //print(game->peoplelist[3].GetAnswer(1));

                                //print(enter_solution);

                                tempstring = game ->peoplelist[3].GetAnswer(1) + "\n" + enter_solution;
                                helpwithhomework = true;
                                //int lsg;
                                //cin >> lsg;
                                //TODO
                                if(GetUserInput(tempstring,999,-999) == -16){
                                    print(thanks_for_homework);
                                    if(!game->inv.CheckIfElementIsInList("Unbekannter Schluessel")){
                                        inventarelement scheunenkey;
                                        scheunenkey.beweisstueck = 0;
                                        scheunenkey.name = "Unbekannter Schluessel";
                                        scheunenkey.typ = key;
                                        game->inv.Add(scheunenkey);
                                        game ->peoplelist[3].SetDialogOptions(p4_set_3_options);
                                        //Nur String 1 aendert sich
                                        game ->peoplelist[3].SetDialog(p4_set_3_str_1,p4_set_2_str_2,p4_set_2_str_3);

                                    }
                                }
                                else{

                                    print(wrong_solution);
                                    game ->peoplelist[3].SetDialogOptions(p4_set_3_options);
                                    //Nur String 1 aendert sich
                                    game ->peoplelist[3].SetDialog(p4_set_4_str_1,p4_set_2_str_2,p4_set_2_str_3);
                                }
                            }
                            else{
                                //Rätsel nicht mehr verfügbar
                                print(game->peoplelist[3].GetAnswer(1));
                            }

                            break;
                        case 2:
                            print(game->peoplelist[3].GetAnswer(2));
                            break;
                        case 3:
                            //Gespräch beenden
                            talkWithP4=false;
                            break;
                        }
                    }
                    talkWithP4 = true;
                    break;
                case 2:
                    //Mit P5 sprechen
                    while(talkWithP5){
                        tempstring = game->peoplelist[4].GetDialogOptions();

                        switch(GetUserInput(tempstring,3)){
                        case 1:
                            print(game->peoplelist[4].GetAnswer(1));
                            break;
                        case 2:
                            print(game->peoplelist[4].GetAnswer(2));
                            break;
                        case 3:
                            //Gespräch beenden
                            talkWithP5=false;
                            break;
                        }
                    }
                    talkWithP5 = true;
                case 3:
                    //Raum verlassen
                    stayinaufenthaltsraum = false;
                    break;
                }
            }
            stayinaufenthaltsraum = true;
            break;
        case 5:
            //Scheune

            print(barn_intro);
            while(stayinscheune){
                if(!knowlegdeOfHiddenRoom){

                    printTextSmoothly(easter_egg_str_1);
                    Sleep(5000);
                    printXEmptyLines(1);
                    printTextSmoothly(easter_egg_str_2);
                    Sleep(5000);
                    printTextSmoothly(easter_egg_str_3);
                    printTextSmoothly(easter_egg_str_4);
                }
                else{

                    print(barn_hay_action);
                    if(game->inv.CheckIfElementIsInList("Unbekannter Schluessel"))
                    {
                        if(!hiddenroomopen){
                            game->inv.Delete("Unbekannter Schluessel");
                            print(hiddenroom_door_opening);
                            hiddenroomopen = true;
                        }
                        print(hiddenroom_entry);
                        while(stayinhiddenroom){
                            if(!hiddenroom_notes_taken){
                                print(hiddenroom_notes_intro);
                                inventarelement hidden_room_notes;
                                hidden_room_notes.beweisstueck = 2;
                                hidden_room_notes.name = "Schuldscheine aus der Scheune";
                                hidden_room_notes.typ = beweisstueck;
                                game->inv.Add(hidden_room_notes);
                                hiddenroom_notes_taken = true;
                            }
                            else{
                            print(hiddenroom_intro_2);
                            }
                            stayinhiddenroom = false;
                        }
                    }
                    else{

                        print(no_key);
                    }
                }
                tempstring = "Druecke 1 um die Scheune zu verlassen";
                if(GetUserInput( tempstring,1) == 1){
                    stayinscheune = false;
                }
            }
            stayinscheune = true;
            break;

        case 6:
            //Friedhof
            while(stayinfriedhof){
                std::string cemetery_intro = "An einigen Gräbern liegen Blumen, an manchen mehr an manchen weniger\nHier kannst du nichts machen\nDrücke die 1 um den Friedhof wieder zu verlassen";
                if(GetUserInput(cemetery_intro,1) ==1){
                    stayinfriedhof = false;
                }
            }
            stayinfriedhof = true;

            break;
        case 7:
            //Gerichtsgebäude -> du willst das Rätsel lösen
            if(game->inv.CheckIfElementIsInList("Schluessel zum Gericht")){                
                print(open_gericht);
                game->inv.Delete("Schluessel zum Gericht");
                print(final_intro);
                Sleep(2000);
                ready_for_final_question = true;
            }
            else{
                print("Du hast keinen Schluessel hierfuer");
            }
            break;

        }
        cleanconsole();
    }
}

void Ask(struct data* game)
{
    int element_number;
    std::string tempstring;

    bool lose = false;
    print(final_intro_part_2);
    printXEmptyLines(1);
    print(choose_person);
    tempstring = "";
    for(int i=0;i<7;i++){
        tempstring += std::to_string(i) + ". " + game ->peoplelist[i].GetName() + "\n";
    }
    int personnumber = GetUserInput(tempstring,6,0);
    cleanconsole();

    tempstring = "Ich klage hiermit " + game ->peoplelist[personnumber].GetName() + " an und habe dafuer folgende Beweise";
    print(tempstring);
    printXEmptyLines(1);
    bool chooseinventar = true;
    int counter = 0;
    bool notdone = true;

    while(notdone){
        print(final_intro_part_3);

        switch(GetUserInput(choose_inventar_intro,2)){
        case 1:
            chooseinventar = true;
            while(chooseinventar){
                if(game->inv.CheckIfEmpty()){
                    print(empty_inventar);
                    notdone = false;
                    break;
                }
                else{
                    printXEmptyLines(1);
                    std::string choose_proof = "Was moechtest du als Beweis vorlegen\n" + game->inv.ListAll() + std::to_string(game->inv.count) + ". Um zurueck zur Uebersicht zu gelangen";

                    element_number = GetUserInput(choose_proof,game->inv.count,0);
                    if(element_number == game->inv.count){
                      chooseinventar = false;
                      break;
                    };
                    int priority = game ->inv.GetPriorityOfListElement(element_number);
                    if( priority < 0){
                        print(game->inv.Liste[element_number].name);
                        lose=true;
                    }

                    if(game->inv.Liste[element_number].typ == beweisstueck && priority != -1){
                        counter += priority;
                    }

                    //Gegenstand entfernen
                    game->inv.Delete(element_number);
                }
            }
            break;
        case 2:
            notdone = false;
            break;
        }
    }

    if(lose){
        printSpecialText("Du hast verloren");
        printXEmptyLines(2);
        print("Das Gericht ist umpört, dass du ohne Gruende in Privaträume des Pfarrers eingedrungen bist um an Beweise zu kommen. Dies entspricht nach Ansichten des Gerichts eines Amtsmissbrauchs. Du verlierst dadurch jegliche Glaubwuerdigkeit und wirst selbst verurteilt.");
    }
    else if(game ->peoplelist[personnumber].GetWerwolfStatus() && counter >=2 && !lose){
        printSpecialText("Herzlichen Glueckwunsch");
        printXEmptyLines(2);
        print("du hast den Täter anhand von aussagekrätigen");
        print("Beweisen ueberfuehrt");
    }
    else{
        printSpecialText("Du hast das Spiel verloren");
        printXEmptyLines(2);
        print("du hast entweder die falsche Person angeklagt ");
        print("oder zu wenig Beweise vorlegen können ");
        print("um das Gericht zu ueberzeugen");
    }
}

int main()
{
    //Beta 42
    struct data gamedata;
    struct data *data_ptr = &gamedata;
    CreateGame(data_ptr);
    Play(data_ptr);
    Ask(data_ptr);
    printXEmptyLines(2);
    print("Das Spiel wird sich in 60 Sekunden beenden"); // Da freut er sich :D #Stefan
    Sleep(60000);
    cleanconsole();
    printSpecialText("Das Spiel wurde erfolgreich beendet");
    Sleep(1000);

    return 0;
}

