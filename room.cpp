#include "room.hpp"

room::room()
{

}
void room::SetRoomName(std::string raumName){
    this->raumName = raumName;
}
std::string room::GetRoomeName(){
    return raumName;
}
