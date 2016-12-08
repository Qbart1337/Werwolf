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

using namespace std;
struct data{
    person peopleList[5];
    room roomList[5];
};

struct data CreateGame(int game){
    struct data z;
    //Erstelle Räume

    cout << initialize_rooms_start << endl;
    /*
    Flur, Schlafzimmer
    */

    //Room One
    room eins;
    eins.SetRoomName("Kueche");
    z.roomList[0] = eins;

    //Room Two
    room zwei;
    zwei.SetRoomName("Badezimmer");
    z.roomList[1] = zwei;

    //Raum Three
    room drei;
    drei.SetRoomName("Wohnzimmer");
    z.roomList[2] = drei;

    //Raum Four
    room vier;
    vier.SetRoomName("Flur");
    z.roomList[3] = vier;

    //Raum Five
    room funf;
    funf.SetRoomName("Schlafzimmer");
    z.roomList[4] = funf;

    cout << initialize_rooms_end << endl;
    cout << initialize_person_start << endl;

    //Number One
    person one;
    one.SetName("Anne");
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

    z.peopleList[0] = one;
    z.peopleList[1] = two;
    z.peopleList[2] = three;
    z.peopleList[3] = four;
    z.peopleList[4] = five;
    cout << initialize_person_end << endl;
    return z;
}

int play(struct game)
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
            cout << j << ": " <<game.roomList[j].GetRoomeName() << endl;
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

        string go_to_room = "Du bist in " + game.roomList[raumnummer].GetRoomeName() + " gegangen";
        cout << go_to_room << endl;

        string people_in_room = "In diesem Raum ist: " + game.peopleList[raumnummer].GetName();
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
                string people_Answer_Intro = game.peopleList[raumnummer].GetName() + " sagt:";
                cout << people_Answer_Intro << endl;
                string people_Answer = game.peopleList[raumnummer].GetAnswer(interactionnumer) ;
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

int ask(struct game)
{
    cout << choose_werwolf << endl;
    for(int i=0; i<5; i++)
    {
        cout << i << ". "<< game.peopleList[i].GetName()<< endl;
    }

    cout << choose_people_to_kill << endl;
    int finalchoose;
    cin >> finalchoose;
    string result = game.peopleList[finalchoose].GetFinalInformation();

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
    while (allGames)
    {
        int counter;
        int gamenumber = counter;
        // Exeption
        struct data game = CreateGame(gamenumber);
        play(&game);
        ask(&game);
        // END
        counter ++;
        if( counter >= 4 )
        {
            allGames = false;
        }
    }
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
