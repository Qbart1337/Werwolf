#include <Windows.h>
#include <string>
std::string GetXTimesTheSameString(std::string singlestring, int value){
    std::string tmp = "";
    for(int i=0; i<value; i++){
        tmp += singlestring;
    }
    return tmp;
}
void printTextSmoothly(std::string AusgabeString, int timeintervall = 20){
    int len = 0;
    len = AusgabeString.length();
    for(int i=0; i<len; i++){
        std::cout << AusgabeString[i];
        Sleep(timeintervall);
    }
    std::cout << std::endl;
}
void printSpecialText(std::string AusgabeString){
    int len = 0;
    len = AusgabeString.length();
    int total_len = len + 20;
    //int half_len_first = total_len/2  -len / 2;
    int half_len_first = (total_len - len) / 2;
    int half_len_second = half_len_first -1;

    /* Anscheinend nicht mehr benötigt
     *
    if(len % 2 != 0){
        half_len_second --;
    }*/
    std::cout << GetXTimesTheSameString("*", total_len) << std::endl;
    std::cout << "*" << GetXTimesTheSameString(" ", total_len-2) << "*" << std::endl;
    std::cout << "*" << GetXTimesTheSameString(" ", half_len_first) << AusgabeString << GetXTimesTheSameString(" ", half_len_second-1) << "*" << std::endl;
    std::cout << "*" << GetXTimesTheSameString(" ", total_len-2) << "*" << std::endl;
    std::cout << GetXTimesTheSameString("*", total_len) << std::endl;
}
void printXEmptyLines(int value){
    for(int i=0; i<value; i++){
        std::cout << std::endl;
    }
}
