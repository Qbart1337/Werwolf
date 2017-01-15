#include "person.hpp"

//@Stefan
// default fuer GetAnswer()
// Konstruktor erstellt den Bewohner init die privaten Variablen
person::person()
{
    bewohnerstatus = Dorfbewohner;
    ask_Counter = 0;
}

// # SETTERS #
void person::SetWerwolf()
{
    bewohnerstatus = Werwolf;
}

void person::SetName(std::string name)
{
    this->name = name;
}

void person::SetDialogOptions(std::string str_opts)
{
    dialog_options=str_opts;
}

void person::SetDialog(std::string ask_neutral, std::string ask_skeptic, std::string answer_random)
{
    ask_Counter = 0;
    this->answer_neutral = ask_neutral;
    this->answer_sceptic = ask_skeptic;
    this->answer_random = answer_random;
}

// # GETTERS #
whoami person::GetPersonenStatus()
{
    return bewohnerstatus;
}

std::string person::GetName()
{
    return (name);
}

std::string person::GetDialogOptions()
{
    return dialog_options;
}

std::string person::GetAnswer(int answer_choose, bool temp = true)
{
    if(ask_Counter >= 2 && temp)
    {
        return answer_random;
    }
    else
    {
        if(temp)
        {
            ask_Counter++;
        }
        switch(answer_choose)
        {
            case(1): return answer_neutral;
            case(2): return answer_sceptic;
            default: return answer_random;
        }
    }
}

std::string person::GetFinalInformation()
{
    if(bewohnerstatus == Werwolf)
    {
        return "Gratuliere - du hast das Spiel gewonnen";
    }
    else
    {
        return "Du hast das Spiel leider verloren";
    }
}
bool person::GetWerwolfStatus()
{
    if(bewohnerstatus == Werwolf)
    {
        true;
    }
    else
    {
        return false;
    }
}
