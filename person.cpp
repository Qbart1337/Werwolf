#include "person.hpp"
person::person()
{
    bewohnerstatus = Dorfbewohner;
    counter = 0;
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
    this->ask_neutral = ask_neutral;
    this->ask_skeptic = ask_skeptic;
    this->answer_random = answer_random;
}
std::string person::GetAnswer(int answer_choose){
    if(counter >= 2)
    {
        return answer_random;
    }
    else
    {
        counter++;
        switch(answer_choose)
        {
            case(1): return ask_neutral;
            case(2): return ask_skeptic;
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
