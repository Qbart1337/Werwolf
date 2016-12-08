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


void ChangeInt(int &number)
{
    number++;
}
*/
// TODO: eventuell play/ask mit Ref als Parameter

using namespace std;
struct data{
    person peoplelist[5];
    room roomlist[5];
};

struct data CreateGame(int game){
    struct data z;
    //Erstelle Räume
    //TODO: Besseres Naming bspw. room_one, room_two, person_one, person_two

    cout << initialize_rooms_start << endl;

    //TODO: Alle am Ende Adden
    //Room One
    room eins;
    eins.SetRoomName("Kueche");
    z.roomlist[0] = eins;

    //Room Two
    room zwei;
    zwei.SetRoomName("Badezimmer");
    z.roomlist[1] = zwei;

    //Raum Three
    room drei;
    drei.SetRoomName("Wohnzimmer");
    z.roomlist[2] = drei;

    //Raum Four
    room vier;
    vier.SetRoomName("Flur");
    z.roomlist[3] = vier;

    //Raum Five
    room funf;
    funf.SetRoomName("Schlafzimmer");
    z.roomlist[4] = funf;

    cout << initialize_rooms_end << endl;
    cout << initialize_person_start << endl;

    //Number One
    person one;
    one.SetName("Anne");
    //TODO: Switch-Case statt If-Schachtelungen
    //TODO: Runde 2-4 Texte kreieren
    if(game == 1)
    {
        one.SetDialog("Ich war mit einer Freundin einkauen", "Ich habe Anna gesehen", "Nerv mich nicht!");
    }
    else if(game == 2)
    {
        one.SetDialog("###", "###", "###");
    }
    //Number Two
    person two;
    two.SetName("Anja");
    if(game == 1)
    {
        two.SetDialog("Ich war mit einem Freund im Kino", "Nein", "Nerv mich nicht!");
    }
    else if(game == 2)
    {
        two.SetDialog("###", "###", "###!");
    }
    //Number Three
    person three;
    three.SetName("Antoine");
    if(game == 1)
    {
        three.SetWerwolf();
        three.SetDialog("Ich habe mir einen Film angeschaut", "Ich habe Anne gesehen", "Nerv mich nicht!");
    }
    else if(game == 2)
    {
        three.SetDialog("###", "###", "###!");
    }
    //Number Four
    person four;
    four.SetName("Anton");
    if(game == 1)
    {
        four.SetDialog("Ich habe mir einen Film angeschaut", "Ich habe Anja gesehen", "Nerv mich nicht!");
    }
    else if(game == 2)
    {
        four.SetDialog("###", "###", "###");
    }
    //Number Five
    person five;
    five.SetName("Anna");
    if(game == 1)
    {
        five.SetDialog("Ich habe mir ein Kleid gekauft", "Ich habe Anne gesehen", "Nerv mich nicht!");
    }
    else if(game == 2)
    {
        five.SetDialog("###", "###", "###");
    }

    z.peoplelist[0] = one;
    z.peoplelist[1] = two;
    z.peoplelist[2] = three;
    z.peoplelist[3] = four;
    z.peoplelist[4] = five;
    cout << initialize_person_end << endl;
    return z;
}

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

int main()
{    
    // Standard User anlegen

    // Stefan Nonn angelegt
    // int gamenumber = 2;
    // struct data game = CreateGame(gamenumber);
    // OTHER angelegt
    // struct data game = CreateGame(3);
    // OTHER_2 Nonn angelegt
    // struct data game = CreateGame(4);

    bool allGames = true;
    int counter = 0;
    while (allGames)
    {
        // Exeption
        struct data game = CreateGame(counter);
        Play(game);
        Ask(game);
        // END
        counter ++;
        if( counter >= 2 )
        {
            allGames = false;
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

    return 0;
}
