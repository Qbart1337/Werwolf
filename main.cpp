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

*/

using namespace std;

class inventarelement{
public:
    string name;
    int beweisstueck; // 1 - Ja, 0 - Egal, -1 Spiel verloren
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
        z ->peoplelist[2].SetWerwolf();
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
        z ->peoplelist[6].SetDialogOptions(p6_set_2_options);
        z ->peoplelist[6].SetDialog(p7_set_2_options, p7_set_2_str_2, p7_set_2_str_3);
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
    // Einführung
    printXEmptyLines(2);
    printTextSmoothly(introduction);
    //printTextSmoothly(gamerules);
    printXEmptyLines(2);

    SetDialog(set,game);

    //printTextSmoothly(introduction);

    bool ready_for_final_question = false;
    while(!ready_for_final_question)
    {
        bool stayinchurch = true;
        bool stayinmensa = true;
        bool stayintatort = true;
        bool stayinaufenthaltsraum = true;
        bool stayinscheune = true;
        bool stayinfriedhof = true;
        bool talkWithP3 = true;
        bool talkWithKoch = true;

        print("Du bist auf dem Marktplatz, wohin willst du gehen?");
        print("1.Kirche \n2.Mensa \n3.Tatort \n4.Aufenthaltsraum \n5.Scheune \n6.Friedhof");
        //falls das Bool "erlaubeGericht" freigeschaltet wurde, wird hier auch der Raum 7 "Gerichtsgebäude" angeboten, da man einen Schlüssel bekommt
        if(enableGericht){
            print("7.Gerichtsgebäude");
        }
        int roomnumber;
        cin >> roomnumber;
        cleanconsole();
        switch(roomnumber){
        case 1:
            //Kirche
           // print("Du bist gerade in die Kirche gegangen");
            //print("In der Kirche brennen ein paar Kerzen für den Verstorbenen");
            print(church_intro);

            while(stayinchurch){
                //print("Du hast folgende Interaktionsmöglichkeiten:");
                //print("1. Mit dem Pfarrer sprechen\n2. Zum Beichstuhl gehen\n3. Zur Tür hinter dem Altar gehen");
                print(church_options);
                int interactionnumber;
                cin >> interactionnumber;
                switch(interactionnumber){
                case 1:
                    //ToDo Anpassen
                    print(game->peoplelist[0].GetDialogOptions());
                    //print("empty\n t \n t");
                    print(game->peoplelist[0].GetAnswer(1));
                    print(game->peoplelist[0].GetAnswer(2));
                    //Mit dem Pfarrer reden
                    break;
                case 2:
                    //Zum Beichtstuhl gehen
                    if(activatedgame){
                        print("test");
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
                                game ->inventar_.Add(church_key);
                                takenChurchKey = true;
                                //Add Schlüssel
                            }
                        }
                        else{
                            print(confessional_intro_2);
                        }
                        //print("Hier sind nur ein paar Staubfetzen und ein Schlüssel");
                    }
                    break;
                case 3:
                    //Tür hinter dem Altar
                    if(game ->inventar_.CheckIfElementIsInList("Kirchenschluessel")){ //game ->inventar.Check("Kirchen-Key")
                        print("Im 2ten Raum der Kirche");
                        // ToDo
                        // Raumlogik ergänzen
                        // enter room
                    }
                    else{
                        print("Du hast leider keinen passenden Schlüssel dabei");
                    }
                    break;
                }
            }
            break;
        case 2:
            print(mensa_intro);

            while(stayinmensa){
                //print("Du hast folgende Interaktionsmöglichkeiten: \n1. Zum Kuechenchef gehen \n.Zu P3 gehen");
                if(!activatedgame){
                    //print("3. Den Raum verlassen");
                    print(mensa_options_1);
                }
                else{
                    //print("3. Mit P2 sprechen \n4. Den Raum verlassen");
                    print(mensa_options_2);
                }

                int interactionnumber;
                cin >> interactionnumber;
                switch (interactionnumber) {
                case 1:
                    //print()
                    while(talkWithKoch){
                        print(game ->peoplelist[6].GetDialogOptions());
                        //print("1. Den Kuechenchef nach Essen fragen\n. Den Kuechenchef nach Desserts fragen \n3. Zurueck in den Raum gehen ");
                        int interactnmb;
                        cin >> interactnmb;
                        inventarelement food;
                        switch (interactnmb) {
                        case 1:
                            print(game ->peoplelist[6].GetAnswer(1));
                            food.name = "Teller mit Schnitzel und ein kleines Dessert";
                            food.beweisstueck = 0;
                            game->inventar_.Add(food);
                            //print("Der Kuechenchef gibt dir Bohnenauflauf");
                            //Add Inventar
                            break;
                        case 2:
                            print(game ->peoplelist[6].GetAnswer(2));
                            //print("Der Kuechenchef gibt dir eine Portion Eis");
                            //Add Inventar
                            break;
                        case 3:
                            talkWithKoch = false;
                            break;
                        }

                    }
                    break;
                case 2:
                    //Reden mit P3

                    while(talkWithP3){
                        print("Du hast dich zu P3 an den Tisch gesetzt");
                        print("Du hast folgende Interaktionsmöglichkeiten: \n1. Dein Essen essen \n2. Mit P3 sprechen \n3. Zurueck in den Raum gehen");
                        int interactnmb;
                        cin >> interactnmb;
                        switch (interactnmb) {
                        case 1:
                            //Schauen ob im Inventar Essen ist und es ggf. auflisten / Entfernen
                            break;
                        case 2:
                            //Talk with P3
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
                        //Reden mit P2
                        //P2 ist der Täter
                        //Verrät den Raum weil er den Schlüsssel weggeworfen hat
                        knowlegdeOfHiddenRoom = true;
                    }
                    break;
                case 4:
                    stayinmensa = false;
                }
            }
            break;
        case 3:
            cleanconsole();
            print("Du betrittst den Tatort, in diesem Raum befindet sich eine Leiche und der Sheriff");

            while(stayintatort){
                print("Du hast folgende Interaktionsmöglichkeiten: \n1. Mit dem Sheriff reden \n2. Die Leiche genauer anschauen \n3. Den Raum verlassen");
                int interactionnumber;
                cin >> interactionnumber;
                switch(interactionnumber){
                case 1:
                    //Mit Sheriff reden
                    print("Gestern Nacht wurde Herr Müller ermordet");
                    printXEmptyLines(1);
                    if(!activatedgame){
                        print("Du hast folgende Interaktionsmöglichkeiten: \n1. Ihm sagen, dass der Bürgermeister dich beauftragt hat den Fall zu lösen\n2. Dein Beileid bekunden und zurück in den Raum gehen");
                    }
                    else{
                        print("Du hast folgende Interaktionsmöglichkeiten: \n1. Ihm sagen, dass du genug Indizien hast um den Schuldigen anzuklagen\n2. Ihn nach Tipps für die Ermittlung fragen");
                    }

                    cin >> interactionnumber;
                    switch(interactionnumber){
                    case 1:
                        if(!activatedgame){
                            print("Der Sheriff übergibt dir einen Sheriffstern um dich als auserordentlicher Ermittler in dieser Sache zu kennzeichen und erteilt dir die Erlaubnis Nachforschungen anzustellen");
                            //game->inventar_.Add(); //Add Sheriffsstern
                            set = 2;
                            activatedgame = true;
                            SetDialog(set, game);
                        }
                        else{
                            print("Der Sheriff gibt dir den Schlüssel für das Gerichtsgebäude");
                            enableGericht = true;
                            //game->inventar_.Add(); // Add Gerichtsschlüssel
                        }
                        break;
                    case 2:
                        if(activatedgame){
                            print("Der Sheriff rät dir mit wirklich allen Personen im Dorf zu sprechen, vielleicht hat jemand ja etwas beobachtet");
                        }
                    }

                    break;
                case 2:
                    //Leiche anschauen
                    //Ggf. findet man hier einen Hinweis
                    break;
                case 3:
                    stayintatort = false;
                    print("Du verlässt den Tatort");
                    break;
                }
            }
            break;
        case 4:
            print("Du bist in den Aufenthaltsraum gegangen");
            while(stayinaufenthaltsraum){
                print("In diesem Raum sitzen P4 und P5 und machen Hausaufgaben");
                print("Du hast in diesem Raum folgende Interaktionsmöglichkeiten: \n1. Zu P4 gehen \n. Zu P5 gehen \n.6. Den Raum wieder verlassen");
                int interactionsnumber;
                cin >> interactionsnumber;
                switch (interactionsnumber) {
                case 1:
                    //P4
                    //* Spieler 4 bei den Hausaufgaben helfen
                    //Kleines Rätsel
                    //* Ja + richtige Antwort -> "Unbekannter Schlüssel"
                    // -> Schlüssel für den geheimen Raum in der Scheune

                    break;
                case 2:
                    //P5
                    break;
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
                    printTextSmoothly("Du reibst dir verwundert die Augen und merkst das du nur getraeumt hast");
                    Sleep(5000);
                    printTextSmoothly("In der Scheune siehst du ausser viel Heu nichts interessantes");
                    printTextSmoothly("Du kannst diesen Raum nur wieder verlassen, druecke dafür die 1");
                }
                else{
                    print("Du schiebst das Heu in einer Ecke zur Seite und findest eine versteckte Tür");
                    if(true)//Schlüssel
                    {
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
    cleanconsole();
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
                print("Du hast folgende Gegenstände und Dialoge wurden in deinem Inventar gespeichert \n0 um das Inventar zu verlassen");
                game ->inventar_.ListAll();
                //Auflisten
                printXEmptyLines(1);

                print("Welchen möchtest du als Beweis vorlegen");

                int actionnumber;
                cin >> actionnumber;
                if(actionnumber == 0){
                  chooseinventar = false;
                  break;
                };
                if(game ->inventar_.GetPriorityOfListElement(actionnumber) < 0){
                    lose=true;
                }
                else{
                    counter += game->inventar_.GetPriorityOfListElement(actionnumber);
                }
                game->inventar_.Delete(actionnumber);

                if(true){//useful
                counter++;
                //Gegenstand entfernen
                }
                else{
                print("Diesen Gegenstand ist kein aussagekräftiger Beweis");
                //Gegenstand auch entfernen
                }
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
    if(game ->peoplelist[personnumber].GetWerwolfStatus() && counter >=2){
        printSpecialText("Herzlichen Glückwunsch, du hast den Täter anhand von aussagekrätigen Beweisen überführt");
    }
    else{
        printSpecialText("Du hast das Spiel verloren, du hast entweder die falsche Person angeklagt oder zu wenig Beweise vorlegen können um das Gericht zu überzeugen");
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

