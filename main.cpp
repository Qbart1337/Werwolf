#include <iostream>
#include <person.hpp>
#include <room.hpp>
#include <string>
#include <stdlib.h>
#include <Windows.h>
#include <printfunctions.cpp>
#include <textstrings.cpp>

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


CleanConsole() um das ganze hübscher zu machen
Leave Messages zu Räumen und teils auch Gesprächen
*/

// @Alex_
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
            print("Inventar voll, Element konnte nicht hinzugefügt werden");
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
    void ListAll(){
        for(int i=0;i<=count;i++){
            cout << i+1 << " "<< Liste[i].name <<endl;
        }
    }
};


struct data
{
    person peoplelist[7];
    inventar inventar_;
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

void SetDialog(int set, struct data* z)
{
    switch(set){
    case 1:
        z ->peoplelist[0].SetDialogOptions("");
        z ->peoplelist[0].SetDialog("Ich war mit einer Freundin einkauen", "Ich habe Anna gesehen", "Nerv mich nicht!");
        z ->peoplelist[1].SetDialogOptions("");
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


void Play(struct data* game)
{
    int set = 2; // TODO: später auf set = 1 setzen, zu Testzwecken schon Set = 2
    bool activatedgame = false;
    bool knowlegdeOfHiddenRoom = false;
    bool enableGericht = false;
    bool takenChurchKey = false;
    bool church_back_room_door = false;
    bool notes_taken = false;
    bool helpwithhomework = false;

    // Einführung
    printXEmptyLines(2);
    printTextSmoothly(introduction);

    printXEmptyLines(2);

    SetDialog(set,game);

    bool ready_for_final_question = false;
    while(!ready_for_final_question)
    {
        bool stayinchurch = true;
        bool stayinmensa = true;
        bool stayintatort = true;
        bool stayinaufenthaltsraum = true;
        bool stayinscheune = true;
        bool stayinfriedhof = true;
        bool stayinchurchbackroom = true;
        bool talkWithP1 = true;
        bool talkWithP2 = true;
        bool talkWithP3 = true;
        bool talkWithP4 = true;
        bool talkWithP5 = true;
        bool talkWithP6 = true;
        bool talkWithP7 = true;
        bool talkWithKoch = true;

        print("Du bist auf dem Marktplatz, wohin willst du gehen?");
        print("1.Kirche \n2.Mensa \n3.Tatort \n4.Aufenthaltsraum \n5.Scheune \n6.Friedhof");
        //TODO: Auslagern
        //falls das Bool "erlaubeGericht" freigeschaltet wurde, wird hier auch der Raum 7 "Gerichtsgebäude" angeboten, da man einen Schlüssel bekommt
        if(enableGericht){
            print("7.Gerichtsgebäude");
        }
        int roomnumber;
        cin >> roomnumber;
        //cleanconsole();
        switch(roomnumber){
        case 1:
            print(church_intro);

            while(stayinchurch){
                print(church_options);
                int interactionnumber;
                cin >> interactionnumber;
                switch(interactionnumber){
                case 1:
                    //ToDo Anpassen
                    while(talkWithP1){
                        print(game->peoplelist[0].GetDialogOptions());
                        int interactnmb;
                        cin >> interactnmb;
                        switch(interactnmb){
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
                        //Sollte man hier hingehen bevor man beim Sheriff war, so findet man den Täter dort und er liefert starke Indizien für seine Tat
                    }
                    else{
                        if(!takenChurchKey){
                            print(confessional_intro);
                            print(confessional_options);
                            int action_numb;
                            cin>>action_numb;
                            if(action_numb = 1 && !takenChurchKey)
                            {
                                inventarelement church_key;
                                church_key.name = "Kirchenschluessel";
                                church_key.beweisstueck = 0;
                                church_key.typ = key;
                                game ->inventar_.Add(church_key);
                                takenChurchKey = true;

                            }
                        }
                        else{
                            print(confessional_intro_2);
                        }

                    }
                    break;
                case 3:
                    stayinchurchbackroom = true;

                    if(church_back_room_door == false){
                        if(game ->inventar_.CheckIfElementIsInList("Kirchenschluessel"))
                        {
                            game ->inventar_.Delete("Kirchenschluessel");
                            church_back_room_door = true;
                        }
                        else{
                            print("Du hast leider keinen passenden Schlüssel dabei");
                        }
                    }
                    if(church_back_room_door)
                    {
                        while(stayinchurchbackroom){

                            print(church_back_room_intro);
                            if(!notes_taken){
                                print(church_back_room_options);
                            }
                            else{
                                //TODO
                            }
                            int interactnumb;
                            cin >> interactnumb;
                            //TODO: Bool notes_taken und zweiter options string für den Raum, damit falls die Notes mitgenommen wurden es die Option nicht mehr gibt
                            switch(interactnumb){
                            case 1: //Gebetsbuchtext
                                break;
                            case 2: // Tagebuch
                                if(!notes_taken){
                                    print(church_back_room_notes);
                                    print("Du hast folgende Optionen: \n1. Mitnehmen \n2. Liegen lassen");
                                    int interactnumb_2;
                                    cin >> interactnumb_2;
                                    if(interactnumb_2 = 1){
                                        inventarelement tagebuch;
                                        tagebuch.name = "Tagebuch des Pfarrers";
                                        tagebuch.typ = beweisstueck;
                                        tagebuch.beweisstueck = -1;
                                        notes_taken = true;
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
            print(mensa_intro);
            while(stayinmensa){

                if(!activatedgame){                    
                    print(mensa_options_1);
                }
                else{                    
                    print(mensa_options_2);
                }

                int interactionnumber;
                cin >> interactionnumber;
                switch (interactionnumber) {
                case 1:

                    while(talkWithP7){
                        print(game ->peoplelist[6].GetDialogOptions());

                        int interactnmb;
                        cin >> interactnmb;
                        inventarelement food;
                        switch (interactnmb) {
                        case 1:
                            print(game ->peoplelist[6].GetAnswer(1));
                            food.name = "Teller mit Schnitzel und ein kleines Dessert";
                            food.beweisstueck = 0;
                            food.typ = food_1;
                            game->inventar_.Add(food);

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
                    while(talkWithP3){
                        print(game->peoplelist[2].GetDialogOptions());
                        int interactnmb;
                        cin >> interactnmb;
                        switch (interactnmb) {
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
                    if(!activatedgame)
                    {
                        stayinmensa = false;
                    }
                    else{
                        while(talkWithP2){
                            print(game->peoplelist[1].GetDialogOptions());
                            int interactnmb;
                            cin >> interactnmb;
                            switch(interactnmb){
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
            print("Du betrittst den Tatort, in diesem Raum befindet sich eine Leiche und der Sheriff");
            print(crime_scene_intro);

            while(stayintatort){
                print(crime_scene_options);
                int interactionnumber;
                cin >> interactionnumber;
                switch(interactionnumber){
                case 1:
                    while(talkWithP6){
                        print(game->peoplelist[5].GetDialogOptions());

                        cin >> interactionnumber;
                        switch(interactionnumber){
                        case 1:
                            if(!activatedgame){
                                print(game->peoplelist[5].GetAnswer(1));
                                //Mission angenommen, spiel wird richtig gestartet
                                set = 2;
                                activatedgame = true;
                                SetDialog(set, game);
                            }
                            else{
                                print(game->peoplelist[5].GetAnswer(1));
                                enableGericht = true;
                                inventarelement gerichtskey;
                                gerichtskey.beweisstueck = 0;
                                gerichtskey.name = "Schluessel zum Gericht";
                                gerichtskey.typ = key;
                                game->inventar_.Add(gerichtskey);
                            }
                            break;
                        case 2:
                            print(game->peoplelist[5].GetAnswer(2));
                            break;
                        case 3:
                            talkWithP6 = false;
                        }
                    }
                    break;
                case 2:
                    print(watch_stiff);
                    break;
                case 3:
                    stayintatort = false;
                    print("Du verlässt den Tatort");
                    break;
                }
            }
            break;
        case 4:
            print(common_room_intro);
            while(stayinaufenthaltsraum){
                print(common_room_options);
                int interactionsnumber;
                cin >> interactionsnumber;
                switch (interactionsnumber) {
                case 1:
                    while(talkWithP4){
                        print(game->peoplelist[3].GetDialogOptions());
                        int interactnmb;
                        cin >> interactnmb;
                        switch(interactnmb){
                        case 1:
                            print(game->peoplelist[3].GetAnswer(1));
                            print("Lösung eintippen");
                            int lsg;
                            cin >> lsg;
                            if(lsg == -16){
                                print("Das sieht gut aus, ich danke dir für deine Hilfe. \nIch möchte dir dafür diesen Schluessel geben, den ich heute morgen im Wald gefunden habe. Ich weiß zwar nicht zu welcher Tür er passt, aber vielleicht findest du es ja heraus.");
                                inventarelement scheunenkey;
                                scheunenkey.beweisstueck = 0;
                                scheunenkey.name = "Unbekannter Schluessel";
                                scheunenkey.typ = key;
                                game->inventar_.Add(scheunenkey);
                                //game ->peoplelist[3].SetDialogOptions();
                                //game ->peoplelist[3].SetDialog();
                                //TODO: Neue Texte schreiben
                            }
                            else{
                                //game ->peoplelist[3].SetDialogOptions();
                                //game ->peoplelist[3].SetDialog();
                            }
                            //Lösungsmöglichkeiten implentieren
                            break;
                        case 2:
                            print(game->peoplelist[3].GetAnswer(2));
                            break;
                        case 3:
                            talkWithP4;
                            break;
                        }
                    }
                    break;
                case 2:
                    while(talkWithP5){
                        game->peoplelist[4].GetDialogOptions();
                        int interactnmb;
                        cin >> interactnmb;
                        switch(interactnmb){
                        case 1:
                            game->peoplelist[4].GetAnswer(1);
                            break;
                        case 2:
                            game->peoplelist[4].GetAnswer(2);
                            break;
                        case 3:
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
            print("Du betrittst die Scheune");
            while(stayinscheune){
                if(!knowlegdeOfHiddenRoom){
                    printTextSmoothly("Eine nackte Frau kommt auf dich zu und fragt dich woher ploetzlich das Heu kommt");
                    Sleep(5000);
                    printXEmptyLines(1);
                    printTextSmoothly("Du reibst dir verwundert die Augen und merkst, dass du das nur getraeumt hast");
                    Sleep(5000);
                    printTextSmoothly("In der Scheune siehst du ausser viel Heu nichts interessantes");
                    printTextSmoothly("Du kannst diesen Raum nur wieder verlassen, druecke dafür die 1");
                }
                else{
                    print("Du schiebst das Heu in einer Ecke zur Seite und findest eine versteckte Tür");
                    if(game->inventar_.CheckIfElementIsInList("Unbekannter Schluessel"))//Schlüssel
                    {
                        game->inventar_.Delete("Unbekannter Schluessel");

                        //TODO
                        //Hinweis in dem Raum
                    }
                    else{
                        print("Leider hast du keinen passenden Schlüssel für diesen Raum");
                    }
                }
                int interactionnumber;
                cin >> interactionnumber;
                if(interactionnumber == 1){
                    stayinscheune = false;
                }
            }
            break;

        case 6:
            while(stayinfriedhof){
                print("An einigen Gräbern liegen Blumen, an manchen mehr an manchen weniger");
                print("Hier kannst du nichts machen");
                print("Drücke die 1 um den Friedhof wieder zu verlassen");
                int interactionnumber;
                cin >> interactionnumber;
                if(interactionnumber ==1){
                    stayinfriedhof = false;
                }
            }

            break;
        case 7:
            print(".... die Zeit bis zum start der Verhandlung vergeht....");
            //Gerichtsgebäude -> du willst das Rätsel lösen
            ready_for_final_question = true;
            break;

        }
        system("cls");
    }
}

void Ask(struct data* game)
{
    bool lose = false;

    print("Alle haben sich im Gericht versammelt, der Dorfälteste ruft dich nach vorne und erklärt, dass du nun deinen Hauptverdächtigen anklagen wirst und eindeutige Beweise vorbringen wirst");
    printXEmptyLines(1);
    print("Wen möchtest du anklagen");
    for(int i=0;i<5;i++){
        game ->peoplelist[i].GetName();
    }
    int personnumber;
    cin >> personnumber;
    //cleanconsole();
    cout << "Ich klage hiermit " << game ->peoplelist[personnumber].GetName() << " an und habe dafür folgende Beweiese" << endl;

    printXEmptyLines(1);
    bool chooseinventar = true;
    bool choosemessage = true;
    int counter = 0;
    bool notdone = true;

    while(notdone){
        print("Du hast die Möglichkeit Gegenstände aus deinem Inventar als Beweise vorzulegen oder Aussagen zu zitieren");
        print("1. Gegenstand aus dem Inventar vorlegen\n2.Aussagen zitieren\n3.Beweisführung beenden und das Gericht entscheiden lassen");
        int numb;
        cin >> numb;
        switch(numb){
        case 1:
            while(chooseinventar){
                print("Du hast folgende Gegenstände und Dialoge in deinem Inventar gespeichert "
                      "\n0 um das Inventar zu verlassen");
                game ->inventar_.ListAll();
                //Auflisten
                printXEmptyLines(1);

                print("Was möchtest du als Beweis vorlegen");

                int actionnumber;
                cin >> actionnumber;
                if(actionnumber == 0){
                  chooseinventar = false;
                  break;
                };
                if(game ->inventar_.GetPriorityOfListElement(actionnumber) < 0){
                    lose=true;
                }
                /*
                else{
                    counter += game->inventar_.GetPriorityOfListElement(actionnumber);
                }*/

                game->inventar_.Delete(actionnumber);

                if(game->inventar_.GetPriorityOfListElement(actionnumber) !=0){//useful
                    counter++;
                //Gegenstand entfernen
                }
                else{
                print("Diesen Gegenstand ist kein aussagekräftiger Beweis");
                //Gegenstand auch entfernen
                }
                game->inventar_.Delete(actionnumber);
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
        print("Das Gericht ist umpört, dass du ohne Gründe in Privaträume des Pfarrers eingedrungen bist um an Beweise zu kommen. Dies entspricht nach Ansichten des Gerichts eines Amtsmissbrauchs. Du verlierst dadurch jegliche Glaubwürdigkeit und wirst selbst verurteilt.");
        msg = -1;
    }
    else if(game ->peoplelist[personnumber].GetWerwolfStatus() && counter >=2 && !lose){
        printSpecialText("Herzlichen Glückwunsch, du hast den Täter anhand von aussagekrätigen Beweisen überführt");
        msg = 1;
    }
    else{
        printSpecialText("Du hast das Spiel verloren, du hast entweder die falsche Person angeklagt oder zu wenig Beweise vorlegen können um das Gericht zu überzeugen");
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
    struct data gamedata;
    struct data *data_ptr = &gamedata;
    CreateGame(data_ptr);
    Play(data_ptr);
    Ask(data_ptr);

    cleanconsole();
    printSpecialText("Programm erfolgreich beendet");

    return 0;
}

