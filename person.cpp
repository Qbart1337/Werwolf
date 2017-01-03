#include "person.hpp"
person::person()
{
    bewohnerstatus = Dorfbewohner;
    //
    ask_Counter = 0;
}

std::string person::GetName(){
    return (name);
}
void person::SetName(std::string name){
    this->name = name;
}
whoami person::GetPersonenStatus(){
    return bewohnerstatus;
}
void person::SetDialog(std::string ask_neutral, std::string ask_skeptic, std::string answer_random){
    this->answer_neutral = ask_neutral;
    this->answer_sceptic = ask_skeptic;
    this->answer_random = answer_random;
}

void person::SetDialogOptions(std::string str_opts){
    dialog_options=str_opts;
}

std::string person::DialogOptions(){
    return dialog_options;
}

std::string person::GetAnswer(int answer_choose){
    if(ask_Counter >= 2)
    {
        return answer_random;
    }
    else
    {
        ask_Counter++;
        switch(answer_choose)
        {
            case(1): return answer_neutral;
            case(2): return answer_sceptic;
        }
    }
}
void person::SetWerwolf(){
    bewohnerstatus = Werwolf;
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
bool person::GetWerwolfStatus(){
    if(bewohnerstatus == Werwolf){
        true;
    }
    else{
        return false;
    }
}
