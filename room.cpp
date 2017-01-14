#include "room.hpp"

//# Caner Yavuz
room::room()
{
    // Ausgenommen! Nicht mehr benutzen
}
void room::SetRoomName(std::string raumName){
    this->room_name = raumName;
}
std::string room::GetRoomeName(){
    return room_name;
}
