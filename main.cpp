#include <iostream>
#include <person.hpp>
// #include <room.hpp> Wurde nach Besprechung ausgebaut. Peoplelist ist geordnet nach den Raumnummern
#include <string>
#include <stdlib.h>
#include <Windows.h>
#include <printfunctions.cpp>
#include <textstrings.cpp>
#include <limits>

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
        for(int i=0;i<=count;i++){
            if(count == 0){
                return -1;
            }
            else{
                if(Liste[i].name == input_name){
                    return i;
                }
            }
        }
        return -1;
    }


    void Add(inventarelement elem)
    {
        if(count >=10)
        {
            printTextSmoothly("Inventar voll! Dieses Element kann nicht aufgenommen werden");
            //Inventar voll
        }
        else{
            Liste[count] = elem;
            count++;
        }
    }
    void Delete(int delete_number){
        if(count-1 == delete_number)
        {
            Liste[delete_number] = t1;
            count --;
        }
        else{
            for(delete_number;delete_number<=count;delete_number++){
                inventarelement tmp = Liste[delete_number];
                Liste[delete_number] = Liste[delete_number+1];
                Liste[delete_number+1] = tmp;
            }
            Liste[delete_number+1] = t1;
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
    person person_one;
    person person_two;
    person person_three;
    person person_four;
    person person_five;
    person person_six;
    person person_seven;

    person_one.SetName("Pfarrer");
    person_two.SetName("Herr Schmidt");
    person_three.SetName("Herr Mueller");
    person_four.SetName("Paul");
    person_five.SetName("Jan");
    person_six.SetName("Sheriff");
    person_seven.SetName("Kuechenchef");

    z ->peoplelist[0] = person_one;
    z ->peoplelist[1] = person_two;
    z ->peoplelist[2] = person_three;
    z ->peoplelist[3] = person_four;
    z ->peoplelist[4] = person_five;
    z ->peoplelist[5] = person_six;
    z ->peoplelist[6] = person_seven;

}

void SetDialogText(int set, struct data* z)
{
    switch(set){
    case 1:
        z ->peoplelist[0].SetDialogOptions(p1_set_1_options);
        z ->peoplelist[0].SetDialog(p1_set_1_str_1, p1_set_1_str_2, p1_set_1_str_3);
        z ->peoplelist[1].SetDialogOptions(p2_set_1_options);
        z ->peoplelist[1].SetDialog(p2_set_1_str_1, p2_set_1_str_2, p2_set_1_str_3);
        z ->peoplelist[1].SetWerwolf();
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


// @Alexander Gross
int GetUserInput(std::string options, int max_allowed_number, int min_allowed_number=1){
    bool correct_input = false;
    int input;

    while (!correct_input) {
        printXEmptyLines(1);
        printTextSmoothly(options);
        cin >> input;
        while(cin.fail()){
            cleanConsole();
            cin.clear();
            cin.ignore();

            printTextSmoothly(error_message_not_a_number);
            printXEmptyLines(1);
            printTextSmoothly(options);
            cin >> input;
        }
        if(input >= min_allowed_number && input <= max_allowed_number){
            correct_input = true;
        }
        else{
            cleanConsole();
            printTextSmoothly("Bitte gebe eine gueltige Zahl ein. Ein gueltige Zahl ist ganzzahlig und liegt im Bereich ZWISCHEN " + std::to_string(min_allowed_number-1) + " und " + std::to_string(max_allowed_number+1));
            printXEmptyLines(1);
        }
    }
    cleanConsole();
    return input;
}

void Play(struct data* game)
{
    int available_houses = 6;
    int set = 1; // TODO: später auf set = 1 setzen, zu Testzwecken schon Set = 2
    bool activatedgame = false;
    bool knowlegde_of_hiddenroom = false;
    bool enable_court = false;
    bool taken_church_key = false;
    bool church_back_room_door = false;
    bool church_notes_taken = false;
    bool hiddenroom_notes_taken = false;
    bool help_with_homework = false;
    bool hiddenroom_open = false;


    // Einführung
    printTextSmoothly(introduction);

    printXEmptyLines(2);

    printTextSmoothly(gamerules);

    printXEmptyLines(2);

    SetDialogText(set,game);

    //Main Game Loop - Spieler kann solange in der Welt umherlaufen,
    //wie er sich nicht entscheidet jemanden zur Anklage zu bringen
    bool ready_for_final_question = false;

    while(!ready_for_final_question)
    {
        //Loop Variablen
        bool stay_in_church = true;
        bool stay_in_mensa = true;
        bool stay_in_crime_scene = true;
        bool stay_in_common_room = true;
        bool stay_in_barn = true;
        bool stay_in_cemetery = true;
        bool stay_in_churchbackroom = true;
        bool stay_in_hiddenroom = true;
        bool talk_with_p1 = true;
        bool talk_with_p2 = true;
        bool talk_with_p3 = true;
        bool talk_with_p4 = true;
        bool talk_with_p5 = true;
        bool talk_with_p6 = true;
        bool talk_with_p7 = true;

        //temporary string
        std::string tempstring;

        //falls das Bool "erlaubeGericht" freigeschaltet wurde, wird hier auch der Raum 7 "Gerichtsgebäude" angeboten, da man einen Schlüssel bekommt
        if(!enable_court){
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
            printTextSmoothly(church_intro);
            while(stay_in_church){
                switch(GetUserInput(church_options,4)){
                case 1:
                    //Mit P1 sprechen
                    printTextSmoothly(p1_intro);
                    while(talk_with_p1){
                        switch(GetUserInput(game->peoplelist[0].GetDialogOptions(),3)){
                            case 1:
                                printTextSmoothly(game->peoplelist[0].GetAnswer(1));
                                break;
                            case 2:
                                printTextSmoothly(game->peoplelist[0].GetAnswer(2));
                                break;
                            case 3:
                                talk_with_p1 = false;
                                break;
                        }
                    }
                    talk_with_p1 = true;
                    break;
                case 2:
                    //Beichtstuhl
                    if(!activatedgame){
                        //Sollte man hier hingehen bevor man beim Sheriff war, so findet man den Täter dort und er liefert starke Indizien fuer seine Tat
                        printTextSmoothly(confessional_intro_pre);

                        while(talk_with_p3){
                            switch(GetUserInput(game->peoplelist[1].GetDialogOptions(),3)){
                            case 1:
                                printTextSmoothly(game->peoplelist[1].GetAnswer(1));
                                if(game->peoplelist[1].GetCounter() < 3 &&!game->inv.CheckIfElementIsInList("Gestaednis von Herr Schmidt")){
                                    //Gestaednis dem Inventar hinzufuegen
                                    inventarelement talked_with_p3;
                                    talked_with_p3.beweisstueck = 2;
                                    talked_with_p3.typ = beweisstueck;
                                    talked_with_p3.name = "Gestaednis von Herr Schmidt";
                                    game->inv.Add(talked_with_p3);
                                    }
                                break;
                            case 2:
                                printTextSmoothly(game->peoplelist[1].GetAnswer(2));
                                break;
                            case 3:
                                talk_with_p3 = false;
                                break;
                            }
                        }
                        talk_with_p3 = true;
                    }
                    else{
                        if(!taken_church_key){
                            printTextSmoothly(confessional_intro);
                            taken_church_key = true;
                            if(GetUserInput(confessional_options,1) == 1)
                            {
                                if(!game->inv.CheckIfElementIsInList("Kirchenschluessel")){
                                    //Kirchenschluessel dem Inventar hinzufuegen
                                    inventarelement church_key;
                                    church_key.name = "Kirchenschluessel";
                                    church_key.beweisstueck = 0;
                                    church_key.typ = key;
                                    game ->inv.Add(church_key);
                                    printTextSmoothly(leave_confessional);
                                }
                            }
                        }
                        else{
                            printTextSmoothly(confessional_intro_2);
                        }
                    }
                    break;
                case 3:
                    //Zur Tür hinter dem Altar gehen
                    if(church_back_room_door == false){
                        if(game ->inv.CheckIfElementIsInList("Kirchenschluessel"))
                        {
                            //Kirchenschluessen aus dem Inventar entfernen
                            printTextSmoothly(use_church_key);
                            game ->inv.Delete("Kirchenschluessel");
                            church_back_room_door = true;
                        }
                        else{
                            printTextSmoothly(no_key);
                        }
                    }
                    if(church_back_room_door)
                    {
                        while(stay_in_churchbackroom){
                            printTextSmoothly(church_back_room_intro);
                            if(!church_notes_taken){
                                tempstring = church_back_room_options;
                            }
                            else{
                                tempstring = church_back_room_options_2;
                            }
                            switch(GetUserInput(tempstring,3)){
                            case 1:
                                //Gebetsbuchtext
                                printTextSmoothly(church_back_room_prayer_book);
                                printTextSmoothly(not_useful);
                                break;
                            case 2:
                                // Tagebuch
                                if(!church_notes_taken){
                                    printTextSmoothly(church_back_room_notes);

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
                                    stay_in_churchbackroom = false;
                                }

                                break;
                            case 3:
                                stay_in_churchbackroom = false;
                                break;
                            }
                        }
                        stay_in_churchbackroom = true;
                    }
                    break;
                case 4:
                    stay_in_church = false;
                    break;
                }
            }
            stay_in_church = true;
            break;
        case 2:
            //Mensa
            printTextSmoothly(mensa_intro);
            while(stay_in_mensa){

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
                    printTextSmoothly(p7_intro);
                    while(talk_with_p7){
                        tempstring = game ->peoplelist[6].GetDialogOptions();

                        switch (GetUserInput(tempstring,3)) {
                        case 1:
                            printTextSmoothly(game ->peoplelist[6].GetAnswer(1));

                            if(!game->inv.CheckIfElementIsInList("Teller mit Schnitzel und ein kleines Dessert")){
                                //Essen dem Inventar hinzufuegen
                                inventarelement food;
                                food.name = "Teller mit Schnitzel und ein kleines Dessert";
                                food.beweisstueck = 0;
                                food.typ = food_1;
                                game->inv.Add(food);
                            }
                            else{
                                if(game->peoplelist[6].GetCounter() < 3){
                                    printTextSmoothly(food_in_inventar);
                                }
                            }
                            break;
                        case 2:
                            printTextSmoothly(game ->peoplelist[6].GetAnswer(2));
                            break;
                        case 3:
                            talk_with_p7 = false;
                            break;
                        }
                    }
                    talk_with_p7 = true;
                    break;
                case 2:
                    //Mit P3 Sprechen (Hr. Müller)
                    printTextSmoothly(p3_intro);
                    while(talk_with_p3){
                        tempstring = game->peoplelist[2].GetDialogOptions();
                        switch (GetUserInput(tempstring,3)) {
                        case 1:
                            printTextSmoothly(game->peoplelist[2].GetAnswer(1));
                            break;
                        case 2:
                            printTextSmoothly(game->peoplelist[2].GetAnswer(2));
                            break;
                        case 3:
                            talk_with_p3 = false;
                            break;
                        }
                    }
                    talk_with_p3 = true;
                    break;
                case 3:
                    //Wenn man bevor man mit dem Sheriff geredet hat,
                    //In der Mensa ist, so sind hier nur 2 Personen
                    //Später sind es 3, da der Täter auch in der Mensa sitzt
                    if(!activatedgame)
                    {
                        stay_in_mensa = false;
                    }
                    else{
                        //Mit P2 Sprechen
                        printTextSmoothly(p2_intro);
                        while(talk_with_p2){
                            tempstring = game->peoplelist[1].GetDialogOptions();
                            switch(GetUserInput(tempstring,3)){
                            case 1:
                                printTextSmoothly(game ->peoplelist[1].GetAnswer(1));
                                break;
                            case 2:
                                printTextSmoothly(game->peoplelist[1].GetAnswer(2));
                                if(game->peoplelist[1].GetCounter() < 3){
                                    knowlegde_of_hiddenroom = true;
                                }
                                break;
                            case 3:
                                talk_with_p2 = false;
                                break;
                            }
                        }
                        talk_with_p2 = true;
                    }
                    break;
                case 4:
                    stay_in_mensa = false;
                }
            }
            stay_in_mensa = true;
            break;
        case 3:
            //Tatort
            printTextSmoothly(crime_scene_intro);
            while(stay_in_crime_scene){
                switch(GetUserInput(crime_scene_options,3)){
                case 1:
                    //Mit dem Sheriff (P6) sprechen
                    printTextSmoothly(p6_intro);
                    while(talk_with_p6){
                        tempstring = game->peoplelist[5].GetDialogOptions();

                        switch(GetUserInput(tempstring,3)){
                        case 1:
                            if(!activatedgame){
                                //Spiel starten und den Auftrag offiziell annehmen
                                printTextSmoothly(game->peoplelist[5].GetAnswer(1,false));

                                //Texte werden neu gesetzt
                                set = 2;
                                activatedgame = true;
                                SetDialogText(set, game);

                                printXEmptyLines(2);
                                printTextSmoothly(mission_accepted);
                                printXEmptyLines(2);

                            }
                            else{
                                //Spiel "beenden" und zur Anklage einer Person kommen
                                //Der Ort "Gericht" wird dadurch freigeschaltet und man bekommt einen Schlüssel
                                printTextSmoothly(game->peoplelist[5].GetAnswer(1,false));
                                enable_court = true;
                                if(!game->inv.CheckIfElementIsInList("Schluessel zum Gericht")){
                                    //Schluessel zum Gericht hinzufuegen
                                    inventarelement court_key;
                                    court_key.beweisstueck = 0;
                                    court_key.name = "Schluessel zum Gericht";
                                    court_key.typ = key;
                                    game->inv.Add(court_key);
                                }
                            }
                            break;
                        case 2:
                            printTextSmoothly(game->peoplelist[5].GetAnswer(2,false));
                            break;
                        case 3:
                            //Gespräch verlassen
                            talk_with_p6 = false;
                        }
                    }
                    talk_with_p6 = 6;
                    break;
                case 2:
                    //Leiche anschauen
                    printTextSmoothly(watch_stiff);
                    break;
                case 3:
                    //Tatort verlassen
                    stay_in_crime_scene = false;

                    break;
                }
            }
            stay_in_crime_scene = true;
            break;
        case 4:
            //Aufenthaltsraum
            printTextSmoothly(common_room_intro);
            while(stay_in_common_room){
                switch (GetUserInput(common_room_options,3)) {
                case 1:
                    //Mit P4 sprechen
                    printTextSmoothly(p4_intro);
                    while(talk_with_p4){
                        tempstring = game->peoplelist[3].GetDialogOptions();
                        switch(GetUserInput(tempstring,3)){
                        case 1:
                            //Bei den Mathehausaufgaben helfen
                            if(!activatedgame){
                                printTextSmoothly(game->peoplelist[3].GetAnswer(1));
                                break;
                            }

                            if(!help_with_homework)
                            {
                                tempstring = game ->peoplelist[3].GetAnswer(1) + "\n" + enter_solution;
                                help_with_homework = true;

                                if(GetUserInput(tempstring,999,-999) == -16){
                                    printTextSmoothly(thanks_for_homework);
                                    if(!game->inv.CheckIfElementIsInList("Unbekannter Schluessel")){
                                        inventarelement barn_key;
                                        barn_key.beweisstueck = 0;
                                        barn_key.name = "Unbekannter Schluessel";
                                        barn_key.typ = key;
                                        game->inv.Add(barn_key);
                                        game ->peoplelist[3].SetDialogOptions(p4_set_3_options);

                                        //Nur String 1 aendert sich
                                        game ->peoplelist[3].SetDialog(p4_set_3_str_1,p4_set_2_str_2,p4_set_2_str_3);

                                    }
                                }
                                else{
                                    printTextSmoothly(wrong_solution);
                                    game ->peoplelist[3].SetDialogOptions(p4_set_3_options);

                                    //Nur String 1 aendert sich
                                    game ->peoplelist[3].SetDialog(p4_set_4_str_1,p4_set_2_str_2,p4_set_2_str_3);
                                }
                            }
                            else{
                                //Rätsel nicht mehr verfügbar
                                printTextSmoothly(game->peoplelist[3].GetAnswer(1));
                            }

                            break;
                        case 2:
                            printTextSmoothly(game->peoplelist[3].GetAnswer(2));
                            break;
                        case 3:
                            //Gespräch beenden
                            talk_with_p4=false;
                            break;
                        }
                    }
                    talk_with_p4 = true;
                    break;
                case 2:
                    //Mit P5 sprechen
                    printTextSmoothly(p5_intro);
                    while(talk_with_p5){
                        tempstring = game->peoplelist[4].GetDialogOptions();

                        switch(GetUserInput(tempstring,3)){
                        case 1:
                            printTextSmoothly(game->peoplelist[4].GetAnswer(1));
                            break;
                        case 2:
                            printTextSmoothly(game->peoplelist[4].GetAnswer(2));
                            break;
                        case 3:
                            //Gespräch beenden
                            talk_with_p5=false;
                            break;
                        }
                    }
                    talk_with_p5 = true;
                case 3:
                    //Raum verlassen
                    stay_in_common_room = false;
                    break;
                }
            }
            stay_in_common_room = true;
            break;
        case 5:
            //Scheune

            printTextSmoothly(barn_intro);
            while(stay_in_barn){
                if(!knowlegde_of_hiddenroom){
                    printTextSmoothly(easter_egg_str_1);
                    Sleep(5000);
                    printXEmptyLines(1);
                    printTextSmoothly(easter_egg_str_2);
                    Sleep(5000);
                    printTextSmoothly(easter_egg_str_3);
                    printTextSmoothly(easter_egg_str_4);
                }
                else{

                    printTextSmoothly(barn_hay_action);
                    if(game->inv.CheckIfElementIsInList("Unbekannter Schluessel"))
                    {
                        if(!hiddenroom_open){
                            game->inv.Delete("Unbekannter Schluessel");
                            printTextSmoothly(hiddenroom_door_opening);
                            hiddenroom_open = true;
                        }
                        printTextSmoothly(hiddenroom_entry);
                        while(stay_in_hiddenroom){
                            if(!hiddenroom_notes_taken){
                                printTextSmoothly(hiddenroom_notes_intro);
                                inventarelement hidden_room_notes;
                                hidden_room_notes.beweisstueck = 2;
                                hidden_room_notes.name = "Schuldscheine aus der Scheune";
                                hidden_room_notes.typ = beweisstueck;
                                game->inv.Add(hidden_room_notes);
                                hiddenroom_notes_taken = true;
                            }
                            else{
                            printTextSmoothly(hiddenroom_intro_2);
                            }
                            stay_in_hiddenroom = false;
                        }
                    }
                    else{
                        printTextSmoothly(no_key);
                    }
                }

                if(GetUserInput( barn_otpions,1) == 1){
                    stay_in_barn = false;
                }
            }
            stay_in_barn = true;
            break;

        case 6:
            //Friedhof
            printTextSmoothly(cemetery_intro);
            while(stay_in_cemetery){
                if(GetUserInput(cemetery_options,1) ==1){
                    stay_in_cemetery = false;
                }
            }
            stay_in_cemetery = true;

            break;
        case 7:
            //Gerichtsgebäude -> du willst das Rätsel lösen

            if(game->inv.CheckIfElementIsInList("Schluessel zum Gericht")){
                printTextSmoothly(open_gericht);
                game->inv.Delete("Schluessel zum Gericht");
                printTextSmoothly(final_intro);
                Sleep(2000);
                ready_for_final_question = true;
            }
            else{
                printTextSmoothly("Du hast keinen Schluessel hierfuer");
            }
            break;
        }
        cleanConsole();
    }
}

void Ask(struct data* game)
{
    bool lose = false;
    int element_number;
    std::string tempstring = "";

    printTextSmoothly(final_intro_part_2);
    printXEmptyLines(1);
    printTextSmoothly(choose_person);

    //Personen auflisten
    for(int i=0;i<7;i++){
        tempstring += std::to_string(i) + ". " + game ->peoplelist[i].GetName() + "\n";
    }

    //
    int personnumber = GetUserInput(tempstring,6,0);
    cleanConsole();

    tempstring = "Ich klage hiermit " + game ->peoplelist[personnumber].GetName() + " an und habe dafuer folgende Beweise";
    printTextSmoothly(tempstring);
    printXEmptyLines(1);
    bool choose_inventar = true;
    int counter = 0;
    bool not_done = true;

    while(not_done){
        printTextSmoothly(final_intro_part_3);

        switch(GetUserInput(choose_inventar_intro,2)){
        case 1:
            choose_inventar = true;
            while(choose_inventar){
                if(game->inv.CheckIfEmpty()){
                    printTextSmoothly(empty_inventar);
                    not_done = false;
                    break;
                }
                else{
                    printXEmptyLines(1);
                    std::string choose_proof = "Was moechtest du als Beweis vorlegen\n" + game->inv.ListAll() + std::to_string(game->inv.count) + ". Um zurueck zur Uebersicht zu gelangen";

                    element_number = GetUserInput(choose_proof,game->inv.count,0);
                    if(element_number == game->inv.count){
                      choose_inventar = false;
                      break;
                    };
                    int priority = game ->inv.GetPriorityOfListElement(element_number);
                    if( priority < 0){
                        printTextSmoothly(game->inv.Liste[element_number].name);
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
            not_done = false;
            break;
        }
    }

    if(lose){
        printSpecialText(lose_msg);
        printXEmptyLines(2);
        printTextSmoothly(lose_declaration_1);
    }
    else if(game ->peoplelist[personnumber].GetWerwolfStatus() && counter >=2 && !lose){
        printSpecialText(win_msg);
        printXEmptyLines(2);
        printTextSmoothly(win_explanation);
    }
    else{
        printSpecialText(lose_msg);
        printXEmptyLines(2);
        printTextSmoothly(lose_declaration_2);
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
    printTextSmoothly("Das Spiel wird sich in 60 Sekunden beenden"); // Da freut er sich :D #Stefan //Nicht nur der Stefan #Alex
    Sleep(60000);
    cleanConsole();
    printSpecialText("Das Spiel wurde erfolgreich beendet");
    Sleep(1000);

    return 0;
}

