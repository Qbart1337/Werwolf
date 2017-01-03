#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
enum whoami { Dorfbewohner, Werwolf};

class person
{
private:
    whoami bewohnerstatus;
    int ask_Counter;
    std::string name;
    std::string answer_neutral;
    std::string answer_sceptic;
    std::string answer_random;
    std::string dialog_options;
public:
    person();

    whoami GetPersonenStatus();
    std::string DialogOptions();
    std::string GetName();
    std::string GetAnswer(int answer_choose);
    std::string GetFinalInformation();

    bool GetWerwolfStatus();

    void SetWerwolf();
    void SetDialogOptions(std::string str_opts);
    void SetDialog(std::string answer_neutral, std::string answer_sceptic, std::string answer_random);
    void SetName(std::string name);
};

#endif // PERSON_H
