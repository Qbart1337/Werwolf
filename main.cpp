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
-Bewegung durch Räume bzw. Szenen basierend auf Textein- und ausgabe
-Interaktion mit Spielwelt, inkl. Zustandsänderung /z.B. Schalter, Türe, LP
-Einfache Inventarverwaltung z.B. Gegenstand aufnehmen, später benutzen
-Teilprozesse z.B. Unterhaltung/Dialog, Kampf, schrittweises Rätsel etc.


TODO:
Std::list -> Inventar // Inventar hat fest 3 Plätze
Bewegung und Verzweigung der Räume
Zustandsänderungen erhöhen ((Interatkion mit Inventar)
Kommentieren wer was gemacht hat

*/

using namespace std;
/*
enum inventartyp { Key, Sheriffsstern, Sonstiges, Notizen};

struct inventar{
    int count = 0;
    struct inventarelement Liste[5];
    bool Check(std::string name){
        if(count == 0){
            return false;
        }
        else{
            for(int i=0;i<count; i++){
                if(Liste[i].name == name){
                    return true;
                }
            }
            return false;
        }
    }

    void Add(inventarelement elem)
    {
        if(count >=4)
        {
            //Inventar voll
        }
        else{
            Liste[count] = elem;
            count++;
        }
    }
    void Delete(){
        ListAll();
        int deletenumber;
        cin >> deletenumber;
        if(count == deletenumber)
        {
            Liste[deletenumber] = null;
            count --;
        }
        else{
            for(deletenumber;deletenumber<count;deletenumber++){
                inventarelement tmp = Liste[deletenumber];
                Liste[deletenumber] = Liste[deletenumber+1];
                Liste[deletenumber+1] = tmp;
            }
            Liste[deletenumber] = null;
            count --;
        }
    }
    void ListAll(){
        for(int i=0;i<=count;i++){
            cout << i << " "<< Liste[i].name <<endl;
        }
    }

};
struct inventarelement{
    string name;
    inventartyp typ;
    bool beweisstueck;
};
*/
struct data
{
    person peoplelist[5];
    //inventar inventar_;
};

void CreateGame(struct data *z)
{
    cout << initialize_person_start << endl;
    person person_one;
    person person_two;
    person person_three;
    person person_four;
    person person_five;

    person_one.SetName("Anne");
    person_two.SetName("Anja");
    person_three.SetName("Antoine");
    person_four.SetName("Anton");
    person_five.SetName("Anna");

    //inventar inv;
    //z ->inventar = inv;

    z ->peoplelist[0] = person_one;
    z ->peoplelist[1] = person_two;
    z ->peoplelist[2] = person_three;
    z ->peoplelist[3] = person_four;
    z ->peoplelist[4] = person_five;
    cout << initialize_person_end << endl;

}

void SetDialog(int set, struct data* z)
{
    switch(set){
    case 1:
        z ->peoplelist[0].SetDialog("Ich war mit einer Freundin einkauen", "Ich habe Anna gesehen", "Nerv mich nicht!");
        z ->peoplelist[1].SetDialog("Ich war mit einem Freund im Kino", "Nein", "Nerv mich nicht!");
        z ->peoplelist[2].SetWerwolf();
        z ->peoplelist[2].SetDialog("Ich habe mir einen Film angeschaut", "Ich habe Anne gesehen", "Nerv mich nicht!");
        z ->peoplelist[3].SetDialog("Ich habe mir einen Film angeschaut", "Ich habe Anja gesehen", "Nerv mich nicht!");
        z ->peoplelist[4].SetDialog("Ich habe mir ein Kleid gekauft", "Ich habe Anne gesehen", "Nerv mich nicht!");
        break;
    case 2:
        z ->peoplelist[0].SetDialog("###", "###", "###");
        z ->peoplelist[1].SetDialog("###", "###", "###");
        z ->peoplelist[2].SetDialog("###", "###", "###");
        z ->peoplelist[3].SetDialog("###", "###", "###");
        z ->peoplelist[4].SetDialog("###", "###", "###");
        break;
    }
    cout << "SetDialoge Erfolgreich" << endl;
}


void Play(struct data* game)
{
    int set = 1;
    bool activatedgame = false;
    bool knowlegdeOfHiddenRoom = false;
    // Einführung
    printXEmptyLines(2);
    printTextSmoothly(gamerules);
    printXEmptyLines(2);

    SetDialog(set,game);

    printTextSmoothly(introduction);

    bool ready_for_final_question = false;
    while(!ready_for_final_question)
    {
        bool stayinchurch = true;
        bool stayinmensa = true;
        bool stayintatort = true;
        bool stayinaufenthaltsraum = true;
        bool stayinscheune = true;
        bool stayinfriedhof = true;
        print("Du bist auf dem Marktplatz, wohin willst du gehen?");
        print("1.Kirche \n2.Mensa \n3.Tatort \n4.Aufenthaltsraum \n5.Scheune\n6.Friedhof\n");
        //falls das Bool "erlaubeGericht" freigeschaltet wurde, wird hier auch der Raum 7 "Gerichtsgebäude" angeboten, da man einen Schlüssel bekommt
        int roomnumber;
        cin >> roomnumber;
        cleanconsole();
        switch(roomnumber){
        case 1:
            //Kirche
            print("Du bist gerade in die Kirche gegangen");
            print("In der Kirche brennen ein paar Kerzen für den Verstorbenen");
            while(stayinchurch){
                print("Du hast folgende Interaktionsmöglichkeiten:");
                print("1. Mit dem Pfarrer sprechen\n2. Zum Beichstuhl gehen\n3. Zur Tür hinter dem Altar gehen");
                int interactionnumber;
                cin >> interactionnumber;
                switch(interactionnumber){
                case 1:
                    //Mit dem Pfarrer reden
                    break;
                case 2:
                    //Zum Beichtstuhl gehen
                    //Sollte man hier hingehen bevor man beim Sheriff war, so findet man den Täter dort und er liefert starke Indizien für seine Tat
                    break;
                case 3:
                    //Tür hinter dem Altar
                    /*if(game ->inventar.Check("Kirchen-Key")){
                        // enter room
                    }
                    else{
                        print("Du hast leider keinen passenden Schlüssel dabei");
                    }*/
                    break;
                }
            }
            break;
        case 2:

            while(stayinmensa){
                int interactionnumber;
                cin >> interactionnumber;
                switch (interactionnumber) {
                case 1:

                    break;
                case 2:
                    break;
                case 3:
                    knowlegdeOfHiddenRoom = true;
                    break;
                }

            }
            //Mensa
            /*
             * Essen
             * Reden mit P1
             * Reden mit P2
             * -> Hat von einem versteckten Raum gehört den der getötete in der Scheune aufgesucht hat
             *
             * Küche
             *  -> P3 (Koch)
             */
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
                    print("Gestern Nacht wurde Herr Müller von einem Werwolf angegriffen und auf bösartige Art und Weiße getötet");
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
                            SetDialog(set, game);
                        }
                        else{
                            print("Der Sheriff gibt dir den Schlüssel für das Gerichtsgebäude");
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
                    //Ggf. findet man hier einen Hinweis
                    //Leiche anschauen
                    break;
                case 3:
                    stayintatort = false;
                    print("Du verlässt den Tatort");
                    break;
                }
            }
            break;
        case 4:

            while(stayinaufenthaltsraum){

            }
            //Aufenthaltsraum
            /*
             * Spieler 4 bei den Hausaufgaben helfen
             * Ja + richtige Antwort -> "Unbekannter Schlüssel"
             */
            break;
        case 5:

            while(stayinscheune){

            }
            //Scheune
            /*
             * Geheimer Raum nur bekannt wenn man die Info von P2 hat.
             */

            break;
        case 6:

            while(stayinfriedhof){

            }
            //Friedhof
            break;
        case 7:
            //Gerichtsgebäude -> du willst das Rätsel lösen
            ready_for_final_question = true;
            break;
        }


        system("cls");

    }


    // Spiel beginnt
    /*
    bool not_ready_for_final_question = true;
    while(not_ready_for_final_question)
    {
        cout << choose_room_intro << endl;
        cout << choose_werwolf_intro << endl;
        for(int j=0; j<5; j++)
        {
            cout << j << ": " <<game.roomlist[j].GetRoomeName() << endl;
        }
        cout << choose_room;
        int raumnummer;
        cin >> raumnummer;
        if(raumnummer == 5)
        {
            not_ready_for_final_question = false;
            break;
        }
        system("cls");

        string go_to_room = "Du bist in " + game.roomlist[raumnummer].GetRoomeName() + " gegangen";
        cout << go_to_room << endl;

        string people_in_room = "In diesem Raum ist: " + game.peoplelist[raumnummer].GetName();
        cout << people_in_room <<endl;
        printXEmptyLines(2);

        bool continue_asking = true;
        while(continue_asking)
        {
            cout << choose_interaction_with_people << endl;
            cout << choose_interaction;

            int interactionnumer;
            cin >> interactionnumer;
            cout << endl;
            if(interactionnumer != 3)
            {
                system("cls");
                string people_Answer_Intro = game.peoplelist[raumnummer].GetName() + " sagt:";
                cout << people_Answer_Intro << endl;
                string people_Answer = game.peoplelist[raumnummer].GetAnswer(interactionnumer) ;
                cout << people_Answer << endl;
                printXEmptyLines(2);
                Sleep(5000);
            }
            else
            {
                system("cls");
                continue_asking = false;
            }
        }
    }*/

}

void Ask(struct data* game)
{
    //Final Question
    //Man muss mindestens zwei Beweise/Indizien haben


    /*
    cout << choose_werwolf << endl;
    for(int i=0; i<5; i++)
    {
        cout << i << ". "<< game.peoplelist[i].GetName()<< endl;
    }

    cout << choose_people_to_kill << endl;
    int finalchoose;
    cin >> finalchoose;
    string result = game.peoplelist[finalchoose].GetFinalInformation();

    printSpecialText(result);
    return 0;
    */
}

int main()
{
    struct data gamedata;
    struct data *data_ptr = &gamedata;
    CreateGame(data_ptr);
    Play(data_ptr);
    Ask(data_ptr);

    //cout <<gamedata.peoplelist[0].GetName()<<endl;
    //cout <<gamedata.peoplelist[0].GetAnswer(1);
    cout << "Erfolgreiche Main" << endl;
/*
    bool startedGame = false;
    int set = 0;
    while (startedGame)
    {
        // Exeption
        struct data game = CreateGame(); // Setzt Spielzustand _ INTRO
        struct data game_1;
        CreateGame(&game_1);
        bool started = false;
        SetDialoge(started);

        SetDialoge(started);
        Play(&game);
        Ask(&game);
        // END
        counter ++;
        if( counter >= 2 )
        {
            startedGame = false;
        }
    }
    // TODO! - Ausgabe wie viele er gewonnen hat. -CLASS
    // Befragung abgeschlossen
    // Finales verdächtigen
    system("cls");
    // Programm lief erfolgreich und hat sein Ende erreicht
    Sleep(10000);
    getchar();
    system("cls");
    printSpecialText("Programm erfolgreich beendet");
*/
    return 0;
}

//
/* Räume

cout << initialize_rooms_start << endl;

room room_one;
room_one.SetRoomName("Kueche");

room roome_two;
roome_two.SetRoomName("Badezimmer");

room room_three;
room_three.SetRoomName("Wohnzimmer");

room room_four;
room_four.SetRoomName("Flur");

room room_five;
room_five.SetRoomName("Schlafzimmer"); */
