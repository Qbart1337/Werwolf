#include <iostream>
#include <string>

//Beta 42

//#Ronaldo Dano & Refactor+Edit Stefan Nonn

std::string initialize_rooms_start = "Initialisiere alle Raeume";
std::string initialize_rooms_end = "Raeume wurden erfolgreich erstellt";
std::string initialize_person_start = "Initialisiere Personen fuer das Spiel";
std::string initialize_person_end = "Personen erfolgreich erstellt";
//std::string gamerules = "Spielregeln:\nDu kannst mit bis zu 5 Personen sprechen und Indizen sammeln um jemand anzuklagen.\nZiel des Spiel ist es durch das Sprechen mit den verschiedenen Personen herauszufinden wessen Alibi nicht stimmt und ihn als Werwolf zu enttarnen";
std::string gamerules = "Ziel des Spiels ist es durch das Sprechen mit den Dorfbewohnern und sammeln von Indizen herauszufinden wer Herr Mustermann umgebracht wird. Begebe dich an den Tatort um mit den Sheriff zu sprechen und das Spiel zu starten";
std::string choose_room_intro = "In Welchen Raum moechtest du gehen? (0-4)";
std::string choose_werwolf_intro = "Alternativ: (5) um zu entscheiden wer der Taeter ist";
std::string choose_room = "Bitte Raumnummer auswaehlen: ";
std::string choose_interaction_with_people = "Moegliche Interaktionen: \n1. Freundlich fragen was er gestern gemacht hat \n2. Nachfragen ob die Person jemand anderen gesehen hat\n3. Raum verlassen";
std::string choose_interaction = "Bitte Interaktion auswaehlen: ";
std::string choose_werwolf = "Du musst dich entscheiden wer der Taeter ist" ;
//std::string choose_people_to_kill = "Wen moechtest du umbringen?";
//std::string introduction = "";

std::string introduction = "Willkommen im kleinen aber ueberschaulichen Dorf Hausen. Im Dorf sind ueber Weihnachten und Neujahr nur wenige Einwohner zurueckgeblieben, die meisten der Bewohner sind bei Freunden in benachbarten Doerfern. Einer von ihnen wurde tot in seinem Haus aufgefunden. Deine Aufgabe ist es, zum Tatort zu gehen, mit dem Sheriff zu sprechen und im folgenden Beweisstuecke oder belastende Gespraeche zu sammeln um den Taeter anklagen zu koennen. Begebe dich zum Sheriff und beginne die Ermittlungen.";

// Optionale Variablen #AFTER Spieler beim Sheriff war

std::string church_intro = "Du bist gerade in die Kirche gegangen. In der Kirche brennen schon ein paar Kerzen fuer den Verstorbenen.";
std::string church_options = "Du hast folgende Moeglichkeiten: \n1. Mit dem Pfarrer sprechen\n2. Den Beichstuhl dieser Kirche besuchen.\n3. Zur Tuer hinter dem Altar gehen\n4. Kirche verlassen";
std::string p1_set_2_options = "Du bist zum Pfarrer gegangen\nDu kannst ihn folgendes Fragen:\n1. Was weisst du ueber Hr. Meier?\n2. Weisst du ob jemand etwas gegen den Hr. Meier hatte?\n3. Gespraech verlassen";
std::string p1_set_2_str_1 = "Puh, eigentlich nicht viel. Er kam leider nicht sehr oft in die Kirche. Ich glaube zwar nicht, dass es dir hilft, aber Herr Meier liebte Spaghetti ueber alles, er war gerade zu suechtig nach ihnen.";
std::string p1_set_2_str_2 = "Tut mir leid, meine Schweigepflicht bindet mir Haende und Fuesse.";
std::string p1_set_2_str_3 = "Ich habe dir schon alles erzaehlt, vielleicht solltest du lieber mit anderen sprechen.";
std::string confessional_intro = "Hier ist ausser ein wenig Staub und einem Schluessel nichts interessantes";
std::string confessional_intro_2 = "Hier ist ausser ein wenig Staub absolut nichts interessantes. Du verlaesst den Beichtstuhl wieder";
std::string confessional_options = "1. Schluessel nehmen\n.2. Beichtstuhl verlassen";
std::string church_back_room_intro = "In diesem Raum liegen viele Gebetsbuecher und Notizen";
std::string church_back_room_options = "Was moechtest du tun?\n1. Aufgeschlagenes Gebetsbuch anschauen\n2. Tagebuch anschauen\n3. Raum verlassen";
std::string church_back_room_options_2 = "Was moechtest du tun?\n1. Aufgeschlagenes Gebetsbuch anschauen\n2. Raum verlassen";
std::string church_back_room_notes = "Auf der aufgeschlagenen Seite ist ein Gespraech vom vormittag notiert, in der Pfarrer sein schlechtes Gewissen beschreibt, weil er nichts unternehmen kann, trotz Herr Schmidts Schuldeingestaendnisses bei der Beichte.";

std::string mensa_intro = "Du bist in die Mensa gegangen, hier duftet es lecker.";
std::string mensa_options_2 = "Was moechtest du tun? \n1.Etwas zu Essen holen \n2. Mit Herr Mueller sprechen\n3 Mit Herr Schmidt sprechen.\n4.Mensa verlassen";
std::string p7_set_2_options = "Du bist zur Essensausgabe gegangen.\nDu hast folgende Optionen: \n1. Essen geben lassen \n2. Ihn nach Herr Meier fragen\n3. Gespraech verlassen";
std::string p7_set_2_str_1 = "Der Kuechenchef gibt dir ein Schnitzel, ein wenig Kartoffelsalat Desert ist leider aus.";
std::string p7_set_2_str_2 = "Herr Meier war besonders oft hier wenn es Spaghetti gab, diese liebte er einfach ueber alles. Ansonsten kann ich dir eigentlich nur noch weiteres ueber seine Essgewohnheiten erzaehlen. Privat hatte ich nichts mit ihm zu tun.";
std::string p7_set_2_str_3 = "Ich denke du hast noch besseres zu tun als mich die ganze Zeit von der Arbeit abzuhalten";

std::string p3_set_2_options="Du hast dich zu Herr Mueller an den Tisch gesetzt, dieser ist gerade dabei zu Essen.\n Du hast folgende Optionen: \n1. Fragen wie das Essen schmeckt \n2. Ihn nach dem verstorbenen Herr Meier fragen\n3. Gespraech verlassen";
std::string p3_set_2_str_1 ="Das Schnitzel hier ist einfach das Beste der Welt, ich kenne niemanden der so ein gutes Schnitzel wie unser Kuechenchef macht";
std::string p3_set_2_str_2 ="Ich glaube Hr. Meier hat ab und zu gerne gezockt, aber da ich selbst nichts davon halte, kann ich dazu auch nicht mehr sagen.";
std::string p3_set_2_str_3="Magst du nicht jemand anderes befragen und mich in Ruhe essen lassen?";

std::string p2_set_2_options ="Du hast dich zu Herr Schmidt gesetzt, dieser sitzt ein wenig nachdenklich vor seinem Essen.\nDu hast folgende Optionen:\n1. Ihn fragen was ihn bekuemmert.\n2. Ihn nach dem verstorbenen Herr Meier fragen \n3. Gespraech verlassen.";
std::string p2_set_2_str_1 ="Ich haette es nie fuer moeglich gehalten, dass in unserem kleinen Dorf mal jemand ermordet werden wuerde. Jetzt wird der Taeter gesucht.. sind wir sicher?.";
std::string p2_set_2_str_2 ="Ich habe Hr. Meier ab und zu in die Scheune gehen sehen. Einmal sah ich wie er viel Heu zur Seite schob und in einen geheimen Raum ging.";
std::string p2_set_2_str_3 ="Lass mich bitte ein wenig in Ruhe, ich brauche Zeit zum Nachdenken";

// TODO text - Neu schreiben
std::string crime_scene_intro="Du bist gerade an den Tartort gegangen. Herr Meier liegt direkt neben der Tuer aufgeschlitzt am Boden. Neben ihm steht der Sheriff";
std::string crime_scene_options="Du hast folgende Optionen: \n1. Mit dem Sheriff sprechen \n2. Die Leiche genauer anschauen\n3. Den Tartort verlassen";
std::string p6_set_2_options = "Du gehst auf den Sheriff zu, dieser erwartet dich schon. \nDu hast folgende Optionen\n1. Jemanden anklagen\n2. Nach Tipps fragen\n3. Gespraech verlassen";
std::string p6_set_2_str_1 ="Der Sheriff uebergibt dir den Schlussel zum Gericht und drueckt dir die Daumen. Gehe zurueck zur Dorfmitte um Gericht zu geklagen\n \n-Gericht freigeschaltet-";
std::string p6_set_2_str_2 ="Der Sheriff gibt dir den Tipp einfach mit allen im Dorf zu sprechen";
std::string p6_set_2_str_3 ="Auch ich bin ein Fehler #fuck";

std::string watch_stiff = "Du hast zwar oft den Tartort im Ersten geschaut, aber wirklich auskennen tust du dich mit dem Untersuchen von Leichen nicht. Du siehst lediglich das Offensichtliche und weißt das Herr Meier sich wohl nie wieder von selbst bewegen wird.";

// TODO text
std::string common_room_intro="Du bist in den Aufenthaltsraum gegangen.";
std::string common_room_options="In diesem Raum bieten sich dir folgende Moeglichkeiten: \n1. Dich zu Paul setzen \n2. Dich zu Jan setzen \n3. Den Raum wieder verlassen";
std::string p4_set_2_options ="Du setzt dich zu Paul an den Tisch, dieser macht gerade Mathe Hausaufgaben und flucht ein wenig darueber.\n Du hast folgende Moeglichkeiten: \n1.Paul bei den Hausaufgaben helfen\n2. Ihn fragen was er ueber Hr. Meier weiß\n3. Aufstehen";
std::string p4_set_2_str_1 ="Paul ließt dir seine aktuelle Aufgabe vor: 'Berechnen sie den Schnittpunkt von y=2x^2 - 16 mit der y-Achse.";
std::string p4_set_2_str_2 ="Jan erzaehlt dir, dass er Herr Meier immer sehr gerne mochte, weil er ihm oefters mal bei den Hausaufgaben geholfen hat.";
std::string p4_set_2_str_3 ="Lass mich bitte in Ruhe meine Hausaufgaben machen";

std::string p5_set_2_options ="Du Setzt dich zu Jan an den Tisch, dieser spielt gerade an einem Handheld\nDir bieten sich folgende Moeglichkeiten: \n1. Ihn fragen was er da gerade macht\n2. Ihn fragen was er ueber Herr Meier weiß \n3. Aufstehen";
std::string p5_set_2_str_1 ="Jan erzaehlt dir, dass er gerade das neue Pokemon spielt. Nach einigen Details und Fachbegriffen steigst du jedoch vollkommen aus und Jan ersparrt dir weitere Details. Kennt er eigentlich Pokemon Go? Egal..";
std::string p5_set_2_str_2 ="Jan erzaehlt dir, dass er glaubt das der Kuechenchef ein Ninja sein so gut wie er mit dem Messer umgehen kann?";
std::string p5_set_2_str_3 ="Ach komm der ist doch unmaeglich der Taeter...";


// Optionale Variablen #BEFORE Spieler beim Sheriff war
std::string p1_intro = "Du bist zum Pfarrer gegangen";
std::string p1_set_1_options = "Du kannst ihn folgendes Fragen:\n1. Was ist hier passiert?\n2. Wo ist den der Sheriff?\n3. Gespraech verlassen";
std::string p1_set_1_str_1 = "Es gab ueber nacht einen Mord. Sie sollten lieber mehr von Sheriff haeren";
std::string p1_set_1_str_2 = "Ich wuerde mal den Tatort schaetzen mein Sohn.";
std::string p1_set_1_str_3 = "Ich habe dir schon alles erzaehltwas ich weiß mein Kind.";

std::string mensa_options_1 = "Was moechtest du tun? \n1. Etwas zu Essen holen \n2. Mit Herr Mueller sprechen\n3. Mensa verlassen";
std::string p7_set_1_options = "Du bist zur Essensausgabe gegangen.\nDu hast folgende Optionen: \n1. Essen geben lassen \n2. Ihn nach dem Sheriff fragen\n3. Gespraech verlassen";
std::string p7_set_1_str_1 = "Der Kuechenchef gibt dir ein Schnitzel, ein wenig Kartoffelsalat und ein kleines Dessert.";
std::string p7_set_1_str_2 = "Der Sheriff ist ein erlicher Mann glaub ich. Ich kenn ihn kaum";
std::string p7_set_1_str_3 = "Ich habe viel Arbeit zu tun bitte stoere mich nicht weiter";

std::string p3_set_1_options="Du hast dich zu Herr Mueller an den Tisch gesetzt, dieser ist gerade dabei zu Essen.\n Du hast folgende Optionen: \n1. Fragen wie das Essen schmeckt \n2. Ihn nach seinem Tag befragen\n3. Gespraech verlassen";
std::string p3_set_1_str_1 ="Das Schnitzel hier ist einfach das Beste der Welt, ich kenne niemanden der so ein gutes Schnitzel wie unser Kuechenchef macht";
std::string p3_set_1_str_2 ="Der Mord verunsichert alle Leute. Der Taeter ist bestimmt schon weg.";
std::string p3_set_1_str_3="Kann ich bitte nun in Ruhe essen?";


//TODO: Herr Schmidt sitzt im Beichtstuhl und beichtet dir seine Tat!!! texte aendern!
//Optionen muessen geaendert werden - p2_set_1_str_1 muss ein Gestaendnis sein
std::string p2_set_1_options ="Du hast dich zu Herr Schmidt gesetzt, dieser sitzt ein wenig nachdenklich vor seinem Essen.\nDu hast folgende Optionen:\n1. Ihn fragen was ihn bekuemmert. \n2. Ihn fragen wie das Dessert schmeckt. \n3. Gespraech verlassen.";
std::string p2_set_1_str_1 ="Ich haette es nie fuer moeglich gehalten, dass in unserem kleinen Dorf mal jemand ermordet werden wuerde. Jetzt wird der Taeter gesucht.. sind wir sicher?.";
std::string p2_set_1_str_2 ="Also ich finde es nicht sehr berauschend."; // Luege
std::string p2_set_1_str_3 ="Lass mich bitte ein wenig in Ruhe essen.";

std::string p6_set_1_options = "Du gehst auf den Sheriff zu, dieser erwartet dich schon. \nDu hast folgende Optionen\n1. Die Mission annehmen\n2. Ihn nach dem verstorbenen fragen \n3. Das Gespraech verlassen";
std::string p6_set_1_str_1 ="Der Sheriff uebergibt dir einen Sheriffsstern und erteilt dir noch einmal offiziell den Auftrag mit allen im Dorf zu sprechen. Deine Aufgabe ist es nun mit allen Bewohnern des Dorfes zu sprechen und Indizien zu sammeln. Wenn du genug davon hast, sollst du wieder zurueck zum Sheriff kommen.";
std::string p6_set_1_str_2 ="Auch der Sheriff bekundet sein Beileid fuer den Verstorbenen, sagt aber sonst nichts weiteres zu ihm.";
std::string p6_set_1_str_3 ="Hilfe ich bin ein Bug, und jetzt kannst du den Auftrag nicht mehr annehmen #GameOver!"; // darf hier nicht rein weil er sonst den Auftrag nicht annehmen kann

std::string p4_set_1_options ="Du setzt dich zu Paul an den Tisch, dieser macht gerade Mathe Hausaufgaben und flucht ein wenig darueber. \n Du hast folgende Moeglichkeiten: \n1. Paul bei den Hausaufgaben helfen. \n2. Ihn fragen warum er sich so aufregt. \n3. Aufstehen";
std::string p4_set_1_str_1 ="Hast du echt nicht besseres zu tun?";
std::string p4_set_1_str_2 ="Haha sehr lustig. Du kannst mir auch gern spaeter helfen wenn du zuviel Zeit hast";
std::string p4_set_1_str_3 ="Lass mich bitte jetzt in Ruhe meine Hausaufgaben machen";

std::string p4_set_3_str_1 = "Nochmal vielen Dank das du mir geholfen hast! Aber den Rest schaffe ich denke ich selber";
std::string p4_set_4_str_1 = "Du solltest dich eher fragen wie du das Abitur geschafft hast, selbst ein Grundschueler konnte mir mehr helfen wie du";
std::string p4_set_3_options ="Du setzt dich zu Paul an den Tisch, dieser macht gerade Mathe Hausaufgaben und flucht ein wenig darueber.\n Du hast folgende Moeglichkeiten: \n1. Bei den Hausaufgaben helfen\n2. Ihn fragen was er ueber Hr. Meier weiß\n3. Aufstehen";

std::string p5_set_1_options ="Du Setzt dich zu Jan an den Tisch, dieser spielt gerade an einem Handheld\nDir bieten sich folgende Moeglichkeiten: \n1. Ihn fragen was er da gerade macht\n2.Ihn fragen warum hier ist \n3.Aufstehen";
std::string p5_set_1_str_1 ="Jan erzaehlt dir, dass er gerade das neue Pokemon spielt. Nach einigen Details und Fachbegriffen steigst du jedoch vollkommen aus und Jan ersparrt dir weitere Details.";
std::string p5_set_1_str_2 ="Jan erzaehlt dir, dass er glaubt das Herr Meier mit dem Sheriff im Klintsch lag und du genau deswegen die Ermittlungen uebernehmen sollst. Wer weiß, vielleicht hat der Sherriff ihn ja selbst umgebracht?";
std::string p5_set_1_str_3 ="Ach komm, lass den armen Jungen doch einfach in Ruhe zocken.";





//Alex 18:08 Push
std::string final_intro_part_2 = "Alle haben sich im Gericht versammelt, der Dorfaelteste ruft dich nach vorne und erklaert, dass du nun deinen Hauptverdaechtigen anklagen wirst und eindeutige Beweise vorbringen wirst";
std::string choose_person = "Wen moechtest du anklagen";
std::string final_intro_part_3 = "Du hast die Moeglichkeit Gegenstaende aus deinem Inventar als Beweise vorzulegen oder Aussagen zu zitieren";
std::string choose_inventar_intro = "1. Gegenstand/Gespraech aus dem Inventar vorlegen\n2.Beweisfuehrung beenden und das Gericht entscheiden lassen";
std::string inventar_stuff_intro = "Du hast folgende Gegenstaende und Dialoge in deinem Inventar gespeichert" ;
std::string options = "Du bist in der Dorfmitte, wohin willst du gehen?\n1. Kirche \n2. Mensa \n3. Tatort \n4. Aufenthaltsraum \n5. Scheune \n6. Friedhof";
std::string options_2 = "Du bist in der Dorfmitte, wohin willst du gehen?\n1. Kirche \n2. Mensa \n3. Tatort \n4. Aufenthaltsraum \n5. Scheune \n6. Friedhof\n7. Gerichtsgebaeude";
std::string church_back_room_prayer_book = "Ave Maria, gratia plena\nMaria, gratia plena\nMaria, gratia plena\nAve Ave Dominus Dominus tecumIn mulieribus\nEt benedictus et benedictus fructus ventris\nVentris tui Jésus\nAve Maria";
std::string not_useful ="Das hilft dir auch nicht weiter, du kehrst in die Raumuebersicht zurueck";

std::string note_options = "Du hast folgende Optionen: \n1. Mitnehmen \n2. Liegen lassen";
std::string enter_solution = "Loesung eintippen";
std::string leave_tatort = "Du verlaesst den Tatort";
std::string thanks_for_homework = "Das sieht gut aus, ich danke dir fuer deine Hilfe. \nIch moechte dir dafuer diesen Schluessel geben, den ich heute morgen im Wald gefunden habe. Ich weiß zwar nicht zu welcher Tuer er passt, aber vielleicht findest du es ja heraus.";
std::string wrong_solution = "Ich glaube nicht dass das stimmt, aber trotzdem nett das du es versucht hast";
std::string easter_egg_str_1 = "Eine nackte Frau kommt auf dich zu und fragt dich woher ploetzlich das Heu kommt";
std::string easter_egg_str_2 = "Du reibst dir verwundert die Augen und merkst, dass du das nur getraeumt hast";
std::string easter_egg_str_3 = "In der Scheune siehst du ausser viel Heu nichts interessantes";
std::string easter_egg_str_4 = "Du kannst diesen Raum nur wieder verlassen, druecke dafuer die 1";
std::string barn_hay_action = "Du schiebst das Heu in einer Ecke zur Seite und findest eine versteckte Tuer";
std::string hiddenroom_door_opening = "Du oeffnest die Tuer mit dem Schluessel, den du von Paul bekommen hast";
std::string hiddenroom_entry = "Du betrittst den geheimen Raum in der Scheune";
std::string hiddenroom_notes_intro = "In dem kleinen Raum liegen ein paar Blaetter auf einem einsamen Tisch.\nBeim genaueren betrachten der Blaetter merkst du das es Schuldscheine sind, aus denen hervorgeht, dass  Hr. Schmidt dem Opfer noch sehr viel Geld geschuldet hat\nAuf einer letzten Seiten ist geplantes Treffen der beiden vermerkt, welches zur Tatzeit passt\nDu packst die Schuldscheine ein und verlaesst die Raum wieder";
std::string hiddenroom_intro_2 = "Seitdem du die Schuldscheine mitgenommen hast, ist dieser Raum genau so uninteressant wie die Scheune selbst, du verlaesst daher den Raum wieder";
std::string no_key = "Leider hast du keinen passenden Schluessel fuer diesen Raum und gehst zurueck in die Kirche";
std::string final_intro = ".... die Zeit bis zum start der Verhandlung vergeht....";
std::string barn_intro = "Du betrittst die Scheune";
std::string confessional_intro_pre = "Du gehst in den Beichtstuhl und triffst auf Herr Schmidt.";
std::string food_in_inventar = "Du hast noch Essen im Inventar, du gibst daher den aktuellen Teller zurueck";
std::string open_gericht = "Du nimmst den Schluessel vom Sheriff und sperrst das Gerichtsgebaeude auf";
std::string empty_inventar = "Inventar leer, Beweisfuehrung beendet";
