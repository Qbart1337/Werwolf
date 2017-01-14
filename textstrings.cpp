#include <iostream>
#include <string>

//# Caner Yavuz & Text-Refactor Stefan Nonn
std::string initialize_rooms_start = "Initialisiere alle Raeume";
std::string initialize_rooms_end = "Raeume wurden erfolgreich erstellt";
std::string initialize_person_start = "Initialisiere Personen fuer das Spiel";
std::string initialize_person_end = "Personen erfolgreich erstellt";
//std::string gamerules = "Spielregeln:\nDu kannst mit bis zu 5 Personen sprechen und Indizen sammeln um jemand anzuklagen.\nZiel des Spiel ist es durch das Sprechen mit den verschiedenen Personen herauszufinden wessen Alibi nicht stimmt und ihn als Werwolf zu enttarnen";
std::string gamerules = "Ziel des Spiels ist es durch das Sprechen mit den Dorfbewohnern und sammeln von Indizen herauszufinden wer Herr Mustermann umgebracht wird. Begebe dich an den Tatort um mit den Sheriff zu sprechen und das Spiel zu starten";
std::string choose_room_intro = "In Welchen Raum moechtest du gehen? (0-4)";
std::string choose_werwolf_intro = "Alternativ: (5) um zu entscheiden wer der Werwolf ist";
std::string choose_room = "Bitte Raumnummer auswaehlen: ";
std::string choose_interaction_with_people = "Moegliche Interaktionen: \n1. Freundlich fragen was er gestern gemacht hat \n2. Nachfragen ob die Person jemand anderen gesehen hat\n3. Raum verlassen";
std::string choose_interaction = "Bitte Interaktion auswaehlen: ";
std::string choose_werwolf = "Du musst dich entscheiden wer der Täter ist" ;
//std::string choose_people_to_kill = "Wen moechtest du umbringen?";
//std::string introduction = "";


std::string introduction = "Willkommen im kleinen aber ueberschaulichen Dorf Hausen. Im Dorf sind ueber Weihnachten und Neujahr nur wenige Einwohner zurueckgeblieben, die meisten der Bewohner sind bei Freunden in benachbarten Doerfern. Einer von ihnen wurde tot in seinem Haus aufgefunden. Deine Aufgabe ist es, zum Tatort zu gehen, mit dem Sheriff zu sprechen und im folgenden Beweisstuecke oder belastende Gespraeche zu sammeln um den Taeter anklagen zu koennen. Begebe dich zum Sheriff und beginne die Ermittlungen.";
std::string church_intro = "Du bist gerade in die Kirche gegangen. In der Kirche brennen schon ein paar Kerzen fuer den Verstorbenen.";
std::string church_options = "Du hast folgende Moeglichkeiten: \n1.Mit dem Pfarrer sprechen\n2. Zum Beichstuhl gehen\n3. Zur Tuer hinter dem Altar gehen\n4. Kirche verlassen";
std::string p1_set_2_options = "Du bist zum Pfarrer gegangen\nDu kannst ihn folgendes Fragen:\n1.Was weisst du ueber Hr. Meier?\n2.Weisst du ob jemand etwas gegen den Hr. Meier hatte?\nGespraech verlassen";
std::string p1_set_2_str_1 = "Puh, eigentlich nicht viel. Er kam leider nicht sehr oft in die Kirche. Ich glaube zwar nicht, dass es dir hilft, aber Herr Meier liebte Spaghetti ueber alles, er war gerade zu suechtig nach ihnen.";
std::string p1_set_2_str_2 = "Tut mir leid, meine Schweigepflicht bindet mir Haende und Fuesse.";
std::string p1_set_2_str_3 = "Ich habe dir schon alles erzaehlt, vielleicht solltest du lieber mit anderen sprechen.";
std::string confessional_intro = "Hier ist ausser ein wenig Staub und einem Schluessel nichts interessantes";
std::string confessional_intro_2 = "Hier ist ausser ein wenig Staub absolut nichts interessantes. Du verlaesst den Beichtstuhl wieder";
std::string confessional_options = "1. Schluessel nehmen\n.2. Beichtstuhl verlassen";
std::string church_back_room_intro = "In diesem Raum liegen viele Gebetsbuecher und Notizen";
std::string church_back_room_options = "Was moechtest du tun?\n1. Aufgeschlagenes Gebetsbuch anschauen\n2. Tagebuch anschauen";
std::string church_back_room_notes = "…";
std::string mensa_intro = "Du bist in die Mensa gegangen, hier duftet es lecker.";
std::string mensa_options_1 = "Was möchtest du tun? \n1.Etwas zu Essen holen \n2. Mit Herr Müller sprechen\n3. Mensa verlassen";
std::string mensa_options_2 = "Was möchtest du tun? \n1.Etwas zu Essen holen \n2. Mit Herr Müller sprechen\n3 Mit Herr Schmidt sprechen.\n4.Mensa verlassen";
std::string p7_set_2_options = "Du bist zur Essensausgabe gegangen.\nDu hast folgende Optionen: \n1. Essen geben lassen \n2.Ihn nach Herr Meier fragen\n3. Gespräch verlassen";
std::string p7_set_2_str_1 = "Der Küchenchef gibt dir ein Schnitzel, ein wenig Kartoffelsalat und ein kleines Dessert.";
std::string p7_set_2_str_2 = "Herr Meier war besonders oft hier wenn es Spaghetti gab, diese liebte er einfach über alles. Ansonsten kann ich dir eigentlich nur noch weiteres über seine Essgewohnheiten erzählen. Privat hatte ich nichts mit ihm zu tun.";
std::string p7_set_2_str_3 = "Ich denke du hast noch besseres zu tun als mich die ganze Zeit von der Arbeit abzuhalten";
std::string p3_set_2_options="Du hast dich zu Herr Müller an den Tisch gesetzt, dieser ist gerade dabei zu Essen.\n Du hast folgende Optionen: \n1. Fragen wie das Essen schmeckt \n2. Ihn nach dem verstorbenen Herr Meier fragen\n3. Gespräch verlassen";
std::string p3_set_2_str_1 ="Das Schnitzel hier ist einfach das Beste der Welt, ich kenne niemanden der so ein gutes Schnitzel wie unser Küchenchef macht";
std::string p3_set_2_str_2 ="Ich glaube Hr. Meier hat ab und zu gerne gezockt, aber da ich selbst nichts davon halte, kann ich dazu auch nicht mehr sagen.";
std::string p3_set_2_str_3="Magst du nicht jemand anderes befragen und mich in Ruhe essen lassen?";
std::string p2_set_2_options ="Du hast dich zu Herr Schmidt gesetzt, dieser sitzt ein wenig nachdenklich vor seinem Essen.\nDu hast folgende Optionen:\n1.Ihn fragen was ihn bekümmert\n2 Ihn fragen was er über Hr. Meier weiß\n3. Gespräch verlassen.";
std::string p2_set_2_str_1 ="Ich hätte es nie für möglich gehalten, dass in unserem kleinen Dorf mal jemand ermordet werden würde. Ich fühle mich erinnert an den Tartort vom letzten Sonntag.";
std::string p2_set_2_str_2 ="Ich habe Hr. Meier ab und zu in die Scheune gehen sehen. Einmal sah ich wie er viel Heu zur Seite schob und in einen geheimen Raum ging.";
std::string p2_set_2_str_3 ="Lass mich bitte ein wenig in Ruhe, ich brauche Zeit zum Nachdenken";
std::string crime_scene_intro="Du bist gerade an den Tartort gegangen. Herr Meier liegt direkt neben der Tür aufgeschlitzt am Boden. Neben ihm steht der Sheriff";
std::string crime_scene_options="Du hast folgende Optionen: \n1. Mit dem Sheriff sprechen \n2. Die Leiche genauer anschauen\n3. Den Tartort verlassen";
std::string p6_set_2_options = "Du gehst auf den Sheriff zu, dieser erwartet dich schon. \nDu hast folgende Optionen";
std::string p6_set_2_str_1 ="Der Sheriff übergibt dir einen Sheriffsstern und erteilt dir noch einmal offiziell den Auftrag mit allen im Dorf zu sprechen. Deine Aufgabe ist es nun mit allen Bewohnern des Dorfes zu sprechen und Indizien zu sammeln. Wenn du genug davon hast, sollst du wieder zurück zum Sheriff kommen.";
std::string p6_set_2_str_2 ="Auch der Sheriff bekundet sein Beileid für den Verstorbenen, sagt aber sonst nichts weiteres zu ihm.";
std::string p6_set_2_str_3 =""; //muss deaktivierbar sein
std::string watch_stiff = "Du hast zwar oft den Tartort im Ersten geschaut, aber wirklich auskennen tust du dich mit dem Untersuchen von Leichen nicht. Du siehst lediglich das Offensichtliche und weißt das Herr Meier sich wohl nie wieder von selbst bewegen wird.";
std::string common_room_intro="Du bist in den Aufenthaltsraum gegangen.";
std::string common_room_options="In diesem Raum bieten sich dir folgende Möglichkeiten: \n1. Dich zu Paul setzen \n2. Dich zu Jan setzen \n3. Den Raum wieder verlassen";
std::string p4_set_2_options ="Du setzt dich zu Paul an den Tisch, dieser macht gerade Mathe Hausaufgaben und flucht ein wenig darüber.\n Du hast folgende Möglichkeiten: \n1.Paul bei den Hausaufgaben helfen\n2. Ihn fragen was er über Hr. Meier weiß\n3. Aufstehen";
std::string p4_set_2_str_1 ="Paul ließt dir seine aktuelle Aufgabe vor: 'Berechnen sie den Schnittpunkt von y=2x² - 16 mit der y-Achse.";
std::string p4_set_2_str_2 ="Jan erzählt dir, dass er Herr Meier immer sehr gerne mochte, weil er ihm öfters mal bei den Hausaufgaben geholfen hat.";
std::string p4_set_2_str_3 ="Lass mich bitte in Ruhe meine Hausaufgaben machen";
std::string p5_set_2_options ="Du Setzt dich zu Jan an den Tisch, dieser spielt gerade an einem Handheld\nDir bieten sich folgende Möglichkeiten: \n1.Ihn fragen was er da gerade macht\n2.Ihn fragen was er über Herr Meier weiß \n3.Aufstehen";
std::string p5_set_2_str_1 ="Jan erzählt dir, dass er gerade das neue Pokemon spielt. Nach einigen Details und Fachbegriffen steigst du jedoch vollkommen aus und Jan ersparrt dir weitere Details.";
std::string p5_set_2_str_2 ="Jan erzählt dir, dass er glaubt das Herr Meier mit dem Sheriff im Klintsch lag und du genau deswegen die Ermittlungen übernehmen sollst. Wer weiß, vielleicht hat der Sherriff ihn ja selbst umgebracht?";
std::string p5_set_2_str_3 ="Ach komm, lass mich doch einfach in Ruhe zocken.";
