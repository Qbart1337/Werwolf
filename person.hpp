#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
enum whoami { Dorfbewohner, Werwolf};

class person
{
private:
    whoami bewohnerstatus;
    int counter;
    std::string name;
    std::string ask_neutral;
    std::string ask_skeptic;
    std::string answer_random;
public:
    person();

    whoami GetPersonenStatus();


    std::string GetName();
    std::string GetAnswer(int answer_choose);
    std::string GetFinalInformation();

    int GetID();

    void SetWerwolf();
    void SetDialog(std::string ask_neutral, std::string ask_skeptic, std::string answer_random);
    void SetName(std::string name);
};

#endif // PERSON_H
