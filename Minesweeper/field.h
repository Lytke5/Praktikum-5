#ifndef FIELD_H
#define FIELD_H
#include <Windows.h>

class Field
{
private:
    int size;
    char field[26][26];
    bool fieldIntern[26][26];
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
public:
    Field(int size_, int bombAmount);
    void printField();
    char sweepMine(int v, int h);
    void openField(int v, int h);
    bool getFieldIntern(int v, int h);
    char getField(int v, int h);
    void setField(int v, int h, char c);
    int getScore();
};

#endif // FIELD_H
