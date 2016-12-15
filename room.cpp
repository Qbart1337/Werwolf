#include "room.hpp"

room::room()
{

}
void room::SetRoomName(std::string raumName){
    this->room_name = raumName;
}
std::string room::GetRoomeName(){
    return room_name;
}
