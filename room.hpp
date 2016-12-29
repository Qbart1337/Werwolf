#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <person.hpp>


class room
{
private:
    std::string room_name;


public:
    room();
    void SetRoomName(std::string room_name);
    std::string GetRoomeName();
};

#endif // ROOM_H
