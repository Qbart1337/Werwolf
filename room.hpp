#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <person.hpp>


class room
{
public:
    std::string raumName;
    room();
    void SetRoomName(std::string raumName);
    std::string GetRoomeName();
};

#endif // ROOM_H
