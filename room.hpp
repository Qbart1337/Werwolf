#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <person.hpp>

//# Caner Yavuz
// Room wurde aus dem Spiel genommen aber Code bleibt.
class room
{
private:
    std::string room_name;
    person room_person;

public:
    room();
    void SetRoomName(std::string room_name);
    std::string GetRoomeName();
};
#endif // ROOM_H
