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







void ChangeInt(int &number)
{
    number++;
}
*/
// TODO: eventuell play/ask mit Ref als Parameter

/*
TODO:
Std::list -> Inventar
Energy-Skala // Essen 3 Hunger Balken
Bewegung und Verzweigung der Räume
Zustandsänderungen erhöhen
Kommentieren wer was gemacht hat

*/

using namespace std;
struct data
{
    person peoplelist[5];
};

void CreateGame(struct data *z)
{
    cout << initialize_person_start << endl;
    person person_one;
    person person_two;
    person person_three;
    person person_four;
    person person_five;

    z ->peoplelist[0].SetName("Anne");
    z ->peoplelist[1].SetName("Anja");
    z ->peoplelist[2].SetName("Antoine");
    z ->peoplelist[3].SetName("Anton");
    z ->peoplelist[4].SetName("Anna");


    //TODO: Switch-Case statt If-Schachtelungen
    //TODO: Runde 2-4 Texte kreieren
    //TODO: SetDialoge(set); auslagern mit 'int set';


    z ->peoplelist[0] = person_one;
    z ->peoplelist[1] = person_two;
    z ->peoplelist[2] = person_three;
    z ->peoplelist[3] = person_four;
    z ->peoplelist[4] = person_five;
    cout << initialize_person_end << endl;
    //return z;
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

/*
int Play(struct data game)
{
    // Einführung
    printXEmptyLines(2);
    printTextSmoothly(gamerules);
    printXEmptyLines(2);

    // Spiel beginnt

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
    }
    return 0;
}

int Ask(struct data game)
{
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
}
*/
int main()
{    
    struct data gamedata;
    struct data *data_ptr = &gamedata;
    CreateGame(data_ptr);
    SetDialog(1,data_ptr);
    cout <<gamedata.peoplelist[0].GetName()<<endl;
    cout <<gamedata.peoplelist[0].GetAnswer(1);
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
