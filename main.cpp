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
        if(count >=5)
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
    //TODO: Muss String zurückliefern
    void ListAll(){
        for(int i=0;i<=count;i++){
            cout << i+1 << " "<< Liste[i].name <<endl;
        }
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
        z ->peoplelist[0].SetDialogOptions("Du weißt doch.. du musst zum Tatort. Trödle nicht rum");
        z ->peoplelist[0].SetDialog("Ich war mit einer Freundin einkauen", "Ich habe Anna gesehen", "Nerv mich nicht!");
        z ->peoplelist[1].SetDialogOptions("Ich glaube du wirst erwartet");
        z ->peoplelist[1].SetDialog("Ich war mit einem Freund im Kino", "Nein", "Nerv mich nicht!");
        z ->peoplelist[1].SetWerwolf();
        z ->peoplelist[2].SetDialogOptions("");
        z ->peoplelist[2].SetDialog("Ich habe mir einen Film angeschaut", "Ich habe Anne gesehen", "Nerv mich nicht!");
        z ->peoplelist[3].SetDialogOptions("");
        z ->peoplelist[3].SetDialog("Ich habe mir einen Film angeschaut", "Ich habe Anja gesehen", "Nerv mich nicht!");
        z ->peoplelist[4].SetDialogOptions("");
        z ->peoplelist[4].SetDialog("Ich habe mir ein Kleid gekauft", "Ich habe Anne gesehen", "Nerv mich nicht!");        
        z ->peoplelist[5].SetDialogOptions("");
        z ->peoplelist[5].SetDialog("###", "###", "###");
        z ->peoplelist[6].SetDialogOptions("");
        z ->peoplelist[6].SetDialog("###", "###", "###");
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
int GetUserInput(std::string options, int maxallowedNumber, int minnumber=1){
    //print("UserInput Methode wird aufgerufen");
    printXEmptyLines(2);
    bool correct_input = false;
    int input;

    while (!correct_input) {
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
        if(input >= minnumber && input <= maxallowedNumber){
            correct_input = true;
        }
        else{
            cleanconsole();
            print("Bitte gebe eine gueltige Zahl ein!");
            printXEmptyLines(1);
        }

    }

    //print("leave");
    //Sleep(5000);
    return input;
}

void Play(struct data* game)
{
    int set = 2; // TODO: später auf set = 1 setzen, zu Testzwecken schon Set = 2
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
        }

        //Switch von der Markplatzmitte
        switch(GetUserInput(tempstring,6)){
        case 1:
            //Kirche
            cleanconsole();
            print(church_intro);
            while(stayinchurch){
                //print(church_options);
                switch(GetUserInput(church_options,4)){
                case 1:
                    //Mit P1 sprechen
                    //ToDo Anpassen
                    while(talkWithP1){
                        cleanconsole();
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
                    break;
                case 2:
                    //Zum Beichtstuhl gehen
                    if(activatedgame){
                        print("test");
                        //TODO: Set 1 Strings bei P2 hinterlegen mit belastenden Aussagen
                        // Werwolf
                        //Sollte man hier hingehen bevor man beim Sheriff war, so findet man den Täter dort und er liefert starke Indizien fuer seine Tat
                    }
                    else{
                        if(!takenChurchKey){
                            print(confessional_intro);
                            print(confessional_options);
                            int action_numb;
                            cin>>action_numb;
                            //TODO
                            if(action_numb = 1 && !takenChurchKey)
                            {
                                inventarelement church_key;
                                church_key.name = "Kirchenschluessel";
                                church_key.beweisstueck = 0;
                                church_key.typ = key;
                                game ->inv.Add(church_key);
                                takenChurchKey = true;
                            }
                        }
                        else{
                            print(confessional_intro_2);
                        }

                    }
                    break;
                case 3:
                    //Zur Tür hinter dem Altar gehen
                    stayinchurchbackroom = true;

                    if(church_back_room_door == false){
                        if(game ->inv.CheckIfElementIsInList("Kirchenschluessel"))
                        {
                            game ->inv.Delete("Kirchenschluessel");
                            church_back_room_door = true;
                        }
                        else{
                            std::string no_key = "Du hast leider keinen passenden Schlüssel dabei";
                            print(no_key);
                        }
                    }
                    if(church_back_room_door)
                    {
                        while(stayinchurchbackroom){

                            print(church_back_room_intro);
                            if(!church_notes_taken){
                                print(church_back_room_options);
                            }
                            else{
                                //TODO
                                //print(church_back_room_options_2);
                            }
                            int interactnumb;
                            cin >> interactnumb;
                            //TODO: Bool notes_taken und zweiter options string fuer den Raum, damit falls die Notes mitgenommen wurden es die Option nicht mehr gibt
                            switch(interactnumb){
                            case 1: //Gebetsbuchtext
                                print(church_back_room_prayer_book);
                                print(not_useful);
                                break;
                            case 2: // Tagebuch
                                if(!church_notes_taken){
                                    print(church_back_room_notes);

                                    //TODO
                                    int interactnumb_2;
                                    cin >> interactnumb_2;
                                    if(GetUserInput(note_options,2) == 1){
                                        inventarelement tagebuch;
                                        tagebuch.name = "Tagebuch des Pfarrers";
                                        tagebuch.typ = beweisstueck;
                                        tagebuch.beweisstueck = -1;
                                        game->inv.Add(tagebuch);
                                        church_notes_taken = true;
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
                    }
                    break;
                }
            }
            break;
        case 2:
            //Mensa
            print(mensa_intro);
            while(stayinmensa){

                //Wenn das Spiel noch nicht aktiviert ist, befindet sich der Täter noch nicht in der Mensa
                if(!activatedgame){
                    tempstring = mensa_options_1;
                }
                else{
                    tempstring = mensa_options_2;
                }

                switch (GetUserInput(tempstring,4)) {
                case 1:
                    //Mit P7 sprechen (Küchenchef)
                    while(talkWithP7){
                        tempstring = game ->peoplelist[6].GetDialogOptions();

                        inventarelement food;
                        switch (GetUserInput(tempstring,3)) {
                        case 1:
                            print(game ->peoplelist[6].GetAnswer(1));
                            food.name = "Teller mit Schnitzel und ein kleines Dessert";
                            food.beweisstueck = 0;
                            food.typ = food_1;
                            game->inv.Add(food);
                            break;
                        case 2:
                            print(game ->peoplelist[6].GetAnswer(2));
                            break;
                        case 3:
                            talkWithP7 = false;
                            break;
                        }
                    }
                    break;
                case 2:
                    //Mit P3 Sprechen (Hr. Müller)
                    while(talkWithP3){
                        tempstring = game->peoplelist[2].GetDialogOptions();
                        switch (GetUserInput(tempstring,3)) {
                        case 1:
                            print(game->peoplelist[2].GetAnswer(1));
                            //TODO: Schauen ob im Inventar Essen ist und es ggf. auflisten / Entfernen
                            break;
                        case 2:
                            print(game->peoplelist[2].GetAnswer(2));
                            break;
                        case 3:
                            talkWithP3 = false;
                            break;
                        }
                    }
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
                        while(talkWithP2){
                            //P2 Talk Loop
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
                    }
                    break;
                case 4:
                    stayinmensa = false;
                }
            }
            break;
        case 3:
            //Tatort
            print(crime_scene_intro);

            while(stayintatort){
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
                    break;
                case 2:
                    //Leiche anschauen
                    print(watch_stiff);
                    break;
                case 3:
                    //Tatort verlassen
                    stayintatort = false;
                    //TODO: Konsistenz?

                    print(leave_tatort);
                    break;
                }
            }
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
                            if(!helpwithhomework)
                            {
                                print(game->peoplelist[3].GetAnswer(1));

                                print(enter_solution);
                                int lsg;
                                cin >> lsg;
                                //TODO
                                if(lsg == -16){
                                    print(thanks_for_homework);
                                    inventarelement scheunenkey;
                                    scheunenkey.beweisstueck = 0;
                                    scheunenkey.name = "Unbekannter Schluessel";
                                    scheunenkey.typ = key;
                                    game->inv.Add(scheunenkey);
                                    //game ->peoplelist[3].SetDialogOptions();
                                    //game ->peoplelist[3].SetDialog();
                                    //TODO: Neue Texte schreiben
                                }
                                else{

                                    print(wrong_solution);
                                    //game ->peoplelist[3].SetDialogOptions();
                                    //game ->peoplelist[3].SetDialog();
                                    //TODO: Neue Texte schreiben
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
                    break;
                case 2:
                    //Mit P5 sprechen
                    while(talkWithP5){
                        tempstring = game->peoplelist[4].GetDialogOptions();

                        switch(GetUserInput(tempstring,3)){
                        case 1:
                            game->peoplelist[4].GetAnswer(1);
                            break;
                        case 2:
                            game->peoplelist[4].GetAnswer(2);
                            break;
                        case 3:
                            //Gespräch beenden
                            talkWithP5=false;
                            break;
                        }
                    }
                case 3:
                    //Raum verlassen
                    stayinaufenthaltsraum = false;
                    break;
                }
            }
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
            break;

        case 6:
            //Friedhof
            while(stayinfriedhof){
                tempstring ="An einigen Gräbern liegen Blumen, an manchen mehr an manchen weniger\nHier kannst du nichts machen\nDrücke die 1 um den Friedhof wieder zu verlassen";
                if(GetUserInput(tempstring,1) ==1){
                    stayinfriedhof = false;
                }
            }

            break;
        case 7:
            print(final_intro);
            //Gerichtsgebäude -> du willst das Rätsel lösen
            ready_for_final_question = true;
            break;

        }
        cleanconsole();
    }
}

void Ask(struct data* game)
{
    int element_number;
    std::string tempstring;
    std::string temp;

    bool lose = false;
    print(final_intro_part_2);
    printXEmptyLines(1);
    print(choose_person);
    for(int i=0;i<7;i++){
        game ->peoplelist[i].GetName();
    }
    int personnumber;
    cin >> personnumber;
    cleanconsole();

    temp = "Ich klage hiermit " + game ->peoplelist[personnumber].GetName() + " an und habe dafuer folgende Beweise";
    print(temp);
    int actionnumber;


    printXEmptyLines(1);
    bool chooseinventar = true;
    bool choosemessage = true;
    int counter = 0;
    bool notdone = true;

    while(notdone){
        print(final_intro_part_3);

        switch(GetUserInput(choose_inventar_intro,3)){
        case 1:
            while(chooseinventar){

                print(inventar_stuff_intro);
                //tempstring = "0. Inventar verlassen" + game ->inv.ListAll() + endl + "\n" + "Was möchtest du als Beweis vorlegen";
                //game ->inv.ListAll();
                //Auflisten
                //printXEmptyLines(1);
                //std::string choose_proof = "Was möchtest du als Beweis vorlegen";
                //print(choose_proof);

                element_number = GetUserInput(tempstring,game->inv.count+1,0);
                if(element_number == 0){
                  chooseinventar = false;
                  break;
                };
                if(game ->inv.GetPriorityOfListElement(actionnumber) < 0){
                    lose=true;
                }
                /*
                else{
                    counter += game->inventar_.GetPriorityOfListElement(actionnumber);
                }*/

                game->inv.Delete(actionnumber);

                if(game->inv.GetPriorityOfListElement(actionnumber) !=0){//useful
                    counter++;
                //Gegenstand entfernen
                }
                else{
                print("Diesen Gegenstand ist kein aussagekräftiger Beweis");
                //Gegenstand auch entfernen
                }
                game->inv.Delete(actionnumber);
            }
            break;
        case 2:
            while(choosemessage){
            //MessageListe
            }
            break;
        case 3:
            notdone = false;
            break;
        }
    }
    int msg;
    if(lose){
        print("Das Gericht ist umpört, dass du ohne Gruende in Privaträume des Pfarrers eingedrungen bist um an Beweise zu kommen. Dies entspricht nach Ansichten des Gerichts eines Amtsmissbrauchs. Du verlierst dadurch jegliche Glaubwuerdigkeit und wirst selbst verurteilt.");
        msg = -1;
    }
    else if(game ->peoplelist[personnumber].GetWerwolfStatus() && counter >=2 && !lose){
        printSpecialText("Herzlichen Glueckwunsch, du hast den Täter anhand von aussagekrätigen Beweisen ueberfuehrt");
        msg = 1;
    }
    else{
        printSpecialText("Du hast das Spiel verloren, du hast entweder die falsche Person angeklagt oder zu wenig Beweise vorlegen können um das Gericht zu ueberzeugen");
        msg=-1;
    }

    if(msg = 1){
        printSpecialText("Du hast gewonnen");
    }
    if(msg = -1){
        printSpecialText("Du hast verloren");
    }
}

int main()
{
    // 15. Beta Stand
    struct data gamedata;
    struct data *data_ptr = &gamedata;
    CreateGame(data_ptr);
    Play(data_ptr);
    Ask(data_ptr);
    cleanconsole();
    printSpecialText("Das Spiel wurde erfolgreich beendet");

    return 0;
}

